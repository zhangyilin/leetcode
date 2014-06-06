class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        vector<int> prev (1, 1);
        for (int row=1; row<=rowIndex; ++row){
            vector<int> current(row+1, 1);
            for (int i=0; i<prev.size()-1; ++i){
                current[i+1] = prev[i]+prev[i+1];
            }
            prev = current;
        }
        return prev;
    }
};
