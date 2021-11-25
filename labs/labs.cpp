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
			swap((void*) (nowIterate + index), (void*)(nowIterate), sizeof(nowIterate));
			//std::swap(*(nowIterate+index), *nowIterate);
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

class sorts
{
private:
	static void insert(int arr[], int left, int right)
	{
		for (int i = left; i < right; i++)
		{
			std::swap(arr[i], arr[right]);
		}
	}
	static int find_minimum(int* arr, int len)
	{
		int minIndex = 0;
		int minVal = arr[0];
		for (int i = 1; i < len; i++)
		{
			if (minVal > arr[i])
			{
				minIndex = i;
				minVal = arr[i];
			}
		}
		return minIndex;
	}
public:
	static void insertion_sort(int input_arr[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			for (int a = 0; a < i; a++)
			{
				if (input_arr[a] >= input_arr[i])
				{
					insert(input_arr, a, i);
				}
			}
		}
	}
	static void bubble_sort(int input_arr[], int len)
	{
		for (int i = 0; i < len - 1; i++)
		{
			for (int a = 0; a < len-i-1; a++)
				if (input_arr[a+1] < input_arr[a])
					std::swap(input_arr[a], input_arr[a+1]);
		}
	}
	static void selection_sort(int input_arr[], int len)
	{
		for (int i = 0; i < len - 1; i++)
		{
			int index =	find_minimum(&input_arr[i], len - i);
			std::swap(input_arr[i], input_arr[index+i]);
		}
	}
};
__interface ICounter
{
	public:
	ICounter* compare_count();
	ICounter* copy_count();
};
class simple_counter: public ICounter
{
private:
	unsigned long long compare_counter;
	unsigned long long copy_counter;
public:
	simple_counter()
	{
		copy_counter = 0;
		compare_counter = 0;
	}
	ICounter* compare_count()
	{
		compare_counter++;
		return this;
	}
	ICounter* copy_count()
	{
		copy_counter++;
		return this;
	}
	long long get_compares()
	{
		return (long long)compare_counter;
	}
	long long get_copies()
	{
		return (long long)copy_counter;
	}
};
struct complex
{
	double first;
	double second;
	complex()
	{
		first = 0;
		second = 0;
	}
	complex(double first, double second)
	{
		this->first = first;
		this->second = second;
	}
	static complex generate_complex()
	{
		return complex((double)rand() /RAND_MAX*100 , (double)rand() / RAND_MAX * 100);
	}
	complex operator+(complex& c1)
	{
		return complex(c1.first + first, c1.second + second);
	}
};
class matrix
{
private:
	complex _m[2][2];
	double norm;
	double set_norm()
	{
		complex sum = complex(0,0);
		for (int i = 0; i < 2; i++)
			for (int a = 0; a < 2; a++)
			{
				sum = sum + _m[i][a];
			}
		return sqrt(pow(sum.first,2) + pow(sum.second, 2));
	}
public:
	matrix(complex **inputMatrix)
	{
		for (int i = 0; i < 2; i++)
			for (int a = 0; a < 2; a++)
				_m[i][a] = inputMatrix[i][a];
		norm = set_norm();
	}
	matrix()
	{
		for (int i = 0; i < 2; i++)
			for (int a = 0; a < 2; a++)
				_m[i][a] = complex::generate_complex();
		norm = set_norm();
	}
	double get_norm()
	{
		return norm;
	}
	void outputMatrix()
	{
		for (int i = 0; i < 2; i++)
		{
			for (int a = 0; a < 2; a++)
				std::cout << "(" << _m[i][a].first << " " << _m[i][a].second << ") ";
			std::cout << std::endl;
		}
		std::cout << "norm: " << norm << "\n\n";
	}
	bool operator<(matrix& m)
	{
		return norm < m.get_norm();
	}
	bool operator>(matrix& m)
	{
		return norm > m.get_norm();
	}
};
class matrixHandler
{
private:
	 ICounter* _counter;
public:
	matrixHandler(ICounter* ic)
	{
		set_counter(ic);
	}
	 void set_counter(ICounter *ic)
	{
		_counter = ic;
	}
	  void BubbleSort(matrix* startP, matrix* endP)
	{
		matrix* iterP = startP;
		matrix* startIteration = startP;
		for (int i = 0; startP != endP - 1; startP++, i++)
		{
			for (; iterP != endP - 1 - i; iterP++)
			{
				if (*iterP < *(iterP + 1))
				{
					std::swap(*iterP, *(iterP + 1));
					 _counter->copy_count()->copy_count()->copy_count();
				}
				_counter->compare_count();
			}
			iterP = startIteration;
		}
	}
		
};
int main()
{
	/*18 лаба*/
	/*lab18::compare_function_type predic = lab18::reverce<float>;
	int len;
	std::cin >> len;
	float *arr = new float[len];
	lab18::input_arr(arr, len, std::cin);
	int index = lab18::find_index(arr, arr + len, predic);
	std::cout <<"index: "<< index<<" result: " <<arr[index] << std::endl;
	lab18::selection_sort(arr, arr+len, predic);
	lab18::output(arr, len, std::cout);
	delete[] arr;
	arr = nullptr;*/

	//20 лаба
	matrix mArray[20];
	simple_counter counter = simple_counter();
	ICounter* ic = &counter;
	matrixHandler mx = matrixHandler(ic);
	mx.BubbleSort(std::begin(mArray), std::end(mArray));
	std::cout << counter.get_compares() << " " << counter.get_copies() << "\n";
	for (auto a : mArray)
	{
		a.outputMatrix();
	}

	int arr[]{ 5,3,67,2,0,2434,565,-3454 };
	sorts::insertion_sort(arr, std::size(arr));
	for (int i = 0; i < std::size(arr); i++)
		std::cout << arr[i]<<" ";
}