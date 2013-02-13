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

#define num(c) (int)((c)-('0'))
#define chr(n) (char)((n)+('0'))
class BinaryCode{
public:
	vector<string> decode(string);
};
vector<string> BinaryCode::decode(string message){
	vector<string> V (0);
	string S = "";
	int len = message.length();
	for (int i = 0; i <=1; i++){
		S = "";
		S.push_back(chr(i));
		for (int pos = 1; pos < len; pos++){
			char c = message[pos-1] -num(S[pos-1]) - num(pos==1?'0':S[pos-2])	;
			if (isdigit(c) && c < '2')
				S.push_back(c);
			else {
				S = "NONE";
				break;
			}
		}
		if (num(message[len-1]) - num(S[len-1]) - num(len>1?S[len-2]:'0') != 0)
			S = "NONE";
		V.push_back(S);
	}
	return V;
}

int main(){
	BinaryCode B;
	vector<string> V = B.decode("123210122");
	cout << V[0]<< endl<< V[1]<< endl;
	V = B.decode("11");
	cout << V[0]<< endl<< V[1]<< endl;
	V = B.decode("22111");
	cout << V[0]<< endl<< V[1]<< endl;
	V = B.decode("123210120");
	cout << V[0]<< endl<< V[1]<< endl;
	V = B.decode("3");
	cout << V[0]<< endl<< V[1]<< endl;
	V = B.decode("12221112222221112221111111112221111");
	cout << V[0]<< endl<< V[1]<< endl;
	return 0;

}
