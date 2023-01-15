//
//#include "mpi.h"
//#include <iostream>
//
//using namespace std;
//
//const int Tag = 0;
//const int root = 0;
//
//int main(int argc, char *argv[])
//{
//	
//		double t1, t2, dt;
//		int rank;
//		int commSize;
//		int M = 1;
//	
//		MPI_Init(NULL, NULL);
//		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//		MPI_Comm_size(MPI_COMM_WORLD, &commSize);
//
//		int N = commSize * 2;
//		int* senddata = new int[N];
//		int* recvdata = new int[2];
//
//		
//			printf("rank = %d; commSize = %d;\n", rank, commSize);
//			MPI_Status status;
//
//			if (root == rank) {
//				
//				for (int i = 0; i < N; i++) {
//					senddata[i] = i*3;
//					/*cout << senddata[i] << " ";*/
//				}
//				cout << endl;
//			}
//			for (int i = 0; i < 2; i++) {
//				recvdata[i] = 0;
//			}
//		for (int i = 0; i < M; i++) {
//
//			t1 = MPI_Wtime();
//
//			MPI_Scatter(senddata,2,MPI_INT, recvdata,2,MPI_INT,root, MPI_COMM_WORLD);
//
//			for (int i = 0; i < 2; i++) {
//				recvdata[i]*=2;
//			}
//
//			MPI_Gather(recvdata, 2, MPI_INT, senddata, 2, MPI_INT, 0, MPI_COMM_WORLD);
//		}
//		/*if (root == rank) {
//			for (int i = 0; i < N; i++) {
//				cout << senddata[i] << "  ";
//			}
//		}
//		else {
//			for (int i = 0; i < 2; i++) {
//				cout << recvdata[i] << "  ";
//			}
//		}*/
//		t2 = MPI_Wtime();
//		dt = t2 - t1;
//		cout<<"Time  "<< dt <<endl;
//			delete[] senddata;
//			delete[] recvdata;
//		MPI_Finalize();
//	return 0;
//}
//
//
//
