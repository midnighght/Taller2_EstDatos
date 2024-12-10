#include "ATS.h"

ATS::ATS() {}

// Evaluar si se ha ganado
int ATS::evaluate(const std::vector<std::vector<char>> &board) const
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == AI_PLAYER)
                return MAXIMIZER_VALUE;
            if (board[i][0] == HUMAN_PLAYER)
                return MINIMIZER_VALUE;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if (board[0][i] == AI_PLAYER)
                return MAXIMIZER_VALUE;
            if (board[0][i] == HUMAN_PLAYER)
                return MINIMIZER_VALUE;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == AI_PLAYER)
            return MAXIMIZER_VALUE;
        if (board[0][0] == HUMAN_PLAYER)
            return MINIMIZER_VALUE;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == AI_PLAYER)
            return MAXIMIZER_VALUE;
        if (board[0][2] == HUMAN_PLAYER)
            return MINIMIZER_VALUE;
    }

    return 0;
}

// Revisar si el tablero esta lleno
bool ATS::isFull(const std::vector<std::vector<char>> &board) const
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
                return true;
        }
    }
    return false;
}

// Minimax algorithm
int ATS::minimax(std::vector<std::vector<char>> &board, int depth, bool isMaximizer)
{
    int score = evaluate(board);

    // Terminal states
    if (score == MAXIMIZER_VALUE)
        return score - depth;
    if (score == MINIMIZER_VALUE)
        return score + depth;
    if (!isFull(board))
        return 0;

    if (isMaximizer)
    {
        int best = std::numeric_limits<int>::min();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = AI_PLAYER;
                    best = std::max(best, minimax(board, depth + 1, false));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
    else
    {
        int best = std::numeric_limits<int>::max();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = HUMAN_PLAYER;
                    best = std::min(best, minimax(board, depth + 1, true));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

// Mejor movimiento
Move ATS::findBestMove(const std::vector<std::vector<char>> &board)
{
    int bestValue = std::numeric_limits<int>::min();
    Move bestMove = {-1, -1};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                std::vector<std::vector<char>> tempBoard = board;
                tempBoard[i][j] = AI_PLAYER;

                int moveValue = minimax(tempBoard, 0, false);

                if (moveValue > bestValue)
                {
                    bestValue = moveValue;
                    bestMove = {i, j};
                }
            }
        }
    }

    return bestMove;
}
