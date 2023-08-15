//
// Created by ozgur on 13/08/2023.
//

#ifndef MATRIX_CODE_RAIN_CHARACTER_H
#define MATRIX_CODE_RAIN_CHARACTER_H

#include "raylib.h"

class Character {

    Color color;

    int positionX;
    int positionY;
    const static int fontSize = 10;

    float transparencyDecreasingSpeed;

    unsigned char green;
    unsigned char transparency;

    bool isTransparencyChangeable;

public:
    char characters[2];
    Character();

    void init(int xCord, int yCord, char value);
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
    static int getFontSize();
};


#endif //MATRIX_CODE_RAIN_CHARACTER_H
