#ifndef NOTE_H
#define NOTE_H

#include <QObject>

// note with startTime, endTime and toneheigh
class Note {

    public:
        Note(unsigned int startTime = 0, unsigned int duration = 0, unsigned int toneHeight = 0);
        ~Note();

        int getStartTime();
        int getDuration();
        int getEndTime();
        int getToneHeight();

    private:
        unsigned int startTime = 0;
        unsigned int duration = 0;
        unsigned int toneHeight = 0;

    signals:

    public slots:

};

#endif // NOTE_H
