//
// Created by chivora on 1/26/18.
//

#ifndef NOURISHCLIENT_MYTHREAD_H
#define NOURISHCLIENT_MYTHREAD_H

#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>

#include <cstdlib>

class MyThread {
public:
    pthread_t tid;

public:
    MyThread();
    int Create(void *Callback, void *args);
    int Join();
};


#endif //NOURISHCLIENT_MYTHREAD_H
