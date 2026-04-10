class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto x:tokens)
        {
            if(x=="+")
            {
                int a1=st.top();
                st.pop();
                int a2=st.top();
                st.pop();
                st.push(a1+a2);
            }
            else if(x=="-")
            {
                int a1=st.top();
                st.pop();
                int a2=st.top();
                st.pop();
                st.push(a2-a1);

            }else if(x=="/")
            {
                int a1=st.top();
                st.pop();
                int a2=st.top();
                st.pop();
                st.push(a2/a1);
                
            }else if(x=="*")
            {
                int a1=st.top();
                st.pop();
                int a2=st.top();
                st.pop();
                st.push(a1*a2);

            }else
            {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};