class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        vector<ListNode*> ans;
        temp=head;
        int count=k;
        int extra=size%k;
        int tempsize=size/k;
        if(size<k) {
            extra=0;
            tempsize=1;
        }
        while(count!=0 &&temp!=NULL){
            ListNode* newNode=temp;
            ans.push_back(newNode);
            int tempcount=1;
            while(tempcount<tempsize){
                newNode=newNode->next;
                tempcount++;
            }
            if(extra>0){
                newNode=newNode->next;
                extra--;                
            }
            if(newNode){
                temp=newNode->next;
                newNode->next=NULL;
            }else{
                temp=NULL;
            }
            count--;
        }
        while(ans.size()!=k){
            ans.push_back(NULL);
        }
            return ans;
    }
};