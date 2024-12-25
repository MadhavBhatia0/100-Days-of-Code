//leeetcode 225. Implement Stack using Queues
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(!empty()){
        int val=q.front();
        q.pop();
        return val;}
        return -1;
    }
    
    int top() {
        if(!empty())
        return q.front();
        else{
            return -1;
        }
    }
    
    bool empty() {
        return q.empty();
    }
};

