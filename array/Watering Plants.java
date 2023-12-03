class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int ans=0;
        int filled=0;
        for(int i=0;i<plants.length;i++){
            if(filled<plants[i]){
                ans+=i*2;
                filled=capacity;
            }
            filled-=plants[i];
            ans++;
        }
        return ans;
    }
}