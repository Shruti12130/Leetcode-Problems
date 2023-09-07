class Solution {
public:
    bool nextPermutation(string &s) {
        int n=s.length();
        int i=n-2;
        while(i>=0 && s[i]>=s[i+1]) {
            i--;
        }
        if(i<0) {
            return 0;
        }
        int j=n-1;
        while(s[i] >= s[j]) {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin()+i+1, s.end());
        return 1;
    }
    
    int nextGreaterElement(int n) {
        string num = to_string(n);
        if(!nextPermutation(num)) {
            return -1;
        }
        
        auto l = stoll(num);  //converted string to long long
        return (l>INT_MAX || l<n) ? -1 : (int)l;
    }
};