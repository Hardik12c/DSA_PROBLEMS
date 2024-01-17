class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int s = 0;
        int e = arr.size() - 1;
        int diff = INT_MAX;
        int mid = s + (e - s) / 2;
        int ind=mid;
        while (s <= e) {
            if (abs(x - arr[mid]) < diff || (abs(x-arr[mid])==diff && mid<ind)) {
                diff = abs(x - arr[mid]);
                ind = mid;
            }
            if (arr[mid] == x) {
                break;
            } else if (arr[mid] > x) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        vector<int> ans;
        k--;
        int i = ind - 1;
        int j = ind + 1;
        vector<int> temp;
        while (i >= 0 || j < arr.size()) {
            if (k == 0)
                break;
            if (j >= arr.size() ||
                (i >= 0 && (abs(x - arr[i]) <= abs(x - arr[j])))) {
                ans.push_back(arr[i]);
                i--;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
            k--;
        }
        reverse(ans.begin(), ans.end());
        ans.push_back(arr[ind]);
        ans.insert(ans.end(), temp.begin(), temp.end());
        return ans;
    }
};