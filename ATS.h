#ifndef ATS_H
#define ATS_H

#include <vector>
#include <limits>

// Constantes
const char HUMAN_PLAYER = 'X';
const char AI_PLAYER = 'O';
const int MAXIMIZER_VALUE = 10;
const int MINIMIZER_VALUE = -10;

// Etructura para representar jugada
struct Move
{
    int row, col;
};

class ATS
{
public:
    ATS();
    Move findBestMove(const std::vector<std::vector<char>> &board);

private:
    int minimax(std::vector<std::vector<char>> &board, int depth, bool isMaximizer);
    int evaluate(const std::vector<std::vector<char>> &board) const;
    bool isFull(const std::vector<std::vector<char>> &board) const;
};

#endif // ATS_H