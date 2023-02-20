Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
  
                                                                            ANSWER:

int searchInsert(vector<int>& nums, int x) {
        int n=nums.size();
        int l=0,r=n-1,m;
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]==x) return m;
            else if (nums[m]>x){
                r=m-1; 
            }
            else {
                l=m+1;
            }
        }
        return r+1; 
    }
      
