class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)

        out = []
        for i in range(n):
            if (i>0 and nums[i]==nums[i-1]):
                continue
            target = nums[i]
            l=i+1
            r=n-1
            while(l<r):
                add = nums[l]+nums[r]
                if (add+target==0):
                    out.append([nums[l],nums[r],target])
                    l += 1
                    while(l<r and nums[l]==nums[l-1]):
                        l += 1
                elif (add+target > 0):
                    r -= 1
                else:
                    l += 1
        return out

