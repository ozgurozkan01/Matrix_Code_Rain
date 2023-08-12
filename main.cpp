#include "Screen.h"
#include <cstdlib>
#include <ctime>
#include "raylib.h"

int main()
{
    srand(time(nullptr));

    Screen screen;

    screen.update();

    return 0;

}
/*
#include "raylib.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

const int screenWidth = 800;
const int screenHeight = 600;
const int fontSize = 20;
const int numRows = screenHeight / fontSize;
const int numCols = screenWidth / fontSize;
const char symbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void DrawMatrixSymbol(const char symbol, int x, int y, Color color) {
    DrawText(&symbol, x * fontSize, y * fontSize, fontSize, color);
}

int main() {
    InitWindow(screenWidth, screenHeight, "Matrix Animation");

    SetTargetFPS(60);

    srand(time(NULL));

    char matrix[numRows][numCols];

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = symbols[rand() % (sizeof(symbols) - 1)];
        }
    }

    int colOffset[numCols];
    for (int j = 0; j < numCols; j++) {
        colOffset[j] = -(rand() % numRows);
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for (int j = 0; j < numCols; j++) {
            int offset = colOffset[j];
            for (int i = 0; i < numRows; i++) {
                Color color = GREEN;
                if (offset >= 0 && offset < 10) {
                    color = LIME;
                }
                DrawMatrixSymbol(matrix[(i + offset + numRows) % numRows][j], j, i, color);
                offset++;
            }
        }

        for (int j = 0; j < numCols; j++) {
            colOffset[j]++;
            if (colOffset[j] >= numRows) {
                colOffset[j] = -10;
            }
        }

        EndDrawing();

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 100ms bekleme süresi
    }

    CloseWindow();

    return 0;
}*/
