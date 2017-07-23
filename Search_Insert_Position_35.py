class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        for idx,num in enumerate(nums):
            if(num == target):
                return idx
            elif(num > target):
                break
        else:
            return (len(nums))
        
        return idx
        

sol = Solution();
assert(sol.searchInsert([1,3,5,6],5) == 2)
assert(sol.searchInsert([1,3,5,6],2) == 1)
assert(sol.searchInsert([1,3,5,6],7) == 4)
assert(sol.searchInsert([1,3,5,6],0) == 0)
assert(sol.searchInsert([],0) == 0)
assert(sol.searchInsert([1],0) == 0)
assert(sol.searchInsert([1],2) == 1)

