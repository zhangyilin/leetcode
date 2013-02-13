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

class ExerciseMachine{
public:
	int getPercentages (string s){
		stringstream ss(s);
		int hr, min, sec;
		char sepr;
		ss>> hr>> sepr>> min>> sepr>> sec;
		int time = hr * 3600 + min * 60 + sec; 
		int v[] = {100,50,25,20,10,5,4,2,1};
		for (int i = 0; i < sizeof(v) / sizeof(int); i++){
			if (time%v[i] == 0) return v[i] - 1;
		}
	}
};
int main(){
	ExerciseMachine t;
	string s = "00:30:00";
	s = "23:59:59";
	s = "00:18:00";
	cout<< t.getPercentages (s)<< endl;
}
