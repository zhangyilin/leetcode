#include <iostream>
#include <map>
using namespace std;

void removeDup (char * str){
	char *cur = str;
	char *mov = str;
	map<char,bool> lup;
	while (*mov != '\0'){
		if (lup.find(*mov)== lup.end()){
			lup[*mov] = true;
			*cur = *mov;
			cur++;
		}
		mov ++;
	}
	*cur = '\0';
}

int main(){
	char * str = new char [10];

	strcpy (str,"abcd");
	removeDup(str);
	cout<< str<< endl;

	strcpy (str,"");
	removeDup(str);
	cout<< str<< endl;

	strcpy (str,"aaaa");
	removeDup(str);
	cout<< str<< endl;

	strcpy (str,"abababb");
	removeDup(str);
	cout<< str<< endl;

	strcpy (str,"aaabbcc");
	removeDup(str);
	cout<< str<< endl;
}
