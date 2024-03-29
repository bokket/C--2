//
// Created by bokket on 2021/2/18.
//

#ifndef BOKKET_MUTEXLOCK_H
#define BOKKET_MUTEXLOCK_H


#pragma once
#include "noncopyable.hpp"
#include <pthread.h>


namespace bokket {
    class MutexLock : public noncopyable {
    public:
        MutexLock() {
            pthread_mutex_init(&mutex, NULL);
        }

        ~MutexLock() {
            pthread_mutex_lock(&mutex);
            pthread_mutex_destroy(&mutex);
        }

        void lock() {
            pthread_mutex_lock(&mutex);
        }

        void unlock() {
            pthread_mutex_unlock(&mutex);
        }

        pthread_mutex_t *get() {
            return &mutex;
        }

    private:
        pthread_mutex_t mutex;

    private:
        friend class Condition;
    };

    class MutexLockGuard : public noncopyable {
    public:
        explicit MutexLockGuard(MutexLock &_mutex)
                : mutex(_mutex) {
            mutex.lock()
        }

        ~MutexLockGuard() {
            mutex.unlock();
        }

    private:
        MutexLock &mutex;
    };
}
#endif //BOKKET_MUTEXLOCK_H
