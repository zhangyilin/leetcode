class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if (n3!=n1+n2)  return false;
        int i1=0, i2=0, i3=0;
        while (i3 < n3){
            if (i1==n1 && i2==n2)   break;
            if (i1<n1 && i2<n2 && s3[i3]==s1[i1] && s3[i3]==s2[i2]){
                return isInterleave (s1.substr(i1+1), s2.substr(i2), s3.substr(i3+1)) 
                || isInterleave(s1.substr(i1), s2.substr(i2+1), s3.substr(i3+1));
            }else if (i1<n1 && s3[i3]==s1[i1]){
                i1++;
                i3++;
            }else if (i2<n2 && s3[i3]==s2[i2]){
                i2++;
                i3++;
            }else{
                break;
            }
        }
        if (i1==n1 && i2==n2 && i3==n3) return true;
        else return false;
    }
};
