#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include<numeric>
#include<cmath>
#include <functional>
#include <vector>
#include<regex>
#include "labs.h"

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

const int ARRAY_LENGTH = 100000;
const int ARRAY_HEIGHT = 100;
const int ARRAY_WIDTH = 200;
//Функция работает с массивами произвольной длины (универсальна)
void Zero1DArray(char my_1d_array[], int length) {
	for (int index = 0; index < length; ++index) {
		my_1d_array[index] = 0;
	}
	return;
}
//Эта функция работает только с массивами массивов длины ARRAY_WIDTH (не универсальна!)
void Zero2DStaticArray(char my_2d_array[][ARRAY_WIDTH], int height, int width) {
	for (int row_index = 0; row_index < height; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			my_2d_array[row_index][column_index] = 0;
		}
	}
	return;
}
//Функция работает с массивами произвольной длины, но не может принять на вход статический массив.
//Она принимает на вход массив указателей на числа.
void Zero2DDynamicArray(char** my_2d_array, int height, int width) {
	for (int row_index = 0; row_index < height; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			my_2d_array[row_index][column_index] = 0;
		}
	}
	return;
}
//Функция работает с двумерными статическими массивами произвольных размеров
void Zero2DStaticArrayUniversal(char my_2d_array[], int height, int width) {
	for (int row_index = 0; row_index < height; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			my_2d_array[row_index * width + column_index] = 0;
		}
	}
	return;
}

void Input3DStaticArray(int my_3d_array[], int height, int width, int depth) {
	for (int row_index = 0; row_index < height; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			for (int depth_index = 0; depth_index < depth; ++depth_index) {
				std::cin>> my_3d_array[(row_index * width + column_index) * depth +
					depth_index];
			}
		}
	}
}
void Input3DDynamicArray(int*** my_3d_array, int height, int width, int depth) {
	for (int row_index = 0; row_index < height; ++row_index) {
		for (int column_index = 0; column_index < width; ++column_index) {
			for (int depth_index = 0; depth_index < depth; ++depth_index) {
				std::cin>> my_3d_array[row_index][column_index][depth_index];
			}
		}
	}
}

int*** AllocateMemory(int height, int width, int depth)
{
	int* dataBlock = new int[height * width * depth];
	int** firstPointersBlock = new int* [height * width];
	int*** arr = new int** [height];
	for (int i = 0; i < height; i++)
	{
		arr[i] = &firstPointersBlock[i*width];
		//arr[i] = new int* [width];
		for (int j = 0; j < width; j++)
			arr[i][j] = &dataBlock[(i * width + j) * depth];
	}
	return arr;
}

void FreeMemory(int*** arr, int height, int width, int depth)
{
	delete[] &arr[0][0][0];
	delete[] & arr[0][0];
	/*for (int i = 0; i < height; i++)
	{
		delete[] arr[i];
	}*/
	delete[] arr;

}
void Output3Darray(int*** arr, int height, int width, int depth)
{

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			for (int k = 0; k < depth; k++)
				std::cout << (**arr)[(i * width + j) * depth + k] << " ";
}
int main()
{
	int height = 2;
	int width = 3;
	int depth = 2;

	auto arr = AllocateMemory(height, width, depth);
	Input3DStaticArray(&arr[0][0][0], height, width, depth);
	Output3Darray(arr, height, width, depth);
	std::cout << '\n';
	Input3DDynamicArray(arr, height, width, depth);
	Output3Darray(arr, height, width, depth);
	FreeMemory(arr, height, width, depth);
}