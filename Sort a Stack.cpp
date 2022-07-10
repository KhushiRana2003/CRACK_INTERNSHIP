void sortedInsert(stack<int> &s,int num)
{
//     base case
    if(s.empty() || (!s.empty() && s.top() < num)){
        s.push(num);
        return;
    }
    int x = s.top();
    s.pop();
    
//     rcursive call
    sortedInsert(s,num);
    s.push(x);
}

void sortStack(stack<int> &stack)
{
// 	base case
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    
//     recursive call
    sortStack(stack);
    sortedInsert(stack,num);
}
