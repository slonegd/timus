#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int arr[n+1];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    arr[n] = 0;
    int k = 1;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] != arr[i-1]) {
            std::cout << k << ' ' << arr[i-1] << ' ';
            k = 1;
        } else {
            k++;
        }
    }
    std::cout << std::endl;
}