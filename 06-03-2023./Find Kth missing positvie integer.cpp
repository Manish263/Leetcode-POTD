BINARY SEARCH SOLUTION 
nt findKthPositive(vector<int>& arr, int k) {   
        int l=0,r=arr.size(),m;
        while(l<r){
            m=(l+r)/2;
            if(arr[m]-(m+1)>=k){
//we are checking difference between mid element to its index+1  then check its difference with k if we got difference less then k then we're sure that in left we'll not get ans so we skip it.
                r=m;
            }
            else l=m+1;
        }
        return l+k;
    }
