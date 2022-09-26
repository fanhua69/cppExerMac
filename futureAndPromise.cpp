

#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>

void accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last,
                std::promise<int> accumulate_promise)
{
    int sum = std::accumulate(first, last, 0);

    accumulate_promise.set_value(sum);  // Notify future

    for(int i=0;i<100;i++)
    {
        for(int j = 0; j< 1000000000;j++)
        {
            int n = i * j * i * j * i* j *i *j;
        }
    }

}

void do_work(std::promise<void> barrier)
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    barrier.set_value();

    for ( int i = 0; i < 100000000; i++ )
    {
        for ( int j = 0; j < 10000000; j++ )
        {
            int n = i * j * i * j * i* j *i *j;
        }
    }


}

int futureAndPromise()
{
    // Demonstrate using promise<int> to transmit a result between threads.
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread work_thread(accumulate, numbers.begin(), numbers.end(),
                            std::move(accumulate_promise));
    accumulate_future.wait();  // wait for result
    std::cout << "result=" << accumulate_future.get() << '\n';
    work_thread.join();  // wait for thread completion

                         // Demonstrate using promise<void> to signal state between threads.
    std::promise<void> barrier;
    std::future<void> barrier_future = barrier.get_future();
    std::thread new_work_thread(do_work, std::move(barrier));
    barrier_future.wait();
    new_work_thread.join();

    return 0;
}