/***********************************************
Author: Barkot Zeyohannes
Date: 1/20/24
Purpose: Positive Integer Guessing Gam
Sources of Help: w3 schools for the random number within certain range
***********************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int guessingGame(int randNum, int num, int min , int max);


int main (void) {
    char repeat;
    int min;
    int max;
    int num;//number of guesses
    int randNum;
    cout << "************* Welcome to the Guessing Game ********************\n";

    // get the minimum
    do {
        cout << "Please enter a positive integer(1-999):\n";
        cin >> min;
    } while(isdigit(min) ||min > 1000 || min <1);
    //get the max
    do {
        cout << "Please enter a positive integer greater than the maximum and less than 1000?\n";
        cin >> max;
    } while(isdigit(max)||max > 1000 || max < min); 
    //get the number of guesses
    do {
        cout << "Please enter the number of guesses you would like (1-10)?\n";
        cin >> num;
    } while(isdigit(num) || num > 10 || num < 1); 
  
    // get our random number for guessing game
    randNum = (rand() % (max - min + 1))+ min;

    do {
    guessingGame(randNum,num,min,max);
    cout << "would you like to play again? (y)es or (n)o\n\n";
    cin >> repeat;
    } while (repeat == 'y');


    return 0;

}
int guessingGame(int randNum, int num, int min, int max) {
    int guess;
    //for loop for the guess breaks on correct answer gives hint on incorrect answer
    for(int i = 0; i < num; i ++) {
        cout << "\nNow, I have a number between " 
        << min 
        << " and " 
        << max  
        << ". Can you guess? my number? Please type your first guess.\n";

        cin >> guess;
        if(guess==randNum) {
            cout<< "Victory, you guessed correctly !!\n";
            return 0;
        }
        else if(guess < randNum) {
            cout << "too low! try again\n";
        }
        else if (guess > randNum){
            cout << "too high! try again\n";
        }
    }
    cout << "Sorry, you have used all your guesses\n";
  return 0;
}