/*
    * Description: Reads a file and outputs the score to an associated name
    * Input: The name the search
    * Output: All the names in the file, the scores, and the statistics of the name to the terminal
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    // variables
    string fileName = "\0";
    ifstream iFile;
    string toFind = "\0"; 
    int foundCnt = 0;
    double sum = 0.0, min = 100, max = 0, avg = 0.0;

    // two arrays
    const int size = 100;
    string names[size];
    double scores[size];

    // intialize the array
    for (int i = 0; i < size; i++) {
        names[i] = "\0";
        scores[i] = 0;
    }    

    // prompt user for file name
    do {
        cout << "Enter a file name\n" << "**";
        cin >> fileName;

        iFile.open(fileName);

        // verifies that the file has opened; if not, output an error
        if (!iFile.is_open()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "\nError: Invalid file name.\n";
        }

    } while (!iFile.is_open());

    // prompts user for a name and saves it
    cout << "\nEnter a name to search\n" << "**";
    cin >> toFind; 

    // reads the names and numbers from the file into the two arrays using a while loop
    // keeps track of how many name/number are read in
    int count = 0;
    while (!iFile.eof()) {
        iFile >> names[count];
        iFile >> scores[count];

        if (!iFile) {
            if (!iFile.eof()) {
                iFile.clear();
                iFile.ignore(256, '\n');
                cout << "\nError in line\n";
            }
            continue;
        }
        count++;

    }

    // close the file
    iFile.close();

    // debugging
    // for (int i = 0; i < count; i++) {
    //     cout << names[i];
    //     cout << scores[i];
    // }

    // prints names arrays forwards by interating from the first element to the last element
    cout << "\nNames Forward: " << names[0];
    for (int i = 1; i < count; i++) {
        cout << ", " << names[i];
    }

    // prints scores array forwards
    cout << "\nScores Forward: " << scores[0];
    for (int i = 1; i < count; i++) {
        cout << ", " << scores[i];
    }

    // prints names arrays backwards by interating from the last element to the first element
    cout << "\nNames Reverse: " << names[count - 1];
    for (int i = count - 2; i >= 0; i--) {
        cout << ", " << names[i];   
    }

    // prints scores array backwards
    cout << "\nScores Reverse: " << scores[count - 1];
    for (int i = count - 2; i >= 0; i--) {
        cout << ", " << scores[i];
    } 

    // look the scores associated with the name inputted by the user
    for (int i = 0; i < count; i++) {
        // calculate the sum
        if (names[i] == toFind) {
            sum += scores[i];
            foundCnt++;

            // calculate the maximum if its the name inputted by the user
            if (scores[i] > max) {
                max = scores[i];
            }

            // calculate the minimum
            if (scores[i] < min) {
                    min = scores[i];
                }
        }
    }

    // calculate the average
    avg = sum / foundCnt;

    // displays an error if name was not found
    if (foundCnt == 0) {
        cout << "\nError: " << toFind << " is not a student in the list\n";
        return 0;
    }

    cout << '\n' << foundCnt << " results for " << toFind
         << fixed << setprecision(2) << right
         << "\nMinimum: " << min
         << "\nMaximum: " << max
         << "\nSum:     " << sum
         << "\nAverage: " << avg << '\n';


    return 0;

}
