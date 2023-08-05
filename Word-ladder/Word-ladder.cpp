class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st{wordList.begin(), wordList.end()};
        
        queue<string> q;
        q.push(beginWord);
        
        if(!st.count(endWord)) {
            return 0;
        }
        int ans = 1;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string word = q.front();
                q.pop();
                if(word == endWord) {
                    return ans;
                }
                
                for(int i=0;i<word.length();i++) {
                    for(char ch='a'; ch<='z';ch++) {
                        string newWord = word;
                        newWord[i] = ch;
                        if(st.count(newWord)) {
                            q.push(newWord);
                            st.erase(newWord);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};
