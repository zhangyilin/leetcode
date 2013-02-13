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

class PowerOutage{
	int max;
public:
	void dfs (int sum, int index, vector<int>& from, vector<int>& to, vector<int>& len){
		bool check = false;
		int n = from.size();
		for (int i = 0; i < n; i++){
			if (from[i] == index){
				check = 1;
				dfs (sum+len[i], to[i], from, to, len);
			}
		}
		if (!check){
			if (sum > max)
				max = sum;
		}
	}
	int estimateTimeOut (vector<int>from, vector<int> to, vector<int> len){
		int sum = 0;
		dfs (sum, 0, from, to, len);
		int n = from.size();
		int rValue = 0;
		for (int i = 0; i < n; i++)
			rValue += 2*len[i];
		rValue -= max;
		return rValue;
	}
};
int main(){
	int from []= {0,0,0,1,4};
	int to []= {1,3,4,2,5};
	int len []= {10,10,100,10,5};
	vector<int> f (from, from + sizeof(from)/sizeof(int));
	vector<int> t (to, to + sizeof(to)/sizeof(int));
	vector<int> l (len, len + sizeof(len)/sizeof(int));
	PowerOutage p;
	cout<< p.estimateTimeOut ( f,t,l)<< endl;
}
