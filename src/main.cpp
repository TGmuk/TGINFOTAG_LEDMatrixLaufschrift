#include "mbed.h"
#include "DOTMATRIX.h"
#include "text.h"
#include <random>

#define SCROLL_SPEED 50

unsigned int scrollSpeed = SCROLL_SPEED; // Speed of scrolling
const unsigned int displays = 26; // Number of 8x8 displays
unsigned int displayBrightness = 5; // 0-15
bool reverseDisplay = false;
//END OF CONFIG


bool changeTextFlag = false;

InterruptIn button(BUTTON1);
DOTMATRIX matrix(PB_13, PB_15, PC_1, displays, reverseDisplay);

displayText *getRandomElement(displayText *list) {

    unsigned int totalWeight = 0;
    for (int i = 0; i < textCount; i++) {
        totalWeight += list[i].weight;
    }

    unsigned int randomValue = rand() % totalWeight;


    unsigned int cumulativeWeight = 0;
    for (int i = 0; i < textCount; i++) {
        cumulativeWeight += list[i].weight;
        if (randomValue < cumulativeWeight) {
            return &list[i];
        }
    }
    return nullptr;


}


void setChangedTextFlag() {
    changeTextFlag = true;
}

void changeText(int index = -1) {
    displayText *newText;

    if (index == -1) {
        newText = getRandomElement(textList);
    } else {
        newText = &textList[index];
    }


    if (newText->scrollSpeed != 0) {
        scrollSpeed = newText->scrollSpeed;
    } else {
        scrollSpeed = SCROLL_SPEED;
    }
    matrix.resetDisplay();
    matrix.clearIDArray();
    matrix.createIDArray(newText->text);
    changeTextFlag = false;

}


int main() {
    button.mode(PullDown);
    button.rise(setChangedTextFlag);
    changeText();


    matrix.initDisplays();
    matrix.setIntensity(-1, displayBrightness);

    while (true) {
        if(matrix.update()){
            changeText();
        }
        if (changeTextFlag) {
            changeText(12);
        }
        thread_sleep_for(scrollSpeed);
    }

    return 1;


}
