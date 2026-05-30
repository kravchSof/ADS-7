// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    head = nullptr;
    operationCounter = 0;
}

void Train::addCar(bool isLightOn) {
    Car* newCarriage = new Car;

    newCarriage->light = isLightOn;
    newCarriage->next = nullptr;
    newCarriage->prev = nullptr;

    if (head == nullptr) {
        head = newCarriage;
        head->next = head;
        head->prev = head;
    } else {
        Car* lastCarriage = head->prev;
        
        lastCarriage->next = newCarriage;
        newCarriage->prev = lastCarriage;
        newCarriage->next = head;
        head->prev = newCarriage;
    }
}

int Train::getLength() {
    operationCounter = 0;

    // Empty train case
    if (head == nullptr) {
        return 0;
    }

    int trainSize = 1;
    bool allLightsActive = head->light;
    const Car* currentCarriage = head->next;

    // Traverse the circular list
    while (currentCarriage != head) {
        trainSize++;
        
        if (!currentCarriage->light) {
            allLightsActive = false;
        }
        
        currentCarriage = currentCarriage->next;
    }

    // Calculate operation count based on configuration
    if (allLightsActive) {
        operationCounter = trainSize * (trainSize + 1);
    } else {
        operationCounter = trainSize * 2;
    }

    return trainSize;
}

int Train::getOpCount() {
    return operationCounter;
}
