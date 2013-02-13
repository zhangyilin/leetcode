#include <iostream>

void print(){
	string L[k];
	int line = 0;
	bool full = false
	while (file.good()){
		getline (file, L[line]) ;
		if (line == k -1){
			full = true;
			line = 0;
		}
		else
			line++;
	}
	if (!full){
		for (int i = 0; i < line; i++)
			cout<< L[i];
	}
	else{
		for (int i = 0; i < k; i++){
			if (line + i >= k)
				cout<< L[line + i - k];
			else
				cout<< L[line + i];
		}
	}
}
