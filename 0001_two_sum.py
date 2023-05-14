from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = []
        value_idx = defaultdict(list)
        for i in range(len(nums):
            value_idx[nums[i]].append(i)
        for i in range(len(nums):
            if nums[i] * 2 = target and len(value_idx[nums[i]]) == 2:
                res.extend(value_idx[nums[i]])
                break
            if nums[i] * 2 == target:
                continue
            if len(value_idx[target - nums[i]]) != 0:
                res.append(value_idx[nums[i]][0])
                res.append(value_idx[target - nums[i]][0])
                break
        return res


