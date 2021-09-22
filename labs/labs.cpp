﻿// labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include<numeric>
#include<cmath>
#include <vector>
//вариант 2, лаба 4
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
//вариант 2, лаба 5
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
//вариант 1, лаба 6
void lab6()
{
    
    int X[] = { -5,-2,2,5 };
    for(auto x:X)
    {
        float dividend = 2 * (pow(x, 3) + 3 * pow(x, 2) - 4 * x + 2);
        float divider = -pow(x, 2) * (x - 2) * (4 + pow(x, 2));
        if(divider != 0)
        {
            float y = dividend / divider;
            std::cout
        	<< "x: " << x << " result: " << y << " test: "
        	<<(2 * pow(x, 3) + 6 * pow(x, 2) - 8 * x + 4) / (-4 * pow(x, 3) + 8 * pow(x, 2) - pow(x, 5) + 2 * pow(x, 4))
        	<<std::endl;
        }
    }
}
//вариант 5 лаба 7
class lab7
{
    public:

	static float firstMethod(int x)
	{
        if (x < -2)
            return -1;
	}
};
//вариант 5, лаба 9
struct vector2
{
    std::pair<int, int> start, end;
    double lenght = 0;
    int x, y;
    vector2(std::pair<int, int> a, std::pair<int, int> b): start(a), end(b)
    {
        lenght = len_calc(start, end);
        x = end.first - start.first;
        y = end.second - start.second;
    }

	double operator+(const vector2& v) const
    {
       return  v.lenght + lenght;
    }
private:
    double len_calc(std::pair<int, int> a, std::pair<int, int> b)
    {
        return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
    }
};

double angle_calc(vector2 first, vector2 second)
{
    float cosinus = abs(first.x * second.x + first.y * second.y) / (first.lenght * second.lenght);
    return acos(cosinus) * 180 / M_PI;
}
std::string lab9(std::pair<int,int> a, std::pair<int, int> b, std::pair<int, int> c, std::pair<int, int> d)
{
    //иницилизируем все стороны
    vector2 vectors[] =
    {
        vector2(a,b),
        vector2(b,c),
        vector2(c,d),
        vector2(d,a)
    };
    //если противоположные стороны параллельны
    if (angle_calc(vectors[0], vectors[2]) == 0 && angle_calc(vectors[1], vectors[3]) == 0)
    {
        //если противоположные стороны равны
        if (vectors[0].lenght == vectors[2].lenght && vectors[1].lenght == vectors[3].lenght)
        {
            //если все стороны равны
            if ((vectors[0] + vectors[1] + (vectors[2] + vectors[3])) / 4 == vectors[0].lenght)
            {
                //и перпендикулярны
                if ((int)angle_calc(vectors[0], vectors[1]) == 90)
                    return "square";
                return "rhombus";
            }
            //если все перперндикулярны, но не равны
            if ((int)angle_calc(vectors[0], vectors[1]) == 90)
            {
                return "rectangle";
            }
            return "parallelogram";
        }
    }
		//если хотя бы одна пара противоположных сторон паралелльна
        if (vectors[0].lenght == vectors[2].lenght || vectors[1].lenght == vectors[3].lenght)
            return "trapezoid";
		
        auto iter = std::find_if(std::begin(vectors) + 1, std::end(vectors), [vectors](vector2 param) { return param.lenght == vectors[0].lenght; });
        if (iter != std::end(vectors))
        {
            std::remove_if(std::begin(vectors), std::end(vectors), [iter](vector2 v)
                {
                   return v.lenght == iter->lenght;
                });
            if (vectors[0].lenght == vectors[1].lenght)
                return "deltoid";
        }
        return "arbitrary quadrangle";
    }
//вариант 7, лаба 10
std::pair<int, int> lab10(std::pair<int,int> numbers)
{
    std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
    int ranks[]{ numbers.first % 10,numbers.first / 10, numbers.second % 10,numbers.second / 10 };
   auto iter = std::remove_if(vec.begin(), vec.end(), [ranks](int num)
        {
           return std::find(std::begin(ranks), std::end(ranks), num) != std::end(ranks);
        });
   vec.erase(iter, vec.end());
   int min, max;
   if (vec[0] == 0)
   {
       min = vec[1] * 10 + vec[0];
   }
   else min = vec[0] * 10 + vec[0];
   max = *(vec.end() - 1) * 10 + *(vec.end() - 1);
   return std::pair<int,int>(min,max);
}

int main()
{
    //ромб
    std::cout << lab9(std::pair<int, int>(3, 2), std::pair<int, int>(1, 5), std::pair<int, int>(3, 8), std::pair<int, int>(5, 5))<<std::endl;
    //квадрат
    std::cout << lab9(std::pair<int, int>(1, 1), std::pair<int, int>(1, 5), std::pair<int, int>(5, 5), std::pair<int, int>(5, 1)) << std::endl;
    //прямоугольник
    std::cout << lab9(std::pair<int, int>(1, 1), std::pair<int, int>(1, 8), std::pair<int, int>(5, 8), std::pair<int, int>(5, 1)) << std::endl;
    //lab10(std::pair<int, int>(12, 87));
}


