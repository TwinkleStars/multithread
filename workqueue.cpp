#include "workqueue.h"

template <typename T>
WQueue<T>::WQueue()
{
    pthread_mutex_init(&itsMutex, NULL);
    pthread_cond_init(&itsCondV, NULL);
}

template <typename T>
WQueue<T>::~WQueue()
{
    pthread_mutex_destroy(&itsMutex);
    pthread_cond_destroy(&itsCondV);
}

template <typename T>
void WQueue<T>::add(T item)
{
    pthread_mutex_lock(&itsMutex);
    itsQueue.push_back(item);
    pthread_cond_signal(&itsCondV);
    pthread_mutex_unlock(&itsMutex);
}

template <typename T>
T WQueue<T>::remove()
{
    pthread_mutex_lock(&itsMutex);
    while (itsQueue.size() == 0)
    {
        pthread_cond_wait(&itsCondV, &itsMutex);
    }

    T item = itsQueue.front();
    itsQueue.pop_front();
    pthread_mutex_unlock(&itMutex);
    return item;
}

template <typename T>
int WQueue<T>::size()
{
    pthread_mutex_lock(&itsMutex);
    int size = itsQueue.size();
    pthread_mutex_unlock(&itsMutex);
    return size;
}
