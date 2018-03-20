/**
 * первая оптимизация, замена вектора на массив структур
 * сработало за 0.514
 */
#include <iostream>
#include <array>
#include <algorithm>

struct Data {
    unsigned int qty;
    unsigned int id;
};

template<class T>
struct my_greater {
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs.qty > rhs.qty;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::array<Data,150001> data{};
    for (auto it = data.begin(); it != data.begin() + n; ++it) {
        std::cin >> it->id >> it->qty;
    }

    std::stable_sort(data.begin(), data.begin() + n, my_greater<Data>());

    for (auto it = data.begin(); it != data.begin() + n; ++it)
        std::cout << it->id << ' ' << it->qty << std::endl;
}