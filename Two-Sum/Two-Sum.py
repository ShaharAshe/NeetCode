class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen: dict[int, int] = {}
        for i, val in enumerate(nums):
            complement: int = target - val
            if complement in seen:
                return [seen[complement], i]
            seen[val] = i
        return []


if __name__ == "__main__":
    nums: list[int] = [3,4,5,6]
    target: int = 7

    result = Solution().twoSum(nums, target)
    print(result)
