//
// Created by amichai on 15/11/18.
//

#ifndef YASMIN_CPP_2_RULES_H
#define YASMIN_CPP_2_RULES_H
#include "Board.h"
#include <string>
using namespace std;

typedef enum{BLACK, WHITE, EMPTY} boardPieces;

class Rules {
public:
    static void initBoard(Board *board);
    static bool isValidInput(string input, Board *board);
    static void updateBoard(Board *board, int x, int y);
    static bool isBoardFull(Board *board);
private:
    static bool isValidSpot(string input);
    static bool isValidMove(Board *board, int x, int y);
    static bool isValidDirection(Board *board, int x, int y, int offsetX, int offsetY);
    static bool isInBoard(int n);
    static void flipDiscs(Board *board, int x, int y, int offsetX, int offsetY);
};


#endif //YASMIN_CPP_2_RULES_H
