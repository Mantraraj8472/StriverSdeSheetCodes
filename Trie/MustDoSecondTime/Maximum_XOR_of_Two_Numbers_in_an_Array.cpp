// problem link:
// https://www.codingninjas.com/codestudio/problems/maximum-xor_3119012?topList=striver-sde-sheet-problems&leftPanelTab=0

struct trie{
    trie *links[2]; 
    
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    
    void put(int bit, trie *node){
        links[bit] = node;
    }
    
    trie* next(int bit){
        return links[bit];
    }
};

int maximumXor(vector<int> A)
{
    int n = A.size();
    trie *root = new trie();
    for(int ele : A){
        trie *temp = root;
        for(int i = 30; i >= 0; i--){
            int bit = (ele >> i) & 1;
            if(!temp->containsKey(bit))
                temp->put(bit, new trie());
            temp = temp->next(bit);
        }
    }
    int ans = 0;
    for(int ele : A){
        trie *temp = root;
        int tempAns = 0;
        for(int i = 30; i >= 0; i--){
            int bit = (ele >> i) & 1;
            if(temp->containsKey(bit ^ 1)){
                tempAns |= (1 << i);
                temp = temp->next(bit ^ 1);
            }
            else 
                temp = temp->next(bit);
        }
        ans = max(ans, tempAns);
    }
    return ans;
}