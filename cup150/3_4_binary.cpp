#include <iostream>
#include <string>

using namespace std;

void print_int (int n) {
	int neg = 0;
	if (n<0){
		neg = 1;
		n *= -1;
	}
	else if (n==0){
		cout<< '0';	
		return;
	}

	char * p = new char [32] ;
	*(p + 31) = '\0';
	char * pc = p + 30;
	while (n){
		int k = n & 0x1;
		*pc = k + '0' ;
		pc --;
		n >>= 1;
	}
	pc ++;
	if (neg)
		cout<< '-';
	cout << pc;
	delete [] p;

}
int s_to_int(string str){
	int res = 0;
	int neg = 0;
	if (str[0] == '-')
	{
		neg = 1;
		str = str.substr(size_t(1), string::npos);
	}
	for (string::iterator i = str.begin(); i != str.end(); i++)
	{
		res *= 10;
		res += *i - '0';
	}
	if (neg)
		res *= -1;
	return res;
}
void print_binary_repr (string str){
	size_t decimal_pos = str.find('.');
	if (decimal_pos == string::npos){
		print_int(s_to_int(str));
	}
	else{
		string s1 = str.substr(size_t(0), decimal_pos - size_t(0));
		string s2 = str.substr(decimal_pos + 1, size_t(str.size()) - decimal_pos);
		print_int(s_to_int(s1));
		cout<< '.';
		print_int(s_to_int(s2));

	}
}

int main(){
	print_int(3);
	cout<< endl;

	print_int(0);
	cout<< endl;

	print_int(-123);
	cout<< endl;
	string s1 = "33.32";
	print_binary_repr(s1);
}
