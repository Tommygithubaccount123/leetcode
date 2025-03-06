class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        if (n<=2):
            return n
        k=2
        for i in range(2,n):
            if (nums[k-2]!=nums[i]):
                nums[k] = nums[i]
                k += 1
        return k