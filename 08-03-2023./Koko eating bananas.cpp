class Solution {
public:
//Basic approach would be take ceil of every values to calculate time needed to eat bananans then traverse to loop and keep calulating and speed as soon as we hit threshold we return speed as our ans.
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size(),ans=0,l=1,m,r;
//we are taking r as max element b/c after that point time needed to  eat bananas will become constant.
        r=*max_element(piles.begin(),piles.end());
//we used normal binary search to skip the part which taking less time to hit threshold. 
        while(l<=r){
            m=(l+r)/2;
            double t=tm(m,piles);
            if(t<=h){  
                //if t reaches to threshold that point m will be ans else
//we keep moving to the left until threshol hits as soon as it hit we cut that part of and move to right if not find our ans. 
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
//we calculate time needed to eat pile of bananans below.
    double tm(int m,vector<int>&piles){
        double s=0,i;
        for (i=0;i<piles.size();i++){
            s+=(piles[i]/m)+(piles[i]%m!=0);
        }
        return s;
    }
};
