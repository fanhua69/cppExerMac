

#include <string>
#include <thread>
#include <iostream>
#include <functional>
#include <mutex>

using namespace std;

thread_local int globalVar = 0;
std::condition_variable con;
std::mutex mutexForCondition;
bool conditionVariable = false;
unsigned int n = std::thread::hardware_concurrency();
mutex mu;

union a
{
    union a *p;
    int b;
};

void PrettyPrint(int valueToPrint)
{
    lock_guard<mutex> lock(mu);
    cout << "Value of globalVar in thread " << this_thread::get_id() << " is " << globalVar << endl;
}

void thread_Local_Test_Func(int newVal, bool condition)
{
    globalVar = newVal;
    for(int i=0;i<1000000;i++)
    {
        std::unique_lock<mutex> lock(mutexForCondition);
        con.wait(lock,[&condition]()->bool{return conditionVariable == condition;});

        PrettyPrint(globalVar);
        globalVar++;
        conditionVariable = !conditionVariable;
        con.notify_all();
    }
}

int threadlocal()
{
    globalVar = 1;
    thread t1(thread_Local_Test_Func, 5, true);
    thread t2(thread_Local_Test_Func, 5, false);

    t1.join();
    t2.join();
    cout << "Value of globalVar in MAIN thread is " << globalVar << endl;
    return 0;

}