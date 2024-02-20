#include "functions.h"

// read questionLines from a file and store it in a vector

using namespace std;

vector<string> assignQuestionsToVector(int questionsLevelTracker)
{
    vector<string> questionLines;
    switch (questionsLevelTracker)
    {
    case 0:
        questionLines = readQuestionLinesFromFile("questions/easyQuestions.txt");
        break;

    case 1:
        questionLines = readQuestionLinesFromFile("questions/mediumQuestions.txt");
        break;

    case 2: 
        questionLines = readQuestionLinesFromFile("questions/hardQuestions.txt");
        break;
    
    default:
        break;
    }

    return questionLines;
}

// read questionLines from a file and store it in a vector.
std::vector<std::string> readQuestionLinesFromFile(const std::string& filename)
{
    std::vector<std::string> questionLines; // store the questionLines in a vector
    std::ifstream file(filename); // open the file
    std::string line; // store each line

    if (file.is_open())
    {
        // read the file
        while (std::getline(file, line))
        {
            questionLines.push_back(line); // add the line to the vector
        }
        file.close(); // close the file in order to prevent memory leaks
    } else // Error handling
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return questionLines;
}

// Reads the answers from the file and prints it.
vector<string> getAndPrintPossibleAnswers(int index, int questionsLevel)
{
    // Possible answers are different based on the specific question, even in the same level.
    vector<string> possibleAnswers;

    // Chooses the answers based on the level.
    // If statements assigns the different possible answers for each question.
    switch (questionsLevel)
    {
    case 0:
        if (index == 0)
        {
            possibleAnswers = readQuestionLinesFromFile("answers/easy1Answers.txt");
        } else if (index == 1)
        {
            possibleAnswers = readQuestionLinesFromFile("answers/easy2Answers.txt");
        } else
        {
            possibleAnswers = readQuestionLinesFromFile("answers/easy3Answers.txt");
        }
        break;

    case 1:
        if (index == 0)
        {
            possibleAnswers = readQuestionLinesFromFile("answers/medium1Answers.txt");
        } else if (index == 1)
        {
            possibleAnswers = readQuestionLinesFromFile("answers/medium2Answers.txt");
        } else
        {
            possibleAnswers = readQuestionLinesFromFile("answers/medium3Answers.txt");
        }
        break;
    case 2:
        if (index == 0)
        {
            possibleAnswers = readQuestionLinesFromFile("answers/hard1Answers.txt");
        } else if (index == 1)
        {
            possibleAnswers = readQuestionLinesFromFile("answers/hard2Answers.txt");
        } else
        {
            possibleAnswers = readQuestionLinesFromFile("answers/hard3Answers.txt");
        }
        break;
    default:
        break;
    }

    // Seed the random number generator
    random_device rd;
    mt19937 gen(rd());

    // Shuffle the possible answers
    shuffle(possibleAnswers.begin(), possibleAnswers.end(), gen);

    for (int i = 0; i < possibleAnswers.size(); i++)
    {
        while (!possibleAnswers.empty())
        {
            int randomAnswersIndex = rand() % possibleAnswers.size();
            cout << possibleAnswers[randomAnswersIndex] << endl;

            possibleAnswers.erase(possibleAnswers.begin() + randomAnswersIndex);
        }
        cout << endl;
    
        shuffle(possibleAnswers.begin(), possibleAnswers.end(), gen);
    }

    return possibleAnswers;
}

string assignCorrectAnswer(int questionIndex, vector<string> possibleAnswers, int questionsLevelTracker)
{
    string correctAnswer;
    // Check the level of the question
    switch (questionsLevelTracker)
    {
    case 0: // Easy
        if (questionIndex == 0)
        {
            correctAnswer =  "Hyper Text Markup Language.";
        } else if (questionIndex == 1)
        {
            correctAnswer =  "To convert high-level programming code into machine code";
        } else
        {
            correctAnswer =  "Central Processing Unit.";
        }
        break;
    
    case 1: // Medium
        if (questionIndex == 0)
        {
            correctAnswer =  "TCP provides reliable, ordered, and error-checked delivery of data, while UDP does not guarantee delivery and is connectionless.";
        } else if (questionIndex == 1)
        {
            correctAnswer =  "To organize and manage data efficiently.";
        } else
        {
            correctAnswer =  "Compiled languages are translated directly into machine code, while interpreted languages are translated line by line during runtime.";
        }
        break;

    case 2: // Hard
        if (questionIndex == 0)
        {
            correctAnswer =  "Big O notation represents the worst-case scenario for the time or space complexity of an algorithm.";
        } else if (questionIndex == 1)
        {
            correctAnswer =  "A hash table is a data structure that uses a hash function to map keys to values, offering constant time complexity for insertion, deletion, and retrieval operations.";
        } else
        {
            correctAnswer =  "Multithreading allows multiple processes to share a single CPU, reducing resource consumption and improving performance.";
        }
        break;
    default:
        cerr << "Error in assignCorrectAnswer function" << endl;
        break;
    }

    return correctAnswer;
}

int translateUserChoice(char userChoice)
{
    userChoice = tolower(userChoice);

    int translatedIndex = -1;

    switch (userChoice)
    {
    case 'a':
        translatedIndex = 0; 
        break;
    
    case 'b':
        translatedIndex = 1; 
        break;

    case 'c':
        translatedIndex = 2; 
        break;

    case 'd':
        translatedIndex = 3; 
        break;

    default:
        break;
    }

    return translatedIndex;
}