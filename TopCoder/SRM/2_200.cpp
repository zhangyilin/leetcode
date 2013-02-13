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

class Time{
	public:
		string whatTime (int);
};
string Time::whatTime (int seconds){
	int hour = seconds/3600;
	int minute = (seconds - 3600*hour)/60;
	int second = seconds - 3600*hour - 60*minute;
	stringstream ss;
	ss<< hour<< ":"<< minute<< ":"<< second;
	string rValue = ss.str();
	return rValue;
}

int main(){
	string s;
	Time t;
	s = t.whatTime(3661);
	s = t.whatTime(0);
	cout<< s<< endl;
}
