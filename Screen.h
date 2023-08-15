//
// Created by ozgur on 14/08/2023.
//

#ifndef MATRIX_CODE_RAIN_SCREEN_H
#define MATRIX_CODE_RAIN_SCREEN_H
#include <iostream>

class CharacterBuffer;

class Screen {
    const static int windowWidth = 800;
    const static int windowHeight = 600;
    const static int characterBufferNumber = 75;

    int matrixBufferMinStart;
    int bufferIndex;
    int matrixIndex;
    float codeRainTimer;
    float codeRainTimeLimit;

    float matrixTimer;
    float matrixTimeLimit;

    bool canBufferIndexIncrease;

    CharacterBuffer* characterBuffers;
    CharacterBuffer* matrixCharacterBuffer;

    std::string theMatrix = "MHTXTIEAR";
    const static int theMatrixLength = 9;

    int theMatrixPosX[theMatrixLength] = {375, 320,  415, 475, 300, 455,340, 395, 435};

public:

    Screen();
    ~Screen();

    void update();
    bool canChangeIndex(float& timer, float& timeLimit);
    bool canDecreaseIndex();
    bool hasBufferIndexReachedMax();
    bool isBufferIndexEmpty();
};


#endif //MATRIX_CODE_RAIN_SCREEN_H
