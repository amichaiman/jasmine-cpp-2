//
// Created by amichai on 15/11/18.
//

#include "Board.h"
#include "Rules.h"
#include <iostream>
using namespace std;

void Board::play() {
    string input;
    bool passFlag = false;

    while (!Rules::isBoardFull(this)) {
        print();
        input = players[currentPlayer].getInput(this);
        if (input == "QUIT") {
            printWinningStatement(getOtherPlayer());
            return;
        }
        if (input == "PASS") {
            if (passFlag){
                printWinningStatement(blackDiscCount > whiteDiscCount ? BLACK : WHITE);
                return;
            }
            passFlag = true;
        } else {
            putDisc(input[0]-'A', input[1]-'1');
        }
        currentPlayer = getOtherPlayer();
    }
    printWinningStatement(blackDiscCount > whiteDiscCount ? BLACK : WHITE);
}

void Board::print() {
    for (int i=0; i<Sizes::BOARD_SIZE; i++){
        for (int j=0; j<Sizes::BOARD_SIZE; j++){
            cout << players[currentPlayer].getColor() << ' ';
        }
        cout << endl;
    }
}

Board::Board() {
    for (int i=0; i<Sizes::BOARD_SIZE; i++){
        for (int j=0; j<Sizes::BOARD_SIZE; j++){
            board[i][j] = EMPTY;
        }
    }
    Rules::initBoard(this);
    currentPlayer = BLACK;
    players[BLACK].setColor('B');
    players[WHITE].setColor('W');
    blackDiscCount = 0;
    whiteDiscCount = 0;
}

boardPieces Board::getOtherPlayer() {
    return currentPlayer == BLACK ? WHITE : BLACK;
}

inline void Board::printWinningStatement(boardPieces player) {
    cout << (player == BLACK ? "B" : "W") <<"wins the game" << endl;

}

boardPieces Board::getPlayerAt(int x, int y) {
    return board[x][y];
}

void Board::setPlayerAt(boardPieces piece, int x, int y) {
    board[x][y] = piece;
}

boardPieces Board::getCurrentPlayer() {
    return currentPlayer;
}

void Board::putDisc(int x, int y) {
    setPlayerAt(getCurrentPlayer(), x, y);
    if (getCurrentPlayer() == BLACK) {
        blackDiscCount++;
    } else {
        whiteDiscCount++;
    }
    Rules::updateBoard(this,x,y);
}

int Board::getBlackDiscCount() const {
    return blackDiscCount;
}

void Board::setBlackDiscCount(int blackDiscCount) {
    Board::blackDiscCount = blackDiscCount;
}

int Board::getWhiteDiscCount() const {
    return whiteDiscCount;
}

void Board::setWhiteDiscCount(int whiteDiscCount) {
    Board::whiteDiscCount = whiteDiscCount;
}
