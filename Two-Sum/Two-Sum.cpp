#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map_nums_vals;

        for (int i = 0; i < nums.size(); ++i) {
            int look_for = target - nums[i]; // 4
            if (map_nums_vals.find(look_for) != map_nums_vals.end()) {
                return std::vector<int>{map_nums_vals[look_for], i};
            }
            map_nums_vals[nums[i]] = i;
        }
        return std::vector<int>{};
    }
};

int main() {
    std::vector<int> nums{3,4,5,6};
    int target = 7;

    auto result = Solution().twoSum(nums, target);

    for (auto &i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}