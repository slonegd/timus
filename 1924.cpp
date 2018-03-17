#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    n %= 4;
    std::cout << ( (n == 1) or (n == 2) ? "grimy" : "black") << std::endl;
}