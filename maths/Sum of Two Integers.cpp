class Solution {
public:
    int getSum(int x, int y) {
        
    if (y == 0)
        return x;
    return getSum( x ^ y, (unsigned)(x & y) << 1);
    }
};