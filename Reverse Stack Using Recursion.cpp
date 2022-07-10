void insertAtBottom(stack<int> &s, int num){
//     base case
    if(s.empty()){
        s.push(num);
        return;
    }
    int num1 = s.top();
    s.pop();
//     recursive call
    insertAtBottom(s,num);
    s.push(num1);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
//     solve(stack);
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
//     recursive call
    reverseStack(stack);
    insertAtBottom(stack,num);
}
