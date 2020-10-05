#ifndef _INPUTS_H
#define _INPUTS_H

#include<windows.h>
#include<GL/glut.h>
#include<_parallax.h>
#include<_player.h>
#include<_enemyA.h>
#include<_sound.h>
#include<_glScene.h>
#include<_enemyB.h>


class _inputs
{
    public:
        _inputs();
        virtual ~_inputs();

        void isPressed();
        bool playerInput(_player *, _parallax*, _enemyA* ,float);//handles movements of player , parallax, enemy.
        bool isLeft,isRight,isUp,isDown;
        WPARAM wParam;

    protected:
    private:
};

#endif // _INPUTS_H
