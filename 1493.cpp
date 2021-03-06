/**
 * 1493. В одном шаге от счастья
 * Вова купил билет в трамвае 13-го маршрута и сразу посчитал
 * суммы первых трёх цифр и последних трёх цифр номера билета
 * (номер у билета шестизначный). Оказалось, что суммы отличаются
 * ровно на единицу. «Я в одном шаге от счастья», — подумал Вова,
 * — «или предыдущий или следующий билет точно счастливый».
 * Прав ли он?
 * 
 * Исходные данные
 * В единственной строке записан номер билета.
 * Номер состоит ровно из шести цифр, среди которых могут быть и нули.
 * Гарантируется, что Вова умеет считать,
 * то есть суммы первых трёх цифр и последних трёх цифр
 * отличаются ровно на единицу.
 * 
 * Результат
 * Выведите «Yes», если Вова прав, и «No», если нет.
 * 
 * Примеры
 * исходные данные   результат
 * 715068            Yes
 * 445219            No
 * 012200            Yes
 */
#include <iostream>

int getSum (int n)
{
   int res = n % 10;
   n /= 10;
   res += n % 10 + n / 10;
   return res;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::cout << (getSum((n + 1) / 1000) == getSum((n + 1) % 1000)
               or getSum((n - 1) / 1000) == getSum((n - 1) % 1000)
               ? "Yes" : "No") << std::endl;

}