#include "_glScene.h"
#include <_inputs.h>
#include <_parallax.h>
#include <_player.h>
#include <_enemyA.h>
#include <_sound.h>
#include <_gClock.h>
#include <_target.h>
#include <_glLight.h>
#include <_model.h>
#include <_timer.h>
#include<_enemyB.h>

//initializing various pointer to various classes.
_inputs *KbMs = new _inputs();
_parallax *plx = new _parallax();
_gClock *Gc = new _gClock();
_player *ply = new _player();
_sound *snds = new _sound();
_timer *tim = new _timer();
_enemyA *enm1 = new _enemyA();
_enemyB *enm2 = new _enemyB();
_target *T = new _target();
_textureLoader *enmTex = new _textureLoader();
_textureLoader *EnemyTex2 = new _textureLoader();

_enemyA Enm[20];// fish enemy array
_enemyB Enm1[20];// jellyfish enemy array
bool level=false;


   int enmNum = 10;// fish starting level counter
   int enmNum1;// jelly fish counter
   int enmNum2 = 8; // fish next level counter



_glScene::_glScene()
{
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
// initialization of all GLScene bool values
    LANDING      = true;
    MENU         = false;
    GAME         = false;
    HELP         = false;
    CREDIT       = false;
    QUIT         = false;
    GAMEOVER     = false;
    INTRO        = false;
}

_glScene::~_glScene()
{
    //dtor
}
// initializer  function
GLint _glScene::initGL()
{
    tim->start();

    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f,1.6f,0.7f,0.0f);
    glClearDepth(1.0f);
    glDisable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    _glLight Light(GL_LIGHT0);



    enmTex->loadTexture("images/shark.png");// to upload fish image
    EnemyTex2->loadTexture("images/jelly.png"); // to upload jelly fish image
    T->initTarget("images/treasure.png");// image treasure box
    snds->playMusic("sounds/game.mp3");// game background music initiator




// For the game User Interface
    lPage->pageInit("images/LandingPage.png");//image landing page
    mPage->pageInit("images/MenuPage.png");//image Menu page
    hPage->pageInit("images/HelpPage.png");//image Help page
    cPage->pageInit("images/CreditPage.png");//image Credits page
    qPage->pageInit("images/QuitPage.png");//image Quit page
    goPage->pageInit("images/gameOver.png");//image Game over page
    inPage->pageInit("images/Intro1.png");//image Intro page

    //game scene
    plx->parallaxInit("images/water.png"); //parallax image of the underwater background
    ply->initPlayer("images/swimmer.png"); // player sprite image
    Gc->clockInit("images/gClock.jpg"); //clock sprite image


      startingLevel(); // initializing starting level
    if(snds->initSounds()) return true; //initializing sounds
    return true;

}

GLint _glScene::drawScene()
{
    if(tim->getTicks() > 15) // reduced the ticks from 24 to 18 for my system
    {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

    if(LANDING) //If the flag of landing page is true, draw the landing scene
    {
        glPushMatrix();
        lPage->drawPage(screenWidth, screenHeight);
        glPopMatrix();
    }
    if(INTRO) //If the flag of landing page is true, draw the Intro scene
    { glPushMatrix();
        inPage->drawPage(screenWidth, screenHeight);
        glPopMatrix();

        }

    if(MENU)//If the flag of landing page is true, draw the menu scene
    {
        glPushMatrix();
        mPage->drawPage(screenWidth, screenHeight);
        glPopMatrix();
        startingLevel();
        enmNum2=10.0; // setting up values to starting level
        enmNum1 = 0; // removing jelly fish
         tim->reset();
    }

    if(GAMEOVER)//If the flag of landing page is true, draw the game over scene
    {
        glPushMatrix();
        goPage->drawPage(screenWidth, screenHeight);
        glPopMatrix();
        enmNum2=10.0; // setting up values to starting level
        enmNum1 = 0; // removing jelly fish
         tim->reset();

    }

    if(GAME)
    {

        glPushMatrix();
        plx->drawSquare(screenWidth,screenHeight);
        glPopMatrix();



        if (Gc->timeAction())
        {
            if(Gc->timeOver == true )
                {
                    GAMEOVER = true;
                }

            else
            {
                nextLevel(); // if timer is not over and user switch found the treasure
            }


        }

        if(GAMEOVER)
        {
            glPushMatrix();
            goPage->drawPage(screenWidth, screenHeight);
            glPopMatrix();
             enmNum2=10.0; // setting up values to starting level
             enmNum1 = 0; // removing jelly fish
              tim->reset();
              startingLevel();


        }
        if(!GAMEOVER)//if the flag of landing page is not true, then
        {

            ply->drawPlayer();
            T->drawTarget();
            T->checkCollision(ply);
            KbMs->isPressed();
            if (KbMs->playerInput(ply,plx,Enm,0.004)) {
                GAME = false;
            }
            ply->actions();
            for(int i=0;i<enmNum;i++)//spawn enemies
            {   Enm[i].enemyTex = enmTex->tex;
                Enm[i].enemyInit();
                Enm[i].drawEnemy();
                Enm[i].enemyMovement(ply);
                Enm[i].checkCollision(snds,ply);
            }

            // if user is in next level it will initialize the new and difficult enemy
            if(level){
                    enmNum1= 4.0;
             for (int i = 0; i <enmNum1; i++) {

                Enm1[i].EnemyTex2 = EnemyTex2->tex;
                Enm1[i].Enemy2Init();
                Enm1[i].drawEnemy2();
                Enm1[i].enemyMovement(ply);
                Enm1[i].checkCollision(ply);
             }
             ++enmNum1;
               }
             ply->knockedBack > 0 ? ply->knockedBack -= 1 : NULL;

            Gc->drawClock();


        }
    }



    if(HELP)
    {
        glPushMatrix();
        hPage->drawPage(screenWidth,screenHeight);
        glPopMatrix();
        enmNum2=10.0; // setting up values to starting level
        enmNum1 = 0; // removing jelly fish
         tim->reset();
    }
    if(CREDIT)
    {
        glPushMatrix();
        cPage->drawPage(screenWidth,screenHeight);
        glPopMatrix();
    }
    if(QUIT)
    {
        glPushMatrix();
        qPage->drawPage(screenWidth,screenHeight );
        glPopMatrix();

        enmNum2= 10.0;; // setting up values to starting level
        enmNum1 = 0; // removing jelly fish
         tim->reset();
         startingLevel();


    }

    tim->reset();
    }
}

