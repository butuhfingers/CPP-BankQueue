//
// Created by Recreational on 12/4/2017.
//

#include <cstdlib>
#include <time.h>
#include "Client.h"

Client::Client() {
    //We need to create a random transaction time

    transactionTime = (rand() % 10 + 1);
}

int Client::TransactionTime() {
    return this->transactionTime;
}
