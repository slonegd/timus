#include <iostream>

int main()
{
    int n,i,sum1,sum2,sum,k;
    std::cin >> n;
    int arr[n];
    i = n;
    while (i--) {
        std::cin >> k;
        arr[n - i - 1] = k;
    }

    sum = sum1 = arr[0] + arr[1] + arr[2];
    k = 2;
    for (auto i = 3; i < n; ++i) {
        sum1 += arr[i] - arr[i-3];
        if (sum1 > sum) {
            sum = sum1;
            k = i;
        }
    }

    std::cout << sum << " " << k << std::endl;
}