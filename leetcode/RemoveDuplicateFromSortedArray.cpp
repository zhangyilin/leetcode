class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int new_p = 0, old_p = 0;
        int counter = 0;
        int old_value = 0;
        for (int old_p=0; old_p<n; ++old_p){
            if (old_p==0 || old_value!=A[old_p]){
                old_value = A[old_p];
                counter = 1;
                A[new_p] = A[old_p];
                ++new_p;
            }else{
                ++counter;
            }
        }
        return new_p;
    }
};
