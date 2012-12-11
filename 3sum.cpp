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
