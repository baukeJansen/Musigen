#include "melody.h"

Melody::Melody(QSharedPointer<Instrument> instrument) {

    this->setInstrument(instrument);

}

QSharedPointer<Instrument> Melody::getInstrument() {

    return instrument;

}

std::vector<Note*> Melody::getNotes() {

    return notes;

}

void Melody::setInstrument(QSharedPointer<Instrument> instrument) {

    this->instrument = instrument;

}

void Melody::addNote(Note *note) {

    location = notes.begin();
    while (location != notes.end() && ((*location)->getStartTime() < note->getStartTime()) ) {

        location = std::next(location);

    }

    notes.insert(location, note);
}

Note* Melody::removeNote(Note *note) {

    location = notes.begin();
    while (location != notes.end() && (*location) != note ) {

        location = std::next(location);

    }

    if (location == notes.end()) {

        return nullptr;

    }

    return *location;

}

void Melody::deleteNote(Note *note) {

    Note *n = removeNote(note);

    if (n != nullptr) {

        delete note;

    }

}

Melody::~Melody() {

}

