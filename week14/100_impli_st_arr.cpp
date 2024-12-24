//gfg impliment stack using array
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
void MyStack::push(int x) {
    if (top == 999) return; // Check if the stack is full
    arr[++top] = x;         // Increment `top` and assign `x`
}

int MyStack::pop() {
    if (top == -1) return -1; // Check if the stack is empty
    return arr[top--];        // Return the top element and decrement `top`
}