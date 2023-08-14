
#include "Character.h"

Character::Character(int positionX, int positionY, char value, unsigned transparentValue) :
        positionX(positionX),
        positionY(positionY),
        transparency(transparentValue)
{
    fontSize = 10;
    characters[0] = value;
    characters[1] = '\0';
    transparency = transparentValue ;
    color = getColor();
    isTransparencyChangeable = true;
    green = 225;
}

void Character::drawCharacter() const
{
    DrawText(characters, positionX, positionY, fontSize, color);
}

void Character::update()
{
    color = getColor();

    drawCharacter();

    if (canTransparencyDecrease() && isTransparencyChangeable)
        decreaseTransparency(GetFrameTime() * 333);

}

Color Character::getColor() {
    return {0, green, 0, transparency};
}

bool Character::canTransparencyDecrease() {
    return transparency > 0.5;
}

void Character::decreaseTransparency(float decreasing)
{
    transparency -= decreasing;
}

void Character::setPositionX(float xCord)
{
    positionX = xCord;
}

void Character::setPositionY(float yCord)
{
    positionY = yCord;
}

void Character::setIsTransparencyChangeable(bool isChangeable)
{
    isTransparencyChangeable = isChangeable;
}

bool Character::getIsTransparencyChangeable() {
    return isTransparencyChangeable;
}

unsigned char Character::getTransparency()
{
    return transparency;
}

void Character::setTransparency(unsigned char transparencyValue)
{
    transparency = transparencyValue;
}
