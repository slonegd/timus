#include <iostream>
#include <string>

int main()
{
    int res = 1;
    std::string str;

    while (std::cin.peek() != '\n') {
        std::cin >> str;
        if (str.back() == ',')
            str.pop_back();
        res *= stoi(str);
    }

    std::cout << res*2 << std::endl;
}