#include <iostream>
#include <algorithm>

int main()
{
    int m,n,min;
    std::cin >> m >> n;
    std::cout << ((m*n) % 2 == 0 ? "[:=[first]" : "[second]=:]") << std::endl;
}