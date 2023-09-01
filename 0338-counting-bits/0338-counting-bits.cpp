class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec(n);
        vec.push_back(0);
        
        if(n==0)
            return vec;
        
        for(int i=1;i<=n;i++){
            vec[i]=vec[i/2]+i%2;
        }
        return vec;
    }
};