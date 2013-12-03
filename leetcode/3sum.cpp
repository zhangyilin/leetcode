class Solution {
public:
    vector<int> combine(int s, int m, int l){
        vector<int> combine;
        combine.push_back(s);
        combine.push_back(m);
        combine.push_back(l);
        return combine;
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result(0);
        if (num.size()<3)    return result;
        sort (num.begin(), num.end());
        int cur = 0;
        for (int i=0; i<num.size(); ++i){
            if (i+3<num.size() && num[i+3]==num[i]) continue;
            num[cur++] = num[i];
        }
        num.resize(cur);
        for (int i=0; i<num.size(); ++i){
            if (i-1>=0 && num[i-1]==num[i]) continue;
            int j=i+1;
            int k=num.size()-1;
            while (j<k){
                if (num[i]+num[j]+num[k]==0){
                    result.push_back(combine(num[i],num[j],num[k]));
                    do{
                        ++j;
                    }while (j<=k && num[j-1]==num[j]);
                    do{
                        --k;
                    }while (j<=k && num[k+1]==num[k]);
                }else if (num[i]+num[j]+num[k]<0){
                    ++j;
                }else{
                    --k;
                }
            }
        }
        return result;
    }
};
/*
class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort(num.begin(),num.end());
            unordered_map<int,bool> m;
            for (size_t i=0; i<num.size(); ++i){
                m.insert (make_pair<int,bool>(num[i],true));
            }
            vector<vector<int> > solution_set;
            for (size_t i=0; i<num.size(); ++i){
                int number_1 = num[i];
                for (size_t j=i+1; j<num.size(); ++j){
                    int number_2 = num[j];
                    if (j+1 ==num.size()){//j is the last element
                        break;
                    }
                    if (0-number_1-number_2 < num[j+1]){
                        break;
                    }
                    if (m.find(0-number_1-number_2)!=m.end()){

                        vector<int> solution (3);
                        solution[0] = number_1;
                        solution[1] = number_2;
                        solution[2] = 0-number_1-number_2;
                        solution_set.push_back(solution);
                    }
                }

            }
            vector<vector<int> > unique_solution_set;
            for (size_t i = 0; i < solution_set.size(); ++i){
                vector<int> potential_solution = solution_set[i];
                bool flag = true;
                for (size_t j = 0; j < unique_solution_set.size(); ++j){
                    vector<int> verified_solution = unique_solution_set[j];
                    if (potential_solution[0] == verified_solution[0] &&
                            potential_solution[1] == verified_solution[1] &&
                            potential_solution[2] == verified_solution[2]){
                        flag = false;
                        break;
                    }
                }
                if (flag == true){
                    unique_solution_set.push_back(potential_solution);
                }
            }
            return unique_solution_set;
        }
};
*/
