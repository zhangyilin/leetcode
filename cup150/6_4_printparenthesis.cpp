#include <iostream>
using namespace std;

void printPar (int l, int r, char p[], int count){
	cout<< l<<r<<count<< " ";
	if (r<l || l<0 )
		return;
	if (l==0 && r==0){
		cout<< p<<endl;
		return;}
	p[count] = '(';
	printPar(l-1,r,p,count+1);
	p[count] = ')';
	printPar(l,r-1,p,count+1);
}
int main(){
	char str[9];
	str[4] = '\0';
	printPar (2,2,str, 0);
}