GLvoid _glScene::reSizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat) height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,aspectRatio,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// starting level when a New  game is started
void _glScene::startingLevel()
{

    enemySpeed = 0.006;
    gameTime = 45.0; // timer to 45 sec

    ply->xPos = -0.3;
    ply->yPos = -0.05;
    plx->xMax = 0.4;
    plx->xMin = 0.0;

    // loop to place initial enemy
    for (int i = 0; i <enmNum; i++) {
        Enm[i].placeEnemy((((rand() % 20) + 2) / 10.0),(((rand() % 8) - 4) / 10.0),-1.0);
        Enm[i].speed = enemySpeed;
        Enm[i].aiType = rand() % 12;
    }

//staring the clock
    Gc->startClock(0,(int) gameTime,((int)(gameTime * 5)) % 10);
}

// next level once the treasure is found
void _glScene::nextLevel()
{
    level = true; // bool for jelly fish

    enemySpeed = enemySpeed + 0.004;
  int  enemySpeed1 = enemySpeed1 + 0.002;
if(enmNum2>20){startingLevel();}

    ply->xPos = -0.3;
    ply->yPos = -0.05;
    plx->xMax = 0.4;
    plx->xMin = 0.0;

    enmNum1 = 4.0;

// loop to place sharks
    for (int i = 0; i<enmNum2; i++) {
        Enm[i].placeEnemy((((rand() % 20) + 2) / 10.0),(((rand() % 8) - 4) / 10.0),-1.0);
        Enm[i].speed = enemySpeed;
        Enm[i].aiType = rand() % 12;
    }

// loop to place jelly fish
    for (int i = 0; i <enmNum1; i++) {

        Enm1[i].placeEnemy2((((rand() % 10) + 2) / 10.0),(((rand() % 8) - 4) / 10.0),-1.0);
        Enm1[i].speed = enemySpeed;
        Enm1[i].aiType = rand() % 12;
    }

enmNum1++; // for jelly
enmNum2++; // for shark

    Gc->startClock(0,(int)gameTime,((int)(gameTime * 10)) % 10);
}

int _glScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

}

// display Menu page
void  _glScene::setMenuPage()
{
    LANDING  = false;
    MENU     = true;
    GAME     = false;
    HELP     = false;
    CREDIT   = false;
    QUIT     = false;
    GAMEOVER = false;
    INTRO    = false;
}
//display  game page
void  _glScene::setGamePage()
{
    LANDING  = false;
    MENU     = false;
    GAME     = true;
    HELP     = false;
    CREDIT   = false;
    QUIT     = false;
    GAMEOVER = false;
    INTRO    = false;
}
// display help page
void  _glScene::setHelpPage()
{
    LANDING  = false;
    MENU     = false;
    GAME     = false;
    HELP     = true;
    CREDIT   = false;
    QUIT     = false;
    GAMEOVER = false;
    INTRO    = false;
}
// display credit page
void  _glScene::setCreditPage()
{
    LANDING  = false;
    MENU     = false;
    GAME     = false;
    HELP     = false;
    CREDIT   = true;
    QUIT     = false;
    GAMEOVER = false;
    INTRO    = false;
}
// display quit page after pressing 'q' in game
void  _glScene::setQuitPage()
{
    LANDING  = false;
    MENU     = false;
    GAME     = false;
    HELP     = false;
    CREDIT   = false;
    QUIT     = true;
    GAMEOVER = false;
    INTRO    = false;
}
// display gameover page
void _glScene::setGameOverPage()
{
    LANDING  = false;
    MENU     = false;
    GAME     = false;
    HELP     = false;
    CREDIT   = false;
    QUIT     = false;
    GAMEOVER = true;
    INTRO    = false;

}
// display Intro page
void _glScene::setIntroPage(){

    LANDING  = false;
    MENU     = false;
    GAME     = false;
    HELP     = false;
    CREDIT   = false;
    QUIT     = false;
    GAMEOVER = false;
    INTRO    = true;

}
