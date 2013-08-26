#include <stdio.h>
#include <stdlib.h>
#include "workqueue.h"
#include "workitem.h"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("usage: %s <iterations>\n", argv[0]);
        exit(-1);
    }

    int iterations = atoi(argv[1]);

    WQueue<WorkItem *> queue;
    ConsumerThread* thread1 = new ConsumerThread(queue);
    ConsumerThread* thread2 = new ConsumerThread(queue);
}
