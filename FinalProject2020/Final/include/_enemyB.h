#ifndef _ENEMYB_H
#define _ENEMYB_H

#include <GL/gl.h>
#include <_timer.h>
#include <_textureLoader.h>
#include <_player.h>
#include <_glScene.h>
#include<_sound.h>

class _enemyB
{
   public:
        _enemyB();
        virtual ~_enemyB();

        void drawEnemy2();
        void placeEnemy2(float, float, float);
        void actions();

        float speed;
        int aiType;

        int action=0;
      GLuint EnemyTex2;
        float xMove;
        bool isEnemy2Live = true;

        void Enemy2Init();

        float xPos,yPos,zPos;
        float xSize,ySize,zSize;
        float xMin,yMin,xMax,yMax;

        float rotateX,rotateY,rotateZ;

        float frames;

        _timer *T3 = new _timer();

        void checkCollision(_player*);
        void enemyMovement(_player*);

    protected:
    private:
};

#endif // _ENEMYB_H
