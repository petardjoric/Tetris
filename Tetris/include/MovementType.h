#ifndef MOVEMENTTYPE_H
#define MOVEMENTTYPE_H

#include <vector>

#include "MatrixUnit.h"

class MovementType
{
    public:
        MovementType(MatrixUnit units[4]);
        virtual ~MovementType();

        virtual bool can_move() = 0;
        virtual void move()     = 0;
    protected:
        std::vector<MatrixUnit*> _units;

};

#endif // MOVEMENTTYPE_H
