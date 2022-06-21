class Solution {
public:
    int furthestBuilding(vector<int>& v, int bricks, int ladders) {
//         Time : O(nlogn)
//         space : O(n)
        int i = 0;
        priority_queue<int> q;
        for(; i < v.size()-1; i++){
            if(v[i+1]<=v[i])continue;
            int d = v[i+1]-v[i];
            if(d <= bricks){
                bricks-=d;
                q.push(d);
            }
            else if(ladders > 0){
                if(q.size()){
                    int x=q.top();
                if(x>d){
                    bricks+=x;
                    q.pop();
                    q.push(d);
                    bricks-=d;
                }
                }
                
                ladders--;
            }
            else break;
        }
        return i;
    }
};
