#include <iostream>

int main()
{
    int n;
    int sum = 0;
    bool minus = false;
    std::cin >> n;

    if (n < 0) {
        n *= -1;
        minus = true;
    }

    sum = 1;

    for (int i = 2; i <= n; i++)
        sum += i;

    std::cout << (minus ? (-1*sum)+1 : sum ) << std::endl;
}