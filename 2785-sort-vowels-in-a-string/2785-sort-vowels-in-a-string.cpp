class Solution {
public:
    
    bool isVowel(char ch) {
        bool a = (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
        bool b = (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
        return (a||b);
    }
    
    string sortVowels(string s) {
        int n = s.length();
        vector<int> temp;
        vector<char> vowels;
        
        for(int i=0;i<n;i++) {
            if(isVowel(s[i])) {
                vowels.push_back(s[i]);
                temp.push_back(i);
            } 
        }
        
        sort(vowels.begin(), vowels.end());
        int i=0, m=vowels.size();
        while(i<m) {
            s[temp[i]] = vowels[i];
            i++;
        }
        return s;
    }
};