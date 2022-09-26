class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = nums.size() - 1;
        
        while (white <= blue){
            if (nums[white] == 0){
                swap(nums[white], nums[red]);
                red += 1;
                white += 1;
            } else if (nums[white] == 1){
                white += 1;
            } else {
                swap(nums[white], nums[blue]);
                blue -= 1;
            }
        }
    }
};