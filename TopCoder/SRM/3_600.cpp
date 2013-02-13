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

class VendingMachine{
	int curCol;
	int curTime;
	int cols;
	int rotateTime;
	typedef vector< vector<int> > VVI;
	inline int distance (int col1, int col2){ return min (abs(col1-col2), min(col1, col2) + cols - max(col2, col1)); }
	void rotate(VVI & goods){
		int max = 0;
		int number = 0;
		for ( VVI::iterator i = goods.begin(); i != goods.end(); i++){
			int sum = accumulate (i->begin(), i->end(), 0);
			if (sum > max){
				number = i - goods.begin();
				max = sum;
			}
		}
		rotateTime += distance (curCol, number);
		cout<< "1 rotateTime + "<< distance(curCol, number)<< endl;
		curCol = number;
	}
	int buy(int row, int col, VVI& goods){
		if (goods[col][row] == 0) return -1;
		rotateTime += distance (curCol, col);
		cout<< "2 rotateTime + "<< distance (curCol, col)<< endl;
		goods[col][row] = 0;
		curCol = col;
		return 0;
	}
public:
	int motorUse (vector<string> prices, vector<string> purchases){
		int i,j,k,n,tmp;
		int rows = prices.size();
		curCol = 0;
		curTime = 0;
		rotateTime = 0;
		cols = 1;
		for (i = 0; i < prices[0].size(); i++)
			if (prices[0][i] == ' ')	cols++;
		int purs = purchases.size();
		VVI goods(cols);
		for (i = 0; i < rows; i++){
			stringstream ss(prices[i]);
			for (j = 0; j < cols; j++){
				ss >> tmp; 
				goods[j].push_back(tmp);
			}
		}
		rotate(goods);
		int row, col, time;
		for (k = 0; k < purs; k++){
			string s = purchases[k];
			sscanf (s.c_str(), "%d,%d:%d", &row, &col, &time);
			if (time - curTime >= 5)
				rotate(goods);
			curTime = time;
			if (buy(row, col, goods) == -1) return -1;
		}
		rotate(goods);
		return rotateTime;
	} 
};
int main(){
	vector<string> prices, purchases;
	/*prices.push_back ("100 200 300 400 500 600");
	purchases.push_back("0,2:0");
	purchases.push_back("0,3:5");
	purchases.push_back("0,1:10");
	purchases.push_back("0,4:15");*/
	prices.push_back ("100 100 100");
	purchases.push_back("0,0:0");
	purchases.push_back("0,2:5");
	purchases.push_back("0,1:10");
	VendingMachine vm;
	cout<< vm.motorUse (prices, purchases)<< endl;
}
