//#include "mpi.h"
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//const int Tag = 0;
//const int root = 0;
//
////double sum_array(double *array, int n) {
////	double sum = 0;
////	for (int i = 0; i < n; ++i) {
////		sum += array[i];
////	}
////	return sum;
////}
//
//int main(int argc, char *argv[])
//{
//	//char message[20];
//	char messeg_test[20];
//	int rank;
//	int commSize;
//
//	char message[20] = "Privet ot potokov";
//	/*char message1[20] = "zdarovo ";*/
//
//
//	MPI_Init(NULL, NULL);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &commSize);
//	printf("rank = %d; commSize = %d;\n", rank, commSize);
//	MPI_Status status;
//
//	if (root == rank) {
//		strcpy_s(message, "Ya 1 potok");
//		/*for (int i = 1; i < commSize; ++i) {
//			MPI_Send(message, strlen(message) + 1, MPI_CHAR, i, Tag, MPI_COMM_WORLD);
//			printf("\n Ya otpravil soobschenie dlya potoka   %3d\n", i);
//		}*/
//	/*	for (int i = 1; i < commSize; ++i) {
//			MPI_Recv(&messeg_test, 20, MPI_CHAR, MPI_ANY_SOURCE, Tag, MPI_COMM_WORLD, &status);
//			printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", messeg_test);
//		}*/
//	}
//	MPI_Bcast(message, strlen(message) + 1, MPI_CHAR, root, MPI_COMM_WORLD);
//	if (root != rank) {
//		strcpy_s(message, "Privet,1 potok");
//		MPI_Recv(&messeg_test, 20, MPI_CHAR, MPI_ANY_SOURCE, Tag, MPI_COMM_WORLD, &status);
//		printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", messeg_test);
//		MPI_Send(message, 20, MPI_CHAR, root, Tag, MPI_COMM_WORLD);
//		
//	}else {
//		for (int i = 1; i < commSize; ++i) {
//			MPI_Recv(&messeg_test, 20, MPI_CHAR, MPI_ANY_SOURCE, Tag, MPI_COMM_WORLD, &status);
//			printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", messeg_test);
//		}
//	}
//
//	//else {
//
//	//	//MPI_Probe(root, Tag, MPI_COMM_WORLD, &status);
//	//	/*MPI_Get_count(&status, MPI_DOUBLE, &n);*/
//	//	/*cout << "i poluchil  - " << rank << "\n";*/
//
//	//	MPI_Bcast(message, strlen(message) + 1, MPI_CHAR, root, MPI_COMM_WORLD);
//
//	//	/*strcpy_s(message, "Privet,1 potok");*/
//
//	//	MPI_Recv(&messeg_test, 20, MPI_CHAR, MPI_ANY_SOURCE, Tag, MPI_COMM_WORLD, &status);
//
//	//	printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", messeg_test);
//
//	//	MPI_Reduce(&message,&messeg_test,20, MPI_CHAR, MPI_SUM,root, MPI_COMM_WORLD);
//
//	//	/*MPI_Send(message, 20, MPI_CHAR, root, Tag, MPI_COMM_WORLD);*/
//
//	//	//if (rank != 2) {
//	//	//	MPI_Send(message1, 20, MPI_CHAR, root, Tag, MPI_COMM_WORLD);
//	//	//	cout << "tyty" << endl;
//	//	//}
//	//	//else {
//	//	/*MPI_Send(&sum, 1, MPI_DOUBLE, root, Tag, MPI_COMM_WORLD);*/
//	//}
//
//
//	MPI_Finalize();
//	return 0;
//}



















//
//#include "mpi.h"
//#include <iostream>
//using namespace std;
//
//const int Tag = 0;
//const int root = 0;
//int M = 3;
//
//
//int main(int argc, char *argv[])
//{
//	char message[20];
//	char messeg_test[20] = "Ya ne root";
//	int rank;
//	int commSize;
//	double t1, t2, dt;
//
//	
//	MPI_Init(NULL, NULL);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &commSize);
//	t1 = MPI_Wtime();
//	for (int i = 0; i < M; i++) {
//		cout << " M = " << i << endl;
//		printf("rank = %d; commSize = %d;\n", rank, commSize);
//		MPI_Status status;
//		if (root == rank) {
//			strcpy_s(message, "Privet Ya root");
//		}
//		MPI_Bcast(&message, strlen(message) + 1, MPI_CHAR, 0, MPI_COMM_WORLD);
//		/*switch (rank)
//		{
//		case(0):
//			printf("\n Ya vasheto : '%d'\n", rank);
//			printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", message);
//
//			break;
//
//		case(1):
//			printf("\n Ya vasheto : '%d'\n", rank);
//			printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", message);
//
//			break;
//
//		case(2):
//			printf("\n Ya vasheto : '%d'\n", rank);
//			printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", message);
//
//			break;
//		default:
//			printf("\n Ya vasheto : '%d' idi na\n", rank);
//			printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", message);
//
//			break;
//		}*/
//		printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", message);
//		MPI_Reduce(&messeg_test, &message, strlen(messeg_test) + 1, MPI_CHAR, MPI_SUM, root, MPI_COMM_WORLD);
//		printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", messeg_test);
//		printf("\n Ya prinal soobschenie ot potoka takoe: '%20s'\n", message);
//	}
//	t2 = MPI_Wtime();
//	dt = t2 - t1;
//    cout<<"Time  "<< dt <<endl;
//	MPI_Finalize();
//	return 0;
//}