//#include <stdio.h>
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include "mpi.h"
//
//using namespace std;
//const int N = 4;
//const int SIZE = N * N;
//
//
//
//int main(int argc, char* argv[])
//
//{
//	int ProcCount, myRank, myRank1;
//	int sendarray[SIZE], temp[SIZE];
//	int *result;
//	int count = 0;
//	unsigned int start_time; // начальное время
//	unsigned int end_time; // конечное время
//
//	MPI_Status Status;
//	MPI_Datatype type;
//	MPI_Init(&argc, &argv);
//	srand(time(NULL));
//	MPI_Comm_size(MPI_COMM_WORLD, &ProcCount);
//	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
//
//
//	if (myRank == 0) {
//		start_time = clock();
//	}
//	// Каждый процесс генерирует массив полиномов
//	for (int i = 0; i < SIZE; i++)
//
//		sendarray[i] = 0;
//
//	for (int i = 0; i < SIZE; i++)
//
//		sendarray[i] = (myRank + rand()) % 6;
//	// Динамически выделяем память под массивы
//
//	result = new int[SIZE];
//
//	// Новый тип type
//
//	MPI_Type_contiguous(SIZE, MPI_INT, &type); //конструктор тип данных 
//	MPI_Type_commit(&type); //объявление типов данных
//
//	// Нечетные процессы посылают свои массивы четным
//	if ((myRank % 2) != 0)
//		MPI_Send(sendarray, 1, type, myRank - 1, 5, MPI_COMM_WORLD);
//	else
//	{
//		if (myRank < ProcCount - 1)
//			MPI_Recv(temp, 1, type, myRank + 1, 5, MPI_COMM_WORLD, &Status);
//	}
//
//	// Четные процессы умножают полиномы
//	if ((myRank % 2) == 0 && (myRank < ProcCount - 1))
//	{
//		for (int i = 0; i < SIZE; i++)
//			result[i] = 0;
//		// Умножение полиномов
//		int t;
//		int r = 0;
//		for (int i = 0; i < SIZE; i++) {
//			for (int s = 0; s < N; s++) {
//				t = 0;
//				for (int k = 0; k < N; k++) {
//					result[i] += sendarray[i] * temp[s + t];
//					t += N;
//				}
//			}
//		}
//		for (int j = 0; j < SIZE; j++) {
//			sendarray[j] = result[j];
//		}
//	}
//	
//	MPI_Comm comm_revs;
//	MPI_Comm_split(MPI_COMM_WORLD, myRank % 2, myRank, &comm_revs);//созд коммутаторов одновременно
//	MPI_Comm_rank(comm_revs, &myRank1);
//
//	if (myRank == 0)
//	{
//		cout << "Result:" << endl;
//		for (int j = 0; j < SIZE; j++) {
//			if ((j%N) == 0) {
//				cout << endl;
//			}
//			cout << sendarray[j] << " ";
//		}
//		cout << endl;
//		end_time = clock();
//		unsigned int search_time = end_time - start_time; // искомое время
//		cout << "Runtime: " << search_time / 1000.0 << endl;
//	}
//	// Освобождение памяти
//	delete[] result;
//	MPI_Comm_free(&comm_revs);
//	MPI_Type_free(&type);
//	MPI_Finalize();
//	return 0;
//}