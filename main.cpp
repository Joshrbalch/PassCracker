#include <random>
#include <iostream>
#include <string>
#include <sys/time.h>
#include <vector>
#include "check.cpp"
#include "randomGuess.cpp"

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

        RandomGuess randomGuess(Check(password));

        if(password == "exit") {
            break;
        }

        cout << "How many times would you like to try to crack?" << endl;
        cin >> num;

        for(int i = 0; i < num; i++) {
            guess = "";

            randomGuess.guess(guess);
            gettimeofday(&end, 0);

            randElapsed = timeCalc(begin, end);
            randTimes[i] = randElapsed;

            gettimeofday(&begin, 0);
            bruteGuess(password);
            gettimeofday(&end, 0);

            bruteElapsed = timeCalc(begin, end);
            bruteTimes[i] = bruteElapsed;
        }

        double avgRand = 0.0, avgBrute = 0.0;

        for(int i = 0; i < num; i++) {
            avgRand += randTimes[i];
            avgBrute += bruteTimes[i];
        }

        avgRand /= (double) num;
        avgBrute /= (double) num;

        cout << "RAND: ";
        
        for(int i = 0; i < num; i++) {
            cout << randTimes[i] << " ";
        }

        cout << endl;
        cout << "BRUTE: ";

        for(int i = 0; i < num; i++) {
            cout << bruteTimes[i] << " ";
        }

        cout << endl;

        printf("The average of %d cracks for a %d letter word:\n", num, password.length());
        printf("Rand: %.4f\n", avgRand);
        printf("Brute: %.4f\n", avgBrute);
        cout <<"------------------"<< endl;
    }
    
    return 0;
}

double timeCalc(timeval begin, timeval end) {
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double out = seconds + microseconds*1e-6;

    return out;
}

bool randomGuess (string password, string guess) {
    while(1) {
        guess = "";
        for(int i = 0; i < password.length(); i++) {
            guess += (char) (rand() % 26 + 97);
        }

        if(guess == password) {
            break;
        }
    }

    return true;
}

bool bruteGuess(string password) {
    string guess = "";
    for(int i = 0; i < password.length(); i++) {
        guess += 'a';
    }

    while(1) {
        if(guess == password) {
            break;
        }

        else {
            for(int i = 0; i < password.length(); i++) {
                if(guess[i] == 'z') {
                    guess[i] = 'a';
                }

                else {
                    guess[i]++;
                    break;
                }
            }
        }
    }

    return true;
}