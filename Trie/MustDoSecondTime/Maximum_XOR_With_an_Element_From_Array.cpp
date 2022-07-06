// problem link:
// https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

struct trie{
    trie* links[2];
    
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    
    void put(int bit, trie* node){
        links[bit] = node;
    } 
    
    trie* get(int bit){
        return links[bit];
    }
};

// void insert(trie* root, int n){
//     for(int i = 30; i >= 0; --i){
//         int bit = (n >> i) & 1;
//         if(!root->containsKey(bit))
//             root->put(bit, new trie());
//         root = root->get(bit);
//     }
// }

void insert(trie *root, int n){
    for(int i = 30; i >= 0; i--){
        int bit = (n >> i) & 1;
        if(!root->containsKey(bit))
            root->put(bit, new trie());
        root = root->get(bit);
    }
}

// int getMaxXor(int n, trie* root){
//     int ans = 0;
//     for(int i = 30; i >= 0; --i){
//         int rbit = ((n >> i) & 1) ^ 1;
//         if(root->containsKey(rbit)){
//             ans |= (1 << i);
//             root = root->get(rbit);
//         }
//         else if(root->containsKey(rbit ^ 1))
//             root = root->get(rbit ^ 1);
//         else 
//             return -1;
//     }
//     return ans;
// }

int getMaxXor(trie *root, int n){
    int ans = 0;
    for(int i = 30; i >= 0; i--){
        int bit = (n >> i) & 1;
        if(root->containsKey(bit ^ 1)){
            ans |= (1 << i);
            root = root->get(bit ^ 1);
        }
        else if(root->containsKey(bit)) 
            root = root->get(bit);
        else
            return -1;
    }
    return ans;
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
// 	int n = arr.size();
//     int q = queries.size();
//     sort(arr.begin(), arr.end());
//     vector<pair<int, pair<int, int> > > v;
//     vector<int> ans(q);
//     for(int i = 0; i < q; i++){
//         v.push_back({queries[i][1], {queries[i][0], i}});
//     }
//     sort(v.begin(), v.end());
//     int ind = 0;
//     trie* root = new trie();
//     for(int i = 0; i < q; i++){
//         while(ind < n and arr[ind] <= v[i].first){
//             insert(root, arr[ind]);
//             ind++;
//         }
//         ans[v[i].second.second] = getMaxXor(v[i].second.first, root);
//     }
//     return ans;
    sort(arr.begin(), arr.end());
    vector<pair<int, pair<int, int> > > q;
    for(int i = 0; i < queries.size(); i++)
        q.push_back({queries[i][1], {queries[i][0], i}});
    sort(q.begin(), q.end());
    int ind = 0, n = arr.size();
    trie *root = new trie();
    vector<int> ans(queries.size());
    for(int i = 0; i < queries.size(); i++){
        while(ind < n and arr[ind] <= q[i].first){
            insert(root, arr[ind]);
            ind++;
        }
        ans[q[i].second.second] = getMaxXor(root, q[i].second.first);
    }
    return ans;
}