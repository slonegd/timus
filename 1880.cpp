#include <iostream>
#include <vector>

int main()
{
    unsigned long qty;
    std::vector<unsigned long> v1, v2, v3;

    auto get = [](auto& v){
        int n;
        unsigned long i;
        std::cin >> n;
        while (n--) {
            std::cin >> i;
            v.push_back(i);
        }
    };

    get(v1);
    get(v2);
    get(v3);

    qty = 0;
    unsigned long incr;

    for (const auto& num1 : v1) {
        for (const auto& num2 : v2) {
            if (num1 == num2) {
                for (const auto& num3 : v3) {
                    if (num1 == num3) {
                        qty++;
                    } else if (num1 < num3) {
                        break;
                    }
                }
            } else if (num1 < num2) {
                break;
            }
        }
    }

    std::cout << qty << std::endl;
}