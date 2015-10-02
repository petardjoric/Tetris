#include "TetrisMatrix.h"

TetrisMatrix::TetrisMatrix()
{

}

void TetrisMatrix::printMatrix()
{
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int j=0; j<MATRIX_SIZE; j++){
            char c = matrix[i][j] ? '1' : '0';
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "-------------------" << std::endl;
}

TetrisMatrix::~TetrisMatrix()
{

}
