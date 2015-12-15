#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QObject>
#include <irrKlang.h>
#include <string>
#include <map>

#include <QDebug>

class Instrument {

public:
    Instrument(irrklang::ISoundEngine* engine);
    void playSound(unsigned int tone);
    void stopSound(unsigned int tone);
    void load(std::string newInstrument);
    ~Instrument();

private:
    const std::string soundLocation = "Resources/Sound/";
    const std::string soundFilenames[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    std::string instrument = "";
    irrklang::ISoundEngine* engine;
    std::map<std::string, irrklang::ISound*> sounds;
    irrklang::ISound* getSound(unsigned int index);

    void unload();

signals:

public slots:
};

#endif // INSTRUMENT_H
