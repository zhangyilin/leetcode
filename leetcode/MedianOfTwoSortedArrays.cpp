class Solution {
public:
    double median(int A[], int m){
        if (m%2)    return A[m/2];
        else    return 0.5*(A[m/2-1]+A[m/2]);
    }
    double median(int A[], int m, int val){//m>=2
        if (m%2){
            if (val<A[m/2]) return 0.5*(max(A[m/2-1],val) + A[m/2]);
            else if (val==A[m/2])   return val;
            else    return 0.5*(min(A[m/2+1],val)+ A[m/2]);
        }else{
            if (val < A[m/2-1])     return A[m/2-1];
            else if (val > A[m/2])     return A[m/2];
            else    return val;
        }
    }
    double median(int A[], int m, int small, int big){//m>=3
        if (m%2){
            if (big<=A[m/2])    return max(big, A[m/2-1]);
            else if (small>=A[m/2]) return min(A[m/2+1], small);
            else return A[m/2];
        }else{
            if (big<=A[m/2-1]){
                return 0.5*(A[m/2-1] + max(A[m/2-2],big));
            }else if (small>=A[m/2]){
                return 0.5*(A[m/2] + min(A[m/2+1],small));
            }else{
                if (big<=A[m/2] && small>=A[m/2-1]){
                    return 0.5*(small+big);
                }else if(big<=A[m/2]){
                    return 0.5*(A[m/2-1]+big);
                }else if(small>=A[m/2-1]){
                    return 0.5*(A[m/2]+small);
                }else{
                    return 0.5*(A[m/2-1]+A[m/2]);
                }
            }
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (m==0 && n==0)   return 0;
        if (m==0)   return median(B,n);
        if (n==0)   return median(A,m);
        if (m==1 && n==1)   return 0.5*(A[0]+B[0]);
        if (m==1)   return median (B,n, A[0]);
        if (n==1)   return median (A,m, B[0]);
        if (m==2 && n==2)    return 0.5*(max(A[0],B[0]) + min(A[1],B[1]));
        if (m==2)   return median (B,n, A[0], A[1]);
        if (n==2)   return median (A,m, B[0], B[1]);
        int a = A[m/2];
        int b = B[n/2];
        if (a <= b){
            int num_abandom = min (m%2==0?m/2-1:m/2, n-n/2-1);
            return findMedianSortedArrays(A+num_abandom, m-num_abandom, B, n-num_abandom);
        }else if (a>b){
            int num_abandom = min (m-m/2-1, n%2==0?n/2-1:n/2);
            return findMedianSortedArrays(A, m-num_abandom, B+num_abandom, n-num_abandom);
        }
    }
};
