#ifndef MATRIXFIGUREMOVEFACADE_H
#define MATRIXFIGUREMOVEFACADE_H

#include <vector>

#include "MatrixUnit.h"
#include "MovementType.h"

class MatrixFigureMoveFacade
{
    public:
        MatrixFigureMoveFacade(MatrixUnit units[4], MovementType & moveType);
        virtual ~MatrixFigureMoveFacade();

        bool canMove() { return _canMove; }
    private:
        std::vector<MatrixUnit*> _units;
        MovementType* movementType;
        bool _canMove;
};

#endif // MATRIXFIGUREMOVEFACADE_H
