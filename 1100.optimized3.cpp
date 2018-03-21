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
 * 7 - данные вместил в 32 бита
 * 0.202 - стало хуже
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
    uint32_t data;
};
struct greater_ {
    constexpr bool operator()(const Data &lhs, const Data &rhs) const 
    {
        return (lhs.data & 0xFF) > (rhs.data & 0xFF);
    }
};

template<class T>
T& operator<< (T& stream, const Data& data)
{
    stream << (data.data >> 8) << ' ' << (data.data & 0xFF) << std::endl;
    return stream;
}
template<class T>
T& operator>> ( T& stream, Data& data )  
{
    uint32_t id, qty;
    stream >> id >> qty;
    data.data = (id << 8) + qty;
    return stream;  
}


int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<Data> v;
    v.reserve(15000);
    while (n--) {
        Data d;
        std::cin >> d;
        // d.id = read_int();
        // d.qty = read_int();
        v.push_back(d);
    }

    std::stable_sort(v.begin(), v.end(), greater_());

    for (auto&& p : v)
        std::cout << p;
}