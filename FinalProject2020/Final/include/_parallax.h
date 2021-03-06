#ifndef _PARALLAX_H
#define _PARALLAX_H

#include <gl/gl.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <_textureLoader.h>
#include <_enemyA.h>
#include<_enemyB.h>


using namespace std;

class _parallax
{
    public:
        _parallax();
        virtual ~_parallax();

        void drawSquare(float, float);  // to draw a quad for the background
        void parallaxInit(char *);  // Load images to the background
        bool scroll(string, float, _enemyA*);// bool for Auto, string for direction
                                                // speed of the movement

        _textureLoader *bTex = new _textureLoader();

        float xMax,yMax,xMin,yMin;      //  For texture coordinates


    protected:
    private:
};

#endif // _PARALLAX_H
