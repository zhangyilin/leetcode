/*------------------write simple one without consider duplicates-----*/
void PermutationWithDuplicateHash(char *str, int position){
    if (pos == str.size()){
        print(str);
        return;
    }
    unordered_set<char> us;
    for (int i = position; i < str.size(); i++){
        if (us.find(str[i]))
            continue;
        us.insert(str[i]);
        swap (str[position], str[i]);
        PermutationWithDuplicateHash(str, position+1);
        swap (str[position], str[i]);
    }
}
