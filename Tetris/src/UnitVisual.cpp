#include "UnitVisual.h"

UnitVisual::UnitVisual(float color[3])
    : _color{color[0], color[1], color[2]}
{

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
