class Solution {
public:
    vector<int> nextsmallerelement(vector<int> heights,int n){
        stack<int> s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevsmallerelement(vector<int> arr,int n){\
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    
    
    int largestarea(vector<int>& heights) {
        
        int n=heights.size();
        
        vector<int> next(n);
        next=nextsmallerelement(heights,n);
        
        vector<int> prev(n);
        prev=prevsmallerelement(heights,n);
        
        
        int maxarea=INT_MIN;
        
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newarea=l*b;
            maxarea=max(maxarea,newarea);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> newmatrix(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newmatrix[i][j]=matrix[i][j]-'0';
            }
        }
        int area=largestarea(newmatrix[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(newmatrix[i][j]!=0){
                    newmatrix[i][j]=((newmatrix[i][j])+(newmatrix[i-1][j]));
                }else{
                    newmatrix[i][j]=0;
                }
            }
            int newarea=largestarea(newmatrix[i]);
            area=max(area,newarea);
        }
        return area;
    }
};