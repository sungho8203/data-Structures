#include "Queue.h"

int main(){
    Queue temp;


    temp.pushQueue(10);
    temp.pushQueue(11);
    temp.pushQueue(10);
    temp.pushQueue(11);
    temp.pushQueue(10);
    temp.pushQueue(11);
    temp.showAllData();
    cout<<temp.getLength()<<endl;
    temp.initQueue();
    temp.showAllData();


    temp.pushQueue(10);
    temp.pushQueue(11);
    temp.showAllData();

    cout <<temp.popQueue()<<endl;
    cout <<temp.popQueue()<<endl;
    cout <<temp.popQueue()<<endl;
}