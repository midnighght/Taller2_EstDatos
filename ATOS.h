#ifndef ATOS_H
#define ATOS_H

#include <vector>
#include <limits>
#include "ATS.h" //para constantes y estrcutura move

// Constantes
// const char HUMAN_PLAYER = 'X';
// const char AI_PLAYER = 'O';
// const int MAXIMIZER_VALUE = 10;
// const int MINIMIZER_VALUE = -10;

// Etructura para representar jugada
// struct Move
// {
//     int row, col;
// };

class ATOS
{
public:
    ATOS();
    Move findBestMove(const std::vector<std::vector<char>> &board);

private:
    int evaluate(const std::vector<std::vector<char>>& board) const;
    bool isFull(const std::vector<std::vector<char>>& board) const;
    int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizer, int alpha, int beta);
};

#endif // ATOS_H
