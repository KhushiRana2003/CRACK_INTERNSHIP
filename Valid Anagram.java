class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> map = new HashMap<>();
        
        for(int i = 0; i < s.length(); i++){
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }
        
        for(int i = 0; i < t.length(); i++){
            if(map.containsKey(t.charAt(i)) == false) return false;
            if(map.get(t.charAt(i)) > 1) map.put(t.charAt(i), map.get(t.charAt(i)) - 1);
            else map.remove(t.charAt(i));
        }
        return map.size() == 0;
    }
}


/*
Second Way to do this
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        return (s.size()==t.size() ? is_permutation(s.begin(),s.end(),t.begin()):0);
    }
};
*/
