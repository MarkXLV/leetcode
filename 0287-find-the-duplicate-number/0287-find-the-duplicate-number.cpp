class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       // use can use binary serch and count no of elements less than mid if(no)>-mid move to left half;

       // hare tortoise algo //
       int slow=nums[0];int fast=nums[0];
       do{
        slow=nums[slow];
        fast=nums[nums[fast]];
       }while(slow!=fast);

       cout<<slow<<endl;
       slow=nums[0];
       while(slow!=fast)
       {
        slow=nums[slow];
        fast=nums[fast];
       }
       return slow;
    }
};