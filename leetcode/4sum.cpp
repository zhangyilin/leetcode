class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = num.size();
            sort (num.begin(),num.end());
            vector<vector<int> > solutions;
            for (int i=0; i<n-3;){
                int number_1 = num[i];
                vector<int> solution(4);
                solution[0] = number_1;
                for (int j=i+1; j<n-2; ){
                    int number_2 = num[j];
                    solution[1] = number_2;
                    int k = j+1;
                    int l = n-1;
                    while (k<l){
                        int sum = number_1+number_2+num[k]+num[l];
                        if (sum == target){
                            solution[2] = num[k];
                            solution[3] = num[l];
                            solutions.push_back(solution);
                            while (k<n && num[k]==solution[2]){
                                k++;
                            }
                            while (l>0 && num[l]==solution[3]){
                                l--;
                            }
                        }else if (sum > target){
                            l--;
                        }else{
                            k++;
                        }
                    }
                    while (num[j] == solution[1]){
                        j++;
                    }
                }//end of j forloop
                while (num[i] == solution[0]){
                    i++;
                }
            }//end of outmost forloop
            return solutions;
        }//end of function
};
