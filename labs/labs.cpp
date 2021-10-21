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
public:
    float min_in_upper_triangle_matrix()
    {
        float min = _matrix[0][0];
        for (int i = 0; i < SIDE; i++)
            for (int j = i; j < SIDE; j++)
            {
                min = min > _matrix[i][j] ? _matrix[i][j] : min;
            }
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

    const int SIDE;

	matrix(const int side, float **m):SIDE(side)
	{
        _matrix = new float*[side];
        for(int i =0; i< side; i++)
        {
            _matrix[i] = new float[side];
            for(int a =0;a < side; a++)
            {
                _matrix[i][a] = m[i][a];
            }
        }
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
        float min = min_in_upper_triangle_matrix();
        std::cout << "min: " << min << "\n";
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
            delete[] _matrix[i];
		}
        delete[] _matrix;
	}
};

float** matrix_console_input(int sideElements)
{
    std::regex reg = std::regex(R"(([-]?\d+\d*([.]\d+)*))");
    float** arr = new float* [sideElements];
    for (int i = 0; i < sideElements; i++)
    {
        std::string str;
        std::cin.sync();
        std::getline(std::cin, str);
        std::vector<std::string> matches{
            std::sregex_token_iterator{str.begin(), str.end(), reg, 0},
            std::sregex_token_iterator() };

        if (matches.size() != sideElements)
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

class equationSolution
{
public:
	static constexpr float START_X = -0.17f;

	static  float get_function_result(float x)
    {
        return exp(-3 * x) - sin(x) - 1.5;
    }
    static float derivative(float x)
	{
        return (3+exp(3*x)*cos(x))/exp(3*x);
	}
    static float g_x(float x)
	{
		return x - derivative(1.9) * get_function_result(x);
	}
    static float iterative_method(float x, float e, int maxIteration = 1000000)
    {
        float result = g_x(x);
        int iter = 0;

        while (abs(x - result) > e && iter < maxIteration) 
        {
            x = result;
            result = g_x(x);
            iter++;
        }
        if(maxIteration != iter)
        return x;
        throw std::string("infinity loop");
    }

    static float binary_method(float left, float right,float e)
	{
        if (get_function_result(left) * get_function_result(right) >= 0)
            throw std::string("incorrect");
        float halfSum = get_function_result((left + right) / 2);
        if (halfSum / get_function_result(left) > 0)
        {
            left = (left + right) / 2;
        }
        else right = (left + right) / 2;

        if (abs(right - left) > e)
            return binary_method(left, right, e);
       // return get_function_result((left + right) / 2);
        return (left + right) / 2;
	}
	
};

int main()
{


    srand(time(NULL));

    try 
    {
        std::cout << equationSolution::binary_method(-abs(equationSolution::START_X), abs(equationSolution::START_X), 0.01f) << std::endl;
    }
    catch (std::string ex)
    {
        std::cout << ex << std::endl;
    }
    for (int i = 1; i < 30; i ++)
    {
        try
        {
            std::cout <<"x= "<<i<<" result = "<< equationSolution::iterative_method(i, 0.01) << std::endl;
        }
        catch (std::string ex)
        {
            std::cout << ex<<std::endl;
        }
    }

}


