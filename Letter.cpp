
#include "Letter.h"

Letter::Letter(int positionX, int positionY, char value, unsigned transparentValue) :
    positionX(positionX),
    positionY(positionY),
    transparency(transparentValue)
{
    fontSize = 10;
    letter[0] = value;
    letter[1] = '\0';
    transparency = transparentValue ;
    color = getColor();
}

void Letter::drawLetter() const
{
    DrawText(letter, positionX, positionY, fontSize, color);
}

void Letter::update()
{
    color = getColor();

    drawLetter();

    if (canTransparencyDecrease())
        decreaseTransparency(GetFrameTime() * 333);

}

Color Letter::getColor() {
    return {0, 175, 0, transparency};
}

bool Letter::canTransparencyDecrease() {
    return transparency > 0.5;
}

void Letter::decreaseTransparency(float decreasing)
{
    transparency -= decreasing;
}
