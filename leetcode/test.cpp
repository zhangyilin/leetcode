#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> a(2,5);
    vector<int> b(a.begin(), a.begin()+1);
    cout << b.size()<< endl;
    vector<int> c(a.begin(), a.end()-1);
    cout << c.size()<< endl;
}
