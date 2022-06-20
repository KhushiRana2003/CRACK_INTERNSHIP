class Solution {
    public int minimumLengthEncoding(String[] words) {
//         Appoarch 1:
//         Time complexity : O(nlogn)
//         Space complexity : O(length of all words)
        // Arrays.sort(words,(a,b)->b.length()-a.length());
        // StringBuilder encoding = new StringBuilder();
        // for(String s:words){
        //     if(encoding.indexOf(s+"#")==-1){ //checking whether the next strinng                                                lies in encoding string or not.. 
        //         encoding.append(s+"#");
        //     }
        // }
        // return encoding.length();
        
//         Appraoch 2:
//         Time Complexity : o(w^2)
//         Space Complexity : O(w) where w is lengh of word.
//         Using Hashset
//         In this we are going to use constructor but as we know we can also iterate through the array and simply insert those element in the hashset.
     //    Set<String> wordSet = new HashSet<>(Arrays.asList(words));
        
        // for(String s: words){
//             remove all substring of string from the wordsSeet.
            // for(int i = 1; i < s.length(); i++) //we start from one bcoz if we start from 0 then whole word will be removed from the wordSet
//             {
//                 wordSet.remove(s.substring(i));
//             }
//         }
//         int length=0;
//         for(String s:wordSet){
//             length+=s.length()+1;
//         }
//         return length;
        
//         approach 3:
//         Timecomplexity:O(w)
//         space :O(w) where w is length of words.
//         using trie
        Trie root=new Trie();
        root.next=new Trie[26];
        int length=0;
        for(String s:words){
            length+=helper(s,root);
        }
        return length;
    }
    private int helper(String s,Trie node){
        boolean newBranch=false;
        int create=0;
        for(int i = s.length()-1; i >= 0; i--){
            boolean newLevel = false;
            int id=s.charAt(i)-'a';
            
            if(node.next==null){
                newLevel = true;
                node.next= new Trie[26];
            }
            if(node.next[id] == null){
                if(newLevel==false) newBranch=true;
                node.next[id] = new Trie();
                create++;
            }
            node=node.next[id];
        }
        return newBranch?s.length()+1:create;
    }
    class Trie{
        Trie[] next = null;
        
    }
}
