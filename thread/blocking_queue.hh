#include <queue>
#include "condition.hh"

template<typename T>
class BlockingQueue {
public:
  BlockingQueue() : mNotEmpty(mMutex) {}

  void push(const T& x) {
    LockGuard lock(mMutex);
    mQueue.push_back(x);
    mNotEmpty.notify();
  }

  T pop() {
    LockGuard lock(mMutex);
    while (mQueue.empty()) {
      mNotEmpty.wait();
    }
    assert(!mQueue.empty());
    T front(mQueue.front());
    mQueue.pop_front();
    return front;
  }
  
  bool empty() const { 
    LockGuard lock(mMutex);
    return mQueue.empty();
  }

  size_t size() const {
    LockGuard lock(mMutex);
    return mQueue.size();
  }

private:
  MutexLock mMutex;
  Condition mNotEmpty;
  std::deque<T> mQueue;
};