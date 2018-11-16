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
            cout << players[currentPlayer].getColor() << ": " << input << endl;
            printWinningStatement(getOtherPlayer());
            return;
        }
        if (input == "PASS") {
            if (passFlag){
                printWinningStatement(blackDiscCount > whiteDiscCount ? Rules::BLACK : Rules::WHITE);
                return;
            }
            passFlag = true;
        } else {
            putDisc(input[1]-'1', input[0]-'A');
        }
        currentPlayer = getOtherPlayer();
    }
    printWinningStatement(blackDiscCount > whiteDiscCount ? Rules::BLACK : Rules::WHITE);
}

void Board::print() {
    for (int i=0; i<Sizes::BOARD_SIZE; i++){
        for (int j=0; j<Sizes::BOARD_SIZE; j++){
            cout << (board[i][j] == Rules::EMPTY ? "O" : board[i][j] == Rules::BLACK ? "B" : "W") << (j == Sizes::BOARD_SIZE-1 ? "" : " ");
        }
        cout << endl;
    }
}

Board::Board() {
    for (int i=0; i<Sizes::BOARD_SIZE; i++){
        for (int j=0; j<Sizes::BOARD_SIZE; j++){
            board[i][j] = Rules::EMPTY;
        }
    }
    Rules::initBoard(this);
    currentPlayer = Rules::BLACK;
    players[Rules::BLACK].setColor('B');
    players[Rules::WHITE].setColor('W');
    blackDiscCount = 0;
    whiteDiscCount = 0;
}

Rules::boardPieces Board::getOtherPlayer() {
    return currentPlayer == Rules::BLACK ? Rules::WHITE : Rules::BLACK;
}

inline void Board::printWinningStatement(Rules::boardPieces player) {
    cout << (player == Rules::BLACK ? "B" : "W") <<" wins the game." << endl;

}

Rules::boardPieces Board::getPlayerAt(int x, int y) {
    return board[x][y];
}

void Board::setPlayerAt(Rules::boardPieces piece, int x, int y) {
    board[x][y] = piece;
}

Rules::boardPieces Board::getCurrentPlayer() {
    return currentPlayer;
}

void Board::putDisc(int x, int y) {
    setPlayerAt(getCurrentPlayer(), x, y);
    if (getCurrentPlayer() == Rules::BLACK) {
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
