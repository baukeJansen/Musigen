#ifndef MELODY_H
#define MELODY_H

#include <QObject>
#include <QSharedPointer>
#include <Melody/note.h>
#include <Melody/instrument.h>

// combination of instrument and multiple notes
class Melody {

    public:
        Melody(QSharedPointer<Instrument> instrument);
        ~Melody();

        QSharedPointer<Instrument> getInstrument();
        std::vector<Note*> getNotes();
        void setInstrument(QSharedPointer<Instrument> instrument);
        void addNote(Note *note);
        Note* removeNote(Note *note);
        void deleteNote(Note *note);

        void play();


        // MidiFile toMidi();
        // void fromMidi(MidiFile);

    private:

        QSharedPointer<Instrument> instrument;
        std::vector<Note*> notes = {};
        std::vector<Note*>::iterator location;

    signals:

    public slots:

};

#endif // MELODY_H
