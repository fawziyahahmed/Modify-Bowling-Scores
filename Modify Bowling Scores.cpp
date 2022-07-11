// FAWZIYAH AHMED
// This program  will use structure and calculate a bowling league's average bowling scores from the BowlingScore.txt file

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

// structure members
struct Bowler {
    string name;
    int scores[5]{};
    int averageScore{};
};

// getBowlingData() function will read and store data into two arrays from a file 
bool getBowlingData(const string fileName, Bowler bowlers[], int & count) {
    
    // Opening the input file
    ifstream myfile;
    myfile.open(fileName, ios::in);

    // checking whether the file name is valid or not
    if (myfile.fail()) {
        cout << "File Not Found!";
        return false;
    }
    else {
        // counting the records from the file  
        while (myfile >> bowlers[count].name) {
            for (int& j : bowlers[count].scores) {
                myfile >> j;
            }
            count++;
        }
        // closing the input file
        myfile.close();
    }
    return true;

}

// GetAverageScore() function will calculate the average bowling score
void GetAverageScore(Bowler bowlers[], int count) {
    double total;
    int i = 0;
    const int cols = 5;
    //using loops to find the average
    while (i < count) {
        total = 0; 
        for (int j : bowlers[i].scores) {
            total += j;
        }

        // calculating the average
        bowlers[i].averageScore = (int)(total / cols);
        i++;
    }
}

// PrettyPrintResults() function will display the results
void PrettyPrintResults(Bowler bowlers[], int count) {

    //printing out each column's name
    cout << setw(10) << left << "NAME" << setw(6) << "S1" << setw(8) << "S2" << setw(8) << "S3" << setw(8) << "S4" << setw(8) << "S5" << "AVG" << endl;
    cout << endl;
    // for loop to print all names and scores
    int i = 0;
    while (i < count) {
        //this will print the names
        cout << setw(10) << left << bowlers[i].name;
        for (int j : bowlers[i].scores) {
            //this will output the scores
            cout << j << "\t";
        }
        // this will output the average
        cout << setw(5) << bowlers[i].averageScore << endl;
        i++;
    }
}
// here goes the main function
int main() {
    // declaring variables
    Bowler bowlers[100];
    string fileName = "BowlingScores.txt";
    int count = 0;
    // display the value upto 2 decimal places
    cout << setprecision(2) << fixed << showpoint;
    // if the file is valid then the program will display, or else it won't
    if (getBowlingData(fileName, bowlers, count)) {
        GetAverageScore(bowlers, count);

        PrettyPrintResults(bowlers, count);
    }
    else {
        cout << "File Not Found!" << endl;
    }
    return 0;
}
