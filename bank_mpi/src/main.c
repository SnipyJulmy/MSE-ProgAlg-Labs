#include <mpi.h>
#include "bank.h"

#define BANK_ID 0

void main(int argc, char** argv)
{
    int task_id;
    int nbr_process;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &task_id);
    MPI_Comm_size(MPI_COMM_WORLD, &nbr_process);

    MPI_Finalize();
}