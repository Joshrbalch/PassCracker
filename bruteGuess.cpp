#ifndef BRUTE_GUESS_CPP
#define BRUTE_GUESS_CPP

#include <iostream>
#include <string>
#include <random>
#include <sys/time.h>
#include <vector>
#include "check.cpp"

using namespace std;

class BruteGuess {
    public:
    vector<double> bruteTimes;
    Check check;

    void setCheck(Check check) {
        this->check = check;
    }

    void calcAvgTime(int num) {
        double avgBrute = 0.0;

        for(int i = 0; i < num; i++) {
            avgBrute += bruteTimes[i];
        }

        avgBrute /= num;

        cout << "Average time to crack with brute guessing: " << avgBrute << "ms" << endl;
    }

    void timeCalc(timeval begin, timeval end) {
        double elapsed = (end.tv_sec - begin.tv_sec) * 1000.0;
        elapsed += (end.tv_usec - begin.tv_usec) / 1000.0;

        bruteTimes.push_back(elapsed);
    }

    bool guess(string password) {
        struct timeval begin, end;

        string guess = "";
        for(int i = 0; i < password.length(); i++) {
            guess += 'a';
        }

        gettimeofday(&begin, 0);

        while(1) {
            if(check.check(guess)) {
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

        gettimeofday(&end, 0);
        timeCalc(begin, end);

        return true;
    }
};

#endif