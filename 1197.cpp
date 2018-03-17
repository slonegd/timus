#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> qty;

    auto incr = [](auto l, auto n) {
        return (l>=0 and l<=7 and n>=0 and n<=7) ? 1 : 0;
    };

    while (n--) {
        char lit;
        char num;
        int lit_,num_;
        int k;
        k = 0;
        std::cin >> lit >> num;
        lit_ = (int)(lit - 'a');
        num_ = (int)(num - '1');

        k += incr(lit_ + 1, num_ + 2);
        k += incr(lit_ + 1, num_ - 2);
        k += incr(lit_ - 1, num_ - 2);
        k += incr(lit_ - 1, num_ + 2);
        k += incr(lit_ + 2, num_ + 1);
        k += incr(lit_ + 2, num_ - 1);
        k += incr(lit_ - 2, num_ + 1);
        k += incr(lit_ - 2, num_ - 1);

        qty.push_back(k);
    }
        
    for (auto&& v : qty) {
        std::cout << v << std::endl;
    }
}