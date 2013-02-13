#include <vector>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>

using namespace std;
vector<vector<int> > results;

class Solution {
    public:
        vector<vector<int> > combinationSum2(vector<int> &num, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort (num.begin(), num.end());
            vector<vector<int> > results(0);
            addOneBit(num, target, results);
            return results;
        }
        void addOneBit (vector<int> &num, int target, vector<vector<int> > & results){
            if (target == 0){
                vector<int> empty;
                results.push_back(empty);
                return;
            }else if (target < 0){
                return;
            }
            else if (num.size() <= 0){
                return;
            }
            if (accumulate(num.begin(), num.end(), 0) < target){
                return;
            }
            int ele = num.back();
            num.pop_back();
            int counter = 1;
            while (num.back() == ele){//eliminate dupes
                num.pop_back();
                counter++;
            }
            vector<vector<int> > temp(0);
            for (int i=0; i<=counter; ++i){
                addOneBit (num, target-i*ele, results);
                vector<int> tail(i,ele);
                for (int j=0; j<results.size(); ++j){
                    results[j].insert(results[j].end(), tail.begin(), tail.end());
                }
                temp.insert(temp.end(), results.begin(), results.end());
                results.clear();
            }
            results = temp;
            for (int i=1; i<=counter; ++i){
                num.push_back(ele);
            }
            return;
        }
};
void PrintVV(vector<vector<int> > & v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << i+1 << ":\t";
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << ',';
        cout << endl;
    }

    cout << endl;
}

int main(int argc, char** argv)
{
    int D[] = {1,1,1,5};
    int dTarget = 8;
    vector<int> Dv;
    for (int i = 0; i< sizeof(D)/sizeof(int); ++i)
        Dv.push_back(D[i]);

    Solution s;
    results = s.combinationSum2(Dv, dTarget);
    PrintVV(results);

    int A[] = {4,2,7,5,6};
    int aTarget = 16;
    vector<int> Av;
    for (int i = 0; i< sizeof(A)/sizeof(int); ++i)
        Av.push_back(A[i]);

    results = s.combinationSum2(Av, aTarget);
    PrintVV(results);

    //Second test stub
    int B[] = {
        28,22,43,41,21,29,27,38,47,23,20,49,24,31,37,26,32,36,25,33,40,46,30,44,35
    };
    int bTarget = 74;
    vector<int> Bv;
    for (int i = 0; i< sizeof(B)/sizeof(int); ++i)
        Bv.push_back(B[i]);
    //sort(Bv.begin(), Bv.end());

    results = s.combinationSum2(Bv, bTarget);    
    PrintVV(results);


    int C[] = {71,79,97,107,81,87,70,102,92,95,80,83,84,91,119,111,89,86,108,98,104,88,82,116,73,74,90,117,85,75,93,99,100,112,78,72,114,96};
    int cTarget = 362;
    vector<int> Cv;

    for (int i = 0; i< sizeof(C)/sizeof(int); ++i)
        Cv.push_back(C[i]);

    s.combinationSum2(Cv, cTarget);    
    PrintVV(results);



    return 0;
}
