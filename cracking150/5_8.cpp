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

void drawLine (byte[] screen, int width, int x1, int x2, int y){
    if (x2<x1)
        cout << "ERROR input"<< endl;
    int b1 = y*width/8 + ceiling(x1/8);
    int b2 = y*width/8 + floor(x2/8);
    for (int i = b1; i<=b2; i++)
        screen[i] |= 0xFF;
    if (x1/8 == x2/8){
        screen[x1/8] |= 1<<(9-x1&8) - 1<<(8-x2&8);
    }else{
        screen[x1/8] |= 1<<(9-x1&8) - 1;
        screen[ceiling(x2/8)] |= ~(1<<(9-x1&8) - 1);
    }
}
