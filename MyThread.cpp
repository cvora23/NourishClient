//
// Created by chivora on 1/26/18.
//
#include "MyThread.h"

using namespace std;

MyThread::MyThread() {
}

int MyThread::Create(void *Callback, void *args) {
    int tret=0;

    //Supercreepy typecast
    tret = pthread_create(&this->tid, NULL, (void *(*)(void *))Callback, args);

    if(tret) {
        cerr << "Error while creating threads." << endl;
        return tret;
    }
    else {
        cout << "Thread successfully created." << endl;
        return 0;
    }
}

int MyThread::Join() {
    pthread_join(this->tid, NULL);
    return 0;
}
