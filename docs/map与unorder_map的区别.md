# map与unorder_map的区别

在C++中，`std::map` 和 `std::unordered_map` 都是关联容器，用于存储键值对。它们的主要区别在于内部实现、性能特性和使用场景。

### `std::map`

- **内部实现**：`std::map` 是基于红黑树（一种自平衡二叉搜索树）实现的。每个元素在树中都有一个特定的位置，这使得插入、删除和查找操作都能在对数时间复杂度（O(log n)）内完成。
- **有序性**：`std::map` 中的元素是按照键的自然顺序或自定义比较函数排序的。这意味着当你遍历 `std::map` 时，元素是按顺序排列的。
- **适用场景**：当你需要保持元素有序，或者需要频繁地进行范围查询（如查找某个范围的元素）时，`std::map` 是一个很好的选择。

### `std::unordered_map`

- **内部实现**：`std::unordered_map` 是基于哈希表（hash table）实现的。哈希表通过哈希函数将键映射到桶（bucket）中，这使得插入、删除和查找操作的平均时间复杂度为 O(1)。最坏情况下（如哈希冲突严重时），时间复杂度可能为 O(n)。
- **无序性**：`std::unordered_map` 中的元素是无序的。元素的存储顺序与插入顺序无关，也不保证任何特定的顺序。
- **适用场景**：当你不需要元素有序，并且需要高效的插入、删除和查找操作时，`std::unordered_map` 是一个更好的选择。

### 示例代码

```c++
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
```

### 输出结果

```
std::map (ordered):
1: one
2: two
3: three
std::unordered_map (unordered):
2: two
1: one
3: three
```

### 总结

- **`std::map`**：基于红黑树，元素有序，适用于需要元素有序或范围查询的场景。
- **`std::unordered_map`**：基于哈希表，元素无序，适用于需要高效插入、删除和查找操作的场景。

选择使用哪种容器取决于你的具体需求：如果你需要元素有序，选择 `std::map`；如果你需要高效的查找、插入和删除操作，选择 `std::unordered_map`。

## 关联容器

在C++标准库中，关联容器（Associative Containers）是一类用于存储和检索数据的数据结构。它们基于键（key）来组织数据，并且通常提供高效的查找、插入和删除操作。关联容器的主要特点是它们的元素是按照键的某种顺序进行排序的。

### 常见的关联容器

C++标准库提供了以下几种关联容器：

1. **`std::set`**：存储一组唯一的键，键本身即是值。
2. **`std::multiset`**：存储一组键，允许键重复。
3. **`std::map`**：存储一组键值对（key-value pairs），键是唯一的。
4. **`std::multimap`**：存储一组键值对，允许键重复。

### 无序关联容器

除了上述的关联容器，C++标准库还提供了无序关联容器（Unordered Associative Containers），它们使用哈希表来组织数据，而不是基于键的顺序。无序关联容器的主要特点是它们在平均情况下提供常数时间的查找、插入和删除操作。

常见的无序关联容器包括：

1. **`std::unordered_set`**：存储一组唯一的键。
2. **`std::unordered_multiset`**：存储一组键，允许键重复。
3. **`std::unordered_map`**：存储一组键值对，键是唯一的。
4. **`std::unordered_multimap`**：存储一组键值对，允许键重复。

### 示例代码

以下是一些使用关联容器和无序关联容器的示例代码。

#### 使用 `std::set`

```c++
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
```

#### 使用 `std::map`

```
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> m = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    // 插入元素
    m["date"] = 4;

    // 遍历映射
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 查找元素
    if (m.find("banana") != m.end()) {
        std::cout << "Found banana" << std::endl;
    }

    return 0;
}
```

#### 使用 `std::unordered_set`

```
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
```

#### 使用 `std::unordered_map`

```
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> um = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    // 插入元素
    um["date"] = 4;

    // 遍历映射
    for (const auto& pair : um) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 查找元素
    if (um.find("banana") != um.end()) {
        std::cout << "Found banana" << std::endl;
    }

    return 0;
}
```

### 总结

- 关联容器

  ：基于键的顺序组织数据，提供有序的存储和检索。

  - `std::set`：存储唯一的键。
  - `std::multiset`：存储键，允许重复。
  - `std::map`：存储键值对，键是唯一的。
  - `std::multimap`：存储键值对，允许键重复。

- 无序关联容器

  ：基于哈希表组织数据，提供平均情况下的常数时间复杂度的查找、插入和删除操作。

  - `std::unordered_set`：存储唯一的键。
  - `std::unordered_multiset`：存储键，允许重复。
  - `std::unordered_map`：存储键值对，键是唯一的。
  - `std::unordered_multimap`：存储键值对，允许键重复。

通过这些关联容器和无序关联容器，你可以高效地存储和检索数据，满足不同的应用需求。

## 范围for循环（Range-based for loop）

### 代码结构

```c++
for (const auto& pair : um) {
    // 循环体
}
```

这段代码是C++11引入的范围for循环（Range-based for loop）的一个示例。它用于遍历一个容器（在这个例子中是一个 `std::unordered_map`）中的所有元素。让我们详细解释一下这段代码的各个部分。

### 详细解释

1. **`for` 关键字**：
   - `for` 是C++中的循环语句，用于遍历一个范围（如容器）中的元素。
2. **`const auto& pair`**：
   - `auto`：自动类型推导。编译器会根据容器的元素类型自动推导出 `pair` 的类型。
   - `const`：表示 `pair` 是一个常量引用。这意味着在循环体内不能修改 `pair` 的值。
   - `&`：引用符号。`pair` 是一个引用，而不是拷贝。这样可以避免不必要的拷贝操作，提高性能。
   - `pair`：循环变量。每次迭代时，`pair` 都会引用容器中的一个元素。
3. **`:` 符号**：
   - `:` 表示“在...范围内”。它用于指定要遍历的容器。
4. **`um`**：
   - `um` 是一个 `std::unordered_map` 类型的容器。这个容器中存储了键值对（key-value pairs）。

### 循环体

循环体中的代码会在每次迭代时执行一次。`pair` 引用当前迭代的键值对。

### 示例代码

以下是一个完整的示例代码，展示了如何使用范围for循环遍历 `std::unordered_map`：

```
#include <iostream>
#include <unordered_map>

int main() {
    // 创建一个 std::unordered_map
    std::unordered_map<std::string, int> um = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    // 使用范围for循环遍历 unordered_map
    for (const auto& pair : um) {
        // pair 是一个 std::pair<const std::string, int>
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
```

### 输出

```
Key: apple, Value: 1
Key: banana, Value: 2
Key: cherry, Value: 3
```

### 解释

- **`pair.first`**：获取键值对中的键（key）。
- **`pair.second`**：获取键值对中的值（value）。

### 性能考虑

- **引用**：使用 `const auto&` 而不是 `auto` 可以避免不必要的拷贝操作，特别是当容器中的元素比较大时，这样可以提高性能。
- **常量**：使用 `const` 可以确保在循环体内不会意外修改元素的值。

### 总结

这段代码展示了如何使用范围for循环遍历 `std::unordered_map` 中的所有键值对。通过使用 `const auto&`，我们可以高效地遍历容器中的元素，并且避免不必要的拷贝操作。这种写法简洁、清晰，并且充分利用了C++11引入的新特性。