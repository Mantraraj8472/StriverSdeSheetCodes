#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
    // Here we can use the advantage of having range of numbers which is [1, n - 1] so we can use this array itself as hash array.
    // And we use hashing by adding n to the arr[ele] and if that arr[ele] > 2 * n means this is repeated.
	for(int i = 0; i < n; i++){
        int ele = arr[i] % n;
        arr[ele] += n;
        if(arr[ele] > 2 * n) return ele;
    }
    
    // Another approach is Floyd cycle detection algo for linked list
    int slow = arr[0], fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];   
    } while (slow != fast);
    slow = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;

    // Now what's the intuition? 
    /*
    As it is for sure that one elements is repeated, there exists a cycle.    
                        a5 -> a6
                       |       |
    a1 -> a2 -> a3 -> a4       a7 (meet point which is b dist)
                       |       |
                        a9 <- a8
    <-------a---------->
    a1 - a4 = a
    a4 - a7 = b
    a7 - a4 = c
    can we say that when slow reaches a4 fast is already in loop somewhere.
    Let say initial dist between them is x and after every iteration their distance increase by one x -> x + 1 -> x + 2 and finally they meet.
    Now tslow = tfast, where is number of iterations by fast in loop
    (a + b) / 1 = (a + n * (b + c) + b) / 2
    a = (n - 1) * (b + c) + c
    so we can say that a is integral multiple of length of circle plus c.
    So, by this we can say that when slow starts from starting position and covers distance of a by that time fast has also made some loops and extra distance of c so they both meet at starting position of cycle which is repeating element.
    */
}
