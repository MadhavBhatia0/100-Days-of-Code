class Value{
    
    public:
    int maxVal,minVal,count;
    Value(int minVal,int maxVal,int count)
    {
        this->maxVal=maxVal;
        this->minVal=minVal;
        this->count=count;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Value helper(Node *root)
    {
        if(!root) return Value(INT_MAX,INT_MIN,0);
        
        Value left=helper(root->left);
        Value right=helper(root->right);
        
        if(left.maxVal<root->data && right.minVal>root->data)
        {
            return Value(min(left.minVal,root->data),max(root->data,right.maxVal),1+left.count+right.count);
        }
        return Value(INT_MIN,INT_MAX,max(left.count,right.count));
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	return helper(root).count;
    }
};