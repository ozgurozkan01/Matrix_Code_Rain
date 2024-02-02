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
    static int characterBufferNumber;

    static int maxColumnNumber;

    int matrixBufferMinStart;
    int bufferIndex;
    static int matrixIndex;
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
    static int getMaxColumbNunber();
    bool canChangeIndex(float& timer, float& timeLimit);
    static int getWindowHeight();
    bool hasBufferIndexReachedMax() const;
    bool isBufferIndexMin() const;
};


#endif //MATRIX_CODE_RAIN_SCREEN_H
