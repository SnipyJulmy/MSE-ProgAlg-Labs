//
// Created by snipy on 21.03.16.
//

#ifndef BANK_MPI_BANK_H
#define BANK_MPI_BANK_H

#define BANK_ID 0
#define START_MONEY 100
#define DEPOSIT 0xf864
#define WITHDRAW 0x89f6
#define BALANCE 0x8c1aff33
#define QUIT_BANK 0x11114421

void bank(void);
void handle_withdraw(MPI_Request pT);

#endif //BANK_MPI_BANK_H
