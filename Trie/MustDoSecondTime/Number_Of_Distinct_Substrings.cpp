// problem link:
// https://www.codingninjas.com/codestudio/problems/number-of-distinct-substring_1465938?topList=striver-sde-sheet-problems&leftPanelTab=0

struct trie{
    trie *links[26];
    bool isEnd = false;
    
    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }
    
    void put(char c, trie *node){
        links[c - 'a'] = node;
    }
    
    trie *next(char c){
        return links[c - 'a'];
    }
};

int distinctSubstring(string &word) {
    int n = word.size(), ans = 0;
    trie *root = new trie();
    for(int i = 0; i < n; i++){
        trie *temp = root;
        for(int j = i; j < n; j++){
            if(!temp->containsKey(word[j]))
                temp->put(word[j], new trie());
            temp = temp->next(word[j]);
            if(temp->isEnd == false){
                ans++;
                temp->isEnd = true;
            } 
        }
    }
    return ans;
}
