/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        b=b+2;
        ListNode* temp=list2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        ListNode* second=list1;
        ListNode* first;
        int count=1;
        while(second!=NULL){
            if(count==a){
                first=second;
            } 
            if(count==b){
                break;
            } 
            second=second->next;
            count++;
        }
        first->next=list2;
        temp->next=second;
        return list1;
    }
};