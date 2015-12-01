#include "note.h"

Note::Note(unsigned int startTime, unsigned int duration, unsigned int toneHeight) {

    this->startTime = startTime;
    this->duration = duration;
    this->toneHeight = toneHeight;

}

int Note::getStartTime() {

    return startTime;

}

int Note::getDuration() {

    return duration;

}

int Note::getEndTime() {

    return startTime + duration;

}

int Note::getToneHeight() {

    return toneHeight;

}

Note::~Note() {



}
