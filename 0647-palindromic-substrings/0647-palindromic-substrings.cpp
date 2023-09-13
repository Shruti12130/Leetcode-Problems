class Solution {
public:
    bool check(int i, int j, string s){
        while(i<j) {
            if(s[i]!=s[j]) {
                return false;
            }
            i++;j--;
        }
        return true;
    }
    
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(j-i+1==1) {
                    ans++;
                } else {
                    ans+=check(i, j, s);
                }
            }
        }
        return ans;
    }
};