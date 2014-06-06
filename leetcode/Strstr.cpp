class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = strlen(haystack);
        int n = strlen(needle);
        if (m < n)  return NULL;
        if (n==0)   return haystack;
        int left = 0, right = m-n;
        int i = left;
        while (i <= right){
            int p = 0;
            while (p<n){
                if (*(haystack+i+p) == *(needle+p)){
                    p++;
                }else{
                    i++;
                    break;
                }
            }
            if (p == n) return haystack+i;
        }
        return NULL;
    }
};
