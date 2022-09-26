

//#include <pthread.h>  
//#include <pthread>
//
//int rdlock1()
//{
//  pthread_rwlock_t rwl;
//  pthread_rwlock_rdlock(&rwl);
//  pthread_rwlock_wrlock(&rwl);
//  pthread_rwlock_unlock(&rwl);
//  pthread_rwlock_unlock(&rwl);
//  return -1;
//
//}
///*³ÌÐò2*/
//#include <pthread.h>  
//int rdlock2()
//{
//  pthread_rwlock_t rwl;
//  pthread_rwlock_wrlock(&rwl);
//  pthread_rwlock_rdlock(&rwl);
//  pthread_rwlock_unlock(&rwl);
//  pthread_rwlock_unlock(&rwl);
//  return -1;
//}