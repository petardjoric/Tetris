#ifndef UNITVISUAL_H
#define UNITVISUAL_H

#include <GL/gl.h>
#include <GL/glut.h>

class UnitVisual
{
    public:
        UnitVisual() {} ;
        UnitVisual(float color[3]);
        virtual ~UnitVisual();

        void setCoordinates(float x, float y);
        void drawUnit();
    private:
        float _x;
        float _y;

        float _color[3];
};

#endif // UNITVISUAL_H
