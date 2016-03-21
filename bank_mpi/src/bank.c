//
// Created by snipy on 21.03.16.
//

#include <mpi.h>
#include <stdio.h>
#include "bank.h"

void bank(void)
{
    int account = START_MONEY;

    int working = 1;
    int amount_operation = 0;
    MPI_Request request_withdraw, request_deposit, request_quit_bank;

    while (working)
    {

        MPI_Irecv(&amount_operation, 1, MPI_INT, MPI_ANY_SOURCE, WITHDRAW, MPI_COMM_WORLD, &request_withdraw);
        MPI_Irecv(&amount_operation, 1, MPI_INT, MPI_ANY_SOURCE, DEPOSIT, MPI_COMM_WORLD, &request_deposit);
        MPI_Irecv(NULL, 0, MPI_INT, MPI_ANY_SOURCE, QUIT_BANK, MPI_COMM_WORLD, &request_quit_bank);

        handle_withdraw(request_withdraw);
    }
}

void handle_withdraw(MPI_Request request_withdraw)
{
    int flag = 0;
    MPI_Status status;
    MPI_Test(&request_withdraw, &flag, &status);

    if(flag)
    {
        printf("")
    }
    else
    {
        // failed !
        printf("No withdraw received");
    }
}

