#include <bits/stdc++.h>

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int size=0;size<=n;size++){
        prev[size]=size*price[0];
    }
    for(int i=1;i<n;i++){
        for(int size=0;size<=n;size++){
            int nottake=prev[size];
            int take=INT_MIN;
            if(i+1<=size) take=price[i]+curr[size-i-1];
            curr[size]=max(take,nottake);
        }
        prev=curr;
    }
	return prev[n];
}
