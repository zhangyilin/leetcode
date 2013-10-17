class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //swap first
        if (n<=0){
            return 1;
        }
        for (int i=0; i<n; ++i){
            int a = A[i];
            while (1<=a && a<=n && a!=A[a-1]){
                swap (A[i], A[a-1]);
                a = A[i];
            }
        }
        for (int i=0; i<n; ++i){
            if (A[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
