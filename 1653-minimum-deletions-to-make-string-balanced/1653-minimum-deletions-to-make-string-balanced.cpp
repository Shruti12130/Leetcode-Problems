class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int> ca(n, 0), cb(n, 0);
        int a=0, b=0;
        
        for(int i=0;i<n;i++) {
            cb[i]=b;
            b+=(s[i]=='b');
        }
        
        for(int j=n-1;j>=0;j--) {
            ca[j]=a;
            a+=(s[j]=='a');
        }
        int ans=1e6;
        for(int i=0;i<n;i++) {
            ans=min(ans, ca[i]+cb[i]);
        }
        return ans;
    }
};