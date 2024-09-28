#include <iostream>
#include <set>

int main() {
    std::set<int> s = {3, 1, 4, 1, 5, 9};

    // 插入元素
    s.insert(2);

    // 遍历集合
    for (int num : s) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 查找元素
    if (s.find(4) != s.end()) {
        std::cout << "Found 4" << std::endl;
    }

    return 0;
}