//#include <stdio.h>
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include "mpi.h"
//
//using namespace std;
//const int SIZE = 2;
//const int SIZE_GENERATE = 3;
//
//
//void printmatrix(int** mas) {
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			cout << mas[i][j] << "  ";
//		}
//		cout << endl;
//	}
//}
////
////int GetCountNumbers(int *num)
////
////{
////	bool flag = false;
////	int count = 0;
////	for (int i = SIZE - 1; i >= 0; i--)
////	{
////		if (num[i] != 0)
////			flag = true;
////		if (flag)
////		{
////			count++;
////		}
////
////	}
////	return count;
////}
////
////long GetNumberFromPolynom(int* pol)
////
////{
////
////	int count = GetCountNumbers(pol);
////	int umn = 1;
////	int result = 0;
////	for (int i = 0; i < count; i++, umn *= 10)
////		result += pol[i] * umn;
////	return result;
////}
////
////void TransferPolynom(int *pol)
////
////{
////
////	int count = GetCountNumbers(pol);
////
////	for (int i = 0; i < count + 1; i++)
////	{
////		if (pol[i] > 9)
////		{
////			int temp = pol[i] / 10;
////			pol[i] = pol[i] % 10;
////			pol[i + 1] += temp;
////		}
////	}
////}
//
//int main(int argc, char* argv[]){
//	int ProcCount, myRank, myRank1;
//	
//	int** matrix = new int*[SIZE];
//		for (int i = 0; i < SIZE; i++) {
//			matrix[i] = new int[SIZE];
//		}
//	int** temp = new int*[SIZE];
//		for (int i = 0; i < SIZE; i++) {
//			temp[i] = new int[SIZE];
//		}
//		
//	int** result = new int*[SIZE];
//		for (int i = 0; i < SIZE; i++) {
//			result[i] = new int[SIZE];
//		}
//
//	int count = 0;
//
//	unsigned int start_time; // ��������� �����
//	unsigned int end_time; // �������� �����
//
//	MPI_Status Status;
//	MPI_Datatype type;
//
//	MPI_Init(&argc, &argv);
//	srand(time(NULL));
//	MPI_Comm_size(MPI_COMM_WORLD, &ProcCount);
//	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
//
//	if (myRank == 0)
//		start_time = clock();
//
//	// ������ ������� ���������� ������ ���������
//
//	//for (int i = 0; i < SIZE; i++)
//
//	//	matrix[i] = 0;
//
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			matrix[i][j] =  + rand() % 6;
//		}
//	}
//	// ����������� �������� ������ ��� �������
//	// ����� ��� type
//
//	MPI_Type_contiguous(SIZE, MPI_INT, &type);
//	MPI_Type_commit(&type);
//
//	// �������� �������� �������� ���� ������� ������
//
//	if ((myRank % 2) != 0)
//
//		MPI_Send(matrix, 1, type, myRank - 1, 5, MPI_COMM_WORLD);
//
//	else
//	{
//		if (myRank < ProcCount - 1)
//			MPI_Recv(temp, 1, type, myRank + 1, 5, MPI_COMM_WORLD, &Status);
//	}
//
//	// ������ �������� �������� ��������
//
//	if ((myRank % 2) == 0 && (myRank < ProcCount - 1))
//
//	{
//		// ����� ����������� ��������� ��� ���������
//
//		for (int i = 0; i < SIZE; i++) {
//			for (int j = 0; j < SIZE; j++) {
//				cout << mas[i][j] << "  ";
//			}
//
//
//		/*printmatrix(matrix);
//		printmatrix(temp);*/
//
//
//		// ��������� ��������������� �������
//
//		for (int i = 0; i < SIZE; i++) {
//			for (int j = 0; j < SIZE; j++) {
//				result[i][j] = 0;
//				for (int k = 0; k < SIZE; k++) {
//					result[i][j] += matrix[i][k] * temp[k][j];
//				}
//			}
//			printmatrix(result);
//		}
//	
//			
//
//		// ��������� ���������
//
//	
//		// ���������� ��������� � ������������ ������
//
//		for (int i = 0; i < SIZE; i++) {
//			for (int j = 0; j < SIZE; j++) {
//				matrix[i][j] = result[i][j];
//			}
//		}
//
//	}
//
//	//MPI_Comm comm_revs;
//	//MPI_Comm_split(MPI_COMM_WORLD, myRank % 2, myRank, &comm_revs);
//	//MPI_Comm_rank(comm_revs, &myRank1);
//	//// ������� ����� ������ ���������
//
//	//while ((ProcCount /= 2) > 0)
//	//{
//	//	// �������� �������� �������� ���� ������� ������
//	//	if ((myRank1 % 2) != 0)
//	//		MPI_Send(matrix, 1, type, myRank1 - 1, 5, comm_revs);
//	//	else
//	//	{
//	//		if (myRank1 < ProcCount - 1)
//	//			MPI_Recv(temp, 1, type, myRank1 + 1, 5, comm_revs, &Status);
//	//	}
//
//	//	// ������ �������� �������� ��������
//
//	//	if ((myRank1 % 2) == 0 && (myRank1 < ProcCount - 1))
//	//	{
//
//	//		for (int i = 0; i < SIZE; i++) {
//	//			for (int j = 0; j < SIZE; j++) {
//	//				result[i][j] = 0;
//	//				for (int k = 0; k < SIZE; k++) {
//	//					result[i][j] += matrix[i][k] * temp[k][j];
//	//				}
//	//			}
//	//			printmatrix(result);
//	//		}
//
//
//
//			// ��������� ���������
//
//
//			// ���������� ��������� � ������������ ������
//
//			/*for (int i = 0; i < SIZE; i++) {
//				for (int j = 0; j < SIZE; j++) {
//					matrix[i][j] = result[i][j];
//				}
//			}*/
//	/*	}*/
//
//		// ����� ������
//
//		//MPI_Comm_split(MPI_COMM_WORLD, myRank1 % 2, myRank1, &comm_revs);
//
//		//MPI_Comm_rank(comm_revs, &myRank1);
//
//	}
//
//	// ����� ����������
//
//	if (myRank == 0)
//
//	{
//
//		cout << "Result:" << endl;
//
//		printmatrix(matrix);
//		
//
//		end_time = clock();
//
//		unsigned int search_time = end_time - start_time; // ������� �����
//
//		cout << "Runtime: " << search_time / 1000.0 << endl;
//
//	}
//
//	// ������������ ������
//
//	delete[] result;
//
//	MPI_Comm_free(&comm_revs);
//
//	MPI_Type_free(&type);
//
//	MPI_Finalize();
//
//	return 0;
//
//}