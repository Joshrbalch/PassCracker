#include <iostream>

using namespace std;

class Check {
    public:
    string password;

    Check(string password) {
        this->password = password;
    }

    int getLength() {
        return password.length();
    }

    bool check(string guess) {
        if(guess == password) {
            return true;
        }

        return false;
    }
};