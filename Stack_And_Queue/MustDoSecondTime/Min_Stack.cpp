// problem link:
// https://www.codingninjas.com/codestudio/problems/min-stack_3843991?topList=striver-sde-sheet-problems&leftPanelTab=0

// Implement class for minStack.
class minStack
{
	private:
        stack<pair<int, int>> st;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			st = stack<pair<int, int>>();
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if(st.empty())
                st.push({num, num});
            else
                st.push({num, min(num, st.top().second)});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(st.empty())
                return -1;
            int ans = st.top().first;
			st.pop();
            return ans;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			return st.size() ? st.top().first : -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			return st.size() ? st.top().second : -1;
		}
};