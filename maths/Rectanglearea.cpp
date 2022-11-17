class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rectangle1=abs(ax2-ax1)*abs(ay2-ay1);
        int rectangle2=abs(bx2-bx1)*abs(by2-by1);
        int l=0,b=0;
        l+=(min(ax2,bx2))-(max(ax1,bx1));
        b+=(min(ay2,by2))-(max(ay1,by1));
        if(l>0 &&b>0) return rectangle1+rectangle2-(l*b);
        return rectangle1+rectangle2;
    }
};