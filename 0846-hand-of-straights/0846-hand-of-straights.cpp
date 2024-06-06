class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) {
            return false;
        }
        map<int, int> mp;
        // sort(hand.begin(), hand.end());
        int k=n/groupSize;
        for(auto h: hand) {
            mp[h]++;
        }
        bool f=1;
        for(int i=0;i<k;i++) {
            int c=groupSize-1;
            int x=(mp.begin())->first;//cout<<endl<<x<<" -> "<<mp[x]<<endl; 
            mp[x]--;
            if(mp[x]==0) {
                mp.erase(x);
            }
            while(c--) {
                //cout<<(x+1)<<" "<<mp[x+1]<<endl;
                if(mp.count(x+1)==0) {
                    f=0;
                    break;
                } else {
                    mp[++x]--;
                    if(mp[x]==0) {
                        mp.erase(x);
                    }
                }
            }
        }
        
        return f;
    }
};