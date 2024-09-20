#include <pthread.h>
#include <stdio.h>

//Possible to do by giving the user the struct address (to allow large data), when locking and setting it (forcing him to give it)
//to NULL, then we can maybe wrap that behaviour in a macro?? Yes, with teh address being an additional arguemnt (initially NULL)


// Macro to lock a mutex and execute a block of code
#define WITH_MUTEX_LOCK(mutex, code_block)    \
    pthread_mutex_lock(&mutex);               \
    do {                                      \
        code_block                            \
    } while (0);                              \
    pthread_mutex_unlock(&mutex);

// Sample critical section of code
void critical_section() {
    printf("Critical section running...\n");
}

int main() {
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    // Use the macro to lock the mutex, execute the code, and unlock the mutex
    WITH_MUTEX_LOCK(mutex, {
        critical_section();
        // You can add more code here if needed
    });

    pthread_mutex_destroy(&mutex);
    return 0;
}