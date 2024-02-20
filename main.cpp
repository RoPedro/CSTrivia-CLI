#include "functions.h"

using namespace std;

vector<string> readQuestionLinesFromFile(const string& filename);

int main()
{
    cout << "\033[2J\033[1;1H";

    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Answer the trivias with a, b, c, or d." << endl;

    vector<string> questionLines;
    bool loseFlag = false;
    char userChoice;
    char restartFlag;

    // Check if the user wants to restart
    do
    {   
        for (int questionsLevelTracker = 0; questionsLevelTracker <= 2; questionsLevelTracker++)
        {
            // Checks if the user loss
            if (loseFlag == false)
            {
                // read questionLines from a file and store it in a vector.
                questionLines = assignQuestionsToVector(questionsLevelTracker);

                // Error handling in case of no questionLines in the file
                if (questionLines.empty())
                {
                    cerr << "No questionLines in file" << endl;
                    return 0;
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

                    string userAnswer = possibleAnswers[userIndex];

                    cout << "Correct answer: " << correctAnswer << endl;
                    cout << "Your answer: " << userAnswer << endl;

                    // Checks if the user's choice is correct
                    if (userAnswer == correctAnswer)
                    {
                        cout << "\033[2J\033[1;1H"; // Clears the screen
                        cout << "Correct! Next question." << endl;
                    } else
                    {
                        cout << "Wrong!" << endl;
                        loseFlag = true;
                    }
                }
            } else
            {
                break;
            }
        }

        if (loseFlag == false)
        {
            cout << "Congratulations! You won!" << endl;
        } else 
        {
            cout << "You lost!" << endl;
        }

        cout << "Would you like to play again? (y/n)" << endl;
        cin >> restartFlag;
        
        if (restartFlag == 'y' || restartFlag == 'Y')
        {
            cout << "\033[2J\033[1;1H"; // Clears the screen
            loseFlag = false;
        }
        

    } while (restartFlag == 'y' || restartFlag == 'Y');
    

    return 0;
}