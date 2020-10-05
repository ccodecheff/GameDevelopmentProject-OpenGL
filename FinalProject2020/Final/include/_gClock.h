#ifndef _GCLOCK_H
#define _GCLOCK_H

#include<GL/gl.h>
#include<_textureLoader.h>
#include<time.h>
#include<_timer.h>
#include<_gClockNum.h>

class _gClock
{
    public:
        _gClock();
        virtual ~_gClock();

        void clockInit(char *);
        void startClock(int,int,int);
        bool timeAction();
        void drawClock();
        void activateClock(bool);

        float xMin, yMin, xMax, yMax;
        float xPos, yPos, zPos;

        _gClockNum numbers[3];

        int minutes;
        int seconds;
        int milliseconds;

        bool timeOver;
        bool runTime;
        bool isActive;

        _textureLoader Text;
        _timer Time;


    protected:

    private:
};

#endif // _GCLOCK_H
