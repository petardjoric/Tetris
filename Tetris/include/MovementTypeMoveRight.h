#ifndef MOVEMENTTYPEMOVERIGHT_H
#define MOVEMENTTYPEMOVERIGHT_H

#include <vector>

#include "MovementType.h"

class MovementTypeMoveRight : public MovementType
{
    public:
        MovementTypeMoveRight(MatrixUnit units[4]);
        virtual ~MovementTypeMoveRight();

        // inherited from interface MovementType
        bool can_move();
        void move();
};

#endif // MOVEMENTTYPEMOVERIGHT_H
