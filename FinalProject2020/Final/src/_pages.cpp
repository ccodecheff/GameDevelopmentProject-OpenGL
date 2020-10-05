#include "_pages.h"

_pages::_pages()
{
    xMax = 1.0;
    xMin = 0.0;
    yMax = 1.0;
    yMin = 0.0;
}

_pages::~_pages()
{

}

GLvoid _pages::pageInit(char* fileName)
{
    tex->loadTexture(fileName);
}

GLvoid _pages::drawPage(GLfloat w, GLfloat h)
{
    glPushMatrix();

    tex->TextureBinder();
    glScaled(4.15,4.14,1.0);

    glBegin(GL_POLYGON);
    glTexCoord2f(xMin,yMin);
    glVertex3f(-w/h,1,-10.0f);
    glTexCoord2f(xMax,yMin);
    glVertex3f(w/h,1,-10.0f);
    glTexCoord2f(xMax,yMax);
    glVertex3f(w/h,-1,-10.0f);
    glTexCoord2f(xMin,yMax);
    glVertex3f(-w/h,-1,-10.0f);

    glEnd();
}
