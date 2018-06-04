#include "mutex_lock.hh"

class Condition {
public:
  explicit Condition(MutexLock& mutex) : mMutex(mutex) {
    pthread_cond_init(&mCond, NULL);
  }

  ~Condition() { pthread_cond_destroy(&mCond); }

  void wait() { pthread_cond_wait(&mCond, mMutex.getPthreadMutex()); }

  void notify() { pthread_cond_notify(&mCond); }

  void notifyAll() { pthread_cond_broadcast(&mCond); }

private:
  MutexLock& mMutex;
  pthread_cond_t mCond;
};