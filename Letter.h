//
// Created by ozgur on 10/08/2023.
//

#ifndef MATRIX_SCENE_LETTER_H
#define MATRIX_SCENE_LETTER_H

#include <iostream>
#include "raylib.h"

class Letter {

    int fontSize;

    Color color;
public:
    int positionX;
    int positionY;
    char letter[2];
    unsigned char transparency;

    Letter(int positionX, int positionY, char value, unsigned transparentValue);

    void drawLetter() const;
    void update();
    Color getColor();
    bool canTransparencyDecrease();
    void decreaseTransparency(float decreasing);
};


#endif //MATRIX_SCENE_LETTER_H