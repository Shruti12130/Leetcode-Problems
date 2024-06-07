class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        stringstream stream(sentence);
        string word;
        char delimiter = ' ';
        string ans;
        
        while(getline(stream, word, delimiter)) {
            string currWord = word;
            bool f=0;
            for(int i=0;i<currWord.length();i++) {
                string k=currWord.substr(0, i+1);
                if(st.find(k) != st.end()) {
                    f=1;
                    ans+=(k+" ");
                    break;
                }
            }
            if(!f) {
                ans+=(currWord+" ");
            }
        }
        ans.pop_back();
        return ans;
    }
};