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

int insertBit (int N, int M, int i, int j){
    int mask = ~ ((1<<(j-i+1) - 1) << i);
    return ((N&mask)|(M<<i));
}
}
