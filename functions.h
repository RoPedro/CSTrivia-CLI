#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>

using namespace std;

std::vector<std::string> readQuestionLinesFromFile(const std::string& filename);

void getAndPrintPossibleAnswers(int index, int questionsLevel);

#endif