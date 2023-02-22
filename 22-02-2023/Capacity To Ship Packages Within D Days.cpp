int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size(),l,r,m,sum=0,ans=0,i,mx=0;
        for (i=0;i<weights.size();i++){
            if(weights[i]>mx) mx=weights[i];
            sum+=weights[i];   //we calculate mx and find sum. 
        }
        l=mx;
        r=sum; // then assign low as max and high as sum to calculate mid.
        while(l<=r){
            m=(l+r)/2;
            if(check(m,weights,days)){
//as of now m is our potential ans but to know if there is any other weight from which we can complete packaging in given days. we check that by using check function to decide which part to skip. 
                ans=m;  
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }

    bool check(int m,vector<int>&weights,int days){
        int s=0,d=1,i;
        for (i=0;i<weights.size();i++){
            if(s+weights[i]<=m) s+=weights[i];
            else {
                s=weights[i];
                d++;   //we calucalte sum upto mid and checking to decide which part we need to skip. 
            }
        }
        if(d<=days) return true;
        else return false;
    }
