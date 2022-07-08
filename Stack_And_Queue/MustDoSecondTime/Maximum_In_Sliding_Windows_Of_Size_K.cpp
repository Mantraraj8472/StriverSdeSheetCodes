// problem link:
// https://www.codingninjas.com/codestudio/problems/sliding-window-maximum_980226?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    // This method will give TLE
//     multiset<int> st;
//     vector<int> ans;
//     int n = nums.size();
//     for(int i = 0; i < k; i++)
//         st.insert(nums[i]);
//     ans.push_back(*(--st.end()));
//     for(int i = k; i < n; i++){
//         st.erase(st.find(nums[i - k]));
//         st.insert(nums[i]);
//         ans.push_back(*(--st.end()));
//     }
//     return ans;
    
    // O(N) approach using deque
    deque<int> q;
    vector<int> ans;
    int n = nums.size();
    for(int i = 0; i < k; i++){
        if(q.empty())
            q.push_back(i);
        else{
            if(nums[i] > nums[q.front()]){
                q = deque<int>();
                q.push_back(i);
            }
            else{
                while(q.size() and nums[i] > nums[q.back()])
                    q.pop_back();
                q.push_back(i);
            }
        }
    }
    ans.push_back(nums[q.front()]);
    for(int i = k; i < n; i++){
        while(q.size() and q.front() <= i - k)
            q.pop_front();
        if(q.empty())
            q.push_back(i);
        else{
            if(nums[i] > nums[q.front()]){
                q = deque<int>();
                q.push_back(i);
            }
            else{
                while(q.size() and nums[i] > nums[q.back()])
                    q.pop_back();
                q.push_back(i);
            }
        }
        ans.push_back(nums[q.front()]);
    }
    return ans;
}