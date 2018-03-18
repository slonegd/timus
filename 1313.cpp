#include <iostream>

int main()
{
    int n, num, k = 0;
    std::cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> arr[i][j];
        
    std::cout << arr[0][0];

    for (int i = 1; i < n; ++i)
        for (int j = i; j >= 0; --j)
            std::cout << ' ' << arr[j][i-j] ;
    for (int i = 1; i < n; ++i)
        for (int j = i; j < n; ++j)
            std::cout << ' ' << arr[n+i-j-1][j];

    std::cout << std::endl;
}