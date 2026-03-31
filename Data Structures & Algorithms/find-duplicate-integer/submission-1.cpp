class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 1 2 3 2 2 -> 1 apna 2 se hai pointed , 1->2 then 2nd index is pointed to 3 therefore 1->2->3 like so on .

        int slow = nums[0];
        int fast = nums[0];

        // ek point chala diya hai 
        slow = nums[slow];
        fast = nums[nums[fast]];

        while(slow !=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    } 
};
