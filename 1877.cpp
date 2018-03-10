#include <iostream>

int main()
{
    int a,b;
    std::cin >> a >> b;
    std::cout << (((a & 1) == 0) or ((b & 1) == 1) ? "yes" : "no") << std::endl;
}