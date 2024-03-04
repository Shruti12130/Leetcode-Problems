class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans=0, score=0, i=0, j=tokens.size()-1;
        sort(tokens.begin(), tokens.end());
        
        while(i<=j) {
            if(power>=tokens[i]) {
                power-=tokens[i++];
                score++;
                ans=max(ans, score);
            } else if(score) {
                power+=tokens[j--];
                score--;
            } else {
                break;
            }
        }
        return ans;
        
    }
};