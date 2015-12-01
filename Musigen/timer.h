#ifndef TIMER_H
#define TIMER_H

//#include cstdlib
#include <sys/timeb.h>

class Timer {

public:
    Timer();
    int getMilliCount();
    int getMilliSpan(int nTimeStart);

};

#endif // TIMER_H
