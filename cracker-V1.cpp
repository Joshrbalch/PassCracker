#include <random>
#include <iostream>
#include <string>
#include <sys/time.h>

using namespace std;

// currently only works for lowercase, alphabeticle letters
// measures the time it takes to crack a password based on it's length

int main() {
    struct timeval begin, end;

    string password;
    string guess;

    while(password != "exit") {
        cout << "Type 'exit' to exit." << endl;
        cout << "Enter a password: ";
        cin >> password;
        gettimeofday(&begin, 0);
        while(1) {
            guess = "";
            for(int i = 0; i < password.length(); i++) {
                guess += (char) (rand() % 26 + 97);
            }

            // cout << "Guess: " << guess << endl;

            if(guess == password) {
                cout << "Cracked!" << endl;
                cout << "Password: " << guess << endl;
                break;
            }
        }

        gettimeofday(&end, 0);
        long seconds = end.tv_sec - begin.tv_sec;
        long microseconds = end.tv_usec - begin.tv_usec;
        double elapsed = seconds + microseconds*1e-6;
        
        printf("The %d letter password took %.4f seconds to crack.\n", password.length(), elapsed);
        cout << endl;
    }
    
    return 0;
}