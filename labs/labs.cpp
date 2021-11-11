#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include<numeric>
#include<cmath>
#include <functional>
#include <vector>
#include<regex>

//лаба 15, 23 вариант
void lab15(std::pair<double, double> segment, double step)
{
	double args[12];
	int i = 0;
	for (double x = segment.first; x <= segment.second, i < 12; x += step)
	{
		std::cout << exp(-x / 3) * pow(sin(5 * x), 2) << std::endl;
	}
}

namespace lab18
{
	template<typename T>
	void input_arr(T* arr, int len, std::istream& stream)
	{
		for (int i = 0; i < len; i++)
		{
			T num;
			stream >> num;
			arr[i] = num;
		}
	}
	template<typename T>
	void output(T* arr, int len, std::ostream& stream)
	{
		for (int i = 0; i < len; i++)
			stream << arr[i] << "\n";
	}
	typedef int (*compare_function_type) (const void*, const void*);

	void swap_byte(char* first_pointer, char* second_pointer) 
	{
		char temp = *first_pointer;
		*first_pointer = *second_pointer;
		*second_pointer = temp;
	}
	void swap(void* first, void* second, int width)
	{
		for (int byte = 0; byte < width; ++byte) 
		{
			swap_byte((char*)first + byte,
				(char*)second + byte);
		}

	}

	template<typename T>
	int find_index(T* startIter, T* endIter, compare_function_type comparator)
	{
		T actualNum = *startIter;
		int actualIndex = 0;
		int index = 1;
		for(; startIter != endIter -1; index++)
		{
			if (comparator(&actualNum, startIter + 1) == -1)
			{
				actualNum = *(startIter + 1);
				actualIndex = index;
			}
			startIter++;
		}
		return actualIndex;
	}
	template<typename T>
	void selection_sort(T* startIter, T* endIter, compare_function_type comparator)
	{
		T* nowIterate = startIter;
		for (int offset = 0; startIter + offset != endIter ; offset++)
		{
			int index = find_index(nowIterate, endIter, comparator);
			//swap((void*) nowIterate[index], (void*)(nowIterate), sizeof(nowIterate));
			std::swap(*(nowIterate+index), *nowIterate);
			nowIterate = startIter + offset+1;
		}
	}

	template<typename T>
	int compare(const void* firstP, const void* secondP)
	{
		T first = *static_cast<const T*>(firstP);
		T second = *static_cast<const T*>(secondP);
		if (first > second)
			return -1;
		if (second > first)
			return 1;
		return 0;
	}
	template<typename T>
	int reverce(const void* firstP, const void* secondP)
	{
		return -1 * compare<T>(firstP, secondP);
	}
}

class fibonacci
{
	std::vector<int> _numbers{ 1,1 };

	int recursive(int number)
	{
		if (_numbers.size() > number)
			return _numbers[number];
		_numbers.push_back(recursive(number - 2) + recursive(number - 1));
		return recursive(number - 1) + recursive(number - 2);
	}

	int iterative(int number)
	{
		while (_numbers.size() <= number)
		{
			_numbers.push_back(*(_numbers.end() - 1) + *(_numbers.end() - 2));
		}
		return _numbers[number];
	}
public:
	int operator[](const int index)
	{
		if (index < 0)
			throw std::exception("less than zero");
#if _DEBUG
		std::cout << recursive(index)<<'\n';
		std::cout << iterative(index) << std::endl;
#endif

		return recursive(index);
	}
};

namespace sorts
{

}
struct complex
{
	double first;
	double second;
	static unsigned long long compare_count;
	static unsigned long long copy_counter;
	complex(double first, double second)
	{
		this->first = first;
		this->second = second;
	}
	bool operator <(complex& c)
	{
		return (first + second) < (c.first + c.second);
	}
	bool operator>(complex& c)
	{
		return (first + second) > (c.first + c.second);
	}

	static void BubbleSort(complex* startP, complex* endP)
	{
		complex* iterP = startP;
		complex* startIteration = startP;
		for (int i = 0; startP != endP - 1; startP++, i++)
		{
			for (; iterP != endP - 1 - i; iterP++)
			{
				if (*iterP < *(iterP + 1))
				{
					std::swap(*iterP, *(iterP + 1));
				}
			}
			iterP = startIteration;
		}
	}
};
int main()
{
	//18 лаба
	lab18::compare_function_type predic = lab18::compare<int>;
	int len;
	std::cin >> len;
	float *arr = new float[len];
	lab18::input_arr(arr, len, std::cin);
	int index = lab18::find_index(arr, arr + len, predic);
	std::cout <<"index: "<< index<<" result: " <<arr[index] << std::endl;
	lab18::selection_sort(arr, arr+len, predic);
	lab18::output(arr, len, std::cout);
	delete[] arr;
	arr = nullptr;


	//19 лаба
	//fibonacci f = fibonacci();
	//f[1];


	//20 лаба
	//complex arr[] = { complex(1,3), complex(3,3), complex(1,1), complex(5,5), complex(0,0) };
	//complex::BubbleSort(std::begin(arr), std::end(arr));	//O(n^2)
	//for (auto a : arr)
	//{
	//	std::wcout << a.first << " " << a.second << "\n";
	//}
}