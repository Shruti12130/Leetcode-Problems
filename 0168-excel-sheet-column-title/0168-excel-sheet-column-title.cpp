class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        
        while(columnNumber) {
            char c=(columnNumber%26)+'A'-1;
            if(columnNumber%26==0) {
                c='Z';
                columnNumber--;
            }
            ans+=c;           
            columnNumber/=26;
        }
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};