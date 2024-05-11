#include "thread.h"

#ifdef HAVE_POSIX_THREADS

#include <pthread.h>
#include <semaphore.h>

int sys_thread_create(sys_thread_t *thread, sys_thread_func_t func, void *arg) {
    return pthread_create(thread, NULL, func, arg);
}

int sys_thread_join(sys_thread_t *thread, void **result) {
    return pthread_join(*thread, result);
}

void sys_mutex_lock(sys_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

void sys_mutex_unlock(sys_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}

void sys_semaphore_init(sys_sem_t *sem, int pshared, unsigned int value) {
    sem_init(sem, pshared, value);
}

void sys_semaphore_wait(sys_sem_t *sem) {
    sem_wait(sem);
}

void sys_semaphore_post(sys_sem_t *sem) {
    sem_post(sem);
}

void sys_semaphore_destroy(sys_sem_t *sem) {
    sem_destroy(sem);
}

#else

#error "Implement thread.c for your platform."

#endif
