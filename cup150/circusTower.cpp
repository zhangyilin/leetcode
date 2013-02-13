#include <iostream>

using namespace std;
#define NUM 6
class man{
	int ht;
	int wt;
	public:
		man(int ht = 0, int wt = 0):ht(ht),wt(wt){}
};

void longestTower (man * circus, int size){
	
}


int main(){
	man * circus = new man[NUM];
	circus[0] =  man(65, 100);
	circus[1] = man(70, 150);
	circus[2] = man(56, 90);
	circus[3] = man(75, 190);
	circus[4] = man(60, 95);
	circus[5] = man(68, 110);
}
