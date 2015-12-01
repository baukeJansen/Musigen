#include "instrument.h"

Instrument::Instrument(irrklang::ISoundEngine* engine) {

    this->engine = engine;
    load("Default");

}

void Instrument::load(std::string newInstrument) {

    if (instrument == newInstrument)
        return;

    if (instrument != "")
        unload();


    instrument = newInstrument;
//sizeof(soundFilenames)
    for (unsigned int i = 0; i < 11; i++) {

        // create sound location string
        std::string soundName = soundLocation + newInstrument + '/' + soundFilenames[i] + "4.mp3";

        // convert to char array
        char* cSoundName = (char*) soundName.c_str();

        // load sound from location
        irrklang::ISound* sound = engine->play2D(cSoundName, true, true, true);
        //sound->setPlaybackSpeed(2);
        // add sound to list
        sounds.insert(std::pair<std::string, irrklang::ISound*>(soundFilenames[i], sound));
    }

}

void Instrument::unload() {

    if (instrument == "")
        return;

    for (unsigned int i = 0; i < sounds.size(); i++) {

        (*getSound(i)).drop();

    }

    instrument = "";

}

void Instrument::playSound(unsigned int tone) {

    (*getSound(tone)).setPlayPosition(1);
    (*getSound(tone)).setIsPaused(false);

}

void Instrument::stopSound(unsigned int tone) {

    (*getSound(tone)).setIsPaused(true);

}

irrklang::ISound* Instrument::getSound(unsigned int index) {

    if (instrument == "")
        return nullptr;

    if (index > sounds.size())
        return nullptr;

    return sounds[soundFilenames[index]];

}

Instrument::~Instrument() {

    unload();

}
