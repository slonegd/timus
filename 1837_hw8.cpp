/**
 * 1837. Число Исенбаева
 * Ограничение времени: 0.5 секунды
 * Ограничение памяти: 64 МБ
 * 
 * Владислав Исенбаев — двукратный чемпион Урала по программированию,
 * вице-чемпион TopCoder Open 2009, абсолютный чемпион ACM ICPC 2009.
 * За то время, которое вы потратите на чтение этого условия,
 * Владислав уже решил бы одну задачу. А может, и две…
 * Поскольку Владислав Исенбаев — выпускник СУНЦ УрГУ, неудивительно,
 * что многие из бывших и действующих олимпиадников УрГУ знакомы с
 * ним уже много лет. Некоторые из них с гордостью заявляют, что
 * играли с Владиславом в одной команде. Или играли в команде с
 * бывшими однокомандниками Владислава…
 * Определим число Исенбаева следующим образом. У самого Владислава
 * это число равняется нулю. У тех, кто играл с ним в одной команде,
 * оно равняется единице. У тех, кто играл вместе с однокомандниками
 * Владислава, но не играл с ним самим, это число равняется двум, и
 * так далее. Помогите автоматизировать процесс вычисления чисел
 * Исенбаева, чтобы каждый олимпиадник в УрГУ мог знать, насколько
 * близок он к чемпиону ACM ICPC.
 * 
 * Исходные данные
 * В первой строке записано целое число n — количество команд
 * (1 ≤ n ≤ 100). В каждой из следующих n строк записаны составы этих
 * команд в виде фамилий трёх участников. Фамилия каждого участника —
 * непустая строка, состоящая из английских букв, длиной не более 20
 * символов. Первая буква фамилии — заглавная, все остальные — строчные.
 * Фамилия Владислава — «Isenbaev».
 * 
 * Результат
 * Для каждого участника, представленного во входных данных, выведите
 * в отдельной строке через пробел его фамилию и число Исенбаева.
 * Если это число не определено, выведите вместо него «undefined».
 * Участники должны быть упорядочены по фамилии в лексикографическом
 * порядке.
 * 
 * Пример
 * исходные данные	
 * 7
 * Isenbaev Oparin Toropov
 * Ayzenshteyn Oparin Samsonov
 * Ayzenshteyn Chevdar Samsonov
 * Fominykh Isenbaev Oparin
 * Dublennykh Fominykh Ivankov
 * Burmistrov Dublennykh Kurpilyanskiy
 * Cormen Leiserson Rivest
 * 
 * результат
 * Ayzenshteyn 2
 * Burmistrov 3
 * Chevdar 3
 * Cormen undefined
 * Dublennykh 2
 * Fominykh 1
 * Isenbaev 0
 * Ivankov 2
 * Kurpilyanskiy 3
 * Leiserson undefined
 * Oparin 1
 * Rivest undefined
 * Samsonov 2
 * Toropov 1
 * 
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

int main()
{
  std::ios::sync_with_stdio(false);

  /// результат на вывод
  std::map<std::string, int> res;
  /// команды с неопределённым числом исимбаева
  std::list<std::array<std::string,3>> undefined;
  /// список людей с текущим и следующим числом исимбаева
  std::vector<std::string> level, level_next;

  int n;

  std::string champion {"Isenbaev"};

  std::cin >> n;
  while (n--) {
    std::array<std::string,3> command;
    bool command_with_champion;
    command_with_champion = false;
    for (auto& name : command) {
      std::cin >> name;
      if (name == champion) {
        res.insert (std::make_pair(champion, 0));
        command_with_champion = true;
      }
    }
    if (command_with_champion) {
      for (auto& name : command) {
        if (name != champion) {
          res.insert (std::make_pair(name, 1));
          level.push_back(name);
        }
      }
    } else {
       undefined.push_back(command);
    }
  }

  // ищем текущего уровня
  // если находим, добавляем к следующему уровню
  // когда дошли до конца и размер следующего уровня не равен нулю
  // запускаем заново с новым уровнем

  n = 2;

repeat:
  auto it = undefined.begin();
  do {
    it = std::find_if ( it, undefined.end(), 
      [level] (const std::array<std::string,3>& command) {
        return std::any_of (command.begin(), command.end(),
          [level] (const std::string& name) {
            return std::any_of (level.begin(), level.end(),
              [name] (const std::string& name_) {
                return name == name_;
            });
        });
    });
    if (it != undefined.end()) {
      for (auto& name : *it) {
        if ( std::any_of (
          level.begin(), level.end(),
          [name] (const std::string& name_) {
            return name != name_;
          }
        ) ) {
          res.insert (std::make_pair(name,n));
          level_next.push_back(name);
        }
      }
      it = undefined.erase(it);
    }
  } while (it != undefined.end());

  if (level_next.size()) {
    level = level_next;
    level_next.clear();
    n++;
    goto repeat;
  }

  // вставляем тех, кого не определили
  for (const auto& command : undefined)
    for (const auto& name : command)
      res.insert (std::make_pair(name,-1));


  // вывод
  for (const auto& men : res) {
    std::cout << men.first << ' ';
    if (men.second == -1)
      std::cout << "undefined";
    else
      std::cout << men.second;
    std::cout << std::endl;
  }


}