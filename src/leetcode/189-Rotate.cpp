#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;
    
    // 对 k 取模，确保 k 在数组长度范围内
    k = k % n;
    
    // 反转整个数组
    std::reverse(nums.begin(), nums.end());
    
    // 反转前 k 个元素
    std::reverse(nums.begin(), nums.begin() + k);
    
    // 反转剩下的 n-k 个元素
    std::reverse(nums.begin() + k, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    rotate(nums, k);
    
    // 输出结果
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
