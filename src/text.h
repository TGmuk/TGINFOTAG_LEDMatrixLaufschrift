//
// Created by leo on 24.01.24.
//

#ifndef TGINFOTAG_LEUCHTSCHRIFT_TEXT_H
#define TGINFOTAG_LEUCHTSCHRIFT_TEXT_H
#include "mbed.h"
#include "string.h"

struct displayText{
    const char *text = "";
    unsigned int weight = 1;
    unsigned int scrollSpeed = 0;
};
int textCount = 14;

displayText textList[] = {
        {"GDS1 % % Informatik ist das beste Profilfach der Schule %H% % % % % % ", 30},
        {"GDS1 %H% % % % % % ",28},
        {"TG %H% % % % % % ",28},
        {"Informatik ist %H% % % % % % ",28},
        {"Informatik hat die besten Lehrkr%afte % % % % % ",23},
        {"Informatik ist am besten % % % % % ",20},
        {"Nerd sein ist cool % % % % % ",15},
        {"Fast so wie GMT... % % nur besser... % % und ohne GMT% % % % % ", 10},
        {"Wir haben Kekse % % % % % ",13},
        {"Kommt auf die Seite des dark modes % % % % % ",13},
        {"Wir sind auch kreativ % % % % % ",12},
        {"Wir malen auch Punkte... % % sogar 1664 St%uck %S % % % % % ",11},
        {"%S %S %S % % % % % ",11, 10},
        {"( ._.) % % % % % ",5,5},

};



#endif //TGINFOTAG_LEUCHTSCHRIFT_TEXT_H
