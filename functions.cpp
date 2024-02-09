#include "functions.h"

// read lines from a file and store it in a vector

using namespace std;

// read lines from a file and store it in a vector.
std::vector<std::string> readLinesFromFile(const std::string& filename)
{
    std::vector<std::string> lines; // store the lines in a vector
    std::ifstream file(filename); // open the file
    std::string line; // store each line

    if (file.is_open())
    {
        // read the file
        while (std::getline(file, line))
        {
            lines.push_back(line); // add the line to the vector
        }
        file.close(); // close the file in order to prevent memory leaks
    } else 
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return lines;
}

// Reads the answers from the file and prints it.
/* void printPossibleAnswers(int index)
{
    vector<string> possibleAnswers = readLinesFromFile("answers/easyAnswers.txt");
    switch (index)
    {
    case 0:

        break;

    case 1:
        
        break;
    
    case 2:
        
        break;
    default:
        break;
    }
} */