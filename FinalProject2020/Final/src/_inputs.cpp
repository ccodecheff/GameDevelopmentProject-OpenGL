#include "_inputs.h"

#define VK_KEY_W	0x57
#define VK_KEY_A	0x41
#define VK_KEY_S	0x53
#define VK_KEY_D	0x44

_inputs::_inputs()
{
    isLeft=false;
    isRight=false;
    isUp=false;
    isDown=false;
}

_inputs::~_inputs()
{

}
bool _inputs::playerInput(_player* ply, _parallax* plx,_enemyA* enm1 ,float speed)//handling movements for player,parallax,enemy and giving the speed.
{
    if (ply->knockedBack > 5)//if the player collides with enemies then knockedBack
    {
        if (ply->xPos > -0.3)
        {
            ply->playerTranslate(-0.03,0.0);//player is moved back by 0.03 x Pos
        }
        else
        {
            if (!plx->scroll("left",speed * 2,enm1))//parallax movement to left
            {
                ply->playerTranslate(-0.03,0.0);
            }
        }
    }
    else
    {
        if (isRight)
        {
            ply->action = 0;//selecting action value 0 for forward movement
            if (ply->xPos < -0.3)
            {
                ply->playerTranslate(0.015,0.0); //player translation
            }
            else
            {
                if (!plx->scroll("right",speed,enm1)) //parallax movement to right
                {
                    ply->playerTranslate(0.015,0.0);
                }
            }
        }
        else
        {
            if (isLeft)
            {
                ply->action = 1; //action value 1 for backward movement
                if (ply->xPos > -0.3) {
                    ply->playerTranslate(-0.015,0.0);
                }
                else
                {
                    if (!plx->scroll("left",speed,enm1))
                    {
                        ply->playerTranslate(-0.015,0.0);
                    }
                }
            }
            else
            {
                ply->action =3; //default action value 3 for staying still facing right
            }
        }
        if (isUp)
        {
            if (!isRight && !isLeft)
            {
                ply->action = 0;    //upward movement action value 0 (facing right moving up)
            }
            ply->playerTranslate(0.0, 0.015);
        }
        else
        {
            if (isDown)
            {
                if (!isRight && !isLeft)
                {
                    ply->action = 0;    //downward movement with action value 0  i.e. facing right and move down
                }
                ply->playerTranslate(0.0, -0.015);
            }
        }
    }
    return false;
}

void _inputs::isPressed()
{
    isLeft = (GetKeyState(VK_KEY_A) & 0x8000) ? true : false;
    isRight = (GetKeyState(VK_KEY_D) & 0x8000) ? true : false;
    isUp = (GetKeyState(VK_KEY_W) & 0x8000) ? true : false;
    isDown = (GetKeyState(VK_KEY_S) & 0x8000) ? true : false;
}
