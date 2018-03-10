#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main()
{
    unsigned long long n;
    std::vector<unsigned long long> v;

    while (std::cin >> n) {
        v.push_back(n);
        if (std::cin.eof())
            break;
    }
    std::cout << std::endl;
    for(auto i = v.size(); i > 0; i--)
        std::cout << std::setprecision(4) << std::fixed << sqrt(v[i-1]) << std::endl;
}