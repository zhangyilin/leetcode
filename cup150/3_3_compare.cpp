#include <iostream>
using namespace std;

int findmax (int a, int b){
	int c = a - b;
	int k = (c >> 31) & 0x1;
	int r = a + (b-a) * k;
	return r;
}

int main(){
	cout<< findmax(5,8)<< endl;
}
