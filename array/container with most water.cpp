class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int e=height.size()-1;
        int area=INT_MIN;
        while(s<e){
            int l=min(height[s],height[e]);
            area=max(area,(l*(e-s)));
            if(height[s]<height[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return area;
    }
};