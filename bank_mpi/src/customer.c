//
// Created by Marc Demierre on 21/03/16.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "mpi.h"

#include "bank.h"

#include "customer.h"

#define NB_ITERATIONS 10
#define PROB_DEPOSIT 60

#define DEPOSIT_MAX 100
#define DEPOSIT_MIN 10
#define WITHDRAW_MAX 50
#define WITHDRAW_MIN 5


int customer_rand_in_range(int min, int max) {
    double scaled = (double)rand()/RAND_MAX;

    return (int)(max - min + 1) * scaled + min;
}

void customer(int rank) {
    for(int i = 0; i < NB_ITERATIONS; i++) {
        int r = rand() % 100;
        int amount = 0;

        if (r < PROB_DEPOSIT) {
            // -- Deposit money
            amount = customer_rand_in_range(DEPOSIT_MIN, DEPOSIT_MAX);
            printf("%d - Deposit: %d", rank, amount);

            // -- Send message
            MPI_Send(&amount, 1, MPI_INT, BANK_ID, DEPOSIT, MPI_COMM_WORLD);
        } else {
            // -- Withdraw money
            amount = customer_rand_in_range(WITHDRAW_MIN, WITHDRAW_MAX);
            printf("%d - Withdrawal: %d", rank, amount);
            // -- Send message
            MPI_Send(&amount, 1, MPI_INT, BANK_ID, DEPOSIT, MPI_COMM_WORLD);
        }

        // -- Print balance
        int balance = 0;
        MPI_Status status;
        MPI_Recv(&balance, 1, MPI_INT, BANK_ID, BALANCE, MPI_COMM_WORLD, &status);
        printf("%d - Balance: %d", rank, balance);
    }

    printf("%d - Finished!", rank);
}