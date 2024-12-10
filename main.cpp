#include <iostream>
#include <vector>
#include <cstdlib>
#include "ATS.h"
#include "ATOS.h"
#include "Board.h"

using namespace std;

void play()
{
    Board board;
    char player = 'X';
    int turn = 0;

    while (true)
    {
        board.print();
        cout << "Turno del jugador " << player << endl;
        cout << "Ingrese fila y columna (separados por un espacio): ";
        int row, col;
        cin >> row >> col;
        row--;
        col--;

        if (board.isValidMovement(row, col))
        {
            board.makeMove(row, col, player);
            turn++;

            if (board.checkWin(player))
            {
                board.print();
                cout << "Gana jugador " << player << "!\n";
                break;
            }
            else if (turn == 9)
            {
                board.print();
                cout << "Es un empate!\n";
                break;
            }

            // Cambiar turno
            player = (player == 'X') ? 'O' : 'X'; // cambiar entre jugador X y O
        }
        else
        {
            cout << "Movimiento invalido. Intente nuevamente.\n";
        }
    }
}

// Función marcador de posición para jugar contra IA sin optimizar
void playATOS()
{
    Board board;
    ATOS ai;

    char player = HUMAN_PLAYER;
    int turn = 0;

    while (true) {
        board.print();

        if (player == HUMAN_PLAYER) {
            cout << "Tu turno" << endl;
            cout << "Ingrese fila y columna (separados por un espacio): ";
            int row, col;
            cin >> row >> col;
            row--;
            col--;

            if (board.isValidMovement(row, col)) {
                board.makeMove(row, col, player);
                turn++;
                if (board.checkWin(player)) {
                    board.print();
                    cout << "Ganaste!\n";
                    break;
                }
                player = AI_PLAYER;
            } else {
                cout << "Movimiento invalido. Intente de nuevo.\n";
            }
        } else {
            cout << "Turno de ATOS...\n";
            Move bestMove = ai.findBestMove(board.getGrid());
            board.makeMove(bestMove.row, bestMove.col, player);
            turn++;

            if (board.checkWin(player)) {
                board.print();
                cout << "Perdiste!\n";
                break;
            }
            player = HUMAN_PLAYER;
        }

        if (turn == 9) {
            board.print();
            cout << "Es un empate!\n";
            break;
        }
    }
}

// Función marcador de posición para jugar contra IA optimizada
void playATS() {
    Board board;
    ATS ai;

    char player = HUMAN_PLAYER;
    int turn = 0;

    while (true) {
        board.print();

        if (player == HUMAN_PLAYER) {
            cout << "Tu turno" << endl;
            cout << "Ingrese fila y columna (separados por un espacio): ";
            int row, col;
            cin >> row >> col;
            row--;
            col--;

            if (board.isValidMovement(row, col)) {
                board.makeMove(row, col, player);
                turn++;
                if (board.checkWin(player)) {
                    board.print();
                    cout << "Ganaste!\n";
                    break;
                }
                player = AI_PLAYER;
            } else {
                cout << "Movimiento invalido. Intente de nuevo.\n";
            }
        } else {
            cout << "Turno de ATS...\n";
            Move bestMove = ai.findBestMove(board.getGrid());
            board.makeMove(bestMove.row, bestMove.col, player);
            turn++;

            if (board.checkWin(player)) {
                board.print();
                cout << "Perdiste!\n";
                break;
            }
            player = HUMAN_PLAYER;
        }

        if (turn == 9) {
            board.print();
            cout << "Es un empate!\n";
            break;
        }
    }
}

// Función para mostrar el menú
void mostrarMenu()
{
    cout << "\n=== Menu ===\n";
    cout << "1. Jugar entre dos jugadores\n";
    cout << "2. Jugar contra ATOS\n";
    cout << "3. Jugar contra ATS (no optimizado)\n";
    cout << "0. Salir\n";
    cout << "Elige una opcion: ";
}

int main()
{
    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            play();
            break;
        case 2:
            playATOS();
            break;
        case 3:
            playATS();
            break;
        case 0:
            cout << "Gracias por jugar!\n";
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente.\n";
        }
    } while (opcion != 0);

    return 0;
}