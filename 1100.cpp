#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
struct greater {
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs.at(0) > rhs.at(0);
    }
};

int main()
{
    int n, id, qty;
    std::cin >> n;
    std::vector<std::vector<int>> v;
    std::vector<int> tmp;
    while (n--) {
        std::cin >> id >> qty;
        tmp.clear();
        tmp.push_back(qty);
        tmp.push_back(id);
        v.push_back(tmp);
    }

    std::stable_sort(v.begin(), v.end(), greater<decltype(v)::value_type>());

    for (auto&& p : v)
        std::cout << p.at(1) << ' ' << p.at(0) << std::endl;
}