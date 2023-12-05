class Solution {
public:
    string largestGoodInteger(string num) {
        int c=1;
        char ch=num[0];
        string ans="";
        for(int i=1;i<num.size();i++) {
            if(num[i]==ch) {
                c++;
                if(c>=3) {
                    if(ans.empty() || num[i]>ans[0]) {
                        ans.clear();
                        for(int j=1;j<=3;j++)  
                            ans+=ch;
                    } 
                }
            } else {
                c=1;
                ch=num[i];
            }
        }
        return ans;
    }
};