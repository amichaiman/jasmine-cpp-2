//
// Created by amichai on 15/11/18.
//

#include "Rules.h"
#include "Board.h"

void Rules::initBoard(Board *board) {
    board->setPlayerAt(WHITE, 3, 3);
    board->setPlayerAt(BLACK, 3, 4);
    board->setPlayerAt(WHITE, 4, 4);
    board->setPlayerAt(BLACK, 4, 3);
    board->setBlackDiscCount(2);
    board->setWhiteDiscCount(2);
}

bool Rules::isValidInput(string input, Board *board) {
    if (input == "QUIT" || input == "PASS"){
        return true;
    }
    return isValidSpot(input) && isValidMove(board, input[0] - 'A', input[1] - '1');
}

bool Rules::isValidSpot(string input) {
    if (input.length() != 2){
        return false;
    }
    return !(!isInBoard(input[0] - 'A') || !isInBoard(input[1]-'1'));
}

bool Rules::isInBoard(int n) {
    return n >= 0 && n < 8;
}

bool Rules::isValidMove(Board *board, int x, int y) {
    int offsetX[] = {-1,-1,-1,0,0,1,1,1};
    int offsetY[] = {-1,0,1,-1,1,-1,0,1};
    const int NUMBER_OF_DIRECTIONS = 8;

    for (int k=0; k<NUMBER_OF_DIRECTIONS; k++){
        if (isValidDirection(board, x, y, offsetX[k], offsetY[k])){
            return true;
        }
    }
    return false;
}

bool Rules::isValidDirection(Board *board, int x, int y, int offsetX, int offsetY) {
    /* move on direction */
    x += offsetX;
    y += offsetY;
    /* make sure adjacent spot is other color */
    if (!isInBoard(x) || !isInBoard(y) || board->getPlayerAt(x,y) != board->getOtherPlayer()){
        return false;
    }
    /* move on direction */
    x += offsetX;
    y += offsetY;

    while (isInBoard(x) && isInBoard(y)){
        if (board->getPlayerAt(x,y) == EMPTY){
            return false;
        }
        if (board->getPlayerAt(x,y) == board->getCurrentPlayer()){
            return true;
        }
        /* move on direction */
        x += offsetX;
        y += offsetY;
    }
    return false;
}

void Rules::updateBoard(Board *board, int x, int y) {
    int offsetX[] = {-1,-1,-1,0,0,1,1,1};
    int offsetY[] = {-1,0,1,-1,1,-1,0,1};
    const int NUMBER_OF_DIRECTIONS = 8;

    for (int k=0; k<NUMBER_OF_DIRECTIONS; k++){
        if (isValidDirection(board, x, y, offsetX[k], offsetY[k])){
            flipDiscs(board, x, y, offsetX[k], offsetY[k]);
        }
    }
}

void Rules::flipDiscs(Board *board, int x, int y, int offsetX, int offsetY) {
    do {
        x += offsetX;
        y += offsetY;
        board->setPlayerAt(board->getCurrentPlayer(),x,y);
        if (board->getCurrentPlayer() == BLACK){
            board->setBlackDiscCount(board->getBlackDiscCount()+1);
            board->setWhiteDiscCount(board->getWhiteDiscCount()-1);
        } else {
            board->setBlackDiscCount(board->getBlackDiscCount()-1);
            board->setWhiteDiscCount(board->getWhiteDiscCount()+1);
        }
    } while (board->getPlayerAt(x,y) != board->getCurrentPlayer());
}

bool Rules::isBoardFull(Board *board) {
    return (board->getBlackDiscCount() + board->getWhiteDiscCount()) == (Sizes::BOARD_SIZE * Sizes::BOARD_SIZE);
}

