#include <pthread.h>
#include <list>

using namespace std;

template <typename T>
class WQueue
{
    list<T> itsQueue;
    pthread_mutex_t itsMutex;
    pthread_cond_t itsCondV;

public:
    WQueue();
    ~WQueue();

    void add(T item);
    T remove();
    int size();
};

