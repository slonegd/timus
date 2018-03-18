/**
 * логика может показаться странной,
 * но я скопил формирование массива из задачи 1313
 * а тут только вывод подогнал
 */

#include <iostream>

int main()
{
    int n, incr;
    std::cin >> n;
    int arr[n][n];

    incr = 1;
    for (int i = 0; i < n; ++i)
        for (int j = i; j >= 0; --j)
            arr[j][i-j] = incr++;
    for (int i = 1; i < n; ++i)
        for (int j = i; j < n; ++j)
            arr[n+i-j-1][j] = incr++;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
             std::cout << arr[n-j-1][i] << ' ';
        }
        std::cout <<  std::endl;
    }

}