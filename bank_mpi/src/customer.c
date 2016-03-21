//
// Created by Marc Demierre on 21/03/16.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "mpi.h"

#include "bank.h"

#include "customer.h"

#define N_ITERATIONS_MIN 10
#define N_ITERATIONS_MAX 20
#define PROB_DEPOSIT 60

#define DEPOSIT_MAX 100
#define DEPOSIT_MIN 10
#define WITHDRAW_MAX 50
#define WITHDRAW_MIN 5


/**
 * Returns a random integer between min and max.
 */
int customer_rand_in_range(int min, int max) {
    double scaled = (double)rand()/RAND_MAX;

    return (int)((max - min + 1) * scaled + min);
}

/**
 * A customer process, which withdraws and deposits money.
 */
void customer(int rank) {
    printf("%d - Starting\n", rank);

    // -- Decide number of iterations to do
    int n_iterations = customer_rand_in_range(N_ITERATIONS_MIN, N_ITERATIONS_MAX);
    printf("%d - Will do %d iterations\n", rank, n_iterations);

    for(int i = 0; i < n_iterations; i++) {
        int r = rand() % 100;
        int amount = 0;

        if (r < PROB_DEPOSIT) {
            // -- Deposit money
            amount = customer_rand_in_range(DEPOSIT_MIN, DEPOSIT_MAX);
            printf("%d - Deposit: %d\n", rank, amount);

            // -- Send message
            MPI_Send(&amount, 1, MPI_INT, BANK_ID, DEPOSIT, MPI_COMM_WORLD);
        } else {
            // -- Withdraw money
            amount = customer_rand_in_range(WITHDRAW_MIN, WITHDRAW_MAX);
            printf("%d - Withdrawal: %d\n", rank, amount);
            // -- Send message
            MPI_Send(&amount, 1, MPI_INT, BANK_ID, DEPOSIT, MPI_COMM_WORLD);
        }

        // -- Print balance
        int balance = 0;
        MPI_Status status;
        MPI_Recv(&balance, 1, MPI_INT, BANK_ID, BALANCE, MPI_COMM_WORLD, &status);
        printf("%d - Balance: %d\n", rank, balance);
    }

    // -- Leave bank
    printf("%d - Leaving bank!\n", rank);
    MPI_Send(NULL, 0, MPI_INT, BANK_ID, QUIT_BANK, MPI_COMM_WORLD);

    printf("%d - Finished!\n", rank);
}