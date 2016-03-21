//
// Created by Marc Demierre on 21/03/16.
//

#include <time.h>
#include <stdlib.h>

#include "mpi.h"

#include "customer.h"

#define NB_ITERATIONS 10
#define PROB_DEPOSIT 60

#define DEPOSIT_MAX 100
#define DEPOSIT_MIN 10
#define WITHDRAW_MAX 50
#define WITHDRAW_MIN 5

void customer() {
    for(int i = 0; i < NB_ITERATIONS; i++) {
        int r = rand() % 100;
        if (r < PROB_DEPOSIT) {
            // -- Deposit money
            // TODO: get amount
            // TODO: send message
        } else {
            // -- Withdraw money
            // TODO: get amount
            // TODO: send message
        }

        // -- Print balance
        // TODO: get balance (message)
    }
}