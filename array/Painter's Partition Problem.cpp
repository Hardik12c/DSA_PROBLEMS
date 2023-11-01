int calculatePainters(vector<int> boards,int maxTime){
    int painterCount=1;
    int time=0;
    for(int i=0;i<boards.size();i++){
        if(time+boards[i]>maxTime){
            painterCount++;
            time=0;
        }
        time+=boards[i];
    }
    return painterCount;
}



int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=*max_element(boards.begin(),boards.end());
    int e=accumulate(boards.begin(),boards.end(),0);
    int ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
        int numberOfPainter=calculatePainters(boards,mid);
        
        if(numberOfPainter>k){
            s=mid+1;
        }else{
            ans=mid;
            e=mid-1;
        }
    }
    return ans;
}