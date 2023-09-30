#pragma once
class Kramer
{
private:
	float x1, x2, x3, y1, y2, y3;
	int length;
	float** array;// �������
	float* vector;// ������ �������� 
	float* resultArray;// ����� ����	
	float determinant; //������������	
	float* determinantArray;// ������������ ������������� ������
	float** intermediateArray;
public:

	Kramer(float** input_mass, float* input_vector, int input_len);
	float* GerResultArray();
	float DeterminantArray(float** array, int length);// ���������� ������������ ������� �������
	void FillIntermediateArray(float** array, int length, float* vector);// ����� ������������� ������������� ������
	void KramerAnswer(float* determinantArray, int length, float determinant);// ������ ������ ����
};

