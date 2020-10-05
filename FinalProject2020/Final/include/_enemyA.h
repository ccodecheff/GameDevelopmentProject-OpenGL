#ifndef _ENEMYA_H
#define _ENEMYA_H

#include <GL/gl.h>
#include <_timer.h>
#include <_textureLoader.h>
#include <_player.h>
#include <_glScene.h>
#include<_sound.h>

class _enemyA
{
    public:
        _enemyA();
        virtual ~_enemyA();

        void drawEnemy();
        void placeEnemy(float, float, float);

        void actions();

        void enemyMovement(_player*);
        float speed;
        int aiType;
        int actionCounter = 0;
        int action=0;

        float xMove;
        bool visible;

        GLuint enemyTex;

        void enemyInit();

        float xPos,yPos,zPos;
        float xSize,ySize,zSize;
        float xMin,yMin,xMax,yMax;

        float rotateX,rotateY,rotateZ;

        float frames;


        _timer *T3 = new _timer();

        void checkCollision(_sound*,_player*);

    protected:
    private:
};

#endif // _ENEMYA_H
