class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort(num.begin(),num.end());

            vector<vector<int> > solution_set;
            for (size_t i=0; i<num.size(); ++i){
                int number_1 = num[i];
                if (i>0 && number_1==num[i-1]){
                    continue;
                }
                vector<int> solution(3);
                solution[0] = number_1;
                size_t j = i+1;
                size_t k = num.size()-1;
                while (j<k){
                    if (number_1+num[j]+num[k] == 0){
                        solution[1] = num[j];
                        solution[2] = num[k];
                        solution_set.push_back(solution);
                        while (j<num.size() && num[j]==solution[1]){
                            j++;
                        }
                        while (k>0 && num[k]==solution[2]){
                            k--;
                        }
                    }else if (number_1+num[j]+num[k] > 0){
                        k--;
                    }else{
                        j++;
                    }

                }
            }
            return solution_set;
        }
};
