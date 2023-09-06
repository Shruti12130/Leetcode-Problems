class Solution {
public:
    vector<string> ans;
    int n;
    
    bool isValidNumber(string s) {
        if(s.length()>1 && s[0]=='0') {
            return 0;
        }
        int num=0, n=s.length(), c=0;
        for(int i=n-1;i>=0;i--) {
            int k=s[i]-'0';
            num+=(k*pow(10, c));
            c++;
        }
        return (num>=0 && num<=255);
    }
    
    void solve(int i, int parts, string str, string &s) {
        if(parts==4 && i==n) {
            str.pop_back();
            ans.push_back(str);
            return;
        }
        
        for(int c=1;c<=3 && i<n;c++) {
            string x=s.substr(i, min(c, n-i)); 
            if(isValidNumber(x)) {
                solve(i+c, parts+1, str+x+".", s);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        n=s.length();
        if(n>=13){
            return ans;
        }
        solve(0, 0, "", s);
        return ans;
    }
};