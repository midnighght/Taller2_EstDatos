#include "Board.h"

// Builder
Board::Board() : grid(SIZE, std::vector<char>(SIZE, ' '))
{
}

// Imprime el tablero
void Board::print() const
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            std::cout << grid[i][j];
            if (j < SIZE - 1)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < SIZE - 1)
            std::cout << "--+---+--" << std::endl;
    }
}

// Verifica si un movimiento es válido
bool Board::isValidMovement(int m, int n) const
{
    return m >= 0 && m < SIZE && n >= 0 && n < SIZE && grid[m][n] == ' ';
}

// Realiza un movimiento
void Board::makeMove(int m, int n, char player)
{
    if (isValidMovement(m, n))
    {
        grid[m][n] = player;
    }
}

// Verifica si un jugador ha ganado
bool Board::checkWin(char player) const
{
    // Verificar filas y columnas
    for (int i = 0; i < SIZE; ++i)
    {
        if ((grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) ||
            (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player))
        {
            return true;
        }
    }
    // Verificar diagonales
    if ((grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) ||
        (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player))
    {
        return true;
    }
    return false;
}

const std::vector<std::vector<char>>& Board::getGrid() const {
    return grid;
}

// Verifica si el tablero está lleno
// bool Board::isFull() const {
//     for (int i = 0; i < SIZE; ++i) {
//         for (int j = 0; j < SIZE; ++j) {
//             if (grid[i][j] == ' ') {
//                 return false;
//             }
//         }
//     }
//     return true;
// }