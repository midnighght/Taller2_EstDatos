#ifndef ATS_H
#define ATS_H

#include <vector>
#include <limits>

// Constants for AI and player
const char HUMAN_PLAYER = 'X';
const char ATS_PLAYER = 'O';
const int MAXIMIZER_VALUE = 10;
const int MINIMIZER_VALUE = -10;

// Structure to represent a move
struct Move {
    int row;
    int col;
};

class ATS {
public:
    ATS();

    // Finds the best move for the AI
    Move findBestMove(const std::vector<std::vector<char>>& board);

private:
    // Helper functions
    int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizer);
    int evaluate(const std::vector<std::vector<char>>& board) const;
    bool isFull(const std::vector<std::vector<char>>& board) const;
};

#endif // ATS_H