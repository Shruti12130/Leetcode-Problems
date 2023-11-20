class Solution {
public:
    
    int getTime(int p, char ch, vector<string>& garbage, vector<int> & travel) {
        if(p==-1) {
            return 0;
        }
        int time=0;
        string str=garbage[0];
        for(char c: str) {
            if(ch==c) time++;
        }
        if(p==0) {
            return time;
        }
        int k=0, n=garbage.size();
        time+=travel[k++];
        for(int i=1;i<p; i++) {
            for(char c: garbage[i]) {
                if(c==ch) {
                    time++;
                }
            }
            time+=travel[k++];
        }
        str=garbage[p];
        for(char c: str) {
            if(c==ch) time++;
        }
        return time;
    }
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int m=-1, p=-1, g=-1;
        int ans=0;
        for(int i=0;i<garbage.size();i++) {
            for(char c: garbage[i]) {
                if(c=='M') {
                    m=i;
                } else if(c=='P') {
                    p=i;
                } else {
                    g=i;
                }
            }
        }
        
        ans+=getTime(m, 'M', garbage, travel)+getTime(p, 'P', garbage, travel)+
            getTime(g, 'G', garbage, travel);
        return ans;
    }
};