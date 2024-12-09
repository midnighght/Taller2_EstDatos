#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Board
{
private:
    std::vector<std::vector<char>> grid; // Representación del tablero
    static const int SIZE = 3;           // Tamaño del tablero (3x3)

public:
    Board(); // Constructor por defecto

    void print() const;                             // Imprime el tablero
    bool isValidMovement(int fila, int col) const;  // Verifica si un movimiento es válido
    void makeMove(int fila, int col, char jugador); // Realiza un movimiento
    bool checkWin(char jugador) const;              // Verifica si un jugador ha ganado
    const std::vector<std::vector<char>>& getGrid() const; // Retornar grid
    // bool isFull() const;                      // Verifica si el tablero está lleno
};

#endif // BOARD_H