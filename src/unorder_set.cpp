#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> us = {3, 1, 4, 1, 5, 9};

    // 插入元素
    us.insert(2);

    // 遍历集合
    for (int num : us) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 查找元素
    if (us.find(4) != us.end()) {
        std::cout << "Found 4" << std::endl;
    }

    return 0;
}