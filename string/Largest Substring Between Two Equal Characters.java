class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
Map<Character, Integer> mpp = new HashMap<>();
        int ans=-1;
        for(int i=0;i<s.length();i++){
            if(mpp.containsKey(s.charAt(i))){
                ans=Math.max(ans,(i-mpp.get(s.charAt(i))-1));
            }else{
                mpp.put(s.charAt(i),i);
            }
        }
        return ans;
    }
}