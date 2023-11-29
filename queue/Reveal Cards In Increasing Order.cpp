class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans;
        sort(deck.begin(),deck.end());
        deque<int> deq;
        deq.push_back(deck[deck.size()-1]);
        for(int i=deck.size()-2;i>=0;i--){
            deq.push_front(deck[i]);
            if(i>0){
                int num=deq.back();
                deq.pop_back();
                deq.push_front(num);
            }
        }
        while(!deq.empty()){
            ans.push_back(deq.front());
            deq.pop_front();
        }
        return ans;
    }
};