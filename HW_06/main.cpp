/***********************************************
Author: Barkot Zeyohannes
Date: March 25, 2024
Purpose: find average movie ratings
Sources of Help:  lecture slides
***********************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream> // for stringstream

using namespace std;

int main() {
    //declate file pointer
    ifstream inStream;
    //open file
    inStream.open("input.txt");

    //check if file is open
    if (inStream.fail()) {
        cout << "Input file opening failed.\n";
        exit(0);
    }

    //declare variables
    int numRatings;
    inStream >> numRatings;
    inStream.ignore(); // ignore the newline character


    
    map<string, pair<int, int>> ratings; // Pair of (total rating, number of ratings)
    string name;
    string rate;
    //loop through every 2 lines of the file
    for (int i = 0; i < numRatings; i++) {
        getline(inStream, name);
        getline(inStream, rate);

        // stringstream for conversion
        stringstream ss(rate);
        int rating;
        if (!(ss >> rating)) {
            cout << "Error converting rating to integer for " << name << endl;
            exit(1);
        }

        // Check if movie already exists in ratings map
        if (ratings.find(name) == ratings.end()) {
            // If not, initialize its total rating and number of ratings
            ratings[name] = make_pair(rating, 1);
        } else {
            // If yes, update its total rating and number of ratings
            ratings[name].first += rating;
            ratings[name].second++;
        }
    }
    inStream.close();

    // Calculate average rating for each movie and print
    for (auto p = ratings.begin(); p != ratings.end(); p++) {
        cout << p->first << " " << ((double)p->second.first / (double)p->second.second) << endl;
    }
    return 0;
}