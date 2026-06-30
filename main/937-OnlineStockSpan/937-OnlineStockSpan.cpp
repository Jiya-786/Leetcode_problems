// Last updated: 30/06/2026, 19:32:16

class StockSpanner {
public:
    StockSpanner(){}
    stack<int> st;
    vector<int> prices;
    
    int next(int price){
        int ans=0;
        prices.push_back(price);
              
        while(!st.empty() && prices[st.top()]<=price){
            st.pop();
        }
        if(st.empty()){
            ans=prices.size();
        }
        else{
            ans=prices.size()-1-st.top();          // st.top() gives index
                                                   //of next greaterr elt
                                                   //ie the elt we will
                                                   //stop counting span
        }
        st.push(prices.size()-1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */