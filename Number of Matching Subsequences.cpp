class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> m;
        int i = 0;
        int count = 0;
        for(auto  x:s){
            m[x].push_back(i++);
        }
        
        for(int i = 0; i < words.size(); i++){
            string curr = words[i];
            int latest = -1;
            for(int j = 0; j < curr.size(); j++){
                auto it = upper_bound(m[curr[j]].begin(),m[curr[j]].end(),latest );
                if(it == m[curr[j]].end()) break;
                
                latest = *it;
                
                if(j == curr.size()-1)
                    count++;
            }
        }
        return count;
    }
};

// upper_bound() is a standard library function in C++ defined in the header . It returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found. 
