#include "functions.h"

// read questionLines from a file and store it in a vector

using namespace std;

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
    } else 
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return questionLines;
}

// Reads the answers from the file and prints it.
void getAndPrintPossibleAnswers(int index, int questionsLevel)
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
}