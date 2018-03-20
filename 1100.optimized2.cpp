/**
 * Вторая оптимизация, вектор структур
 * также ошибка на 4 тесте (неверный ответ)
 */
#include <iostream>
#include <vector>
#include <algorithm>

struct Data {
    unsigned int id;
    unsigned char qty;
};

template<class T>
struct greater {
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs.qty > rhs.qty;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<Data> v;
    std::vector<int> tmp;
    while (n--) {
        Data d{};
        std::cin >> d.id >> d.qty;
        v.push_back(d);
    }

    std::stable_sort(v.begin(), v.end(), greater<decltype(v)::value_type>());

    for (auto&& p : v)
        std::cout << p.id << ' ' << p.qty << std::endl;
}