#include "oldLabClass.h"

#include <corecrt_math_defines.h>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include<regex>

//    //вариант 2, лаба 4
//    void lab4()
//    {
//        int A[] = { 1,2,-2,3,4 };
//        for (int a : A)
//        {
//            int B = a + 2;
//            int c1 = a + 3;
//            int c2 = a + 2;
//            int d1 = a + 4;
//            int d2 = a + 3;
//            int e1 = a + 5;
//            int e2 = a + 4;
//            std::cout << "B: " + std::to_string(B) << std::endl;
//            if (c2 != 0)
//            {
//                int C = c1 / c2;
//                std::cout << "C: " + std::to_string(C) << " Test: " << (a + 3) / (a + 2) << std::endl;
//            }
//            if (d2 != 0)
//            {
//                int D = d1 / d2;
//                std::cout << "D: " + std::to_string(D) << " Test: " << (a + 4) / (a + 3) << std::endl;
//            }
//            if (e2 != 0)
//            {
//                int E = e1 / e2;
//                std::cout << "E: " + std::to_string(E) << " Test: " << (a + 5) / (a + 4) << std::endl;
//            }
//            std::cout << "\n";
//        }
//    }
//    //вариант 2, лаба 5
//    void lab5(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c)
//    {
//        //поиск длин всех сторон
//        double la = sqrt(std::pow(b.first - a.first, 2) + std::pow(b.second - a.second, 2));
//        double lb = sqrt(std::pow(c.first - b.first, 2) + std::pow(c.second - b.second, 2));
//        double lc = sqrt(std::pow(a.first - c.first, 2) + std::pow(a.second - c.second, 2));
//
//        //полупериметр
//        double p = (la + lb + lc) / 2;
//        //площадь треугольника
//        double S = sqrt(p * (p - la) * (p - lb) * (p - lc));
//        //определяем углы через формулу
//        double angles[] =
//        {
//           (asin(S / (0.5f * la * lb))) * 180 / M_PI,
//          (asin(S / (0.5f * lb * lc))) * 180 / M_PI,
//          (asin(S / (0.5f * lc * la))) * 180 / M_PI
//        };
//        std::cout << "Sides: " << la << " " << lb << " " << lc << "\n";
//        std::cout << "Angles: ";
//        std::copy(std::begin(angles), std::end(angles), std::ostream_iterator<double>(std::cout, " "));
//        std::cout << "\n";
//        //проверка на правильность
//        std::cout << "Sum of angles: " << std::accumulate(std::begin(angles), std::end(angles), .0f);
//    }
//    //вариант 1, лаба 6
//    void lab6()
//    {
//
//        int X[] = { -5,-2,2,5 };
//        for (auto x : X)
//        {
//            float dividend = 2 * (pow(x, 3) + 3 * pow(x, 2) - 4 * x + 2);
//            float divider = -pow(x, 2) * (x - 2) * (4 + pow(x, 2));
//            if (divider != 0)
//            {
//                float y = dividend / divider;
//                std::cout
//                    << "x: " << x << " result: " << y << " test: "
//                    << (2 * pow(x, 3) + 6 * pow(x, 2) - 8 * x + 4) / (-4 * pow(x, 3) + 8 * pow(x, 2) - pow(x, 5) + 2 * pow(x, 4))
//                    << std::endl;
//            }
//        }
//    }
//    //вариант 5 лаба 7
//    class lab7
//    {
//    public:
//
//        static float firstMethod(float x)
//        {
//            float result;
//            if (-2 > x)
//                result = -1;
//            else {
//                if (1 <= x)
//                    result = 0;
//                else
//                {
//                    if (x < 0)
//                        result = x + 1;
//                    else result = 1;
//                }
//            }
//            return result;
//        }
//        static float secondMethod(float x)
//        {
//            if (-2 > x)
//                return -1;
//            if (0 <= x && x < 1)
//                return 1;
//            if (-2 <= x && x < 0)
//                return x + 1;
//            return 0;
//        }
//    };
//
//    //8, вариант 11
//    class lab8
//    {
//    public:
//
//        static int firstMethod(float x, float y)
//        {
//            int result = 0;
//            if (abs(y) >= abs(0.5 * x))
//            {
//                result = 2;
//            }
//            else
//            {
//                if (x > 0)
//                {
//                    if (x <= 2)
//                    {
//                        result = 1;
//                    }
//                    else result = 3;
//                }
//                else result = 4;
//            }
//            return result;
//        }
//
//        static int secondMethod(float x, float y)
//        {
//            int result = 4;
//            if (abs(y) >= abs(0.5 * x))
//            {
//                result = 2;
//            }
//            if (abs(y) < abs(0.5 * x) && x > 0)
//            {
//                if (x <= 2)
//                    result = 1;
//                if (x > 2)
//                    result = 3;
//            }
//            return result;
//        }
//    };
//    //вариант 5, лаба 9
//    struct vector2
//    {
//        std::pair<int, int> start, end;
//        double length;
//        int x, y;
//        vector2(std::pair<int, int> a, std::pair<int, int> b) : start(a), end(b)
//        {
//            length = len_calc(start, end);
//            x = end.first - start.first;
//            y = end.second - start.second;
//        }
//
//        double operator+(const vector2& v) const
//        {
//            return  v.length + length;
//        }
//    private:
//        double len_calc(std::pair<int, int> a, std::pair<int, int> b)
//        {
//            return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
//        }
//    };
//
//    double angle_calc(vector2 first, vector2 second)
//    {
//        float cosinus = abs(first.x * second.x + first.y * second.y) / (first.length * second.length);
//        return acos(cosinus) * 180 / M_PI;
//    }
//    std::string lab9(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c, std::pair<int, int> d)
//    {
//        //иницилизируем все стороны
//        vector2 vectors[] =
//        {
//            vector2(a,b),
//            vector2(b,c),
//            vector2(c,d),
//            vector2(d,a)
//        };
//        //если противоположные стороны параллельны
//        if (angle_calc(vectors[0], vectors[2]) == 0 && angle_calc(vectors[1], vectors[3]) == 0)
//        {
//            //если противоположные стороны равны
//            if (vectors[0].length == vectors[2].length && vectors[1].length == vectors[3].length)
//            {
//                //если все стороны равны
//                if ((vectors[0] + vectors[1] + (vectors[2] + vectors[3])) / 4 == vectors[0].length)
//                {
//                    //и перпендикулярны
//                    if ((int)angle_calc(vectors[0], vectors[1]) == 90)
//                        return "square";
//                    return "rhombus";
//                }
//                //если все перперндикулярны, но не равны
//                if ((int)angle_calc(vectors[0], vectors[1]) == 90)
//                {
//                    return "rectangle";
//                }
//                return "parallelogram";
//            }
//        }
//        //если хотя бы одна пара противоположных сторон паралелльна
//        if (angle_calc(vectors[0], vectors[2]) == 0 || angle_calc(vectors[1], vectors[3]) == 0)
//            return "trapezoid";
//
//        auto iter = std::find_if(std::begin(vectors) + 1, std::end(vectors), [vectors](vector2 param) { return param.length == vectors[0].length; });
//        if (iter != std::end(vectors))
//        {
//            std::remove_if(std::begin(vectors), std::end(vectors), [iter](vector2 v)
//                {
//                    return v.length == iter->length;
//                });
//            if (vectors[0].length == vectors[1].length)
//                return "deltoid";
//        }
//        return "arbitrary quadrangle";
//    }
//    //вариант 7, лаба 10
//    std::pair<int, int> lab10(std::pair<int, int> numbers)
//    {
//        std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
//        int ranks[]{ numbers.first % 10,numbers.first / 10, numbers.second % 10,numbers.second / 10 };
//        auto iter = std::remove_if(vec.begin(), vec.end(), [ranks](int num)
//            {
//                return std::find(std::begin(ranks), std::end(ranks), num) != std::end(ranks);
//            });
//        vec.erase(iter, vec.end());
//        int min, max;
//        if (vec[0] == 0)
//        {
//            min = vec[1] * 10 + vec[0];
//        }
//        else min = vec[0] * 10 + vec[0];
//        max = *(vec.end() - 1) * 10 + *(vec.end() - 1);
//        return std::pair<int, int>(min, max);
//    }
//    //лаба 11, 7
//    void lab11()
//    {
//        std::cout << /*"x\t\t" +*/"sqrt(x - 1)\tF(x)\t\toptimized F(x)\tdelta\t\t\trelative delta\n";
//        for (double x = 1; x >= pow(0.5, 6); x *= 0.5)
//        {
//            //std::cout <<x<<"\t\t";
//            std::cout << sqrt(x + 1) << "\t\t";
//            double nonOptimized = 1 + x / 2 - pow(x, 2) / (2 * 4) + pow(x, 3) / (2 * 4 * 6) - 3 * 5 * pow(x, 4) / (2 * 4 * 6 * 8);
//            double optimized = 1 + x / 2 - pow(x, 2) / 8 + pow(x, 3) / 16 - 5 * pow(x, 4) / 128;
//            std::cout << nonOptimized << "\t\t" << optimized << "\t\t";
//            double del = abs(nonOptimized - optimized);
//            double relativeDel = del / optimized;
//            std::cout << del << "\t\t" << relativeDel * 100 << "%";
//            std::cout << std::endl;
//        }
//    }
//    //лаба 13, 2
//    void lab13(int x, bool useWhile = false)
//    {
//        int divCount = 0;
//        bool minEx = 0;
//        if (!useWhile)
//        {
//
//            for (int i = 2; i <= x; i++)
//            {
//                if (x % i == 0)
//                {
//                    if (!minEx)
//                    {
//                        std::cout << "Min divider: " << i << "\n";
//                        minEx = 1;
//                    }
//                    std::cout << i << "\n";
//                    divCount++;
//                }
//            }
//
//        }
//        else
//        {
//            int i = 2;
//            while (i <= x)
//            {
//                if (x % i == 0)
//                {
//                    if (!minEx)
//                    {
//                        std::cout << "Min divider: " << i << "\n";
//                        minEx = 1;
//                    }
//                    std::cout << i << "\n";
//                    divCount++;
//                }
//                i++;
//            }
//
//        }
//        if (divCount == 1)
//            std::cout << "Prime";
//        else std::cout << "not a prime number";
//    }
//
//    //16 вариант 23
//    class matrix
//    {
//    private:
//        float** _matrix;
//    public:
//        float min_in_upper_triangle_matrix()
//        {
//            float min = _matrix[0][0];
//            for (int i = 0; i < SIDE; i++)
//                for (int j = i; j < SIDE; j++)
//                {
//                    min = min > _matrix[i][j] ? _matrix[i][j] : min;
//                }
//            return min;
//        }
//
//        float find_multiple(float lessNumber)
//        {
//            bool findAnyNumber = false;
//            float multiple = 1;
//            for (int i = 0; i < SIDE; i++)
//                for (int j = 0; j <= i; j++)
//                {
//                    if (_matrix[i][j] < lessNumber)
//                    {
//                        multiple *= _matrix[i][j];
//                        findAnyNumber = true;
//                    }
//                }
//            if (!findAnyNumber)
//                throw std::string("all numbers are greater than a given number");
//            return  multiple;
//        }
//
//        const int SIDE;
//
//        matrix(const int side, float** m) :SIDE(side)
//        {
//            _matrix = new float* [side];
//            for (int i = 0; i < side; i++)
//            {
//                _matrix[i] = new float[side];
//                for (int a = 0; a < side; a++)
//                {
//                    _matrix[i][a] = m[i][a];
//                }
//            }
//        }
//        void lab16()
//        {
//            for (int i = 0; i < SIDE; i++)
//            {
//                for (int j = 0; j < SIDE; j++)
//                {
//                    std::cout << _matrix[i][j] << "\t";
//                }
//                std::cout << "\n";
//            }
//            float min = min_in_upper_triangle_matrix();
//            std::cout << "min: " << min << "\n";
//            try
//            {
//                std::cout << "multiple = " << find_multiple(min_in_upper_triangle_matrix());
//            }
//            catch (std::string ex)
//            {
//                std::cout << ex;
//            }
//        }
//        ~matrix()
//        {
//            for (int i = 0; i < SIDE; i++)
//            {
//                delete[] _matrix[i];
//            }
//            delete[] _matrix;
//        }
//    };
//
//    float** matrix_console_input(int sideElements)
//    {
//        std::regex reg = std::regex(R"(([-]?\d+\d*([.]\d+)*))");
//        float** arr = new float* [sideElements];
//        for (int i = 0; i < sideElements; i++)
//        {
//            std::string str;
//            std::cin.sync();
//            std::getline(std::cin, str);
//            std::vector<std::string> matches{
//                std::sregex_token_iterator{str.begin(), str.end(), reg, 0},
//                std::sregex_token_iterator() };
//
//            if (matches.size() != sideElements)
//                throw "too many elements";
//
//            float* array = new float[sideElements];
//            for (int j = 0; j < sideElements; j++)
//            {
//                array[j] = std::atof(matches[j].c_str());
//            }
//            arr[i] = array;
//        }
//        return  arr;
//    }
//
//    class equationSolution
//    {
//    public:
//        static constexpr float START_X = -0.17f;
//
//        static  float get_function_result(float x)
//        {
//            return exp(-3 * x) - sin(x) - 1.5;
//        }
//        static float derivative(float x)
//        {
//            return (3 + exp(3 * x) * cos(x)) / exp(3 * x);
//        }
//        static float g_x(float x)
//        {
//            return x - derivative(1.9) * get_function_result(x);
//        }
//        static float iterative_method(float x, float e, int maxIteration = 1000000)
//        {
//            float result = g_x(x);
//            int iter = 0;
//
//            while (abs(x - result) > e && iter < maxIteration)
//            {
//                x = result;
//                result = g_x(x);
//                iter++;
//            }
//            if (maxIteration != iter)
//                return x;
//            throw std::string("infinity loop");
//        }
//
//        static float binary_method(float left, float right, float e)
//        {
//            if (get_function_result(left) * get_function_result(right) >= 0)
//                throw std::string("incorrect");
//            float halfSum = get_function_result((left + right) / 2);
//            if (halfSum / get_function_result(left) > 0)
//            {
//                left = (left + right) / 2;
//            }
//            else right = (left + right) / 2;
//
//            if (abs(right - left) > e)
//                return binary_method(left, right, e);
//            // return get_function_result((left + right) / 2);
//            return (left + right) / 2;
//        }
//    };
//    class fibonacci
//    {
//    private:
//        std::vector<long> _numbers{ 1,1 };
//
//        long recursive(int number)
//        {
//            if (_numbers.size() > number)
//                return _numbers[number];
//            _numbers.push_back(recursive(number - 2) + recursive(number - 1));
//            return _numbers[number];
//        }
//
//        long iterative(int number)
//        {
//            while (_numbers.size() <= number)
//            {
//                _numbers.push_back(*(_numbers.end() - 1) + *(_numbers.end() - 2));
//            }
//            return _numbers[number];
//        }
//    public:
//        int operator[](const int index)
//        {
//            if (index < 0)
//                throw std::exception("less than zero");
//#if _DEBUG
//            std::cout << "recursive: " << recursive(index) << '\n';
//            _numbers = { 1,1 };
//            std::cout << "iterative: " << iterative(index) << std::endl;
//#endif
//
//            return recursive(index);
//        }
//    };
//    namespace lab18
//    {
//        template<typename T>
//        void input_arr(T* arr, int len, std::istream& stream)
//        {
//            for (int i = 0; i < len; i++)
//            {
//                T num;
//                stream >> num;
//                arr[i] = num;
//            }
//        }
//        template<typename T>
//        void output(T* arr, int len, std::ostream& stream)
//        {
//            for (int i = 0; i < len; i++)
//                stream << arr[i] << "\n";
//        }
//        typedef int (*compare_function_type) (const void*, const void*);
//
//        void swap_byte(char* first_pointer, char* second_pointer)
//        {
//            char temp = *first_pointer;
//            *first_pointer = *second_pointer;
//            *second_pointer = temp;
//        }
//        void swap(void* first, void* second, int width)
//        {
//            for (int byte = 0; byte < width; ++byte)
//            {
//                swap_byte((char*)first + byte,
//                    (char*)second + byte);
//            }
//
//        }
//
//        template<typename T>
//        int find_index(T* startIter, T* endIter, compare_function_type comparator)
//        {
//            T actualNum = *startIter;
//            int actualIndex = 0;
//            int index = 1;
//            for (; startIter != endIter - 1; index++)
//            {
//                if (comparator(&actualNum, startIter + 1) == -1)
//                {
//                    actualNum = *(startIter + 1);
//                    actualIndex = index;
//                }
//                startIter++;
//            }
//            return actualIndex;
//        }
//        template<typename T>
//        void selection_sort(T* startIter, T* endIter, compare_function_type comparator)
//        {
//            T* nowIterate = startIter;
//            for (int offset = 0; startIter + offset != endIter; offset++)
//            {
//                int index = find_index(nowIterate, endIter, comparator);
//                swap((void*)(nowIterate + index), (void*)(nowIterate), sizeof(nowIterate));
//                //std::swap(*(nowIterate+index), *nowIterate);
//                nowIterate = startIter + offset + 1;
//            }
//        }
//
//        template<typename T>
//        int compare(const void* firstP, const void* secondP)
//        {
//            T first = *static_cast<const T*>(firstP);
//            T second = *static_cast<const T*>(secondP);
//            if (first > second)
//                return -1;
//            if (second > first)
//                return 1;
//            return 0;
//        }
//        template<typename T>
//        int reverce(const void* firstP, const void* secondP)
//        {
//            return -1 * compare<T>(firstP, secondP);
//        }
//    }
//
//    class sorts
//    {
//    private:
//        static void insert(int arr[], int left, int right)
//        {
//            for (int i = left; i < right; i++)
//            {
//                std::swap(arr[i], arr[right]);
//            }
//        }
//        static int find_minimum(int* arr, int len)
//        {
//            int minIndex = 0;
//            int minVal = arr[0];
//            for (int i = 1; i < len; i++)
//            {
//                if (minVal > arr[i])
//                {
//                    minIndex = i;
//                    minVal = arr[i];
//                }
//            }
//            return minIndex;
//        }
//    public:
//        static void insertion_sort(int input_arr[], int len)
//        {
//            for (int i = 0; i < len; i++)
//            {
//                for (int a = 0; a < i; a++)
//                {
//                    if (input_arr[a] >= input_arr[i])
//                    {
//                        insert(input_arr, a, i);
//                    }
//                }
//            }
//        }
//        static void bubble_sort(int input_arr[], int len)
//        {
//            for (int i = 0; i < len - 1; i++)
//            {
//                for (int a = 0; a < len - i - 1; a++)
//                    if (input_arr[a + 1] < input_arr[a])
//                        std::swap(input_arr[a], input_arr[a + 1]);
//            }
//        }
//        static void selection_sort(int input_arr[], int len)
//        {
//            for (int i = 0; i < len - 1; i++)
//            {
//                int index = find_minimum(&input_arr[i], len - i);
//                std::swap(input_arr[i], input_arr[index + i]);
//            }
//        }
//    };
//    __interface ICounter
//    {
//    public:
//        ICounter* compare_count();
//        ICounter* copy_count();
//    };
//    class simple_counter : public ICounter
//    {
//    private:
//        unsigned long long compare_counter;
//        unsigned long long copy_counter;
//    public:
//        simple_counter()
//        {
//            copy_counter = 0;
//            compare_counter = 0;
//        }
//        ICounter* compare_count()
//        {
//            compare_counter++;
//            return this;
//        }
//        ICounter* copy_count()
//        {
//            copy_counter++;
//            return this;
//        }
//        long long get_compares()
//        {
//            return (long long)compare_counter;
//        }
//        long long get_copies()
//        {
//            return (long long)copy_counter;
//        }
//    };
//    struct complex
//    {
//        double first;
//        double second;
//        complex()
//        {
//            first = 0;
//            second = 0;
//        }
//        complex(double first, double second)
//        {
//            this->first = first;
//            this->second = second;
//        }
//        static complex generate_complex()
//        {
//            return complex((double)rand() / RAND_MAX * 100, (double)rand() / RAND_MAX * 100);
//        }
//        complex operator+(complex& c1)
//        {
//            return complex(c1.first + first, c1.second + second);
//        }
//    };
//    class matrix
//    {
//    private:
//        complex _m[2][2];
//        double norm;
//        double set_norm()
//        {
//            complex sum = complex(0, 0);
//            for (int i = 0; i < 2; i++)
//                for (int a = 0; a < 2; a++)
//                {
////                    sum = sum /*+ _m[i][a];
//                }
//            return sqrt(pow(sum.first, 2) + pow(sum.second, 2));
//        }
//    public:
//        matrix(complex** inputMatrix)
//        {
//            for (int i = 0; i < 2; i++)
//                for (int a = 0; a < 2; a++)
//                    _m[i][a] = inputMatrix[i][a];
//            norm = set_norm();
//        }
//        matrix()
//        {
//            for (int i = 0; i < 2; i++)
//                for (int a = 0; a < 2; a++)
//                    _m[i][a] = complex::generate_complex();
//            norm = set_norm();
//        }
//        double get_norm()
//        {
//            return norm;
//        }
//        void outputMatrix()
//        {
//            for (int i = 0; i < 2; i++)
//            {
//                for (int a = 0; a < 2; a++)
//                    std::cout << "(" << _m[i][a].first << " " << _m[i][a].second << ") ";
//                std::cout << std::endl;
//            }
//            std::cout << "norm: " << norm << "\n\n";
//        }
//        bool operator<(matrix& m)
//        {
//            return norm < m.get_norm();
//        }
//        bool operator>(matrix& m)
//        {
//            return norm > m.get_norm();
//        }
//    };
//    class matrixHandler
//    {
//    private:
//        ICounter* _counter;
//    public:
//        matrixHandler(ICounter* ic)
//        {
//            set_counter(ic);
//        }
//        void set_counter(ICounter* ic)
//        {
//            _counter = ic;
//        }
//        void BubbleSort(matrix* startP, matrix* endP)
//        {
//            matrix* iterP = startP;
//            matrix* startIteration = startP;
//            for (int i = 0; startP != endP - 1; startP++, i++)
//            {
//                for (; iterP != endP - 1 - i; iterP++)
//                {
//                    if (*iterP < *(iterP + 1))
//                    {
//                        std::swap(*iterP, *(iterP + 1));
//                        _counter->copy_count()->copy_count()->copy_count();
//                    }
//                    _counter->compare_count();
//                }
//                iterP = startIteration;
//            }
//        }
//
//    };*/