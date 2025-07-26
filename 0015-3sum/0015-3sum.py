class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        out = []
        for i in range(len(nums)):
            if i >= 1 and nums[i] == nums[i-1]:
                continue
            triples = self.twoSum(nums, -nums[i], i, nums[i])
            if triples:
                out.extend(triples)
        return out

    def twoSum(self, nums, target, i, fixed):
        l = i+1
        r = len(nums) - 1
        out = []
        while (l < r):
            total = nums[l] + nums[r]

            if total < target:
                l += 1
            elif total > target:
                r -= 1
            else:
                out.append([nums[l], nums[r], fixed])
                l += 1
                r -= 1
                while l<r and nums[l] == nums[l-1]:
                    l += 1
                while r>l and nums[r] == nums[r+1]:
                    r -= 1
        return out