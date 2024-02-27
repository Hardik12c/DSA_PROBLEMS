class Solution {
public:
    vector<int> nextSmallerElement(vector<int> heights) {
        vector<int> arr;
        stack<int> s;
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (s.empty()) {
                arr.push_back(heights.size());
            } else if (heights[s.top()] < heights[i]) {
                arr.push_back(s.top());
            } else {
                while (!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                if (s.empty())
                    arr.push_back(heights.size());
                else
                    arr.push_back(s.top());
            }
            s.push(i);
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
    vector<int> prevSmallerElement(vector<int> heights) {
        vector<int> arr;
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            if (s.empty()) {
                arr.push_back(-1);
            } else if (heights[s.top()] < heights[i]) {
                arr.push_back(s.top());
            } else {
                while (!s.empty() && heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                if (s.empty())
                    arr.push_back(-1);
                else
                    arr.push_back(s.top());
            }
            s.push(i);
        }
        return arr;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> rightSmaller = nextSmallerElement(heights);
        vector<int> leftSmaller = prevSmallerElement(heights);
        int ans = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            ans =
                max(ans, (heights[i] * (rightSmaller[i] - leftSmaller[i]-1)));
        }
        return ans;
    }
};