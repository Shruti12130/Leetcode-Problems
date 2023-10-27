class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        int n=s.length(), m=t.length();
        int i=0;
        string a, b;
        while(i<n){
            if(s[i]!='#'){
                st.push(s[i]);
            } else {
                if(st.size()) {
                    st.pop();
                }
            }
            i++;
        }
        while(!st.empty()) {
            a+=st.top();
            st.pop();
        }
        i=0;
        while(i<m){
            if(t[i]!='#'){
                st.push(t[i]);
            } else {
                if(st.size()) {
                    st.pop();
                }
            }
            i++;
        }
        while(!st.empty()) {
            b+=st.top();
            st.pop();
        }
        return (a==b);
    }
};