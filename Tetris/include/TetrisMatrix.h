#ifndef TETRISMATRIX_H
#define TETRISMATRIX_H

#include <iostream>

#define MATRIX_SIZE 10

class TetrisMatrix
{
    public:
        TetrisMatrix();
        virtual ~TetrisMatrix();

        void printMatrix();
    private:
        bool matrix[MATRIX_SIZE][MATRIX_SIZE];

    friend class MatrixUnit;
};

#endif // TETRISMATRIX_H