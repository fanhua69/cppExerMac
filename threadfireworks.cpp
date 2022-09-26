
#include <iostream>       // std::cout
#include <chrono>         // std::chrono::milliseconds
#include <thread>         // std::thread
#include <mutex>          // std::timed_mutex

std::timed_mutex mtx;

void fireworks(int id)
{
  // waiting to get a lock: each thread prints "-" every 200ms:
  while ( !mtx.try_lock_for(std::chrono::milliseconds(300)) )
  {
    std::cout << id;
  }
  // got a lock! - wait for 1s, then this thread prints "*"
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::cout << "("<<id<<"*)\n";
  mtx.unlock();
}

int fireworksmain()
{
  std::thread threads[10];
  // spawn 10 threads:
  for ( int i = 0; i < 10; ++i )
  {
    threads[i] = std::thread(fireworks,i);
  }

  for ( auto& th : threads )
  {
    th.join();
  }

  return 0;
}