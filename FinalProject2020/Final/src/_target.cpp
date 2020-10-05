#include "_target.h"
_glScene *GS = new _glScene();
_target::_target()
{
    vertices[0].x = 0.0; vertices[0].y = 0.0; vertices[0].z = -0.3;
    vertices[1].x = 1.0; vertices[1].y = 0.0; vertices[1].z = -0.3;
    vertices[2].x = 1.0; vertices[2].y = 1.0; vertices[2].z = -0.3;
    vertices[3].x = 0.0; vertices[3].y = 1.0; vertices[3].z = -0.3;

    xMin = 0.0;
    yMin = 0.0;
    xMax = 0.0;
    yMax = 0.0;

    xSize = 0.3;
    ySize = 0.3;

    xPos = 0.5;
    yPos = -0.55;
    zPos = -1.0;

    xMin = 0.0;
    xMax = 1.0;
    yMin = 0.0;
    yMax = 1.0;
}

_target::~_target()
{
    //dtor

}

void _target::drawTarget()
{

    T->TextureBinder();

    glPushMatrix();
    glTranslated(xPos,yPos,zPos);

    glScaled(xSize,ySize,1.0);

    glBegin(GL_QUADS);

    glTexCoord2f(xMin,yMax);
    glVertex3f(vertices[0].x,vertices[0].y, vertices[0].z);
    glTexCoord2f(xMax,yMax);
    glVertex3f(vertices[1].x,vertices[1].y, vertices[1].z);
    glTexCoord2f(xMax,yMin);
    glVertex3f(vertices[2].x,vertices[2].y, vertices[2].z);
    glTexCoord2f(xMin,yMin);
    glVertex3f(vertices[3].x,vertices[3].y, vertices[3].z);

    glEnd();

    glPopMatrix();

}

void _target::placeTarget(float x, float y, float z)
{
    xPos= x;
    yPos= y;
    zPos= z;
}

void _target::initTarget(char *filename)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    T->loadTexture(filename);
    TE->start();
}

void _target::checkCollision(_player* ply)
{
    float enmLeftBound = xPos + xSize * 0.1;
    float enmRightBound = xPos + xSize * 0.2;
    float plyLeftBound = ply->xPos + ply->xSize * 0.2;
    float plyRightBound = ply->xPos + ply->xSize * 0.8;

    float enmBottomBound = yPos + ySize * 0.2;
    float enmTopBound = yPos + ySize * 0.8;
    float plyBottomBound = ply->yPos + ply->ySize * 0.1;
    float plyTopBound = ply->yPos + ply->ySize * 0.8;
    if (enmRightBound >= plyLeftBound && plyRightBound >= enmLeftBound) {
        if (enmTopBound >= plyBottomBound && plyTopBound >= enmBottomBound) {
            if (ply->knockedBack == 0)
                {
                    ply->knockedBack = 15;
                    GS->nextLevel();
                    actionCounter = true;
            }
        }
    }
}
