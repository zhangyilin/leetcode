class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unordered_map<int,int> h_to_t;
        unordered_map<int,int> t_to_h;
        unordered_set<int> visited;
        for (int i=0; i<num.size(); ++i){
            int cur = num[i];
            if (visited.find(cur)!=visited.end())   continue;
            else    visited.insert(cur);
            if (h_to_t.find(cur)==h_to_t.end())
                h_to_t[cur] = cur;
            if (t_to_h.find(cur)==t_to_h.end())
                t_to_h[cur] = cur;

            if (h_to_t.find(cur+1)!=h_to_t.end()){
                t_to_h[h_to_t[cur+1]] = cur;
                h_to_t[cur] = h_to_t[cur+1];
                h_to_t.erase(cur+1);
                t_to_h.erase(cur);
            }
            if (t_to_h.find(cur-1)!=t_to_h.end()){
                h_to_t[t_to_h[cur-1]] = h_to_t[cur];
                t_to_h[h_to_t[cur]] = t_to_h[cur-1];
                t_to_h.erase(cur-1);
                h_to_t.erase(cur);
            }
            
        }
        int max_con = 0;
        for (unordered_map<int,int>::iterator it=h_to_t.begin(); it!=h_to_t.end(); ++it){
            max_con = max(max_con, it->second - it->first + 1);
        }
        return max_con;
    }
};
