#include <random>
#include <iostream>
#include <string>
#include <sys/time.h>
#include <vector>
#include "check.cpp"
#include "randomGuess.cpp"
#include "bruteGuess.cpp"

using namespace std;

// currently only works for lowercase, alphabeticle letters
// measures the time it takes to crack a password based on it's length

bool randomGuess (string password, string guess);
bool bruteGuess(string password);
double timeCalc(timeval begin, timeval end);

int main() {
    string password;
    string guess;
    int num;

    while(password != "exit") {
        cout << "Type 'exit' to exit." << endl;
        cout << "Enter a password: ";
        cin >> password;

        RandomGuess randomGuess;
        BruteGuess bruteGuess;
        Check check(password);
        randomGuess.setCheck(check);

        if(password == "exit") {
            break;
        }

        cout << "How many times would you like to try to crack?" << endl;
        cin >> num;

        for(int i = 0; i < num; i++) {
            guess = "";
            randomGuess.guess(guess);
            bruteGuess.guess(guess);
        }

        randomGuess.calcAvgTime(num);
        bruteGuess.calcAvgTime(num);

        
    }
    
    return 0;
}