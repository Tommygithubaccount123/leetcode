class Solution(object):
    def twoSum(self, nums, target):
        storage = {}
        for i in range(len(nums)):
            number = nums[i]
            diff = target - number
            if diff in storage:
                return [i, storage[diff]]
            storage[number] = i
        return        