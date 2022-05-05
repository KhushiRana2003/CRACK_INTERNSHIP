class MyStack {
public:
    queue<int> q1,q2;
    int curr_size = 0;
    MyStack() {
        curr_size =0;
    }
    
    void push(int x) {
        curr_size++;
        
        q2.push(x);
        
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    
    int pop() {
       
        int topp;
        if(!q1.empty()){
            topp = q1.front();
        }
         q1.pop();
        return topp;
    }
    
    int top() {
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        return false;
    }
};
// Time complexity : O(1).
// Space complexity : O(1).
