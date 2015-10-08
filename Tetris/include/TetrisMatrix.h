#ifndef TETRISMATRIX_H
#define TETRISMATRIX_H

#include <iostream>

#define MATRIX_SIZE 10

class TetrisMatrix
{
    public:
        TetrisMatrix();
        virtual ~TetrisMatrix();

        enum FigureEnum { FIGURE_T, FIGURE_CUBE };

        void printMatrix();
    private:
        bool matrix[MATRIX_SIZE][MATRIX_SIZE];

    // units have direct access for matrix modification
    friend class MatrixUnit;
};

#endif // TETRISMATRIX_H
