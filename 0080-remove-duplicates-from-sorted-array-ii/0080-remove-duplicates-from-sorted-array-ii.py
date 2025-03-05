class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        if (n==1):
            return 1
        i = 0
        k_inv = 0
        while (i<len(nums)-1):
            counter = 1
            while (i<len(nums)-1 and nums[i]==nums[i+1]):
                counter += 1
                if (counter > 2):
                    nums.pop(i)
                    k_inv += 1
                else:
                    i += 1
            i += 1
        return n-k_inv