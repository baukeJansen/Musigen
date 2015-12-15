#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QTimer>
#include <Melody/instrument.h>
#include <Melody/melody.h>
#include <Melody/note.h>
#include <recorder.h>
#include <QSharedPointer>

#include <qdebug.h>

// play sounds or melody
class MusicPlayer : public QObject {

    Q_OBJECT

    public:
        MusicPlayer();
        MusicPlayer(QSharedPointer<Instrument> instrument);
        ~MusicPlayer();

        void setInstrument(QSharedPointer<Instrument> instrument);
        QSharedPointer<Instrument> getInstrument();

        void playNote(int toneHeight);
        void stopNote(int toneHeight);

        void play(Melody *melody);
        void pause();
        void unpause();
        void stop();

        void startRecording();
        void startRecording(Melody* melody);
        Melody* stopRecording();

    private:
        void init();
        void getNextNote();
        void startNoteTimer();
        void runTimer(int newTime);
        void addNoteEnd(Note* note);

        QSharedPointer<Instrument> instrument;
        Melody *melody;
        Recorder *recorder;
        std::vector<Note*> startNotes;
        std::vector<Note*> stopNotes;
        QTimer *timer;

        std::vector<Note*>::iterator startIt;
        std::vector<Note*>::iterator stopIt;

        int time = 0;
        bool playing = false;
        bool recording = false;



    signals:

    public slots:
        void nextNote();

};

#endif // MUSICPLAYER_H
