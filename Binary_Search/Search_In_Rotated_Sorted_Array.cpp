// problem link:
// https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_630450?topList=striver-sde-sheet-problems&leftPanelTab=0

int search(int* arr, int n, int key) {
    int l = 0, h = n - 2, mid, indOfDec = -1;
    while(l <= h){
        mid = (l + h) >> 1;
        if(arr[mid] > arr[mid + 1]) {
            indOfDec = mid;
            break;
        }
        if(arr[mid] >= arr[0])
            l = mid + 1;
        else 
            h = mid - 1;
    }
    l = 0;
    h = n - 1;
    if(indOfDec != -1){
        if(key <= arr[indOfDec] and key >= arr[0]) h = indOfDec;
        else l = indOfDec + 1;
    }
    while(l <= h){
        mid = (l + h) >> 1;
        if(arr[mid] == key) return mid;
        if(arr[mid] < key) l = mid + 1;
        else h = mid - 1;
    }
    return -1;
}