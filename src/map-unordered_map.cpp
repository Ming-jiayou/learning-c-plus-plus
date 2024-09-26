#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    // 使用 std::map
    std::map<int, std::string> myMap;
    myMap[3] = "three";
    myMap[1] = "one";
    myMap[2] = "two";

    std::cout << "std::map (ordered):" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 使用 std::unordered_map
    std::unordered_map<int, std::string> myUnorderedMap;
    myUnorderedMap[3] = "three";
    myUnorderedMap[1] = "one";
    myUnorderedMap[2] = "two";

    std::cout << "std::unordered_map (unordered):" << std::endl;
    for (const auto& pair : myUnorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}