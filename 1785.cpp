#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    std::cout << (n > 999 ? "legion"  :
                  n > 499 ? "zounds"  :
                  n > 249 ? "swarm"   :
                  n > 99  ? "throng"  :
                  n > 49  ? "horde"   :
                  n > 19  ? "lots"    :
                  n > 9   ? "pack"    :
                  n > 4   ? "several" :
                  n > 0   ? "few"     : " ") << std::endl;
}