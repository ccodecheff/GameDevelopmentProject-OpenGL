#ifndef _GLSCENE_H
#define _GLSCENE_H

#include <windows.h>
#include<GL/glut.h>
#include <_pages.h>

class _glScene
{
    public:
        _glScene();             //constructor
        virtual ~_glScene();    //destructor
        GLint initGL();         //initializing openGL
        GLint drawScene();      //renderer
        GLvoid reSizeScene(GLsizei, GLsizei);   //Screen size changes

        _pages *lPage = new _pages();
        _pages *mPage = new _pages();
        _pages *hPage = new _pages();
        _pages *cPage = new _pages();
        _pages *qPage = new _pages();
        _pages *goPage = new _pages();
        _pages* inPage= new _pages();


        void setMenuPage();
        void setGamePage();
        void setHelpPage();
        void setCreditPage();
        void setQuitPage();
        void setGameOverPage();
        void setIntroPage();

        bool LANDING,MENU,GAME,HELP,CREDIT,QUIT,GAMEOVER,INTRO;

        float screenHeight, screenWidth;        //to map background images
        int winMsg(HWND, UINT, WPARAM, LPARAM); //callback of inputs
        float enemySpeed = 0.001;
//int enmNum;
        float gameTime = 45.0;

        void startingLevel();
        void nextLevel();
    protected:
    private:
};

#endif // _GLSCENE_H
