//
// Created by amichai on 15/11/18.
//

#ifndef YASMIN_CPP_2_PLAYER_H
#define YASMIN_CPP_2_PLAYER_H
#include <string>
using namespace std;
class Board;

using namespace std;
class Player {
public:
    string getInput(Board *board);
    bool cinGoodStatus();
    void setColor(char color);
    char getColor() const;

private:
    char color;

};


#endif //YASMIN_CPP_2_PLAYER_H
