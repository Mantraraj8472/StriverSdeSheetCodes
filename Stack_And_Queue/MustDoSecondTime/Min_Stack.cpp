// problem link:
// https://www.codingninjas.com/codestudio/problems/min-stack_3843991?topList=striver-sde-sheet-problems&leftPanelTab=0

// Implement class for minStack.
// class minStack
// {
// 	private:
//         stack<pair<int, int>> st;
	
// 	public:
		
// 		// Constructor
// 		minStack() 
// 		{ 
// 			st = stack<pair<int, int>>();
// 		}
		
// 		// Function to add another element equal to num at the top of stack.
// 		void push(int num)
// 		{
// 			if(st.empty())
//                 st.push({num, num});
//             else
//                 st.push({num, min(num, st.top().second)});
// 		}
		
// 		// Function to remove the top element of the stack.
// 		int pop()
// 		{
//             if(st.empty())
//                 return -1;
//             int ans = st.top().first;
// 			st.pop();
//             return ans;
// 		}
		
// 		// Function to return the top element of stack if it is present. Otherwise return -1.
// 		int top()
// 		{
// 			return st.size() ? st.top().first : -1;
// 		}
		
// 		// Function to return minimum element of stack if it is present. Otherwise return -1.
// 		int getMin()
// 		{
// 			return st.size() ? st.top().second : -1;
// 		}
// };

// Here instead of creating new stack we update the value of new smallest by:
// 2 * val - mini
// so this is always less than num and we check if number is smaller than mini then it must be updated and return mini in case of that number and how do we get old mini back?
// By the same equation: 2 * cur_mini - val 
// As 2 * val - mini = newVal and val is cur_mini
// So mini = 2 * cur_mini - newVal

class minStack
{
    private:
        stack<int> st;
        int mini;
    
    public:
        
        // Constructor
        minStack() 
        { 
            st = stack<int>();
            mini = 1e9 + 1;
        }
        
        // Function to add another element equal to num at the top of stack.
        void push(int num)
        {
            if(st.empty()){
                st.push(num);
                mini = num;
                return;
            }
            if(num >= mini){
                st.push(num);
                return;
            }
            st.push(2 * num - mini);
            mini = num;
        }
        
        // Function to remove the top element of the stack.
        int pop()
        {
            if(st.empty())
                return -1;
            int ans = st.top();
            if(st.top() >= mini){
                st.pop();
                return ans;
            }
            ans = mini;
            mini = 2 * mini - st.top();
            st.pop();
            return ans;
        }
        
        // Function to return the top element of stack if it is present. Otherwise return -1.
        int top()
        {
            if(st.empty())
                return -1;
            if(st.top() >= mini)
                return st.top();
            return mini;
        }
        
        // Function to return minimum element of stack if it is present. Otherwise return -1.
        int getMin()
        {
            return st.size() ? mini : -1;
        }
};