#include <iostream>
#include <math.h>
using namespace std;

int Count2s(int number){
	if (number < 0) return -1;
	int digit = 0;
	int twos = 0;
	int currentdigit;
	int num = number;
	while (num){
		currentdigit = num % 10;
		if (digit > 0)
			twos += currentdigit * digit * pow (10, digit - 1); 
		if (currentdigit == 2){
			twos += number % ((int)pow (10, digit)) + 1;
		}
		else if (currentdigit > 2){
			twos += digit * pow(10, digit);
		}
		num = num/10 ;
		digit ++;
		cout << "num "<< num<< " digit "<< digit<< " twos "<< twos<< endl;
	}
	return twos;
}

int main (){
	cout << Count2s (100)<< endl;
	cout << Count2s (2)<< endl;
	cout << Count2s (1)<< endl;
	cout << Count2s (222)<< endl;
	cout << Count2s (422)<< endl;
}
