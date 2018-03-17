#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int main()
{
    int n, go, steps = 0;
    std::string str;
    std::vector<std::string> v;
    std::cin >> n;
    while (n--) {
        std::cin >> str;
        v.push_back(str);
    }
    n = 0;
    for (auto&& str : v) {
        if (str == "Alice"
            or str == "Ariel"
            or str == "Aurora"
            or str == "Phil"
            or str == "Peter"
            or str == "Olaf"
            or str == "Phoebus"
            or str == "Ralph"
            or str == "Robin"
        ) {
            go = 0;
        } else if (str == "Bambi"
                or str == "Belle"
                or str == "Bolt"
                or str == "Mulan"
                or str == "Mowgli"
                or str == "Mickey"
                or str == "Silver"
                or str == "Simba"
                or str == "Stitch"
        ) {
            go = 1;
        } else {
            go = 2;
        }
        if (go != n) {
            steps += std::abs(go - n);
            n = go;
        }
    }

    std::cout << steps<< std::endl;
}