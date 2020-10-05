#ifndef _TARGET_H
#define _TARGET_H

#include <GL/gl.h>
#include<_glScene.h>
#include <_player.h>
#include <_textureLoader.h>
#include <_timer.h>

typedef struct {
    float x;
    float y;
    float z;
}vec1;

class _target
{
     public:
        _target();
        virtual ~_target();

        vec1 vertices[4];
        void drawTarget();
        void placeTarget(float,float,float);
        void initTarget(char *filename);

        bool actionCounter = false;

        GLuint TargetTex;

        float xPos, yPos, zPos;
        float xSize, ySize;
        float xMin, yMin, xMax, yMax;

        int frames;     //number of frames selected from sprite sheets
        float xMove;    //movement along x axis

        _timer *TE = new _timer();
        _textureLoader *T = new _textureLoader();
        void checkCollision(_player*);

    protected:

    private:


};

#endif // _TARGET_H
