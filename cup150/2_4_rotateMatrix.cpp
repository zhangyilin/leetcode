#include <iostream>

using namespace std;

void rotate (int **matrix, int n){
	int layer = 1;
	while (layer <= n/2){
		int ind = layer;
		while ( ind < n - ind){
			swap (matrix[layer - 1][ind - 1], matrix[layer + ind - 2][n - layer]);
		}
	}
}

int main(){
	int a[] = {3,11};
	cout<< sizeof (a);
}
