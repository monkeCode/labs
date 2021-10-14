// labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include<numeric>
#include<cmath>
#include <functional>
#include <vector>
#include<regex>

//лаба 15, 23 вариант
void lab15(std::pair<double,double> segment, double step)
{
    double args[12];
    int i = 0;
	for(double x = segment.first ; x <= segment.second, i < 12 ; x+=step)
	{
        std::cout << exp(-x / 3) * pow(sin(5 * x), 2)<<std::endl;
	}
}

//16 вариант 23
class matrix
{
private:
    float** _matrix;

    float min_in_upper_triangle_matrix()
    {
        float min = _matrix[0][0];
        for (int i = 0; i < SIDE; i++)
            for (int j = i; j < SIDE; j++)
            {
                min = min > _matrix[i][j] ? _matrix[i][j] : min;
            }
        std::cout << "min: " << min << "\n";
        return min;
    }

	float find_multiple(float lessNumber)
    {
        bool findAnyNumber = false;
        float multiple = 1;
	    for(int i = 0; i <SIDE;i++)
            for (int j = 0; j <=i;j++)
            {
                if (_matrix[i][j] < lessNumber)
                {
                    multiple *= _matrix[i][j];
                    findAnyNumber = true;
                }
            }
        if (!findAnyNumber)
            throw std::string("all numbers are greater than a given number");
        return  multiple;
    }
public:
    const int SIDE;

	matrix(const int side, float **m):SIDE(side)
	{
        _matrix = m;
	}
    void lab16()
	{
        for (int i = 0; i < SIDE; i++)
        {
            for (int j = 0; j < SIDE; j++)
            {
                std::cout << _matrix[i][j] << "\t";
            }
            std::cout << "\n";
        }
        try 
        {
            std::cout << "multiple = " << find_multiple(min_in_upper_triangle_matrix());
        }
        catch (std::string ex)
        {
            std::cout << ex;
        }
	}
 ~matrix()
	{
		for(int i =0; i< SIDE;i++)
		{
            delete _matrix[i];
		}
        _matrix = nullptr;
	}
};

float** matrix_console_input(int sideElements)
{
    std::regex reg = std::regex(R"((\d+\d*([.]\d+)*))");
    float** arr = new float* [sideElements];
    for (int i = 0; i < sideElements; i++)
    {
        std::string str;
        std::cin.sync();
        std::getline(std::cin, str);
        std::vector<std::string> matches{
            std::sregex_token_iterator{str.begin(), str.end(), reg, 0},
            std::sregex_token_iterator() };
        if (matches.size() > sideElements)
            throw "too many elements";
        float* array = new float[sideElements];
        for (int j = 0; j < sideElements; j++)
        {
            array[j] = std::atof(matches[j].c_str());
        }
        arr[i] = array;
    }
    return  arr;
}

int main()
{


    srand(time(NULL));
  
    int constexpr side = 5;
    /*float* arr[] ={
       new float[] {5,10,20,9,4},
       new float[] {5,6,7,8,9},
       new float[] {10,11,12,13,15},
       new float[] {16,17,18,19,20},
       new float[] {21,3,23,2,25} };*/

    /*float* arr[side];
        for(int i = 0; i< side; i++)
        {
            arr[i] = new float[side];
            for(int a =0; a< side;a++)
            {
                arr[i][a] = rand() % 100;
            }
        }*/


    int sideElements;
    std::string input;
    std::getline(std::cin, input);
    sideElements = std::atoi(input.c_str());
    matrix m = matrix(sideElements, matrix_console_input(sideElements));
    std::cout << '\n';
    m.lab16();

}


