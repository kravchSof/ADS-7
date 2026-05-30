// Copyright 2022 NNTU-CS
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  std::ofstream outputFile("data.txt");

  unsigned int randomSeed = time(nullptr);

  for (int carriageCount = 10; carriageCount <= 500; carriageCount += 10) {
    Train firstTrain;
    Train secondTrain;
    Train thirdTrain;

    for (int idx = 0; idx < carriageCount; idx++) {
      firstTrain.addCar(false);
    }

    for (int idx = 0; idx < carriageCount; idx++) {
      secondTrain.addCar(true);
    }

    for (int idx = 0; idx < carriageCount; idx++) {
      thirdTrain.addCar(rand_r(&randomSeed) % 2);
    }

    firstTrain.getLength();
    secondTrain.getLength();
    thirdTrain.getLength();

    outputFile << carriageCount << " "
               << firstTrain.getOpCount() << " "
               << secondTrain.getOpCount() << " "
               << thirdTrain.getOpCount() << std::endl;
  }

  outputFile.close();

  return 0;
}
