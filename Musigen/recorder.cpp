#include "recorder.h"

Recorder::Recorder(int toneRange) {

    this->toneRange = toneRange;

    noteStartTimes = new int[toneRange];
    timer = new Timer();

    std::fill( noteStartTimes, noteStartTimes + toneRange, -1 );

}

void Recorder::startRecording(Melody *melody) {

    this->melody = melody;
    recordingStartTime = timer->getMilliCount();

}

void Recorder::startNote(int toneHeight) {

    if (toneRange < toneHeight || toneHeight < 0) {

        return;

    }

    noteStartTimes[toneHeight] = timer->getMilliSpan(recordingStartTime);

}

void Recorder::stopNote(int toneHeight) {

    if (toneRange < toneHeight || toneHeight < 0) {

        return;

    }

    int startTime = noteStartTimes[toneHeight];
    int endTime = timer->getMilliSpan(recordingStartTime);

    if ( startTime == -1) {

        return;

    }

    Note *note = new Note(startTime, endTime - startTime, toneHeight);
    melody->addNote(note);

    noteStartTimes[toneHeight] = -1;

}

Melody* Recorder::stopRecording() {

    return melody;

}

Recorder::~Recorder() {

    delete timer;
    delete noteStartTimes;

}
