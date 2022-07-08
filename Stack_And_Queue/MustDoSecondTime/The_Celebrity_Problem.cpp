// problem link:
// https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&leftPanelTab=0

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
    int cele = 0;
    while(cele < n){
        int next = cele + 1;
        while(next < n and knows(next, cele))
            next++;
        if(next == n) 
            break;
        else 
            cele = next;
    }
    for(int i = 0; i < cele; i++){
        if(i != cele and knows(i, cele) == false)
            return -1;
    }
    for(int i = 0; i < n; i++){
        if(i != cele)
            if(knows(cele, i))
                return -1;
    }
    return cele;
}