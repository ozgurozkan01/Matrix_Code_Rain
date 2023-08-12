#include "LetterContainer.h"
#include "Letter.h"
#include <iostream>

LetterContainer::LetterContainer()
{
    timeLimit = 0.075;
    timer = 0.f;
    index = 1;
    int firstLetterPosY = (rand() % 11) * 15;
    int firstLetterPosX = (rand() % 41) * 20;
    int additionY = 20;
    targetIndex = designateTargetIndexRandomly();

    unsigned char transparencyValue = (rand() % 101) + 75;

    for (auto & letter : letterBuffer)
    {
        letter = new Letter(firstLetterPosX, firstLetterPosY + additionY, designateLetterRandomly(), transparencyValue);
        additionY += 20;
    }
}

void LetterContainer::update()
{
    for (int i = 0; i < index; ++i)
    {
        letterBuffer[i]->update();
    }

    if (canIncreaseIndex())
    {
        index++;
    }

    if (index == targetIndex)
    {
        index = 1;
        targetIndex = designateTargetIndexRandomly();
        positionUpdate();
    }
}

LetterContainer::~LetterContainer()
{
    for (auto letter : letterBuffer)
    {
        delete letter;
    }
}

void LetterContainer::positionUpdate()
{
    int firstLetterPosY = (rand() % 11) * 15;
    int firstLetterPosX = (rand() % 41) * 20;
    int additionY = 0;
    for (auto & letter : letterBuffer)
    {
        letter->positionY = firstLetterPosY + additionY;
        letter->positionX = firstLetterPosX;
        letter->letter[0] = designateLetterRandomly();
        letter->letter[1] = '\0';
        letter->transparency = 255;
        additionY += 20;
    }
}


bool LetterContainer::canIncreaseIndex() {

    if (timer >= timeLimit)
    {
        timer = 0.f;
        return true;
    }

    timer += GetFrameTime();
    return false;
}

int LetterContainer::designateTargetIndexRandomly()
{
    return (rand() % 26) + 25;
}

char LetterContainer::designateLetterRandomly() {
    return char((rand() % 26) + 65);
}


