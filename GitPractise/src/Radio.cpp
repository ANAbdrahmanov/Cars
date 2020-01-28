#include "Radio.h"
#include "IObserver.h"
#include <string>

void Radio::Attach(std::shared_ptr<IObserver> c) 
{
    std::lock_guard<std::mutex> lock(m_listUsageMutex);
    m_observers.push_back(c);
}
void Radio::Detach(std::shared_ptr<IObserver> c)
{
    std::lock_guard<std::mutex> lock(m_listUsageMutex);
    m_observers.remove(c);
}

Radio::Radio()
    :m_bCancelationToken(true),
    counter(1),
    m_threadHandler(&Radio::StartSending, this)
{
}

void Radio::StartSending() 
{
    while(m_bCancelationToken) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        Notify();
        counter++;
    }
}

Radio::~Radio()
{
    m_bCancelationToken = false;
    if(m_threadHandler.joinable()) 
    {
        m_threadHandler.join();
    }
}

void Radio::Notify()
{
    std::lock_guard<std::mutex> lock(m_listUsageMutex);
    std::string str = "News#" + std::to_string(counter);
    for(auto it = m_observers.begin(), end = m_observers.end(); it!= end; ++it)
    {
        (*it)->Update(str);
    }
}