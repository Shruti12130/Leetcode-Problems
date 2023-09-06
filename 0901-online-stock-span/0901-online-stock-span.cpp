class StockSpanner {
public:
    vector<int> ans, priceArr;
    stack<int> st;
    int j;
    
    StockSpanner() {
        ans.resize(100001, 1);
        j=0;
    }
    
    int next(int price) {
        priceArr.push_back(price);
        if(j==0) {
            st.push(j++);
            return 1;
        }
        
        int c=0;
        while(!st.empty() && price>=priceArr[st.top()]) {
            c+=ans[st.top()];
            st.pop();
        }
        ans[priceArr.size()-1]+=c;
        st.push(j++);
        return ans[priceArr.size()-1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */