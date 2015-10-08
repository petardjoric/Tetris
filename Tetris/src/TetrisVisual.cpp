#include "TetrisVisual.h"

TetrisVisual::TetrisVisual()
{
    //ctor
}

void TetrisVisual::addUnit(UnitVisual& unit)
{
    units.push_back(unit);
}

void TetrisVisual::draw()
{
    glColor3f(1, 1, 1);
    for(int i=0; i<10; i++)
    {
        glBegin(GL_LINE);
            glVertex2f(-i*.1, 0);
            glVertex2f(i*.1, 0);
        glEnd();

        glBegin(GL_LINE);
            glVertex2f(0, -i*.1);
            glVertex2f(0, i*.1);
        glEnd();
    }

    for( auto &unit : units )
        unit.drawUnit();
}

TetrisVisual::~TetrisVisual()
{
    //dtor
}
