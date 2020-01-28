#pragma once
#include <list>
#include <thread>
#include <mutex>
#include <atomic>
#include "IPublisher.h"

class Radio : public IPublisher {
    std::list<std::shared_ptr<IObserver>> m_observers;
    int counter;

    std::atomic<bool> m_bCancelationToken;
    std::thread m_threadHandler;
    std::mutex m_listUsageMutex;

    void StartSending();

public:
    Radio(const Radio&) = delete;
    Radio(Radio&&) = delete;
    Radio& operator=(const Radio&) = delete;
    Radio& operator=(Radio&&) = delete;
    Radio();
	void Attach(std::shared_ptr<IObserver>) override;
	void Detach(std::shared_ptr<IObserver>) override;
	void Notify() override;
	virtual ~Radio() override;
};