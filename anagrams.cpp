/*
   A trie structure is used to record every string.
   Each string is sorted. In the first mark loop, mark every string in trie and count the number at the ending node.
   In the second loop, output every string if counting node illustrates it is not the only one.
   */
class Solution {
    public:
        struct Node{
            int count;
            vector<Node*> children;
            Node (): count(0), children(26){
                for (size_t i=0; i<children.size(); ++i){
                    children[i] = NULL;
                }
            }
            int get_count (){return count;}
            void add_count () {count++;}
            Node * get_child (int i){
                return children[i];
            }
            void set_child (int i){
                Node * child = new Node;
                children[i] = child;
            }
        };
        vector<string> anagrams(vector<string> &strs) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            Node * root  = new Node;
            vector<string> anagrams;
            for (size_t i = 0; i < strs.size(); ++i){//First, mark
                string s = strs[i];
                string s_copy = s;
                sort (s_copy.begin(),s_copy.end());
                Node * current = root;
                for (size_t j = 0; j < s_copy.size(); ++j){
                    if (current->get_child (s_copy[j]-'a') == NULL){
                        current->set_child (s_copy[j]-'a');
                    }
                    current = current->get_child(s_copy[j]-'a');
                    if (j == s_copy.size()-1){//last character in the string s
                        current->add_count();
                    }
                }
            }
            for (size_t i = 0; i < strs.size(); ++i){
                string s = strs[i];
                string s_copy = s;
                sort (s_copy.begin(),s_copy.end());
                Node * current = root;
                for (size_t j = 0; j < s_copy.size(); ++j){
                    if (current->get_child (s_copy[j]-'a') == NULL){
                        break;
                    }
                    current = current->get_child(s_copy[j]-'a');
                    if (j == s_copy.size()-1){//last character in the string s
                        if (current->get_count() > 1){
                            anagrams.push_back(s);
                        }
                    }
                }
            }        
            return anagrams;
        }
};
