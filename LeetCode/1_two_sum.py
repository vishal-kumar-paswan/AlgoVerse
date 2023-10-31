'''
Question URL: https://leetcode.com/problems/two-sum/
Approach:
1. Start by copy and sorting.
2. Then, we find two numbers with two pointers.
3. Finally, return two index numbers from origin list 'nums'.
Time Complexity: O(NlogN) (maybe)
Space Complexity: O(N) (maybe)
'''

class Solution:
    def find_nth_occurrence(self, lst, number, n):
        count = 0
        for i, element in enumerate(lst):
            if element == number:
                count += 1
                if count == n:
                    return i
        return None
    
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_copy = nums.copy()
        nums_copy.sort()

        left = 0
        right = len(nums_copy) - 1
        while left < right:
            current_sum = nums_copy[left] + nums_copy[right]
            if current_sum == target:
                if nums_copy[left] == nums_copy[right]:
                    return [self.find_nth_occurrence(nums, nums_copy[left], 1), 
                            self.find_nth_occurrence(nums, nums_copy[left], 2)]
                else:
                    return [nums.index(nums_copy[left]), nums.index(nums_copy[right])]
            elif current_sum < target:
                left += 1
            else:
                right -= 1

        return None
