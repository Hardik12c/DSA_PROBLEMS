class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans=new Node(-1);
        Node* temp2=ans;
        Node* temp=head;
        unordered_map<Node*,Node*> mpp;
        while(temp!=NULL){
            Node* newNode= new Node(temp->val);
            mpp[temp]=newNode;
            temp2->next=newNode;
            temp2=temp2->next;
            temp=temp->next;
        }
        temp2=ans->next;
        temp=head;
        while(temp!=NULL){
            Node* temp2random=temp->random?mpp[temp->random]:NULL;
            temp2->random=temp2random;
            temp2=temp2->next;
            temp=temp->next;
        }
        return ans->next;
    }
};