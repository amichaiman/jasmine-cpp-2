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
    Rules::boardPieces getOtherPlayer();
    Rules::boardPieces getPlayerAt(int x, int y);
    void setPlayerAt(Rules::boardPieces piece, int x, int y);
    Rules::boardPieces getCurrentPlayer();
    int getBlackDiscCount() const;
    void setBlackDiscCount(int blackDiscCount);
    int getWhiteDiscCount() const;
    void setWhiteDiscCount(int whiteDiscCount);
private:
    Rules::boardPieces board[Sizes::BOARD_SIZE][Sizes::BOARD_SIZE];
    Player players[Sizes::NUMBER_OF_PLAYERS];
    Rules::boardPieces currentPlayer;
    int blackDiscCount;
    int whiteDiscCount;
    inline void printWinningStatement(Rules::boardPieces player);
    void putDisc(int x, int y);
};


#endif //YASMIN_CPP_2_BOARD_H
