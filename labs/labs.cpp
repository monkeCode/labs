// labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include<numeric>
#include<cmath>

void lab4()
{
    int A[] = { 1,2,-2,3,4 };
    for (int a : A)
    {
            int B = a + 2;
            int c1 = a + 3;
            int c2 = a + 2;
            int d1 = a + 4;
            int d2 = a + 3;
            int e1 = a + 5;
            int e2 = a + 4;
            std::cout << "B: " + std::to_string(B) << std::endl;
            if (c2 != 0)
            {
                int C = c1 / c2;
                std::cout << "C: " + std::to_string(C) << " Test: " << (a + 3) / (a + 2) << std::endl;
            }
            if (d2 != 0)
            {
                int D = d1 / d2;
                std::cout << "D: " + std::to_string( D) << " Test: " << (a + 4) / (a + 3) << std::endl;
            }
            if (e2 != 0)
            {
                int E = e1 / e2;
                std::cout << "E: " + std::to_string(E) << " Test: " << (a + 5) / (a + 4) << std::endl;
            }
            std::cout << "\n";
    }
}

void lab5(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c)
{
    //поиск длин всех сторон
    double la = sqrt(std::pow(b.first - a.first, 2) + std::pow(b.second - a.second, 2));
    double lb = sqrt(std::pow(c.first - b.first, 2) + std::pow(c.second - b.second, 2));
    double lc = sqrt(std::pow(a.first - c.first, 2) + std::pow(a.second - c.second, 2));

    //полупериметр
    double p = (la + lb + lc) / 2;
    //площадь треугольника
    double S = sqrt(p * (p - la) * (p - lb) * (p - lc));
    //определяем углы через формулу
    double angles[] =
    {
       (asin(S / (0.5f * la * lb))) * 180 / M_PI,
      (asin(S / (0.5f * lb * lc))) * 180 / M_PI,
      (asin(S / (0.5f * lc * la))) * 180 / M_PI
    };
    std::cout << "Sides: " << la << " " << lb << " "<< lc << "\n";
    std::cout << "Angles: ";
    std::copy(std::begin(angles), std::end(angles), std::ostream_iterator<double>(std::cout, " "));
    std::cout << "\n";
    //проверка на правильность
    std::cout <<"Sum of angles: " << std::accumulate(std::begin(angles), std::end(angles), .0f);
}
int main()
{
    lab5(std::pair<int, int>(-1, 0), std::pair<int, int>(3, 0), std::pair<int, int>(3, 3));
}


