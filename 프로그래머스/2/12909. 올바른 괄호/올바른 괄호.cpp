#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for(auto c : s)
    {
        if(st.empty())
        {
            st.push(c);
            continue;
        }
        
        if(c == ')' && st.top() == '(')
        {
            st.pop();
            continue;
        }
        
        st.push(c);
        
    }
    answer = st.empty();
    return answer;
    
    
}