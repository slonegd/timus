#include <iostream>
#include <algorithm>

int main()
{
    int a,b,c,res;
    std::cin >> a >> b >> c;
    res = a + b + c;
    res = std::min(res, a + b - c);
    res = std::min(res, a + b * c);
    res = std::min(res, a - b + c);
    res = std::min(res, a - b - c);
    res = std::min(res, a - b - c);
    res = std::min(res, a - b * c);
    res = std::min(res, a * b + c);
    res = std::min(res, a * b * c);
    res = std::min(res, a * b - c);

    std::cout << res << std::endl;
}