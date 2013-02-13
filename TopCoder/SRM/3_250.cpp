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

class Bonuses{
public:
	vector<int> getDivision (vector<int> points){
		int n = points.size();
		int i;
		int total = std::accumulate(points.begin(), points.end(), 0);
		vector<int> rValue;
		//const_mem_fun_t<Bonuses,int> mf(&Bonuses::percentage);
		transform (points.begin(), points.end(), inserter(rValue, rValue.begin()), std::bind2nd(std::divides<long double>(), (long double)total/100) );
		int remain = 100 - accumulate(rValue.begin(), rValue.end(), 0);
		vector<int> sorted = points;
		sort(sorted.begin(), sorted.end());
		int edge = sorted[n-remain];
		i = 0;
		for (vector<int>::iterator it=points.begin(); it!=points.end(); it++){
			if(remain==0)
				break;
			if (*it > edge){
				rValue[i] += 1;
				remain--;
			}
			i++;
		}
		i = 0;
		for (vector<int>::iterator it=points.begin(); it!=points.end(); it++){
			if(remain==0)
				break;
			if (*it == edge){
				rValue[i] += 1;
				remain--;
			}
			i++;
		}
		return rValue;
	}
};

int main(){
	int ia[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470};
	vector<int> v(ia,ia+sizeof(ia)/sizeof(int));
	Bonuses b;
	vector<int> v2 = b.getDivision(v);
	for(vector<int>::iterator it = v2.begin(); it!= v2.end(); it++)
		cout<< *it<<endl;
}
