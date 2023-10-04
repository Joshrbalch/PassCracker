#include <iostream>
#include <string>
#include <random>
#include <sys/time.h>
#include <vector>
#include "check.cpp"

using namespace std;

class RandomGuess {
    public:
    vector<double> randTimes;
    Check check;

    RandomGuess(Check check) {
        this->check = check;
    }

    void calcAvgTime(int num) {
        double avgRand = 0.0;

        for(int i = 0; i < num; i++) {
            avgRand += randTimes[i];
        }

        avgRand /= num;

        cout << "Average time to crack with random guessing: " << avgRand << "ms" << endl;
    }

    void timeCalc(timeval begin, timeval end) {
        double elapsed = (end.tv_sec - begin.tv_sec) * 1000.0;
        elapsed += (end.tv_usec - begin.tv_usec) / 1000.0;

        randTimes.push_back(elapsed);
    }

    bool guess (string guess) {
        struct timeval begin, end;

        gettimeofday(&begin, 0);
        while(1) {
            guess = "";
            for(int i = 0; i < check.getLength(); i++) {
                guess += (char) (rand() % 26 + 97);
            }

            if(check.check(guess)) {
                break;
            }
        }

        gettimeofday(&end, 0);
        timeCalc(begin, end);
        return true;
    }
};