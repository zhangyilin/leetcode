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

class RectangularGrid{
public:
    long long countRectangles(int width, int height){
        int subwidth = width;
        int subheight = height;
        long long count = 0; 
        for (subwidth = width; subwidth > 0; subwidth--){
            for (subheight = height; subheight > 0; subheight--){
                if (subwidth != subheight)
                    count += (width - subwidth + 1)*(height - subheight + 1);
            }//inside for
        }//out for
        return count;
    }
};

int main(){
    RectangularGrid rg;
    cout << rg.countRectangles (1,1);
}
