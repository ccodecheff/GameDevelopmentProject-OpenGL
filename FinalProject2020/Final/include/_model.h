#ifndef _MODEL_H
#define _MODEL_H

#include<windows.h>
#include<GL/glut.h>

class _model
{
    public:
        _model();
        virtual ~_model();
        void drawModel();
        void modelInit(char*);

        double rotateX;
        double rotateY;
        double rotateZ;

        double posZ;
        double posX;
        double posY;

    protected:

    private:
};

#endif // _MODEL_H
