//
// Created by amichai on 15/11/18.
//

#ifndef YASMIN_CPP_2_BOARD_H
#define YASMIN_CPP_2_BOARD_H
#include "Sizes.h"
#include "Player.h"
#include "Rules.h"

class Board {
public:
    Board();
    void play();
    void print();
    boardPieces getOtherPlayer();
    boardPieces getPlayerAt(int x, int y);
    void setPlayerAt(boardPieces piece, int x, int y);
    boardPieces getCurrentPlayer();
    int getBlackDiscCount() const;
    void setBlackDiscCount(int blackDiscCount);
    int getWhiteDiscCount() const;
    void setWhiteDiscCount(int whiteDiscCount);
private:
    boardPieces board[Sizes::BOARD_SIZE][Sizes::BOARD_SIZE];
    Player players[Sizes::NUMBER_OF_PLAYERS];
    boardPieces currentPlayer;
    int blackDiscCount;
    int whiteDiscCount;
    inline void printWinningStatement(boardPieces player);
    void putDisc(int x, int y);
};


#endif //YASMIN_CPP_2_BOARD_H
