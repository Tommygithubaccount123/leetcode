class Solution {
    func containsDuplicate(_ nums: [Int]) -> Bool {
        var hash = [Int: Int]()
        for num in nums{
            if (hash[num] != nil){
                return true
            }
            hash[num] = 0
        }
        return false
    }
}