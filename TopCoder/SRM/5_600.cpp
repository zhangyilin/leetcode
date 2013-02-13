#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Masterbrain{
    public:
        int possibleSecrets(vector <string> guesses, vector <string> results){
            int possible = 0;
            for (int number = 0; number <= 9999; number++){
                int correct = 0;
                for (int i = 0; i < guesses.size(); i++){
                    if (isCorrect(number, guesses.at(i), results.at(i)))
                        correct++;
                }
                if (correct == guesses.size()-1)
                    possible++;
            }
            return possible;
        }
        bool isCorrect(int number, string guess, string result){
            int b = result[4];
            int w = result[1];
            vector<int> counter (10,0);
            string snumber = itoa (number);
            for (int bit = 0; bit < 4; bit++){
                counter.at(snumber.at(bit)-'0')++;
            }
            for (int bit = 0; bit < 4; bit++){
                if (snumber.at(bit) == guess.at(bit))
                    b-- = 1;
                else{
                    if (counter.at(guess.at(bit)-'0') > 0){
                        counter.at(guess.at(bit)-'0')--;
                        w-- = 1;
                    }
                }
            }
            return w==0 && b==0;
        }
};

int main(){
    Masterbrain mb;
    cout<< mb.possibleSecrets()<< endl;
}
