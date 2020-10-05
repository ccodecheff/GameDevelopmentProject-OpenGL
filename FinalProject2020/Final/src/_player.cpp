#include "_player.h"

_player::_player()
{
    verticies[0].x=0.0; verticies[0].y=0.0;verticies[0].z=-0.3;
    verticies[1].x=1.0; verticies[1].y=0.0;verticies[1].z=-0.3;
    verticies[2].x=1.0; verticies[2].y=1.0;verticies[2].z=-0.3;
    verticies[3].x=0.0; verticies[3].y=1.0;verticies[3].z=-0.3;

    xPos = -0.3;        //initial positions of the player on the screen
    yPos = -0.05;
    zPos = -1.0;

    xSize = 0.3;        //size of the player
    ySize = 0.3;


    frames  = 4.0;      //number of frames selected from the sprite sheet
    xMin    = 3.0/frames;   //default action from sprite sheet
    yMin    = 0.0;
    yMax    = 0.33;
    xMax    = 1.0;
    knockedBack=0;
}

_player::~_player()
{
    //dtor
}

void _player::playerTranslate(float xNew,float yNew)
{
    xPos += xNew;
    if (xPos > 0.7)
    {
        xPos = 0.7;
    }
    yPos += yNew;
    if (yPos < -0.6)
    {
        yPos = -0.6;
    }
    if (yPos > 0.35)
    {
        yPos = 0.35;
    }
}

void _player::drawPlayer()
{
    glColor3f(1.0,0.0,0.0);
    T->TextureBinder();

    glPushMatrix();

    glTranslated(xPos,yPos,zPos);
    glScaled(xSize,ySize,1.0);

    glBegin(GL_QUADS);
    glTexCoord2f(xMin,yMax);
    glVertex3f(verticies[0].x,verticies[0].y, verticies[0].z);
    glTexCoord2f(xMax,yMax);
    glVertex3f(verticies[1].x,verticies[1].y, verticies[1].z);
    glTexCoord2f(xMax,yMin);
    glVertex3f(verticies[2].x,verticies[2].y, verticies[2].z);
    glTexCoord2f(xMin,yMin);
    glVertex3f(verticies[3].x,verticies[3].y, verticies[3].z);
    glEnd();

    glPopMatrix();
}

void _player::initPlayer(char *fileName)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    T->loadTexture(fileName);               //texture loader pointer
    tmr->start();       //start the timer
}

void _player::actions()     //describing different actions
{
    switch(action) //pass the action int value to select particular action
    {
        case 0:
            frames= 4.0;    //giving the number of frames for each case
            if(tmr->getTicks()>60)
            {
                xMin+=1.0/frames;
                xMax+=1.0/frames;
                yMin= 0.0;
                yMax= 0.33;
                if(xMax>=1.0){xMin=0.0; xMax=1.0/frames;}
                tmr->reset();   //reseting timer after each action
            }
        break;
        case 1:
            frames= 4.0;
            if(tmr->getTicks()>60)
            {
                xMin+=1.0/frames;
                xMax+=1.0/frames;
                yMin= 0.0;
                yMax= 0.33;
                if(xMax>=1.0){xMin=1.0/frames; xMax=0.0;}
                tmr->reset();   //reseting timer after each action
            }
        break;
        case 3:
            frames= 4.0;
            xMin = 3.0/frames;
            xMax = 1.0;
            yMin = 0.0;
            yMax = 0.33;
            break;
    }
}
