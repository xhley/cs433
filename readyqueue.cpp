#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code

const int MAX_READYQUEUE_SIZE = 100; 

/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
     //TODO: add your code here
  //initialize queue
  count = 0;
  for(int i = 1; i < MAX_READYQUEUE_SIZE; i++)
   queue[i] = nullptr;
 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() {
    //TODO: add your code to release dynamically allocate memory
 //delete any PCBs in queue
 for(int i = 0; i < count; i++){
  delete queue[i];
  queue[i] = nullptr;
 }
 count = 0;
}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
    //TODO: add your code here
    // When adding a PCB to the queue, you must change its state to READY.
 if(pcbPtr == nullptr || count >= MAX_READYQUEUE_SIZE)
  return;
 pcb -> setState(ProcState::Ready);

 //insert in sorted order (descending priority)
 int i = count - 1;
 while( i>= 0 && queue[i] -> getProority() < pcbPtr -> getPriority ()){
  queue[i + 1] = queue[i];
  i--;
 }
 queue[i + 1] = pcbPtr;
 count++;
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    //TODO: add your code here
    // When removing a PCB from the queue, you must change its state to RUNNING.
 if(count == 0)
  return nullptr;
 //queue[0] always has highest priority
 PCB* pcb = queue[0];
 pcb -> setState(ProcState::RUNNING);

 //shift elements left
 for(int i = 1; i < count; i++)
  queue[i - 1] = queue[i];
 queue[count - 1] = nullptr;
 count --;
 return pcb;
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {
    //TODO: add your code here
 return count;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {
    //TODO: add your code here
for(int i = 0; i < count; i++)
 queue[i] -> display();
}
