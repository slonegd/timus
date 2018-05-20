/**
 * 1110. Степень
 * Ограничение времени: 0.5 секунды
 * Ограничение памяти: 64 МБ
 * 
 * Даны целые числа N, M и Y.
 * Напишите программу, которая найдёт все целые числа X в диапазоне [0, M – 1],
 * такие что X^N mod M = Y.
 * 
 * Исходные данные
 * Ввод содержит единственную строку с числами N, M и Y
 * (0 < N < 999, 1 < M < 999, 0 < Y < 999), записанными через пробел.
 * 
 * Результат
 * Выведите все числа X через пробел в одной строке.
 * Числа должны идти в порядке возрастания.
 * Если искомых чисел нет, выведите −1.
 * 
 * Пример
 * исходные данные	
 * 2 6 4
 * результат
 * 2 4
 **/

#include <iostream>
#include <vector>

// https://clck.ru/DQxQp
int pow_and_mod (int val, int pow, int mod)
{
    int res = 1;
    val %= mod;
    while (pow--)
        res = (res * val) % mod;  
    return res;  
}

int main()
{
    std::ios::sync_with_stdio(false);
    int N, M, Y;
    std::cin >> N >> M >> Y;

    std::vector<int> X;

    for (int i = 0; i < M; ++i)
        if (pow_and_mod(i, N, M) == Y)
            X.push_back(i);

    if (X.size()) {
        auto it = std::cbegin(X);
        std::cout << *it;
        for (it = std::next(it); it != std::cend(X); ++it)
            std::cout << ' ' << *it;
        
    } else {
        std::cout << -1;
    }
    std::cout << std::endl;
}