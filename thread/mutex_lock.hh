#include <pthread.h>

class MutexLock {
public:
  MutexLock() { pthread_mutex_init(&mMutex, NULL); }
  ~MutexLock() { pthread_mutex_destroy(&mMutex); }

  void lock() { pthread_mutex_lock(&mMutex); }
  void unlock() { pthread_mutex_unlock(&mMutex); }

  pthread_mutex_t* getPthreadMutex() { return &mMutex; }

private:
  pthread_mutex_t mMutex;
};

class LockGuard {
public:
  explicit LockGuard(MutexLock& mutex) : mMutex(mutex) { mMutex.lock(); }
  ~LockGuard() { mMutex.unlock(); }

private:
  MutexLock& mMutex;
};