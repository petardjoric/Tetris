#include "UnitVisual.h"

UnitVisual::UnitVisual(float color[3])
{
    _color[0] = color[0];
    _color[1] = color[1];
    _color[2] = color[2];
}

void UnitVisual::drawUnit()
{
    glColor3fv(_color);

    glPushMatrix();
        glTranslatef(_x, _y, 0);
            glutSolidCube(.1);
        glTranslatef(-_x, -_y, 0);
    glPopMatrix();
}

void UnitVisual::setCoordinates(float x, float y)
{
    _x = x;
    _y = y;
}

UnitVisual::~UnitVisual()
{
    //dtor
}
