#include <iostream>
#include <string>


const std::string comp[] = {
    "Emperor Penguin",
    "Little Penguin",
    "Macaroni Penguin"
};

int main()
{
    int n;
    int k[3] {0};
    std::cin >> n;
    std::string str[n];
    std::getline(std::cin, str[0]);
    for (int i = 0; i < n; ++i)
        std::getline(std::cin, str[i]);
    for (int i = 0; i < n; ++i) {
        if (str[i].compare(comp[0]) == 0) {
            k[0]++;
        } else if (str[i].compare(comp[1]) == 0) {
            k[1]++;
        } else if (str[i].compare(comp[2]) == 0) {
            k[2]++;
        }
    }

    if ((k[0] > k[1]) and (k[0] > k[2])) {
        std::cout << comp[0] << std::endl;
    } else if ((k[1] > k[0]) and (k[1] > k[2])) {
        std::cout << comp[1] << std::endl;
    } else if ((k[2] > k[0]) and (k[2] > k[1])) {
        std::cout << comp[2] << std::endl;
    }
}