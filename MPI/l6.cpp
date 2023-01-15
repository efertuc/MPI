#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mpi.h"

using namespace std;
const int N = 10;

/*

все процессы делятся пополам : нечетные идут в группу, в которой
осуществляется обмен информацией по кольцу при помощи сдвига в одномерной декартовой топологии
Они передают свой новый номер ранга, ранги суммируются
Четные должны идти в группу, в которой общение осуществляется по схеме master-slave(звезда) на базе топологии графа,

*/

void ring(MPI_Comm comm) {
	int i, commrank, size, left, right;
	int sum, send_buf, rec_buf;
	MPI_Comm ring_comm;
	int dims[1], periods[1], reorder;
	MPI_Status send_status, rec_status;
	MPI_Request request;

	MPI_Comm_rank(comm, &commrank);
	MPI_Comm_size(comm, &size);
	// Задать декартовую топологию
	dims[0] = size;
	periods[0] = 1;
	reorder = 1;
	MPI_Cart_create(comm, 1, dims, periods,reorder, &ring_comm);
	MPI_Cart_shift(ring_comm, 0, 1, &left, &right);
	sum = 0;
	send_buf = commrank;
	for (i = 0; i < size; i++) {
		MPI_Issend(&send_buf, 1, MPI_INT, right, 0,ring_comm, &request);
		MPI_Recv(&rec_buf, 1, MPI_INT, left, 0, ring_comm, &rec_status);
		sum += rec_buf;
		MPI_Wait(&request, &send_status);
		send_buf = rec_buf;
	}
	printf("Proc %d, sum %d\n", commrank, sum);
}

int slave(int* a, int N) {
	int b = 0;
	for (int i = 0; i < N; i++)  b += (a[i] * 4 - 3);
	return b;
}


int main(int argc, char* argv[]) {
	
	int world_rank, world_size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int color = world_rank % 2;
	MPI_Comm row_comm;
	MPI_Comm_split(MPI_COMM_WORLD, color, world_rank, &row_comm);
	int row_rank, row_size;
	MPI_Comm_rank(row_comm, &row_rank);
	MPI_Comm_size(row_comm, &row_size);
	printf("WORLD RANK/SIZE: %d/%d \t ROW RANK/SIZE: %d/%d\n",world_rank, world_size, row_rank, row_size);
	
	if (world_rank % 2) {
		ring(row_comm);
	}
	MPI_Comm_free(&row_comm);
	MPI_Finalize();
	return 0;
}