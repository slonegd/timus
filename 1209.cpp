#include <iostream>
#include <vector>
#include <algorithm>

const size_t s = 2147483647UL;

int main()
{
    int n;
    std::cin >> n;
    int arr[n];

    std::vector<int> v;
    long long i = 1;
    long long k = 1;
    
    while (i <= s) {
        v.push_back(i);
        i += k;
        k++;
    }

    for (auto& n : arr) {
        std::cin >> n;
        n = (std::binary_search(v.begin(), v.end(), n)) ? 1 : 0;
    }

    for (auto& n : arr)
        std::cout << n << ' ';
    std::cout << std::endl;
}