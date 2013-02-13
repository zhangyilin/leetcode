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

class ImageDithering {
	typedef vector<string> VI;
public:
	int count (string dithered, vector <string> screen);
};

int ImageDithering::count (string dithered, vector<string> screen){
	int count = 0;
	for (VI::iterator it = screen.begin(); it != screen.end(); it++){
		string s = *it;
		for (int i = 0; i < it->size(); i++){
			if (dithered.find(s[i])!=string::npos)
				count++;
		}
	}
	return count;

}

int main(){
	ImageDithering I;
	string s = "BW";
	vector<string> vs;
	vs.push_back ("AAAAAAAA");
	vs.push_back ("ABWBWBWA");
	vs.push_back ("AWBWBWBA");
	vs.push_back ("ABWBWBWA");
	vs.push_back ("AWBWBWBA");
	vs.push_back ("AAAAAAAA");
	cout<< I.count (s, vs)<< endl;
}
