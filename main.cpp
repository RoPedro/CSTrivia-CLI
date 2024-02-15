#include "functions.h"

using namespace std;

vector<string> readQuestionLinesFromFile(const string& filename);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Answer the trivias with a, b, c, or d." << endl;

    vector<string> questionLines;
    bool loseFlag = false;
    char userChoice;

    if (loseFlag == false)
    {
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
                int randomIndex = rand() % questionLines.size(); // randomize the question
                cout << questionLines[randomIndex] << endl; // print the question
                vector<string> possibleAnswers = getAndPrintPossibleAnswers(randomIndex, questionsLevelTracker); // assign and print the possible answers
                string correctAnswer = assignCorrectAnswer(randomIndex, possibleAnswers, questionsLevelTracker); // assign the correct answer

                cin >> userChoice;

                // validate the user's choice
                while ( userChoice != 'a' &&
                        userChoice != 'b' &&
                        userChoice != 'c' &&
                        userChoice != 'd' &&
                        userChoice != 'A' &&
                        userChoice != 'B' &&
                        userChoice != 'C' &&
                        userChoice != 'D' ) {
                
                    cout << "Invalid choice. Use a, b, c, or d." << endl;
                    cin >> userChoice;
                }

                int userIndex = translateUserChoice(userChoice); // translate the user's choice into a index

                if (possibleAnswers[userIndex] == correctAnswer)
                {
                    cout << "Correct!" << endl;
                    loseFlag = false;
                }
            }
        }
    } else {
        cout << "You lost, restart the game." << endl;
        loseFlag = true;
    }

    cout << "You won!" << endl;

    return 0;
}