class Solution {
  public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
      vector<vector<string> > results;
      vector <string>  frontier;     
      unordered_map <string, vector<string> > visited;//word and where it comes from: cog,[dog,log]
      frontier.push_back (start);       
      visited[start] = vector<string> (0);
      do{ 
        unordered_set <string>  new_frontier;        
        for (int i=0; i<frontier.size(); ++i){
          string word = frontier[i];
          for (int j=0; j<word.size(); ++j){
            for (char k='a'; k<='z'; ++k){
              string new_word = word;
              new_word[j] = k;
              if (dict.find(new_word) == dict.end() ) continue;
              if (new_word == end){
                new_frontier.insert(new_word);
                visited[end].push_back(word);   
                continue;
              }
              if ( visited.find(new_word) == visited.end() || new_frontier.find(new_word) != new_frontier.end() ){
                if  (visited.find(new_word) == visited.end()){
                  new_frontier.insert(new_word);
                }
                visited[new_word].push_back(word);
              }   
            }   
          }   
        }   
        frontier.clear();
        for (auto& x:new_frontier){
          frontier.push_back(x);
        }
      }while (!frontier.empty() && visited.find(end)==visited.end());
      if (frontier.empty()) return results;
      results.push_back( vector<string> (1, end) );
      do{
        vector< vector<string> > new_results;
        if (results[0][0] == start) break;
        for (int i=0; i<results.size(); ++i){
          vector<string> path = results[i];
          vector<string> neighbors = visited[path[0]];
          for (int j=0; j<neighbors.size(); ++j){
            vector<string> new_path = path;
            new_path.insert(new_path.begin(), neighbors[j]);
            new_results.push_back(new_path);
          }
        }
        results = new_results;
      }while (true);
      return results;
    }   
};
