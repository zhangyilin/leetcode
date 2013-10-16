class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool is_neg = false;
        if (n<0){
            is_neg = true;
            n = -1*n;
        }
        double result;
        if (n==0){   
            result = 1;
        }else if (n==1){
            result = x;
        }else if (n%2 == 1){
            double temp = pow(x, n/2);
            result = temp*temp*x;
        }else{
            double temp = pow(x, n/2);
            result = temp*temp;
        }
        if (is_neg){
            result = 1.0/result;
        }
        return result;
    }
};
