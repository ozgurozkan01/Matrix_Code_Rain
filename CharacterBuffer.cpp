//
// Created by ozgur on 14/08/2023.
//
#include <iostream>
#include "Screen.h"
#include "CharacterBuffer.h"
#include "Character.h"

int CharacterBuffer::characterNumber = Screen::getWindowHeight() / Character::getFontSize();

CharacterBuffer::CharacterBuffer()
{
    timeLimit = 0.075;
    timer = 0.f;
    index = 1;

    setFirstCharacterPositionRandomly();
    additionY = 20;

    isPositionUpdatable = true;
    targetIndexToDraw = designateTargetIndexRandomly();

    charBuffer = new Character[characterNumber];
    
    for (int i = 0; i < characterNumber; ++i)
    {
        charBuffer[i].init(firstCharacterPosX, firstCharacterPosY + (additionY * (i + 1)), designateCharacterRandomly());
    }
}

void CharacterBuffer::update()
{

    // Draw characters one by one
    for (int i = 0; i < index; ++i)
    {
        if (charBuffer[i].getIsTransparencyChangeable())
        {
            charBuffer[i].update();
        }

        else
        {
            charBuffer[targetIndexToDraw - 1].drawCharacter();
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

    if (isIndexEqualToTarget() && isPositionUpdatable && charBuffer[targetIndexToDraw - 1].getTransparency() < 10)
    {
        index = 1;
        targetIndexToDraw = designateTargetIndexRandomly();
        updateNonstaticBufferProperty();
    }
}

CharacterBuffer::~CharacterBuffer()
{
    delete [] charBuffer;
}

void CharacterBuffer::updateNonstaticBufferProperty()
{
    setFirstCharacterPositionRandomly();

    for (int i = 0; i < characterNumber; ++i)
    {
        charBuffer[i].setPositionY(firstCharacterPosY + additionY * i);
        charBuffer[i].setPositionX(firstCharacterPosX);
        charBuffer[i].characters[0] = designateCharacterRandomly();
        charBuffer[i].characters[1] = '\0';
        charBuffer[i].setTransparency(0xFF);
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
    firstCharacterPosY = 0;
    firstCharacterPosX = (rand() % Screen::getMaxColumbNunber()) * Character::getFontSize();
}

int CharacterBuffer::designateTargetIndexRandomly()
{
    return (rand() % (characterNumber / 2)) + (characterNumber / 2);
}

char CharacterBuffer::designateCharacterRandomly() {
    return char((rand() % 26) + 65);
}

Character *CharacterBuffer::getBuffer() {
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
    return charBuffer[targetIndexToDraw - 2].getTransparency() < 10 &&
           !isPositionUpdatable &&
            charBuffer[targetIndexToDraw - 1].getIsTransparencyChangeable();
}

void CharacterBuffer::setStaticBufferTransparency()
{
    for (int i = 0; i < targetIndexToDraw; ++i)
    {
        charBuffer[i].setTransparency(0x00);
        charBuffer[i].setIsTransparencyChangeable(false);
    }

    charBuffer[targetIndexToDraw - 1].setTransparency(0xFF);
}