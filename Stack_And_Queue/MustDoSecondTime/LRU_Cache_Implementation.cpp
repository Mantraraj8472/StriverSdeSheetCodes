// problem link:
// https://www.codingninjas.com/codestudio/problems/lru-cache-implementation_670276?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

struct Node{
    int key;
    int val;
    Node *prev;
    Node *next;
};

class LRUCache
{
private:
    int cap;
    Node *head = NULL, *tail = NULL;
    unordered_map<int, Node*> hsh;
    
public:
    void del(int key){
        Node *toDel = hsh[key];
        hsh.erase(key);
        if(toDel == head){
            if(head == tail){
                head = NULL;
                tail = NULL;
                delete(toDel);
                return;
            }
            head = head->next;
            head->prev = NULL;
            toDel->next = NULL;
            delete(toDel);
            return;
        }
        if(toDel == tail){
            tail = tail->prev;
            tail->next = NULL;
            toDel->prev = NULL;
            delete(toDel);
            return;
        }
        toDel->next->prev = toDel->prev;
        toDel->prev->next = toDel->next;
        toDel->next = toDel->prev = NULL;
        delete(toDel);
    }
    
    void add(int key, int val){
        Node *toIns = (Node*)malloc(sizeof(Node));
        hsh[key] = toIns;
        toIns->key = key;
        toIns->val = val;
        toIns->next = head;
        toIns->prev = NULL;
        if(head == NULL){
            head = tail = toIns;
            return;
        }
        head->prev = toIns;
        head = toIns;
    }
    
    LRUCache(int capacity)
    {
        cap = capacity;
        while(head){
            Node *temp = head;
            head = head->next;
            temp->prev = NULL;
            temp->next = NULL;
            delete(temp);
        }
        tail = NULL;
        hsh.clear();
    }

    int get(int key)
    {
        if(hsh.find(key) == hsh.end())
            return -1;
        int ans = hsh[key]->val;
        del(key);
        add(key, ans);
        return ans;
    }

    void put(int key, int value)
    {
        if(hsh.find(key) == hsh.end()){
            if(cap == 0){
                del(tail->key);
                add(key, value);
            }
            else{
                cap--;
                add(key, value);
            }
        }
        else{
            del(key);
            add(key, value);
        }
    }
};
