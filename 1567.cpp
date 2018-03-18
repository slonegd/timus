#include <iostream>
#include <string>

int main()
{
    std::string str;
    int res = 0;
    std::getline(std::cin, str);
    for (auto c : str) {
        if (c >= 'a' and c <= 'z') {
            res += (int)(c-'a') % 3 +1;
        } else if (c == '.' or c== ' ') {
            res += 1;
        } else if (c == ',') {
            res += 2;
        } else if (c == '!') {
            res += 3;
        }
    }

    std::cout << res << std::endl;
}