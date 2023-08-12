#include "Screen.h"
#include "raylib.h"
#include "LetterContainer.h"
#include "Letter.h"
#include <iostream>

Screen::Screen()
{
    InitWindow(windowWidth, windowHeight, "MATRIX_SCENE");
    SetTargetFPS(60);
    letterContainers = new LetterContainer[containerNumber];

    index = 1;
    timer = 0.f;
    timeLimit = 0.25;
}

Screen::~Screen()
{
    delete [] letterContainers;
    CloseWindow();
}

void Screen::update()
{

    while(!WindowShouldClose())
    {
        ClearBackground(BLACK);

/*        for (int i = 0; i < index; ++i)
        {
            letterContainers[i].update();
        }

        if (shouldIncreaseIndexToDraw() && index != containerNumber)
        {
            index++;
        }*/

        DrawText("T", 300, 275, 20, GREEN);
        DrawText("H", 320, 275, 20, GREEN);
        DrawText("E", 340, 275, 20, GREEN);
        DrawText("M", 375, 275, 20, GREEN);
        DrawText("A", 395, 275, 20, GREEN);
        DrawText("T", 415, 275, 20, GREEN);
        DrawText("R", 435, 275, 20, GREEN);
        DrawText("I", 455, 275, 20, GREEN);
        DrawText("X", 475, 275, 20, GREEN);



        EndDrawing();
    }
}

bool Screen::shouldIncreaseIndexToDraw()
{
    if (timer >= timeLimit)
    {
        timer = 0.f;
        return true;
    }

    timer += GetFrameTime();
    return false;
}