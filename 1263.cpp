#include <iostream>
#include <iomanip>

int main()
{
    int N, M;
    std::cin >> N >> M;
    int arr[M];
    int qty[N]{};
    int sum = 0;
    while (M--)
        std::cin >> arr[M];
    for (auto n : arr)
        for (int i = 1; i <= N; ++i)
            if (n == i) {
                qty[n-1]++;
                sum++;
                break;
            }
    
    for (int i = 0; i < N; ++i)
        std::cout << std::setprecision(2) << std::fixed << qty[i] * 100.0 / sum
                  << '%'
                  << std::endl;
}