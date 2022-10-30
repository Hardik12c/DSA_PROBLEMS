class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    static 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k=lists.size();
        
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        
        for(int i=0;i<k;i++){
            if(lists[i]) pq.push(lists[i]);
        }
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(!pq.empty()){
            ListNode* k=pq.top();
            temp->next=k;
            temp=temp->next;
            pq.pop();
            if(k->next) pq.push(k->next);
        }
        
        return ans->next;
    }
};