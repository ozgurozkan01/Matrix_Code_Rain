//
// Created by ozgur on 14/08/2023.
//

#include "Screen.h"
#include "raylib.h"
#include "CharacterBuffer.h"
#include "Character.h"
#include <iostream>

Screen::Screen()
{
    InitWindow(windowWidth, windowHeight, "Matrix_Code_Rain");
    SetTargetFPS(60);
    characterBuffers = new CharacterBuffer[characterBufferNumber];
    matrixCharacterBuffer = new CharacterBuffer[theMatrixLength];

    for (int i = 0; i < theMatrixLength; ++i)
    {
        matrixCharacterBuffer[i].setTargetIndex(12);
        matrixCharacterBuffer[i].setCanPositionUpdate(false);
        matrixCharacterBuffer[i].getBuffer()[matrixCharacterBuffer[i].getTargetIndex() - 1]->characters[0] = theMatrix[i];

        for (int j = 0; j < 12; ++j)
        {
            matrixCharacterBuffer[i].getBuffer()[j]->setPositionX(theMatrixPosX[i]);
            matrixCharacterBuffer[i].getBuffer()[j]->setPositionY(0 + (25 * j));
        }
    }

    bufferIndex = 1;
    matrixIndex = 1;
    codeRainTimer = 0;
    codeRainTimeLimit = 0.3;
    matrixTimer = 0;
    matrixTimeLimit = 0.55;
    matrixBufferMinStart = 17;
}

Screen::~Screen()
{
    delete [] characterBuffers;
    CloseWindow();
}

void Screen::update()
{

    while(!WindowShouldClose())
    {
        ClearBackground(BLACK);

        // Draw all letter in the letterBuffer
        for (int i = 0; i < bufferIndex; ++i)
        {
            characterBuffers[i].update();
        }

        // Draw "The Matrix" on the screen
        if (canDecreaseIndex() && bufferIndex <= matrixBufferMinStart)
        {
            for (int i = 0; i < matrixIndex; ++i)
            {
                matrixCharacterBuffer[i].update();
            }

            if (canChangeIndex(matrixTimer, matrixTimeLimit) && matrixIndex != 9)
            {
                matrixIndex++;
            }
        }

        if (canChangeIndex(codeRainTimer, codeRainTimeLimit) && bufferIndex != characterBufferNumber && !canDecreaseIndex())
        {
            bufferIndex++;
        }

        else if (canChangeIndex(codeRainTimer, codeRainTimeLimit) && bufferIndex != 0 && canDecreaseIndex())
        {
            bufferIndex--;
        }


        EndDrawing();
    }
}

bool Screen::canChangeIndex(float& timer, float& timeLimit)
{
    if (timer >= timeLimit)
    {
        timer = 0.f;
        return true;
    }

    timer += GetFrameTime();
    return false;
}

bool Screen::canDecreaseIndex()
{
    return GetTime() > 20.f;
}