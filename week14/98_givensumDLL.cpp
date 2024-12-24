vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> ans;
        Node* temp=head;
        while(temp!=NULL)
        {
            int i=temp->data;
            if(i>=target) break;
            int j=target-i;
            Node* temp2=temp->next;
            while(temp2!=NULL)
            {
                if(temp2->data==j) {
                    ans.push_back({i,j});
                    break;
                }
                else if(temp2->data>j) break;
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        return ans;
    }
//TC O(N*N)
//SC O(1)

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> ans;
        if(!head || !head->next) return ans;
        Node* right=head;
        Node* left=head;
        while(right->next!=NULL)
        {
            right=right->next;
        }
        while(left!=right && left->prev != right)
        {
            int sum=left->data+right->data;
            if(sum==target)
            {
                ans.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if(sum<target) left=left->next;
            else right=right->prev;
        }
        return ans;
    }
//TC O(N)
//SC O(1)