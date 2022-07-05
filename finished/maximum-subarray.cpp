#include <iostream>
#include <vector>

using namespace std;

//KADANES ALGO
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (!n){
        return 0;
    }
    int max_out = nums[0];
    int current_max = nums[0];
    int start_index_sum = 0;
    int end_index = 0;
    int start_index = 0;
    for (int i=1; i<n; i++){
        //current_max = max(nums[i], current_max+nums[i]);
        if (current_max+nums[i]>nums[i]){
            current_max += nums[i];
        }
        else{
            current_max = nums[i];
            start_index_sum = i;
        }
        //max_out = max(max_out,current_max);
        if (current_max > max_out){
            max_out = current_max;
            start_index = start_index_sum;
            end_index = i;
        }
    }
    cout << "[";
    for (int i=start_index; i<=end_index; i++){
        cout << nums[i] << ",";
    }
    cout << "]" << endl;
    return max_out;
    }

int main(){
    vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(test) << endl;
}