#include "musicplayer.h"

MusicPlayer::MusicPlayer() {

    init();

}

MusicPlayer::MusicPlayer(QSharedPointer<Instrument> instrument) {

    this->instrument = instrument;
    init();

}

void MusicPlayer::init() {

    recorder = new Recorder(10);
    timer = new QTimer(this);

    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextNote()));

}

QSharedPointer<Instrument> MusicPlayer::getInstrument() {

    return instrument;

}

void MusicPlayer::setInstrument(QSharedPointer<Instrument> instrument) {

    this->instrument = instrument;

}

void MusicPlayer::playNote(int toneHeight) {

    instrument->playSound(toneHeight);

    if (recording) {

        recorder->startNote(toneHeight);

    }

}

void MusicPlayer::stopNote(int toneHeight) {

    instrument->stopSound(toneHeight);


    if (recording) {

        recorder->stopNote(toneHeight);

    }

}

void MusicPlayer::play(Melody *melody) {

    if (playing == true) {

        stop();

    }

    this->melody = melody;
    this->instrument = melody->getInstrument();
    this->startNotes = melody->getNotes();

    startIt = startNotes.begin();
    stopIt = stopNotes.end();

    playing = true;
    time = 0;

    startNoteTimer();

}

void MusicPlayer::stop() {

    playing = false;

    std::vector<Note*>::iterator location = stopNotes.begin();
    while (location != stopNotes.end()) {

        instrument->stopSound((*location)->getToneHeight());
        location = std::next(location);

    }

    stopNotes.clear();

}

void MusicPlayer::nextNote() {

    getNextNote();
    startNoteTimer();

}

void MusicPlayer::getNextNote() {

    if (startIt == startNotes.end() && stopIt == stopNotes.end()) {

        return;

    }

    if (startIt == startNotes.end()) {

        instrument->stopSound((*stopIt)->getToneHeight());
        stopIt = std::next(stopIt);
        return;

    }

    if (stopIt == stopNotes.end()) {

        instrument->playSound((*startIt)->getToneHeight());
        addNoteEnd(*startIt);
        startIt = std::next(startIt);
        return;

    }

    Note *start = *startIt;
    Note *stop = *stopIt;

    int startTime = start->getStartTime();
    int stopTime = stop->getEndTime();
//qDebug() << startTime << ", " << stopTime;
    if (startTime >= stopTime) {

        stopIt = std::next(stopIt);
        instrument->stopSound(stop->getToneHeight());

    } else {

        startIt = std::next(startIt);
        instrument->playSound(start->getToneHeight());
        addNoteEnd(start);

    }

}

// find time till next note and start timer
void MusicPlayer::startNoteTimer()  {

    // end of music
    if (startIt == startNotes.end() && stopIt == stopNotes.end()) {

        return;

    }

    // start liste empty
    if (startIt == startNotes.end()) {

        runTimer((*stopIt)->getEndTime());
        return;

    }

    // stop list empty
    if (stopIt == stopNotes.end()) {

        qDebug() << (*startIt)->getStartTime();
        runTimer((*startIt)->getStartTime());
        return;

    }

    int startTime = (*startIt)->getStartTime();
    int stopTime = (*stopIt)->getEndTime();

    // decide if start or stop is first
    if (startTime > stopTime) {

        runTimer(stopTime);

    } else {

        runTimer(startTime);

    }

}

// start new timer until next note
void MusicPlayer::runTimer(int newTime) {

    // calculate time remaining from now
    newTime = newTime - time;

    // update global time with new time
    time += newTime;

    // start timer
    timer->start(newTime);

}

// add playing note to stop list
void MusicPlayer::addNoteEnd(Note* note) {

    //=== loop through stoplist to search the location for new note ===

    int it = -1;

    for (unsigned int i = 0; i < stopNotes.size(); i++) {

        if (stopNotes[i]->getEndTime() > note->getEndTime()) {

            stopNotes.insert(stopNotes.begin() + i, note);

            if ( it != -1) {

                stopIt = stopNotes.begin() + it;

            } else {

                stopIt = stopNotes.begin() + i;

            }

            return;

        }

        if (stopNotes.begin() + i == stopIt) {

            it = i;

        }

    }

    stopNotes.insert(stopNotes.end(), note);

    if ( it != -1) {

        stopIt = stopNotes.begin() + it;

    } else {

        stopIt = (stopNotes.begin() + stopNotes.size() - 1);

    }

}

void MusicPlayer::startRecording() {

    startRecording(new Melody(instrument));

}

void MusicPlayer::startRecording(Melody *melody) {

    this->recording = true;
    recorder->startRecording(melody);

}

Melody* MusicPlayer::stopRecording() {

    this->recording = false;
    return recorder->stopRecording();

}


MusicPlayer::~MusicPlayer() {

    delete timer;
    delete recorder;

}
