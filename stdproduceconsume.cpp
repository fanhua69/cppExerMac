

#include <vector>
#include <iostream>
#include <queue>
#include <mutex>
#include <chrono>

using namespace std;

std::queue <int> foodChain;
std::mutex foodMutex;


void producefood(unsigned int enoughFood)
{
    static int food=0;

    while(true)
    {
        if(foodChain.size() < enoughFood)
        {
            food ++;
            cout << "Food shortage, ready to produce food" << endl;
            {
                std::lock_guard<mutex> foodGuard(foodMutex);
                foodChain.push(food);
            }

            cout << "Food produced : " << food << endl;

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

void consumefood(int hasFood)
{
    std::mutex mutexFood;
    while(true)
    {
        if( !foodChain.empty() )
        {
            int food;
            cout << "Food not empty, ready to consume :" << foodChain.size() << endl;
            {
                std::lock_guard<std::mutex> guard(foodMutex);
                food = foodChain.front();
                foodChain.pop();
            }
            cout << "Food consumed: " << food << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

void stdproduceconsume()
{
    std::thread threadProduce(producefood,5);
    std::thread threadConsume(consumefood,3);

    threadProduce.join();
    threadConsume.join();
}