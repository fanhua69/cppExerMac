

#include <string>
#include <thread>
#include <iostream>
#include <functional>

using namespace std;

void FireHTTPGet()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    cout << "Finished Executing HTTP Get" << endl;
}

void ProcessHTTPResult(thread t1)
{
    t1.join();
    cout << "HTTP Get Thread Finished Executing - Processing Result Data!" << endl;
}

int threadmovethread()
{
    thread t11(FireHTTPGet);
    thread t12(ProcessHTTPResult, std::move(t11));

    //Do bunch of other processing without waiting for t11 to finish - instead now we've shouldered off the 

    // responsibility of monitoring t11 thread to t12.

    //Finally wait for t12 to finish

    t12.join();
    return 0;

}