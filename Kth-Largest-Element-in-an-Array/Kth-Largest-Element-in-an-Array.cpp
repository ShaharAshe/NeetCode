#include <cstdlib>
#include <iostream>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int i_start = 0,
            i_end = nums.size() - 1;
        int i_small_val = i_start - 1,
            i_big_val = i_start,
            i_pivot = i_end,
            pivot = nums[i_pivot],
            largest_count = 0;
        
        while (true) {
            i_pivot = partision(nums, i_small_val, i_big_val, i_pivot, pivot);
            int range_len = (i_end - i_pivot) + 1;

            if ((largest_count + range_len) == k) {
                break;
            } else if ((largest_count + range_len) < k) {
                largest_count += range_len;
                i_end = --i_pivot;
            } else {
                i_start = i_pivot + 1;
                i_pivot = i_end;
            }
            i_small_val = i_start - 1;
            i_big_val = i_start;
            pivot = nums[i_pivot];
        }
        return pivot;
    }

private:
    int partision(std::vector<int>& nums, int i_small_val, int i_big_val, int i_pivot, int pivot) {
        while (i_small_val < i_pivot && i_big_val < i_pivot) {
            if (nums[i_big_val] < pivot) {
                std::swap(nums[++i_small_val], nums[i_big_val]);
            }
            ++i_big_val;
        }
        std::swap(nums[i_small_val + 1], nums[i_pivot]);
        i_pivot = i_small_val + 1;
        return i_pivot;    
    }
};

int main() {
    // std::vector<int> nums{2,3,1,5,4};
    // int k = 2;

    std::vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    auto result = Solution().findKthLargest(nums, k);
    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}