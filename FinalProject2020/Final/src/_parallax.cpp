#include "_parallax.h"

_parallax::_parallax()
{
    xMax =0.4;
    yMax =1.0;
    xMin =0.0;
    yMin =0.0;
}

_parallax::~_parallax()
{

}

void _parallax::drawSquare(float width, float height)
{
    bTex->TextureBinder();
    //glColor3f(1.0,1.0,1.0);
    glScaled(4.2,4.2,1.0);

    glBegin(GL_POLYGON);

    glTexCoord2f(xMin,yMin);
    glVertex3f(-width/height, 1, -10.0f);
    glTexCoord2f(xMax,yMin);
    glVertex3f(width/height, 1, -10.0f);
    glTexCoord2f(xMax,yMax);
    glVertex3f(width/height, -1, -10.0f);
    glTexCoord2f(xMin,yMax);
    glVertex3f(-width/height, -1, -10.0f);

    glEnd();
}

void _parallax::parallaxInit(char* fileName)
{
    bTex->loadTexture(fileName);
}

bool _parallax::scroll(string dir, float speed, _enemyA *enm)
{
    if (dir == "left" && xMin >= 0.0) {
        xMin = xMin - speed;
        xMax = xMax - speed;
        for (int i = 0; i < 20; i++) {
            enm[i].xPos += speed * 4.5;


        }
        return true;
    }
    else
    {
        if (dir == "right" && xMax <= 1.0)
        {
            xMin = xMin + speed;
            xMax = xMax + speed;
            for (int i = 0; i < 20; i++)
            {
                enm[i].xPos -= speed * 4.5;

            }
            return true;
        }
        else
        {
            return false;
        }
    }
}
