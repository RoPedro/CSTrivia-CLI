#include "functions.h"

using namespace std;

vector<string> readLinesFromFile(const string& filename);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<string> lines = readLinesFromFile("questions/easyQuestions.txt");
    // int questionsLevelTracker = 0;
    // for (questionsLevelTracker < 2; questionsLevelTracker++)
    // {
        
    // }
    
    
    if (lines.empty())
    {
        cerr << "No lines in file" << endl;
        return 1;
    } else
    {
        int randomIndex = rand() % lines.size();
        switch (randomIndex)
        {
        case 0:
            cout << lines[randomIndex] << endl;
            cout << "a - Answer 1" << endl;
            cout << "b - Answer 2" << endl;
            cout << "c - Answer 3" << endl;

            break;
        
        case 1:
            cout << lines[randomIndex] << endl;
            cout << "a - Answer 1" << endl;
            cout << "b - Answer 2" << endl;
            cout << "c - Answer 3" << endl;

            break;
        
        case 2:
            cout << lines[randomIndex] << endl;
            cout << "a - Answer 1" << endl;
            cout << "b - Answer 2" << endl;
            cout << "c - Answer 3" << endl;

            break;
        default:
            break;
        }

        // cout << lines[randomIndex] << endl;
    }

    return 0;
}