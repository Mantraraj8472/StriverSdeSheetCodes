// problem link:
// https://www.codingninjas.com/codestudio/problems/lfucache_3114758?topList=striver-sde-sheet-problems&leftPanelTab=0

// This question is very much similar to that of LRU
// But here in LFU, we have to remove LFU element and if tie we have to apply concept of LRU
// So we will be using DLL that is LRU for each frequency

#include <bits/stdc++.h>

struct Node{
    int key;
    int val;
    int fre;
    Node *prev = NULL;
    Node *next = NULL;
    
    Node(int key, int val, int fre){
        this->key = key;
        this->val = val;
        this->fre = fre;
    }
};

class LFUCache
{

private:
    map<int, pair<Node*, Node*> > hshFre;
    map<int, Node*> hshKey;
    int cap;
    
    void add(int key, int val, int fre){
        Node *head = NULL, *tail = NULL;
        if(hshFre.find(fre) != hshFre.end())
            head = hshFre[fre].first, tail = hshFre[fre].second;
        Node *toIns = new Node(key, val, fre);
        hshKey[key] = toIns;
        if(head == NULL){
            head = tail = toIns;
            if(hshFre.find(key) == hshFre.end())
            hshFre[key] = {head, tail};
            return;
        }
        head->prev = toIns;
        toIns->next = head;
        head = toIns;
        if(hshFre.find(key) == hshFre.end())
            hshFre[key] = {head, tail};
    }
    
    void remove(int key){
        Node *toRem = hshKey[key];
        int fre = toRem->fre;
        hshKey.erase(key);
        Node *head = hshFre[fre].first, *tail = hshFre[fre].second;
        if(toRem == head)
            head = head->next;
        if(toRem == tail)
            tail = tail->prev;
        if(toRem->prev)
            toRem->prev->next = toRem->next;
        if(toRem->next)
            toRem->next->prev = toRem->prev;
        toRem->prev = toRem->next = NULL;
        delete(toRem);
        if(head == NULL)
            hshFre.erase(key);
    }
    
public:
    LFUCache(int capacity)
    {
        hshFre.clear();
        hshKey.clear();
        cap = capacity;
    }

    int get(int key)
    {
        if(hshKey.find(key) == hshKey.end())
            return -1;
        int ans = hshKey[key]->val;
        int fre = hshKey[key]->fre;
        remove(key);
        add(key, ans, fre + 1);
        return ans;
    }

    void put(int key, int value)
    {
        if(hshKey.find(key) == hshKey.end()){
            if(cap == 0){
                remove((((*(hshFre.begin())).second).second)->key);
                add(key, value, 0);
            }
            else{
                cap--;
                add(key, value, 0);
            }
        }
        else{
            int fre = hshKey[key]->fre;
            remove(key);
            add(key, value, fre + 1);
        }
    }
};
