class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = gas.size();
        if (n == 0) return -1;
        
        vector<vector<int> > record(n, vector<int>(n,0));
        vector<int> new_v(n,0);
        set<int> remained;
        for (int i=0; i<n; ++i){
            remained.insert(i);
        }
        for (int i=0; i<n; ++i){
            new_v = vector<int>(n,0);
            for (int j=0; j<=i; ++j){
                new_v[j] = record[i][j]+gas[i]-cost[i];
                if (new_v[j] < 0){
                    remained.erase(j);
                }
            }
            if (i != n-1){
                record[i+1] = new_v;
            }
        }
        record[0] = new_v;
        for (int i=0; i<n-1; ++i){
            new_v = record[i+1];
            for (int j=i+1; j<n-1; ++j){
                new_v[j] = record[i][j]+gas[i]-cost[i];
                if (new_v[j] < 0){
                    remained.erase(j);
                }
            }
            record[i+1] = new_v;
        }
        if (remained.empty()){
            return -1;
        }
        return *remained.begin();
    }
};
