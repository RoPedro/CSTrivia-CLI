#include "functions.h"

using namespace std;

vector<string> readQuestionLinesFromFile(const string& filename);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Answer the trivias with a, b, c, or d." << endl;

    vector<string> questionLines;
    for (int questionsLevelTracker = 0; questionsLevelTracker <= 2; questionsLevelTracker++)
    {
        // read questionLines from a file and store it in a vector.
        // switch statement to select the the level of the questions
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

        // Error handling in case of no questionLines in the file
        if (questionLines.empty())
        {
            cerr << "No questionLines in file" << endl;
            return 1;
        } else
        {
            int randomIndex = rand() % questionLines.size();
            switch (randomIndex, questionsLevelTracker)
            {
            case 0:
                cout << questionLines[randomIndex] << endl;
                getAndPrintPossibleAnswers(randomIndex, questionsLevelTracker);

                break;
            case 1:
                cout << questionLines[randomIndex] << endl;
                getAndPrintPossibleAnswers(randomIndex, questionsLevelTracker);

                break;
            case 2:
                cout << questionLines[randomIndex] << endl;
                getAndPrintPossibleAnswers(randomIndex, questionsLevelTracker);

                break;
            default:
                break;
            }
        }


    }

    return 0;
}