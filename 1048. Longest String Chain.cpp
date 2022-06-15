class Solution {
    public int longestStrChain(String[] words) {
//         Time Complexity: Nlogn+N*L*L
//         Space : O(N) || O(NL)
//         Sort on Length
        Arrays.sort(words,(a,b) -> a.length()-b.length());
        int res=0;
    Map<String,Integer> memo = new HashMap<>();
        
//         Iterate on the words
//         Time : N
        for(String word: words){
//             Put current word in map with default value.
            memo.put(word,1);
//             time: Length*length
            for(int i=0; i < word.length(); i++){
                StringBuilder curr = new StringBuilder(word);
                String next = curr.deleteCharAt(i).toString(); //time: length
//                 Check if the value for next is already calculated
                if(memo.containsKey(next)){
//                     Update the value in map with the maximum possible value
                    memo.put(word,Math.max(memo.get(word),memo.get(next)+1));
                }
            }
            res=Math.max(res,memo.get(word));
        }
        return res;
    }
}
