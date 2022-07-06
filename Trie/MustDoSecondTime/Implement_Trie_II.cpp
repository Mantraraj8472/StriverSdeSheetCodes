// problem link:
// https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>

// struct TrieNode{
//     TrieNode* links[26];
//     int endCt = 0;
//     int preCt = 0;
    
//     bool containsKey(char c){
//         return links[c - 'a'] != NULL;
//     }
    
//     void put(char c, TrieNode* node){
//         links[c - 'a'] = node;
//     }
    
//     void increasePre(){
//         preCt++;
//     }
    
//     void increaseEnd(){
//         endCt++;
//     }
    
//     TrieNode* get(char c){
//         return links[c - 'a'];
//     }
// };

struct Node{
    Node *links[26];
    int endCt = 0;
    int preCt = 0;
    
    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }
    
    void put(char c, Node *node){
        links[c - 'a'] = node;
    }
    
    Node* next(char c){
        return links[c - 'a'];
    }
};

class Trie{
    
    private:
    Node *root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *temp = root;
        for(char c : word){
            if(!temp->containsKey(c))
                temp->put(c, new Node());
            temp = temp->next(c);
            temp->preCt++;
        }
        temp->endCt++;
    }

    int countWordsEqualTo(string &word){
        Node *temp = root;
        for(char c : word){
            if(!temp->containsKey(c))
                return 0;
            temp = temp->next(c);
        }
        return temp ? temp->endCt : 0;
    }

    int countWordsStartingWith(string &word){
        Node *temp = root;
        for(char c : word){
            if(!temp->containsKey(c))
                return 0;
            temp = temp->next(c);
        }
        return temp ? temp->preCt : 0;
    }

    void erase(string &word){
        Node *temp = root;
        for(char c : word){
            temp = temp->next(c);
            temp->preCt--;
        }
        temp->endCt--;
    }
//     private:
//     TrieNode* root;
//     public:

//     Trie(){
//         root = new TrieNode();
//     }

//     void insert(string &word){
//         TrieNode* cur = root;
//         for(int i = 0; i < word.size(); i++){
//             if(!cur->containsKey(word[i]))
//                 cur->put(word[i], new TrieNode());
//             cur = cur->get(word[i]);
//             cur->increasePre();
//         }
//         cur->increaseEnd();
//     }

//     int countWordsEqualTo(string &word){
//         TrieNode* cur = root;
//         for(int i = 0; i < word.size() and cur; i++){
//             if(!cur->containsKey(word[i])) 
//                 return 0;
//             cur = cur->get(word[i]);
//         }
//         return cur ? cur->endCt : 0;
//     }

//     int countWordsStartingWith(string &word){
//         TrieNode* cur = root;
//         for(int i = 0; i < word.size() and cur; i++){
//             if(!cur->containsKey(word[i])) 
//                 return 0;
//             cur = cur->get(word[i]);
//         }
//         return cur ? cur->preCt : 0;
//     }
   
//     void erase(string &word){
//         TrieNode* cur = root;
//         for(int i = 0; i < word.size(); i++){
//             cur = cur->get(word[i]);
//             cur->preCt--;
//         }
//         cur->endCt--;
//     }
};


// #include <bits/stdc++.h>

// struct TrieNode{
//     vector<pair<TrieNode *, int>> links_ct;
//     bool isEndOfWord;

//     TrieNode(){
//         links_ct.resize(26, {NULL, 0});
//         isEndOfWord = false;
//     }
    
//     bool containsKey(char c){
//         return links_ct[c - 'a'].first != NULL and links_ct[c - 'a'].second > 0;
//     }
    
//     void put(char c, TrieNode* node){
//         links_ct[c - 'a'].first = node;
//         links_ct[c - 'a'].second++;
//     }
    
//     TrieNode* get(char c){
//         return links_ct[c - 'a'].first;
//     }
// };

// class Trie{
//     private:
//     TrieNode* root;
//     public:

//     Trie(){
//         root = new TrieNode();
//     }

//     void insert(string &word){
//         TrieNode* cur = root;
//         for(int i = 0; i < word.size(); i++){
//             if(cur->containsKey(word[i]))
//                 cur->links_ct[word[i] - 'a'].second++;
//             else
//                 cur->put(word[i], new TrieNode());
//             cur = cur->get(word[i]);
//         }
//         cur->isEndOfWord = true;
//     }

//     int countWordsEqualTo(string &word){
//         TrieNode* cur = root;
//         int ans = 0;
//         for(int i = 0; i < word.size() and cur; i++){
//             if(!cur->containsKey(word[i])) return 0;
//             ans = cur->links_ct[word[i] - 'a'].second;
//             cur = cur->get(word[i]);
//         }
//         return cur and cur->isEndOfWord ? ans : 0;
//     }

//     int countWordsStartingWith(string &word){
//         TrieNode* cur = root;
//         int ans = 0;
//         for(int i = 0; i < word.size() and cur; i++){
//             if(!cur->containsKey(word[i])) return 0;
//             ans = cur->links_ct[word[i] - 'a'].second;
//             cur = cur->get(word[i]);
//         }
//         return cur ? ans : 0;
//     }
   
//     void erase(string &word){
//         TrieNode* cur = root;
//         for(int i = 0; i < word.size(); i++){
//             cur->links_ct[word[i] - 'a'].second--;
//             cur = cur->get(word[i]);
//         }
//         cur->isEndOfWord = false;
//     }
// };
