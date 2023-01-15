//#include <mpi.h>
//#include<stdio.h>
//#include<stdlib.h>
//
//#define DBG(a) if(rank==(a))
//
//int main(int argc, char** argv)
//
//{
//	int rank, size;
//	int* neighbours, n;
//	int *nodes, *edges;
//	int nnodes, nedges, nprev = 0;
//
//	MPI_Comm newcomm;
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//	nnodes = size;
//	nedges = 0;
///*
//	nodes = (int*)malloc(sizeof(int)*nnodes);*/
//
//	nodes = new int [nnodes];
//	nodes[0] = nnodes - 1;
//	DBG(!0) {
//		for (int i = 1; i < nnodes; i++)
//		{
//			nodes[i] = 1;
//			/*nedges += 2;*/
//		}
//	}
//	edges = new int[nnodes * 2 - 2];
//	for (int i = 0; i < (nnodes * 2 - 2); i++) {
//		if(i<(nnodes -1)) edges[i] = i + 1;
//		else edges[i] = 0;
//	}
//
//	/*edges = (int*)malloc(nedges * sizeof(int));*/
//
//	/*for (int i = 0; i < nnodes; i++)
//	{
//		edges[nprev] = (i + 1) % nnodes;
//		edges[nprev + 1] = (i - 1 + nnodes) % nnodes;
//		nprev += 2;
//	}*/
//
//	DBG(0) printf("Before graph create\n");
//	nprev = 0;
//	DBG(0)
//	{
//		for (int i = 0; i < nedges; i++)
//		{
//			printf("%d: ", edges[i]);
//		}
//		printf("\n");
//	}
//
//	MPI_Graph_create(MPI_COMM_WORLD, nnodes, nodes, edges, 0, &newcomm);
//	MPI_Graph_neighbors_count(newcomm, rank, &n);
//	neighbours = (int*)malloc(sizeof(int)*n);
//	MPI_Graph_neighbors(newcomm, rank, n, neighbours);
//	{
//		printf("[%d] My %d neighbours are: ", rank, n);
//		for (int k = 0; k < n; k++)
//			printf("%d ", neighbours[k]);
//		printf("\n");
//	}
//
//	free(nodes);
//	free(neighbours);
//	free(edges);
//	MPI_Comm_free(&newcomm);
//	MPI_Finalize();
//	return 0;
//
//}