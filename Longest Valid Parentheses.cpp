#include<stack>
int longestValidParentheses(string s) {
    int n = s.size();
    stack<int> st;
    st.push(-1);
    int count = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            if(!st.empty()){
                count = max(count, i - st.top());
            }
            else{
                st.push(i);
            }
        }
    }
    return count;
    // Write your code here.
}
