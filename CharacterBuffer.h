//
// Created by ozgur on 14/08/2023.
//

#ifndef MATRIX_CODE_RAIN_CHARACTERBUFFER_H
#define MATRIX_CODE_RAIN_CHARACTERBUFFER_H

class Character;

class CharacterBuffer {

    static int characterNumber;

    Character* charBuffer;
    float timeLimit;
    float timer;

    int targetIndexToDraw;
    bool isPositionUpdatable; // Static Buffer

    int firstCharacterPosY;
    int firstCharacterPosX;
    int additionY;
    int index;

public:

    CharacterBuffer();
    ~CharacterBuffer();

    Character* getBuffer();

    // Comman
    void update();
    void setTargetIndex(int targetIndex);
    void setCanPositionUpdate(bool canUpdate);
    int getTargetIndex() const;
    bool isIndexEqualToTarget() const;
    bool canIncreaseIndex();
    static char designateCharacterRandomly();
    static int designateTargetIndexRandomly();


    // Static Buffer
    bool canUpdateStaticBuffer();
    void setStaticBufferTransparency();

    // Nonstatic Buffer
    void updateNonstaticBufferProperty();
    void setFirstCharacterPositionRandomly();

};


#endif //MATRIX_CODE_RAIN_CHARACTERBUFFER_H
