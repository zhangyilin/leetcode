#include <vector>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>

using namespace std;
vector<vector<int> > results;

class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort (candidates.begin(), candidates.end());
            return subCombinationSum(candidates, target);
        }
        vector<vector<int> > subCombinationSum( vector<int> &candidates, int target) {
            vector<vector<int> > all_combs;
            if (target==0){
                vector<int> empty_sol;
                all_combs.push_back(empty_sol);
                return all_combs;
            }
            if (candidates.size() == 0){
                return all_combs;
            }
            int last_ele = candidates.back();       
            candidates.pop_back();

            int max_last_ele = target/last_ele;
            for (int i=0; i<=max_last_ele; ++i){
                vector<vector<int> > sub_combs =
                    subCombinationSum( candidates, target-i*last_ele);
                if (!sub_combs.empty()){
                    vector<int> tail(i, last_ele);
                    for (int j=0; j<sub_combs.size(); ++j){
                        vector<int> each_sub_comb = sub_combs[j];
                        each_sub_comb.insert(each_sub_comb.end(), 
                                tail.begin(), tail.end());
                        all_combs.push_back(each_sub_comb);
                    }
                }
            }
            candidates.push_back(last_ele);
            return all_combs;
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
    int D[] = {1};
    int dTarget = 1;
    vector<int> Dv;
    for (int i = 0; i< sizeof(D)/sizeof(int); ++i)
        Dv.push_back(D[i]);

    Solution s;
    results = s.combinationSum(Dv, dTarget);
    PrintVV(results);

    int A[] = {4,2,7,5,6};
    int aTarget = 16;
    vector<int> Av;
    for (int i = 0; i< sizeof(A)/sizeof(int); ++i)
        Av.push_back(A[i]);

    results = s.combinationSum(Av, aTarget);
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

    results = s.combinationSum(Bv, bTarget);    
    PrintVV(results);


    int C[] = {71,79,97,107,81,87,70,102,92,95,80,83,84,91,119,111,89,86,108,98,104,88,82,116,73,74,90,117,85,75,93,99,100,112,78,72,114,96};
    int cTarget = 362;
    vector<int> Cv;

    for (int i = 0; i< sizeof(C)/sizeof(int); ++i)
        Cv.push_back(C[i]);

    s.combinationSum(Cv, cTarget);    
    PrintVV(results);



    return 0;
}
