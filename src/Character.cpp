
#include "Character.h"
#include <iostream>
Character::Character()
{
    transparencyDecreasingSpeed = 300.f;
    transparency = 255;
    color = getColor();
    isTransparencyChangeable = true;
    green = 255;
}

void Character::init(int xCord, int yCord, char value)
{
    positionX = xCord;
    positionY = yCord;
    characters[0] = value;
    characters[1] = '\0';
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
        decreaseTransparency(GetFrameTime() * transparencyDecreasingSpeed);
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

int Character::getFontSize() {
    return fontSize;
}