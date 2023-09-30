#include <iostream>
#include "Kramer.h"

int main()
{
	int length = 2;
	float x1, x2, x3, y1, y2, y3;
	float* vector;
	float** array;
	float r;

	setlocale(LC_ALL, "");

	std::cout << "Введите значение x первой точки: ";
	std::cin >> x1;
	std::cout << "Введите значение y первой точки: ";
	std::cin >> y1;
	std::cout << "Введите значение x второй точки: ";
	std::cin >> x2;
	std::cout << "Введите значение y второй точки: ";
	std::cin >> y2;
	std::cout << "Введите значение x третьей точки: ";
	std::cin >> x3;
	std::cout << "Введите значение y третьей точки: ";
	std::cin >> y3;

	vector = new float[length];
	vector[0] = (x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1);
	vector[1] = (x3 * x3 - x1 * x1 + y3 * y3 - y1 * y1);

	array = new float* [length];
	for (int i = 0; i < length; i++)
	{
		array[i] = new float[length];
		for (int j = 0; j < length; j++);
	}

	array[0][0] = (2 * (x2 - x1));
	array[0][1] = (2 * (y2 - y1));
	array[1][0] = (2 * (x3 - x1));
	array[1][1] = (2 * (y3 - y1));

	Kramer kramer(array, vector, length);
	float* centre = kramer.GerResultArray();
	r = sqrt((x1 - centre[0]) * (x1 - centre[0]) + (y1 - centre[1]) * (y1 - centre[1]));
	std::cout << std::endl;
	std::cout << "Радиус: " << r << std::endl;
	std::cout << "Координаты центра окружности: " << "( " << centre[0] << ", " << centre[1] << " )";
	std::cout << std::endl;
}