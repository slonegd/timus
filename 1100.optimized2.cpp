/**
 * Вторая оптимизация, вектор структур
 * сработало за 0.514
 * Третья оптимизация qty - в чар
 * сработало хуже 0.577
 * 4 - std::ios::sync_with_stdio(false);
 * 0.187
 * 5 - read_int_unlocked 
 * ошибка компиляции
 * 6 - read_int 
 * не проходит тест 1 на тимусе, хотя на компе проходит
 */
#include <iostream>
#include <vector>
#include <algorithm>

int read_int()
{
    int res = 0;
    int c = getchar();
    for (; !('0' <= c && c <= '9'); c = getchar()) {

    }
    for (; '0' <= c && c <= '9'; c = getchar()) {
        res = res*10 + c - '0';
    }
    return res;
}

struct Data {
    int id;
    int qty;
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
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<Data> v;
    v.reserve(15000);
    while (n--) {
        Data d;
        std::cin >> d.id >> d.qty;
        // d.id = read_int();
        // d.qty = read_int();
        v.push_back(d);
    }

    std::stable_sort(v.begin(), v.end(), greater<decltype(v)::value_type>());

    for (auto&& p : v)
        std::cout << p.id << ' ' << p.qty << std::endl;
}