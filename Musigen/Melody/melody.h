#ifndef MELODY_H
#define MELODY_H

#include <QObject>
#include <vector>
#include <Melody/note.h>
#include <Melody/instrument.h>

// combination of instrument and multiple notes
class Melody {

    public:
        Melody(Instrument *instrument);
        ~Melody();

        Instrument* getInstrument();
        std::vector<Note*> getNotes();
        void setInstrument(Instrument *instrument);
        void addNote(Note *note);
        Note* removeNote(Note *note);
        void deleteNote(Note *note);

        void play();


        // MidiFile toMidi();
        // void fromMidi(MidiFile);

    private:

        Instrument *instrument;
        std::vector<Note*> notes = {};
        std::vector<Note*>::iterator location;

    signals:

    public slots:

};

#endif // MELODY_H
