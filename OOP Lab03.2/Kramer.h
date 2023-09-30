#pragma once
class Kramer
{
private:
	float x1, x2, x3, y1, y2, y3;
	int length;
	float** array;// матрица
	float* vector;// вектор значений 
	float* resultArray;// корни СЛАУ	
	float determinant; //определитель	
	float* determinantArray;// определители промежуточных матриц
	float** intermediateArray;
public:

	Kramer(float** input_mass, float* input_vector, int input_len);
	float* GerResultArray();
	float DeterminantArray(float** array, int length);// нахождение определителя главной матрицы
	void FillIntermediateArray(float** array, int length, float* vector);// поиск определителей промежуточных матриц
	void KramerAnswer(float* determinantArray, int length, float determinant);// расчет корней СЛАУ
};

