/**
 * 1149. Танцы синуса
 * Ограничение времени: 1.0 секунды
 * Ограничение памяти: 64 МБ
 * Пусть An = sin(1–sin(2+sin(3–sin(4+…sin(n))…)
 * Обозначим Sn = (…(A1+n)A2+n–1)A3+…+2)An+1
 * Для заданного N выведите выражение SN
 * 
 * Исходные данные
 * В единственной строке дано целое число N. 1 ≤ N ≤ 200
 * 
 * Результат
 * Выведите строку SN
 * 
 * Пример
 * исходные данные	
 * 3
 * результат
 * ((sin(1)+3)sin(1–sin(2))+2)sin(1–sin(2+sin(3)))+1
 **/

#include <iostream>
#include <vector>
#include <sstream>
		

int main()
{
    int N;
    std::string res;
    std::cin >> N;

    std::vector<std::string> An;
    An.reserve(N);

    std::string tmp {"sin(1)"};
    An.push_back(tmp);
    tmp.pop_back();

    for (auto i {2}; i <= N; ++i) {
        tmp += std::string {(i%2 ? '+' : '-')}
            + "sin("
            + std::to_string(i);
        for (auto j {1}; j <= i; ++j) {
            tmp += ')';
        }
        An.push_back(tmp);
        // std::cout << tmp << std::endl;
        for (auto j {1}; j <= i; ++j) {
            tmp.pop_back();
        }
    }

    for (auto i {0}; i < N - 1; ++i)
        res += '(';
    for (auto i {0}; i < N; ++i)
        res += An[i] + '+' + std::to_string(N-i) + ')';
    res.pop_back();

    std::cout << res << std::endl;
}