/**
 * 1893. A380
 * Ограничение времени: 1.0 секунды
 * Ограничение памяти: 64 МБ
 * Радости Джека не было предела: он успел купить в интернете билеты
 * на полуфинал чемпионата мира по программированию, который совсем
 * скоро пройдёт в загадочном заокеанском городе Санкт-Петербурге.
 * Теперь Джеку предстоит трансатлантический перелёт на самом большом
 * пассажирском авиалайнере в мире — Airbus A380.
 * Джек решил заранее изучить план самолёта по Википедии, чтобы при
 * регистрации на рейс сразу попросить себе удобное место рядом с
 * иллюминатором. Ну, или возле прохода — Джек ещё не решил.
 * На Airbus A380 две палубы для пассажиров. Верхняя палуба предназначена
 * для пассажиров премиум-класса и бизнес-класса. Места премиум-класса
 * расположены в первом и втором ряду — в каждом ряду по четыре кресла,
 * обозначенных буквами от A до D. В салоне премиум-класса проходы
 * расположены между первым и вторым и между третьим и четвёртым креслами
 * в ряду. Ряды с третьего по двадцатый отведены пассажирам бизнес-класса
 * — в каждом ряду по шесть кресел, обозначенных буквами от A до F.
 * Проходы расположены между вторым и третьим и между четвёртым и пятым
 * креслами в ряду.
 * На нижней палубе сидят только пассажиры эконом-класса. Ряды занумерованы
 * числами от 21 до 65, в каждом ряду по десять кресел, обозначенных
 * буквами от A до K (буква I не используется). Проходы расположены между
 * третьим и четвёртым и между седьмым и восьмым креслами в ряду.
 * Научите Джека определять по обозначению кресла, расположено ли оно возле
 * иллюминатора или возле прохода.
 * 
 * Исходные данные
 * В единственной строке записано обозначение места — сначала номер ряда,
 * а потом буква, задающая положение кресла в ряду.
 * Результат
 * Если место расположено возле иллюминатора, выведите «window».
 * В противном случае, если место расположено у прохода, выведите «aisle».
 * Если ни одно из условий не выполняется, выведите «neither».
 * 
 * Примеры
 * исходные данные	результат
 * 3C               aisle
 * 64A              window
 * 21F              neither
 *
 **/

#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::string str;
    std::cin >> str;

    char c = std::toupper(str.back());
    str.pop_back();
    int n = stoi (str);

    if (n >= 21 and n <= 65)
        std::cout << (
            c == 'A' or c == 'K'                         ? "window" :
            c == 'C' or c == 'D' or c == 'G' or c == 'H' ? "aisle"  : 
                                                           "neither"
        );
    else if (n >= 3 and n < 21)
        std::cout << (
            c == 'A' or c == 'F'                         ? "window" :
            c == 'B' or c == 'C' or c == 'D' or c == 'E' ? "aisle"  : 
                                                           "neither"
        );
    else if (n == 1 or n == 2)
        std::cout << (
            c == 'A' or c == 'D' ? "window"  :
            c == 'B' or c == 'C' ? "aisle"   :
                                   "neither"
        );
    else
        std::cout <<  "neither";

    std::cout << std::endl;
}