#include "_enemyA.h"

_glScene* GS1 = new _glScene();

_enemyA::_enemyA()
{
    xPos = -0.3;        //initial x,y,z positions of the enemy.
    yPos = 0.0;
    zPos = -1.0;

    xSize = 0.19;       //size coordinates of the enemy
    ySize = 0.19;

    rotateX = 0.0;
    rotateY = 0.0;
    rotateZ = 0.0;

    xMove=0.01;

    speed = 0.01;
    aiType = 0;
}

_enemyA::~_enemyA()
{

}

void _enemyA::enemyInit()
{
    frames = 1.0;
    xMin = 0.0;
    yMin = 0.0;
    xMax = 1.0;
    yMax = 1.0;
}

void _enemyA::drawEnemy()
{
    glPushMatrix();

    glTranslated(xPos,yPos,zPos);
    glRotated(rotateX,1,0,0);
    glRotated(rotateY,0,1,0);
    glRotated(rotateZ,0,0,1);
    glBindTexture(GL_TEXTURE_2D,enemyTex);
    glScaled(xSize,ySize,1.0);

    glBegin(GL_QUADS);

    glTexCoord2f(xMin,yMax);
    glVertex3f(1.0,0.0,-0.2);
    glTexCoord2f(xMax,yMax);
    glVertex3f(0.0,0.0, -0.2);
    glTexCoord2f(xMax,yMin);
    glVertex3f(0.0,1.0, -0.2);
    glTexCoord2f(xMin,yMin);
    glVertex3f(1.0,1.0, -0.2);

    glEnd();

    glPopMatrix();
}

void _enemyA::placeEnemy(float x, float y, float z)
{
    xPos = x;
    yPos = y;
    zPos = z;
}

void _enemyA::actions()
{
    switch(action)
    {
        case 0:
            if(T3->getTicks()>60)
            {
                xMin +=1.0/(float)frames;
                xMax +=1.0/(float)frames;

                yMin = 0.0;
                yMax = 1.0;
                    if(xMax>=1)
                    {
                        xMin=1.0;
                        xMax = 0.0;
                        T3->reset();
                    }
                T3->reset();
            }
        break;
        case 1:
            if(T3->getTicks()>60)
            {
                xMin +=1.0/(float)frames;
                xMax +=1.0/(float)frames;

                yMin = 0.4;
                yMax = 0.6;
                   if(xMax>=1.0){xMin=0.0; xMax=1.0/frames;}
                T3->reset();
            }
        break;
    }
}

void _enemyA::checkCollision(_sound*snds, _player* ply)
{
    float enmLeftBound = xPos + xSize * 0.1;
    float enmRightBound = xPos + xSize * 0.2;
    float plyLeftBound = ply->xPos + ply->xSize * 0.2;
    float plyRightBound = ply->xPos + ply->xSize * 0.6;

    float enmBottomBound = yPos + ySize * 0.2;
    float enmTopBound = yPos + ySize * 0.6;
    float plyBottomBound = ply->yPos + ply->ySize * 0.1;
    float plyTopBound = ply->yPos + ply->ySize * 0.6;


    if (enmRightBound >= plyLeftBound && plyRightBound >= enmLeftBound)
    {
        if (enmTopBound >= plyBottomBound && plyTopBound >= enmBottomBound)
        {
            if (ply->knockedBack == 0)
            {
                ply->knockedBack = 15;
                aiType = 0;
                //snds->playMusic("sounds/death.wav");
                //ply->lives--;
            }

        }
    }
}

void _enemyA::enemyMovement(_player* ply)
{
    float xDif = (ply->xPos + (ply->xSize / 2.0)) - (xPos + (xSize / 2.0));     // x axis distance from player
    float yDif = (ply->yPos + (ply->ySize / 2.0)) - (yPos + (ySize / 2.0));     // y axis distance from player

    switch (aiType)
    {
        case 1:             // follow player only on x axis
            if (xDif < -0.02 || xDif > 0.02)
            {
                if (xDif > 0) {
                    xPos=xPos+speed;
                }
            else
            {
                xPos=xPos-speed;
            }
        }
        break;
        case 2:
            if (yDif < -0.02 || yDif > 0.02)
            {
                if (yDif > 0)
                {
                    yPos=yPos+(speed / 2.2);
                }
                else
                {
                    yPos=yPos-(speed / 2.2);
                }
            }
        break;
        case 3:             // chase player, get slower when closer
            if (xDif > 0)
            {
                xPos=xPos+speed*3.0*((ply->xPos + (ply->xSize / 2.0)) - (xPos + (xSize / 2.0)));
            }
            else
            {
                xPos=xPos+speed*((ply->xPos + (ply->xSize / 2.0)) - (xPos + (xSize / 2.0)));
            }
            yPos=yPos+speed*((ply->yPos + (ply->ySize / 2.0)) - (yPos + (ySize / 2.0)));
        break;
        case 4:             // chase player at consistent speed, tries to get in front of them
            if (xDif + 0.2 < -0.1 || xDif + 0.2 > 0.1)
            {
                if (xDif + 0.2 > 0)
                {
                    xPos=xPos+(speed / 2);
                }
                else
                {
                    xPos=xPos-speed;
                }
            }
            if (yDif < -0.1 || yDif > 0.1)
            {
                if (yDif > 0) {
                    yPos=yPos+(speed / 1.1);
                }
                else
                {
                    yPos=yPos-(speed / 1.1);
                }
            }
        break;
    default:;
    }
}
