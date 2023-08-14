//
// Created by ozgur on 14/08/2023.
//

#include "CharacterBuffer.h"
#include "Character.h"

CharacterBuffer::CharacterBuffer()
{
    timeLimit = 0.075;
    timer = 0.f;
    index = 1;

    setFirstCharacterPositionRandomly();
    additionY = 20;

    isPositionUpdatable = true;
    targetIndexToDraw = designateTargetIndexRandomly();

    unsigned char transparencyValue = (rand() % 101) + 75;


    for (int i = 0; i < characterNumber; ++i)
    {
        charBuffer[i] = new Character(firstCharacterPosX, firstCharacterPosY + (additionY * (i + 1)), designateCharacterRandomly(), transparencyValue);
    }
}

void CharacterBuffer::update()
{

    // Draw characters one by one
    for (int i = 0; i < index; ++i)
    {
        if (charBuffer[i]->getIsTransparencyChangeable())
        {
            charBuffer[i]->update();
        }

        else
        {
            charBuffer[targetIndexToDraw - 1]->drawCharacter();
        }
    }


    if (canIncreaseIndex() && !isIndexEqualToTarget())
    {
        index++;
    }

    if (canUpdateStaticBuffer())
    {
        setStaticBufferTransparency();
    }

    if (isIndexEqualToTarget() && isPositionUpdatable && charBuffer[targetIndexToDraw - 1]->getTransparency() < 10)
    {
        index = 1;
        targetIndexToDraw = designateTargetIndexRandomly();
        updateNonstaticBufferProperty();
    }
}

CharacterBuffer::~CharacterBuffer()
{
    for (auto letter : charBuffer)
    {
        delete letter;
    }
}

void CharacterBuffer::updateNonstaticBufferProperty()
{
    setFirstCharacterPositionRandomly();

    for (int i = 0; i < characterNumber; ++i)
    {
        charBuffer[i]->setPositionY(firstCharacterPosY + additionY * i);
        charBuffer[i]->setPositionX(firstCharacterPosX);
        charBuffer[i]->characters[0] = designateCharacterRandomly();
        charBuffer[i]->characters[1] = '\0';
        charBuffer[i]->setTransparency(0xFF);
    }
}

bool CharacterBuffer::canIncreaseIndex() {

    if (timer >= timeLimit)
    {
        timer = 0.f;
        return true;
    }

    timer += GetFrameTime();
    return false;
}

void CharacterBuffer::setFirstCharacterPositionRandomly()
{
    firstCharacterPosY = (rand() % 31) * 15;
    firstCharacterPosX = (rand() % 41) * 20;
}

int CharacterBuffer::designateTargetIndexRandomly()
{
    return (rand() % 13) + 8;
}

char CharacterBuffer::designateCharacterRandomly() {
    return char((rand() % 26) + 65);
}

Character **CharacterBuffer::getBuffer() {
    return charBuffer;
}

void CharacterBuffer::setTargetIndex(int targetIndex)
{
    targetIndexToDraw = targetIndex;
}

int CharacterBuffer::getTargetIndex() const {
    return targetIndexToDraw;
}

bool CharacterBuffer::isIndexEqualToTarget() const {
    return index == targetIndexToDraw;
}

void CharacterBuffer::setCanPositionUpdate(bool canUpdate)
{
    isPositionUpdatable = canUpdate;
}

bool CharacterBuffer::canUpdateStaticBuffer()
{
    return charBuffer[targetIndexToDraw - 2]->getTransparency() < 10 &&
           !isPositionUpdatable &&
            charBuffer[targetIndexToDraw - 1]->getIsTransparencyChangeable();
}

void CharacterBuffer::setStaticBufferTransparency()
{
    for (int i = 0; i < targetIndexToDraw; ++i)
    {
        charBuffer[i]->setTransparency(0x00);
        charBuffer[i]->setIsTransparencyChangeable(false);
    }

    charBuffer[targetIndexToDraw - 1]->setTransparency(0xFF);
}