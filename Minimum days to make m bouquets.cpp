bool ispossible(vector<int>&arr, int m, int k,int day){
    int count=0;
    int noOfb=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            count++;
        }
        else{
            noOfb+=(count/k);
            count=0;
        }
    }
    noOfb+=(count/k);
    return noOfb >=m;
}
    int  roseGarden(vector<int> bloomDay, int k, int m) {
        long long val= m*1LL * k*1LL;
        if(val>bloomDay.size())return -1;
        int minele=INT_MAX;
        int maxele=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            minele=min(minele,bloomDay[i]);
            maxele=max(maxele,bloomDay[i]);
        }
        int low=minele;
        int high=maxele;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(bloomDay,m,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
