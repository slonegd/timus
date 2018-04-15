/**
 * исходя из условия надо найти количество нечётных чисел в промежутке
 */
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);

    int a, b, res;
    std::cin >> a >> b;
    res = b - a;
    res /= 2;
    if (a & 1 == 1)
        res++;
    if (b & 1 == 1)
        res++;
    if (a & 1 == 1 and b & 1 == 1)
        res--;

    std::cout << res << std::endl;

}