class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.length();
        int alice=0, bob=0;
        char prev=colors[0];
        for(int i=1;i<n-1;i++) {
            if(i+1>=n) {
                break;
            }
            char next=colors[i+1];
            if(prev==colors[i] && colors[i]==next) {
                (colors[i]=='A') ? alice++ : bob++;
            } else {
                prev=colors[i];
            }
        }
        return (alice > bob);
    }
};