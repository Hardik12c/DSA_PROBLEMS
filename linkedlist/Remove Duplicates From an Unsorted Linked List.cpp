Node *removeDuplicates(Node *head)
{
    if (head==NULL) return NULL;
    unordered_map<int,bool> visited;
    Node* temp=head;
    visited[temp->data]=true;
    while(temp->next!=NULL){
        if (visited[temp->next->data]==true){
            Node* temp1=temp->next;
            temp->next=temp->next->next;
            delete temp1;
        }
        else{
           visited[temp->next->data]=true;
           temp=temp->next;
        } 
        
    }
    return head;
}