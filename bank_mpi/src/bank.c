//
// Created by snipy on 21.03.16.
//

#include <mpi.h>
#include <stdio.h>
#include "bank.h"


void bank(void)
{
    int account = START_MONEY;

    int flag = 1;
    int amount_operation[2] = {0,0};
    MPI_Request request;

    while(flag)
    {
        MPI_Irecv(&amount_operation[0], 1, MPI_INT, MPI_ANY_SOURCE, WITHDRAW, MPI_COMM_WORLD, &request);
    }
}

