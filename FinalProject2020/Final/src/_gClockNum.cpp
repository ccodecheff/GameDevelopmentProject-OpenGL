#include "_gClockNum.h"

_gClockNum::_gClockNum()
{
    xMin = 0.0;
    yMin = 0.0;
    xMax = 1.0;
    yMax = 1.0;

    xPos = 0.0;
    yPos = 0.0;
    zPos = 0.0;
}

_gClockNum::~_gClockNum()
{

}

void _gClockNum::drawNumbers()
{
    switch(current) {
    case 0:
        xMin = 0.0;
        xMax = 0.2;
        yMin = 0.0;
        yMax = 0.5;
        break;
    case 1:
        xMin = 0.2;
        xMax = 0.4;
        yMin = 0.0;
        yMax = 0.5;
        break;
    case 2:
        xMin = 0.4;
        xMax = 0.6;
        yMin = 0.0;
        yMax = 0.5;
        break;
    case 3:
        xMin = 0.6;
        xMax = 0.8;
        yMin = 0.0;
        yMax = 0.5;
        break;
    case 4:
        xMin = 0.8;
        xMax = 1.0;
        yMin = 0.0;
        yMax = 0.5;
        break;
    case 5:
        xMin = 0;
        xMax = 0.2;
        yMin = 0.5;
        yMax = 1.0;
        break;
    case 6:
        xMin = 0.2;
        xMax = 0.4;
        yMin = 0.5;
        yMax = 1.0;
        break;
    case 7:
        xMin = 0.4;
        xMax = 0.6;
        yMin = 0.5;
        yMax = 1.0;
        break;
    case 8:
        xMin = 0.6;
        xMax = 0.8;
        yMin = 0.5;
        yMax = 1.0;
        break;
    case 9:
        xMin = 0.8;
        xMax = 1.0;
        yMin = 0.5;
        yMax = 1.0;
        break;
    default:
        xMin = 0.0;
        xMax = 0.2;
        yMin = 0.0;
        yMax = 0.5;
    }
    Tex.TextureBinder();
    glPushMatrix();
    glTranslated(xPos,yPos,zPos);
    glBegin(GL_QUADS);

    glTexCoord2f(xMin,yMax);
    glVertex3f(0.0,0.0,-1.0);
    glTexCoord2f(xMax,yMax);
    glVertex3f(0.08,0.0,-1.0);
    glTexCoord2f(xMax,yMin);
    glVertex3f(0.08,0.12,-1.0);
    glTexCoord2f(xMin,yMin);
    glVertex3f(0.0,0.12,-1.0);

    glEnd();
    glPopMatrix();
}

void _gClockNum::initNumber(char* filename)
{
    Tex.loadTexture(filename);
}

