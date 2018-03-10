#include <iostream>

int main()
{
    int a[3],b[3];
    std::cin >> a[0] >> b[0] >> a[1] >> b[1] >> a[2] >> b[2];
    int basketB = b[1];
    int basketA = a[2];
    std::cout << a[0] - basketA << ' ' << b[0] - basketB << std::endl;
}