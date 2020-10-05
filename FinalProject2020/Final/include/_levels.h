#ifndef _LEVELS_H
#define _LEVELS_H
#include <_glScene.h>


class _levels
{
    public:
        _levels();
        virtual ~_levels();

        int levelCount;
        void levelParam(int);
        _glScene * glS = new _glScene();

    protected:
    private:
};

#endif // _LEVELS_H
