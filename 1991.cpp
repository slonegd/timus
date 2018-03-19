#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;
    int qty[n];
    int boomLeft = 0;
    int droidLeft = 0;
    //int droids = 0;
    for (auto num : qty) {
        std::cin >> num;
        if (num > k) {
            boomLeft += num - k;
        } else if (num < k) {
            droidLeft += k - num;
        }
    }
    
    std::cout << boomLeft << ' ' << droidLeft << std::endl;
}