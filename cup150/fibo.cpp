#include <iostream>
using namespace std;

int fibo(int n){
	if (n < 0) return -1;
	else if ( n == 0 ) return 0;
	else if ( n == 1 ) return 1;
	else{
		int fibo_n1 = 0;
		int fibo_n2 = 1;
		int i = 2;
		int fibo_n;
		while ( i <= n ){
			fibo_n = fibo_n1 + fibo_n2 ;
			i ++;
			fibo_n2 = fibo_n1;
			fibo_n1 = fibo_n;
		}
		return fibo_n;
	}
}

int main(){
	cout<< fibo(10)<< endl;
}
