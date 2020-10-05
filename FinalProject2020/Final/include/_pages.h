#ifndef _PAGES_H
#define _PAGES_H

#include <GL/gl.h>
#include <_textureLoader.h>

class _pages
{
    public:
        _pages();
        virtual ~_pages();
        _textureLoader* tex = new _textureLoader();

        GLvoid pageInit(char*);
        GLvoid drawPage(GLfloat, GLfloat);

        float xMin,xMax, yMin, yMax;

    protected:
    private:
};

#endif // _PAGES_H
