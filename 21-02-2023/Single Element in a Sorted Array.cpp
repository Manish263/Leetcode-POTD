int singleNonDuplicate(vector<int>& nums) {

        //check idx if m idx is odd then pair should end at even idx and if 
        //even it should end with odd idx. 
        //if m is odd then check its previous element if equal then skip that part because in that part seq is maintained and we find disrupted pattern in other side.
        int n=nums.size();
         int l=0,r=n-1,m;
         if(r==0 || nums[0]!=nums[1]) return nums[0];
         else if (nums[r]!=nums[r-1]) return nums[r];
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]!=nums[m+1] && nums[m]!=nums[m-1]) return nums[m];
            else if (((m%2==0) && nums[m]==nums[m+1]) || (m%2==1 && nums[m]==nums[m-1])) l=m+1;
            else r=m-1;
        }
        return -1;
