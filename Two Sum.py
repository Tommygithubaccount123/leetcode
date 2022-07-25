def twoSum(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for w in range(len(nums)):
                if i==w:
                    continue
                if (nums[i]+nums[w]==target):
                    return [i,w]

x = [0,1,2]
y = 2

print(twoSum(x,y))