class Solution {
    public int minOperations(int n) {
        int mid=n/2;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==mid) continue;
            ans+=Math.abs(mid-i);
        }
        return ans;
    }
}