//
//#include "pthreadtest.h"
//#include "pthread.h"
//#include <stdio.h>
//#include <iostream>
//#include <process.h>
//#include <windows.h>
//#include "semaphore.h"
//
//#pragma comment(lib,"pthreadVC2.lib")
//
//pthread_t main_tid;
//
//static pthread_mutex_t myMutex;// = PTHREAD_MUTEX_INITIALIZER;
//static int gNum = 0;
//static MyQueue gQueue;
//static pthread_rwlock_t myrwlock;
//static pthread_cond_t mycond;
//static sem_t mysem;
//
//const int PRINTER_QTY = 3;
//const int PRINTER[PRINTER_QTY] = { 0,0,0 };
//
//
//MyQueue & MyQueue::append(MyQueueNode * node)
//{
//  if ( m_pQueueTail == NULL )
//  {
//    m_pQueueHead = node;
//    m_pQueueTail = node;
//    pthread_cond_signal(&mycond);
//  }
//  else
//  {
//    m_pQueueTail->append(node);
//    m_pQueueTail = node;
//  }
//
//  return *this;
//}
//
//MyQueueNode * MyQueue::removeHead()
//{
//  if ( m_pQueueHead == NULL )
//  {
//    return NULL;
//  }
//
//  MyQueueNode * node = m_pQueueHead;
//  m_pQueueHead = m_pQueueHead->getNext();
//  if ( m_pQueueHead == NULL )
//  {
//    m_pQueueTail = NULL;
//  }
//
//  return node;
//}
//
//int MyQueue::getSize()
//{
//  if(m_pQueueHead == NULL)
//  {
//    return 0;
//  }
//
//  int n = 1;
//  MyQueueNode * node = m_pQueueHead;
//  while( (node = node->getNext())!=NULL)
//  {
//    n++;
//  }
//
//  return n;
//}
//
//void MyQueue::waitEmpty()
//{
//  while(m_pQueueHead != NULL)
//  {
//    pthread_cond_wait(&mycond, &myMutex);
//  }
//}
//
//
//void MyQueue::clearQueue()
//{
//  while ( m_pQueueHead )
//  {
//    MyQueueNode * node = m_pQueueHead;
//    m_pQueueHead = m_pQueueHead->getNext();
//    delete node;
//  }
//}
//
//
//void print_ids(const char *str)
//{
//  pid_t pid;
//  pthread_t tid;
//  pid = _getpid();
//  tid = pthread_self();
//
//
//  printf("%s pid: %u tid: \n",
//         str,
//         (unsigned int)pid);
//}
//
//void funcExit(void *arg)
//{
//  printf("Thread existed.\n");
//}
//
//void *func(void *arg)
//{
//  int nThread = 0;
//  if ( arg )
//  {
//    int * p = (int*)arg;
//    nThread = *p;
//    printf("new thread:%d\n", *p);
//  }
//
//  pthread_cleanup_push(funcExit, NULL);
//
//  for ( int i = 0; i < 50; i++ )
//  {
//    pthread_mutex_lock(&myMutex);
//
//    gNum++;
//    printf("Thread : %d ,  gNum : %d\n", nThread, gNum);
//
//    pthread_mutex_unlock(&myMutex);
//  }
//
//
//  pthread_cleanup_pop(0);
//  pthread_exit(NULL);
//
//  return ((void*)0);
//}
//
//void *funcEat(void *arg)
//{
//
//  int nThread = 0;
//  if(arg != NULL)
//  {
//    nThread = *(int*)arg;
//  }
//
//  while(true)
//  {
//    int nMark = 0;
//    while(pthread_mutex_lock(&myMutex) != 0)
//    {
//      int m = 0;
//    }
//
//    MyQueueNode *node = NULL;
//    while((node = gQueue.removeHead()) == NULL)
//    {
//      pthread_cond_wait(&mycond,&myMutex);
//    }
//
//    nMark = node->getValue();
//
//    printf("Thread:%d, eating node: %d\n", nThread, node->getValue());
//      
//    delete node;
//
//    pthread_mutex_unlock(&myMutex);
//
//    Sleep(100);
//
//    if ( nMark < 0 )
//    {
//      pthread_exit(NULL);
//    }
//  }
//
//  return NULL;
//}
//
//void *funcSave(void *arg)
//{
//  int nThread = 0;
//  if ( arg != NULL )
//  {
//    nThread = *(int*)arg;
//  }
//
//  int nAll = 100000;
//  for(int i= 0;i<nAll;i++)
//  {
//    while(pthread_mutex_lock(&myMutex)!=0)
//    {
//      int m = 0; 
//    };
//
//    gNum ++;
//    if(i > nAll - 3)
//    {
//      gNum = -1;
//    }
//
//    MyQueueNode *pNode = new MyQueueNode(gNum);
//    gQueue.append(pNode);
//
//    while(gQueue.getSize()>10)
//    {
//      
//    }
//
//    printf("Thread:%d, saving :%d\n",nThread, gNum);
//    pthread_mutex_unlock(&myMutex);
//
//    Sleep(10);
//  }
//
//  return NULL;
//}
//
//void pthreadtest()
//{
//  MyQueueNode node;
//  MyQueueNode n1 = node ++;
//  MyQueueNode n2 = ++node;
//  pthread_attr_t attr;
//  pthread_mutexattr_t mutexAttr;
//
//  pthread_mutex_init(&myMutex, NULL); //&mutexAttr);
//  pthread_rwlock_init(&myrwlock,NULL);
//  pthread_cond_init(&mycond,NULL);
//  sem_init(&mysem, 0, PRINTER_QTY);
//
//  pthread_attr_init(&attr);
//
//  
//  //pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
//
//  pthread_t id1;
//  int nThread = 1;
//  int rc = pthread_create(&id1, &attr, func, &nThread);
//  if ( rc )
//  {
//    exit(-1);
//  }
//
//  pthread_t id2;
//  int nThread2 = 2;
//  int rc2 = pthread_create(&id2, &attr, funcSave, &nThread2);
//  if ( rc2 )
//  {
//    exit(-1);
//  }
//
//  pthread_t id3;
//  int nThread3 = 3;
//  int rc3 = pthread_create(&id3, &attr, funcEat, &nThread3);
//  if ( rc3 )
//  {
//    exit(-1);
//  }
//
//
//  pthread_join(id1, NULL);
//  pthread_join(id2, NULL);
//  pthread_join(id3, NULL);
//  
//
//  pthread_attr_destroy(&attr);
//  pthread_cond_destroy(&mycond);
//  pthread_rwlock_destroy(&myrwlock);
//  pthread_mutex_destroy(&myMutex);
//
//  return;
//}