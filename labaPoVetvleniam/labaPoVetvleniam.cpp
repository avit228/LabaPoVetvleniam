/**********************
*автор: Витвинова.А   *
*дата:13.10.26        *
*название:Вариант1    *
**********************/

#include <iostream>
#include <cmath>
#include <vector>

int main() {
    //блок вводна данных
    const double Re = 20000.0;
    const double diameter = 25.4;
    const double s1 = 60.0;

    //массив шагов S2
    std::vector<double> s2 = { 30.0, 50.0, 65.0, 75.0, 80.0 };

    //блок ввода заголовка
    std::cout << "S2\tDelta\tNu\n";

    //блок расчетов
    for (int index = 0; index < s2.size(); ++index) {
        double currentS2 = s2[index];

        //формула 3:диагональный шаг Sg
        double sg = diameter * std::sqrt(0.25 * std::pow(s1 / diameter, 2.0) + std::pow(currentS2 / diameter, 2.0));

        //формула 2:параметр Delta
        double delta = (s1 - diameter) / (sg - diameter);

        //формула 1:число нуссельта
        double nu = 0.0;

        if (delta < 0.7) {
            nu = 0.27 * std::pow(Re, 0.6) * delta;
        }
        else {
            nu = 0.295 * std::pow(Re, 0.6) * std::pow(delta, 0.25);
        }

        //блок вывода
        std::cout << currentS2 << "\t" << delta << "\t" << nu << "\n";
    }

    return 0;
}