// problem link:
// https://www.codingninjas.com/codestudio/problems/complete-string_2687860?topList=striver-sde-sheet-problems&leftPanelTab=0

// struct trie{
//     trie* links[26];
//     bool isEnd = false;
    
//     bool containsKey(char c){
//         return links[c - 'a'] != NULL;
//     }
    
//     void put(char c, trie* node){
//         links[c - 'a'] = node;
//     }
    
//     trie* get(char c){
//         return links[c - 'a'];
//     }
// };

struct trie{
    trie* links[26];
    bool isEnd = false;
    
    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }
    
    void put(char c, trie *node){
        links[c - 'a'] = node;
    }
    
    trie* next(char c){
        return links[c - 'a'];
    }
};

void insert(trie *root, string &s){
    for(char c : s){
        if(!root->containsKey(c))
            root->put(c, new trie());
        root = root->next(c);
    }
    root->isEnd = true;
}

bool canAns(trie *root, string &s){
    for(char c : s){
        root = root->next(c);
        if(root->isEnd == false) return false;
    }
    return true;
}

string completeString(int n, vector<string> &a){
    trie *root = new trie();
    for(string &s : a){
        insert(root, s);
    }
    
    string ans;
    for(string &s : a){
        if(canAns(root, s)){
            if(s.size() > ans.size())
                ans = s;
            else if(s.size() == ans.size())
                ans = min(ans, s);
        }
    }
    return ans.size() ? ans : "None";
    
//     trie* root = new trie();
//     string ans;
//     for(int i = 0; i < a.size(); i++){
//         bool present = true;
//         trie* temp = root;
//         for(int j = 0; j < a[i].size(); j++){
//             if(!temp->containsKey(a[i][j]))
//                 temp->put(a[i][j], new trie());
//             temp = temp->get(a[i][j]);    
//         }
//         temp->isEnd = true;
//     }
//     for(int i = 0; i < a.size(); i++){
//         bool present = true;
//         trie* temp = root;
//         for(char c : a[i]){
//             if(!temp->containsKey(c)){
//                 present = false;
//                 break;
//             }
//             temp = temp->get(c);
//             if(temp->isEnd == false) {
//                 present = false;
//                 break;
//             }
//         }
//         if(present and ans.size() < a[i].size()) ans = a[i];
//         else if(present and ans.size() == a[i].size()) ans = min(ans, a[i]);
//     }
    
//     return ans.size() ? ans : "None";
}