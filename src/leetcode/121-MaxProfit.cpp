#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    if (prices.empty()) return 0;

    int minPrice = prices[0];  // 记录当前遍历到的最低价格
    int maxProfit = 0;         // 记录当前的最大利润

    for (int i = 1; i < prices.size(); ++i) {
        // 更新最低价格
        minPrice = std::min(minPrice, prices[i]);
        // 更新最大利润
        maxProfit = std::max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}

int main() {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);
    std::cout << "MaxProfit:" << result << std::endl;
    return 0;
}
