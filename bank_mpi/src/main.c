#include <mpi.h>

#include "bank.h"
#include "customer.h"

void main(int argc, char** argv)
{
    int task_id;
    int nbr_process;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &task_id);
    MPI_Comm_size(MPI_COMM_WORLD, &nbr_process);

    if(task_id == BANK_ID) {
        bank();
    } else {
        customer(task_id);
    }

    MPI_Finalize();
}