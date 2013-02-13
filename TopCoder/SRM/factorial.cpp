
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
unsigned long long C (int num, int l){
	unsigned long long rValue = 1;
	for (int i = num; i > num - l; i--){
		rValue *= i;
		rValue /= num-i+1;
	}
	return rValue;
}
int main(){
	cout<< 1- (double)(C(90,10)+10*C(90,9))/C(100,10)<< endl;
	cout<< (double)C(10,2)*C(98,8)/C(100,10)<<endl;

}
