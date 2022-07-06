// problem link:
// https://www.codingninjas.com/codestudio/problems/chess-tournament_981299?topList=striver-sde-sheet-problems&leftPanelTab=0

bool canAllocate(int mid, int n, int c, vector<int> &pos){
    int posi = 0;
    for(int i = 2; i <= c; i++){
        int next = lower_bound(pos.begin(), pos.end(), pos[posi] + mid) - pos.begin();
        if(next == n) return false;
        posi = next;
    }
    return true;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());
    int l = 0, h = positions.back() - positions[0], mid, ans = -1;
    while(l <= h){
        mid = (l + h) >> 1;
        if(canAllocate(mid, n, c, positions)){
            ans = mid;
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    return ans;
}