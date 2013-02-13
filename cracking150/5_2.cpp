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

string printBinary(double num){
    if (num>=1 || num<=0)
        return "ERROR";
    string s = "0.";
    int counter = 0;
    while (num != 0){
        if (counter >= 32)
            return "ERROR";
        counter++;
        if (2*num >= 1){
            num = 2*num - 1;
            s += "1";
        }else{
            num *= 2;
            s += "0";
        }
    }
    return s;
}
int main(){
    cout<< printBinary(0.72)<< endl;
    cout<< printBinary(0.75)<< endl;
}
