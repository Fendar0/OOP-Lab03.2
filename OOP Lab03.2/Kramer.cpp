#include "Kramer.h"
#include <iostream>

// конструктор
Kramer::Kramer(float** input_mass, float* input_vector, int input_len)
{
	length = input_len;
	array = input_mass;
	vector = input_vector;

	determinant = DeterminantArray(array, length);
	FillIntermediateArray(array, length, vector);
	KramerAnswer(determinantArray, length, determinant);
}

// получение массива с корнями СЛАУ
float* Kramer::GerResultArray()
{
	return resultArray;
}

// нахождение определителя главной матрицы
float Kramer::DeterminantArray(float** array, int length)
{
	if (length == 1)
		return **array;
	else if (length == 2)
	{
		return array[0][0] * array[1][1] - array[0][1] * array[1][0];
	}
	else {
		float d = 0;
		for (int k = 0; k < length; k++) {
			float** m = new float* [length - 1];
			for (int i = 0; i < length - 1; i++) {
				m[i] = new float[length - 1];
			}
			for (int i = 1; i < length; i++) {
				int t = 0;
				for (int j = 0; j < length; j++) {
					if (j == k)
						continue;
					m[i - 1][t] = array[i][j];
					t++;
				}
			}
			d += pow(-1, k + 2) * array[0][k] * DeterminantArray(m, length - 1);
		}
		return d;
	}
}

// поиск определителей промежуточных матриц
void Kramer::FillIntermediateArray(float** array, int length, float* vector)
{
	determinantArray = new float[length];
	intermediateArray = new float*[length];
	for (int c = 0; c < length; c++)
	{
		for (int i = 0; i < length; i++)
		{
			intermediateArray[i] = new float[length];
			for (int j = 0; j < length; j++)
				intermediateArray[i][j] = array[i][j];
		}

		for (int i = 0; i < length; i++)
		{
			for (int j = c; j < length; j++)
			{
				intermediateArray[i][j] = vector[i];
				break;
			}
		}
		determinantArray[c] = DeterminantArray(intermediateArray, length);
	}
}

// расчет корней СЛАУ
void Kramer::KramerAnswer(float* determinantArray, int length, float determinant)
{
	resultArray = new float[length];
	for (int i = 0; i < length; i++)
		resultArray[i] = round(determinantArray[i] / determinant * 10000) / 10000;
}


