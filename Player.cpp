//
// Created by amichai on 15/11/18.
//

#include <clocale>
#include <iostream>
#include <limits>
#include "Rules.h"
#include "Player.h"
#include "Board.h"

string Player::getInput(Board *board) {
    string input;
    cout << getColor() << ":" << endl;
    cin >> input;

    while (!cinGoodStatus() || !Rules::isValidInput(input, board)){
        cerr << "Invalid move; the game awaits a valid move.\n";
        cin >> input;
    }

    return input;
}

bool Player::cinGoodStatus() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

char Player::getColor() const {
    return color;
}

void Player::setColor(char color) {
    Player::color = color;
}
