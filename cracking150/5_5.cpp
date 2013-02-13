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

int bitSwapRequired (int a, int b){
    int count = 0;
    for (int c = a^b; c != 0; c = c>>1)
        count += c&1?1:0;
    return count;
}
int main(){
    cout<< bitSwapRequired (3,18);
}
