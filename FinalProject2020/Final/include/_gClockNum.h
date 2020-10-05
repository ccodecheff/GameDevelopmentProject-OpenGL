#ifndef _GCLOCKNUM_H
#define _GCLOCKNUM_H

#include<_textureLoader.h>

class _gClockNum
{
    public:
        _gClockNum();
        virtual ~_gClockNum();

        void drawNumbers();
        void initNumber(char*);

        int current;

        float xMin, yMin, xMax, yMax;
        float xPos, yPos, zPos;
        _textureLoader Tex;

    protected:

    private:
};

#endif // _GCLOCKNUM_H
