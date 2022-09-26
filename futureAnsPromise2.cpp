

#include <vector>
#include <string>
#include <future>
#include <chrono>
#include <iostream>


struct student
{
    std::string m_name;
    int m_age;
};


void calcData(std::vector<student>::iterator itbegin, 
              std::vector<student>::iterator itEnd, 
              std::string searchName, 
              std::promise<student> studentPromise)
{
    std::cout << "Thread Started" << std::endl;
    std::vector<student>::iterator it = itbegin;
    for(it = itbegin; it<itEnd;it++)
    {
        if(it->m_name == searchName )
        {
            std::cout << "Thread Found the student and to set the promise" << std::endl;
            studentPromise.set_value(*it);
            std::cout << "Thread After setting the promise" << std::endl;
            break;
        }
    }

    std::cout << "Thread wants  to sleep" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Thread woke up" << std::endl;
}

void futureAndPromise2()
{
    std::vector<student> students;
    students.push_back({"Smith",10});
    students.push_back({"Tom", 13});
    students.push_back({"Kyb", 15});

    std::promise<student> stPromise;
    std::future<student> stFuture = stPromise.get_future();

    std::cout << "Main function starts to create thread" << std::endl;
    std::thread threadSearch(calcData, students.begin(), students.end(),"Tom",std::move(stPromise));

    std::cout << "Main function starts to wait" << std::endl;
    stFuture.wait();
    std::cout << "Main function got the future" << std::endl;
    student dataFound = stFuture.get();
    std::cout << "Found student:" << std::endl;
    std::cout << dataFound.m_name <<std::endl << dataFound.m_age << std::endl;
    std::cout << "Main to join the thread" << std::endl;
    threadSearch.join();
    std::cout << "Main after joining the thread" << std::endl;

    return;
}
