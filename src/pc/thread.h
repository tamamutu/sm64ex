#ifndef _PC_THREAD_H
#define _PC_THREAD_H

// TODO: add other backends if required
#define HAVE_POSIX_THREADS 1

#ifdef HAVE_POSIX_THREADS
#include <pthread.h>
#include <semaphore.h>
typedef pthread_t sys_thread_t;
typedef void *(*sys_thread_func_t)(void *);
typedef pthread_mutex_t sys_mutex_t;
typedef sem_t sys_sem_t;
#define SYS_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
#else
#error "Implement thread.c for your platform."
#endif

int sys_thread_create(sys_thread_t *thread, sys_thread_func_t func, void *arg);
int sys_thread_join(sys_thread_t *thread, void **result);

void sys_mutex_lock(sys_mutex_t *mutex);
void sys_mutex_unlock(sys_mutex_t *mutex);

void sys_semaphore_init(sys_sem_t *sem, int pshared, unsigned int value);
void sys_semaphore_wait(sys_sem_t *sem);
void sys_semaphore_post(sys_sem_t *sem);
void sys_semaphore_destroy(sys_sem_t *sem);

#endif // _PC_THREAD_H
