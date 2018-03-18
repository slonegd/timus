/**
 * 1 -> 2
 * 2 -> 2
 * 3 -> 4
 * 4 -> 6
 * 5 -> 10
 * 6 -> 16
 * 7 -> 26
 * 8 -> 42
 */
#include <iostream>

int main()
{
    unsigned long n, _1, _2;
    std::cin >> n;
    _1 = 2;
    _2 = 2;
    for (int i = 3; i <= n; ++i) {
        unsigned long tmp = _2;
        _2 = _1 + _2;
        _1 = tmp;
    }

    std::cout << _2 << std::endl;
}