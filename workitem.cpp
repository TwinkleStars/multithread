#include "workitem.h"

void* ConsumerThread::run()
{
    for (int i = 0; ; ++i)
    {
        printf("thread %lu, loop %d - waiting for item...\n", (long unsigned int)self(), i);
        WorkItem* anItem = (WorkItem *)itsQueue.remove();
        printf("thread %lu, loop %d - got one item\n", (long unsigned int)self(), i);
        printf("thread %lu, loop %d - item: message - %s, number - %d\n",
                (long unsigned int)self(),
                i,
                anItem->getMessage(),
                anItem->getNumber());
        delete anItem;
    }

    return NULL;
}
