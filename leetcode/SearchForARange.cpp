class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        if (n==0){
            return result;
        }
        int middle = A[n/2];
        if (middle==target){
            vector<int> left = searchRange(A, n/2, target);
            result[0] = left[0]==-1?n/2:left[0];
            vector<int> right = searchRange(A+n/2+1, n-n/2-1, target);
            result[1] = right[1]==-1? n/2: n/2+1+right[1];
        }else if (middle>target){
            result = searchRange(A, n/2, target);
        }else if (middle<target){
            vector<int> right = searchRange(A+n/2+1, n-n/2-1, target);
            result[0] = right[0]==-1?-1:right[0] + n/2 + 1;
            result[1] = right[0]==-1?-1:right[1] + n/2 + 1;
        }
        return result;
    }
};
