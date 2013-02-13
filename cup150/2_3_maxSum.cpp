#include <iostream>

using namespace std;

int main(){
	int a[] = {6,2,-3,-1,5,7};
	int maxsum = 0;
	int sum = 0;
	for (int i = 0; i < 6; i++){
		sum += a[i];
		if (maxsum < sum)
			maxsum = sum;
		else if (sum < 0)
			sum = 0;
	}
	cout<< maxsum<< endl;
}
