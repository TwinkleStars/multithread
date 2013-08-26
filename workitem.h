#include <string>
#include "thread.h"
#include "workqueue.h"

class WorkItem
{
    string itsMessage;
    int itsNumber;
    
public:
    WorkItem(const char* theMessage, int theNumber) :itsMessage(theMessage), itsNumber(theNumber) {}
    ~WorkItem() {}

    const char* getMessage() { return itsMessage.c_str(); }
    int getNumber() { return itsNumber; }
};

class ConsumerThread : public Thread
{
    WQueue<WorkItem *>& itsQueue;

public:
    ConsumerThread(WQueue<WorkItem *>& theQueue) : itsQueue(theQueue) {}
    
    void* run();
};
