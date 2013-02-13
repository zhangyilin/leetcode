#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

//num*(num-1)*..*(num-l+1)
unsigned long long factorial (int num, int l){
	unsigned long long rValue = 1;
	for (int i = num; i > num - l; i--)
		rValue *= i;
	return rValue;
}
class Lottery{
	typedef std::pair<string,unsigned long long> LotteryOdds;
	static LotteryOdds getOdds (const string & rule);
	typedef struct Comp {
		bool operator () (const LotteryOdds &left, const LotteryOdds &right){
			if (left.second == right.second)
				return left.first < right.first;
			else
				return left.second < right.second;
		}   
	}CompFunctor;
	public:
	vector<string> sortByOdds(vector<string> rules);
};
Lottery::LotteryOdds Lottery::getOdds (const string & rule){
	istringstream in(rule);
	string name;
	int choices, blanks;
	char sorted,unique;
	getline(in, name, ':');
	in >> choices>> blanks>> sorted>> unique;
	unsigned long long odd = 0;
	if (sorted == 'T' && unique == 'T')
		odd = factorial(choices, blanks)/factorial(blanks,blanks);
	else if (sorted == 'T' && unique == 'F')
		odd = factorial (choices+blanks-1,blanks)/factorial(blanks,blanks);
	else if (sorted == 'F' && unique == 'T')
		odd = factorial(choices,blanks);
	else if (sorted == 'F' && unique == 'F')
		odd = pow((long double)choices, blanks);
	return make_pair(name,odd);
}
vector<string> Lottery::sortByOdds(vector<string> rules){
	vector <Lottery::LotteryOdds> results;
	vector <string> rValue;
	transform (rules.begin(), rules.end(), inserter(results, results.begin()), getOdds);
	sort (results.begin(), results.end(), Lottery::CompFunctor());
	for (vector <Lottery::LotteryOdds>::iterator it = results.begin(); it != results.end(); it++)
		rValue.push_back(it->first);
	return rValue;
}
int main(){
	Lottery L;
	vector<string> s;
	s.push_back ("A:100 10 T T");
	s.push_back ("B:20 2 F T");
	string ss[]= {"INDIGO: 93 8 T F","ORANGE: 29 8 F T","VIOLET: 76 6 F F","BLUE: 100 8 T T","RED: 99 8 T T","GREEN: 78 6 F T","YELLOW: 75 6 F F"};
	vector<string> sss(ss,ss+sizeof(ss)/sizeof(string));
	L.sortByOdds(sss);
	cout<< 1- (double)(factorial(90,10)+10*factorial(90,9))/factorial(100,10)<< endl;
	cout<< (double)factorial(10,2)*factorial(98,8)/factorial(100,10)<<endl;
	cout<< factorial(5,2)<<endl;
}
