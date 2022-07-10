// problem link:
// https://www.codingninjas.com/codestudio/problems/median-of-two-sorted-arrays_985294?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

double median(vector<int> nums1, vector<int> nums2)
{
    int n = nums1.size(), m = nums2.size();
        if(n > m)
            return median(nums2, nums1);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int totM = (m + n + 1) / 2;
        int tot = n + m;
        if(n == 0)
            return tot & 1 ? nums2[totM - 1] : (nums2[totM - 1] + nums2[totM]) / 2.0;
        int l = 0, h = n - 1, mid;
        while(l <= h){
            mid = (l + h) >> 1;
            int req = totM - 1 - mid;
            if(req < 0){
                h = mid - 1;
                continue;
            }
            if(req == 0){
                if(nums1[mid] <= nums2[0]){
                    if(tot & 1)
                        return nums1[mid];
                    return (nums1[mid] + min(nums1[mid + 1], nums2[0])) / 2.0;
                }
                h = mid - 1;
                continue;
            }
            if(nums1[mid] <= nums2[req] and nums2[req - 1] <= nums1[mid + 1]){
                if(tot & 1)
                    return max(nums1[mid], nums2[req - 1]);
                return (max(nums1[mid], nums2[req - 1]) + min(nums1[mid + 1], nums2[req])) / 2.0;
            }
            if(nums1[mid] > nums2[req])
                h = mid - 1;
            else 
                l = mid + 1;
        }
        return tot & 1 ? nums2[totM - 1] : (nums2[totM - 1] + min(nums1[0], nums2[totM])) / 2.0;
}
