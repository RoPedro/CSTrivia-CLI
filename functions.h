#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>


using namespace std;

vector<string> assignQuestionsToVector(int questionsLevelTracker);

std::vector<std::string> readQuestionLinesFromFile(const std::string& filename);

vector<string> getAndPrintPossibleAnswers(int index, int questionsLevel);

string assignCorrectAnswer(int questionIndex, vector<string> possibleAnswers, int questionsLevelTracker);

int translateUserChoice(char userChoice);

#endif