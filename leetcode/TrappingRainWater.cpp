class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int water = 0;
        vector<int> left;
        for (int i=0; i<n; ++i){
            if (i==0)   left.push_back(i);
            else if (A[i] >= A[left.back()]){
                for (int j=left.back()+1; j<i; ++j){
                    water += A[left.back()]-A[j];
                }
                left.push_back(i);
            }
        }
        vector<int> right;
        for (int i=n-1; i>=0; --i){
            if (i<left.back())  break;
            if (i==n-1)   right.push_back(i);
            else if (A[i] >= A[right.back()]){
                for (int j=right.back()-1; j>i; --j){
                    water += A[right.back()]-A[j];
                }
                right.push_back(i);
            }
        }
        return water;
    }
};
