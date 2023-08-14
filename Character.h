//
// Created by ozgur on 13/08/2023.
//

#ifndef MATRIX_CODE_RAIN_CHARACTER_H
#define MATRIX_CODE_RAIN_CHARACTER_H

#include "raylib.h"

class Character {

    int fontSize;

    Color color;
    int positionX;
    int positionY;
    unsigned char green;
    bool isTransparencyChangeable;
    unsigned char transparency;

public:
    char characters[2];
    Character(int positionX, int positionY, char value, unsigned transparentValue);

    void update();
    void drawCharacter() const;
    void decreaseTransparency(float decreasing);
    void setPositionX(float xCord);
    void setPositionY(float yCord);
    void setIsTransparencyChangeable(bool isChangeable);
    void setTransparency(unsigned char transparencyValue);

    Color getColor();
    bool canTransparencyDecrease();
    bool getIsTransparencyChangeable();
    unsigned char getTransparency();
};


#endif //MATRIX_CODE_RAIN_CHARACTER_H
