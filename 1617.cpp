/**
 *  * Пример
 * исходные данные
 * 
 * 9
 * 689
 * 690
 * 690
 * 689
 * 689
 * 690
 * 689
 * 688
 * 688
 * 
 * 	
 * результат
 * 1
 **/
#include <iostream>
#include <map>
#include <sstream>
		

int main()
{
    std::map<int,int> qty;

    int n;
    std::cin >> n;
    while (n--) {
        int d;
        std::cin >> d;
        qty[d]++;
    }

    int res {0};
    for (auto& q : qty)
        res += q.second / 4;

    std::cout << res << std::endl;
}