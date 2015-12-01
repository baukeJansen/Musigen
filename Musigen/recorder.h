#ifndef RECORDER_H
#define RECORDER_H

#include <Melody/melody.h>
#include <timer.h>

// record current played melody
class Recorder {

public:
    Recorder(int toneRange);
    void startRecording(Melody *melody);
    void startNote(int toneHeight);
    void stopNote(int toneHeight);
    Melody* stopRecording();
    ~Recorder();

private:
    Melody *melody;
    Timer *timer;
    int *noteStartTimes;
    int recordingStartTime;
    int toneRange = 0;



};

#endif // RECORDER_H
