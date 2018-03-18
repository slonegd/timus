#include <iostream>
#include <string>

int main()
{
    int n, res = 2;
    std::cin >> n;
    std::string str;
    while (n--) {
        std::cin >> str;
        res = (str.find("+one") != str.npos) ? res + 2 : res + 1;
    }

    if (res == 13)
        res = 14;
    
    std::cout << res*100 << std::endl;
}