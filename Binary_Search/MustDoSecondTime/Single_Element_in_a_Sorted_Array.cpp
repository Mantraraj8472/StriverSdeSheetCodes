// problem link:
// https://www.codingninjas.com/codestudio/problems/unique-element-in-sorted-array_1112654?topList=striver-sde-sheet-problems&leftPanelTab=0

int uniqueElement(vector<int> arr, int n)
{
// 	for(int i = 0; i < n; i += 2){
//         if(arr[i] != arr[i + 1]) return arr[i];
//     }
    
    // Another same time and space complexity method is xor
//     int xorArr = 0;
//     for(int i = 0; i < n; i++)
//         xorArr ^= arr[i];
//     return xorArr;
    
    // Another O(LogN) time complexity method
    int l = 0, h = n - 2, mid;
    while(l <= h){
        mid = (l + h) >> 1;
        if(arr[mid] != arr[mid - 1] and arr[mid] != arr[mid + 1])
            return arr[mid];
        if(arr[mid] == arr[mid - 1]){
            if(mid & 1) 
                l = mid + 1;
            else 
                h = mid - 1;
        }
        else{
            if(mid & 1) 
                h = mid - 1;
            else 
                l = mid + 1;
        }
    }
    return arr[n - 1];
}
