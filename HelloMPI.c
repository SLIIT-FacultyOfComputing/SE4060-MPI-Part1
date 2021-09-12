
#include <cstdio>
#include <cstdlib>
#include <mpi.h>
int main(void)
{
    int rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0)
      printf("Hello World! From rank %d\n", rank);
    else
      print("Just a normal process From rank %d\n", rank);
    MPI_Finalize();
}
