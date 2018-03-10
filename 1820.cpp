#include <iostream>

int main()
{
    int n,k;
    std::cin >> n >> k;
    n = n < k ? k * 2 : n * 2;
    std::cout << n/k + (n%k != 0) << std::endl;
}