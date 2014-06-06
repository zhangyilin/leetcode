class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<int, int> visited;
        vector<int> two;
        for (int i=0; i<numbers.size(); ++i){
            int current = numbers[i];
            int remain = target-current;
            if (visited.find(remain) != visited.end()){
                two.push_back(visited[remain]+1);
                two.push_back(i+1);
                break;
            }else{
                visited[current] = i;
            }
        }
        return two;
    }
};
