#include "_model.h"
#include<_textureLoader.h>

_textureLoader *tex = new _textureLoader();

_model::_model()
{
    rotateX = 0.0;
    rotateY = 0.0;
    rotateZ = 0.0;

    posZ = -8.0;
    posX = 0.0;
    posY = 0.0;

}

_model::~_model()
{

}

void _model::modelInit(char* filename)
{
    tex->loadTexture(filename);
}

void _model::drawModel()
{
    tex->TextureBinder();
    glColor3f(0.9,0.6,0.6);
    glTranslated(posX,posY,posZ);
    glRotated(rotateX,1,0,0);
    glRotated(rotateY,0,1,0);
    glRotated(rotateZ,0,0,1);

}
