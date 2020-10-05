#ifndef _PLAYER_H
#define _PLAYER_H

#include <GL/gl.h>
#include <_textureLoader.h>
#include <_timer.h>

typedef struct
{
    float x;
    float y;
    float z;
}vec3;

class _player
{
    public:
        _player();
        virtual ~_player();

        //float scale[3]={1.0,1.0,1.0};
        vec3 verticies[4];  //boundary for player

        float xPos;   //x position of the Player
        float yPos;   //y position of the Player
        float zPos;   //z position of the Player

        float xSize;
        float ySize;

        float xRotation;
        float yRotation;
        float zRotation;

        void drawPlayer();
        void playerTranslate(float, float);
        void actions();     //may have to pass different values
        void initPlayer(char *);

        _textureLoader *T = new _textureLoader();
        _timer *tmr = new _timer();

       int lives=3.0;

        int action,knockedBack; //give values for forwards,backward,up and down actions.
        float frames;       //select the number of frames from the sprite sheet
        float xMax,xMin,yMax,yMin;  //the min and max values of the coordinates selection from the sprite sheet

    protected:
    private:
};

#endif // _PLAYER_H
