#include <iostream>
#include <list>
#include <queue>
#include <time.h>
#include "Client.h"
using namespace std;

//////////////////
/// Variables
////////////////
//What is the longest amount of time we want people to wait?
int maxWaitTimer = 20;
list<list<Client*>> queueList;

//////////////////
/// Methods
////////////////
int QueueTime(list<Client*> clientQueue){
    int queueTime = 0;
    //Go through all the elements and get the queue time
    for(Client* currentClient : clientQueue){
        queueTime = queueTime + currentClient->TransactionTime();
    }

    return queueTime;
}

void AddToList(Client* clientToAdd){
    //Check all the queue times and see if we are able to add to them
    for(list<Client*> &currentQueue : queueList){
        int addedTime = QueueTime(currentQueue) + clientToAdd->TransactionTime();

        if(addedTime < maxWaitTimer){
//            cout << addedTime << endl;
            //We can just add the client to he list and return
            currentQueue.push_back(clientToAdd);
            return;
        }
    }

    //If we have made it this far, create another queue
    list<Client*> clientQueue;
    clientQueue.push_back(clientToAdd);
    queueList.push_back(clientQueue);
}
//Print the queue times of all the queues
void PrintQueueTimes(){
    for(list<Client*> &currentQueue : queueList){
        cout << "Current Time Queue: " << QueueTime(currentQueue) << endl;
    }
}

//We need to add a certain amount of clients
void AddAmountOfClients(int amountOfClients){
    for(int i = 0;i < amountOfClients;i++){
        AddToList(new Client());
    }
}

//////////////////
/// Main
////////////////
int main(int argc, char const *argv[])
{
    srand(time(NULL));

    AddAmountOfClients(40);

    PrintQueueTimes();

    return 0;
}