//
// Created by ozgur on 10/08/2023.
//

#ifndef MATRIX_SCENE_LETTERCONTAINER_H
#define MATRIX_SCENE_LETTERCONTAINER_H

class Letter;

class LetterContainer {

    const static int letterNumber = 60;

    Letter* letterBuffer[letterNumber];

    float timeLimit;
    float timer;

    int index;
    int targetIndex;
public:

    LetterContainer();
    ~LetterContainer();

    void update();
    void positionUpdate();
    bool canIncreaseIndex();
    int designateTargetIndexRandomly();
    char designateLetterRandomly();
};


#endif //MATRIX_SCENE_LETTERCONTAINER_H
