#include <iostream>

int main()
{
    int k, n;
    std::cin >> k >> n;
    int a[n];
    int cars = 0;
    for (auto num : a) {
        std::cin >> num;
        cars += num - k;
        if (cars < 0)
            cars = 0;
    }

    std::cout << cars << std::endl;
}