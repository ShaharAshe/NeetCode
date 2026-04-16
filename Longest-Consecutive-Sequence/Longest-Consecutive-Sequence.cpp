#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> nums_set(nums.begin(), nums.end());
        int max_count = 0;
        for (auto &num : nums_set) {
            if (nums_set.find(num - 1) != nums_set.end()) {
                continue;
            }
            int temp_num = num;
            int temp_max_count = 0;
            while (nums_set.find(temp_num++) != nums_set.end()) {
                ++temp_max_count;
            }
            if (max_count < temp_max_count) {
                max_count = temp_max_count;
            }
        }
        return max_count;
    }
};

int main() {
    std::vector<int> nums{2,20,4,10,3,4,5};

    auto result = Solution().longestConsecutive(nums);
    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}