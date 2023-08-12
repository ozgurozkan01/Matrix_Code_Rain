#ifndef MATRIX_SCENE_SCREEN_H
#define MATRIX_SCENE_SCREEN_H

class LetterContainer;
class Letter;

class Screen {

public:

    const static int windowWidth = 800;
    const static int windowHeight = 600;
    const static int containerNumber = 50;

    int index;
    float timer;
    float timeLimit;

    const static int theMatrixLength = 9;

    LetterContainer* letterContainers;
    Letter* theMatrixContainer[theMatrixLength];

    Screen();
    ~Screen();

    void update();
    bool shouldIncreaseIndexToDraw();
};


#endif //MATRIX_SCENE_SCREEN_H
