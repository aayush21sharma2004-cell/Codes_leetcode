class Solution {
public:
    int pivotIndex(vector<int>& nums) {

       int left=0;
       int right=0;
       int total=0;

       for(int i=0; i<nums.size(); i++) {
            total=total+nums[i];
       }
       
       for(int i=0; i<nums.size(); i++) {
        right=total-left-nums[i];
        if(right==left){
            return i;
        }
        else{
            left=left+nums[i];
        }     
      }
      return -1;
  }
  
};