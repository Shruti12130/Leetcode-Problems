class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int c=0;
        unordered_map<string, int> mp;
        for(int i=0;i<arr.size();i++) {
            mp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++) {
            if(mp[arr[i]]==1) {
                c++;
            }
            if(c==k) {
                return arr[i];
            }
        }
        return "";
    }
};