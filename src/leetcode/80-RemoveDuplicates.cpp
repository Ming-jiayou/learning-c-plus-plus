#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    
    int n = nums.size();
    int index = 0; // 用于记录当前有效位置的指针
    int count = 1; // 用于记录当前元素出现的次数
    
    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[index]) {
            if (count < 2) {
                // 如果当前元素出现次数小于2，则可以继续添加
                ++index;
                nums[index] = nums[i];
                ++count;
            }
        } else {
            // 如果当前元素与前一个元素不同，则重置计数器并添加新元素
            ++index;
            nums[index] = nums[i];
            count = 1; // 重置计数器
        }
    }
    
    return index + 1; // 返回新数组的长度
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int newLength = removeDuplicates(nums);
    
    std::cout << "New length: " << newLength << std::endl;
    std::cout << "Array after removal: ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}