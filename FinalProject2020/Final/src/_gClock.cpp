#include "_gClock.h"

_gClock::_gClock()
{
    xMin = 0.47;
    yMin = 0.08;
    xMax = 0.53;
    yMax = 0.33;

    xPos = -0.5675;
    yPos = 0.275;
    zPos = 0;

    minutes = 0;
    seconds = 0;
    milliseconds = 0;

    timeOver = true;
    runTime = false;
}

_gClock::~_gClock()
{
    //dtor
}

void _gClock::clockInit(char* filename)
{
    Text.loadTexture(filename);
    for (int i = 0; i < 3; i++)
    {
        numbers[i].initNumber("images/gClocks.jpg");
        numbers[i].xPos = -0.725 + (i * 0.08);
        if (i > 1)
        {
            numbers[i].xPos += 0.025;
        }
        numbers[i].yPos = 0.275;
    }
    isActive = true;
}

void _gClock::startClock(int mins, int secs, int msecs)
{
    minutes = mins;
    seconds = secs;
    milliseconds = msecs;

    runTime = true;
    timeOver = false;
    Time.start();
}

bool _gClock::timeAction()
{
    if (runTime) {
        if (Time.getTicks() > 85) {
            milliseconds -= 1;
            Time.reset();
        }
        if (minutes == 0 && seconds == 0 && milliseconds == 0) {
            runTime = false;
            timeOver = true;
        }
        if (milliseconds == -1) {
            seconds -= 1;
            milliseconds = 9;
        }
        if (seconds == -1) {
            minutes -= 1;
            seconds = 59;
        }
    }
    return timeOver;
}

void _gClock::drawClock()
{
    if (minutes > 0) {
        numbers[0].current = minutes / 10;
        numbers[1].current = minutes % 10;
        numbers[2].current = seconds / 10;
    }
    else {
        numbers[0].current = seconds / 10;
        numbers[1].current = seconds % 10;
        numbers[2].current = milliseconds;
    }
    for (int i = 0; i < 3; i++) {
        numbers[i].drawNumbers();
    }

    Text.TextureBinder();
    if (isActive)
    {
        glPushMatrix();
        glTranslated(xPos,yPos,zPos);
        glBegin(GL_QUADS);

        glTexCoord2f(xMin,yMax);
        glVertex3f(0.0,0.0,-1.0);

        glTexCoord2f(xMax,yMax);
        glVertex3f(0.03,0.0,-1.0);

        glTexCoord2f(xMax,yMin);
        glVertex3f(0.03,0.12,-1.0);

        glTexCoord2f(xMin,yMin);
        glVertex3f(0.0,0.12,-1.0);

        glEnd();

        glPopMatrix();
    }
}

void _gClock::activateClock(bool act)
{
    isActive = act;
}

