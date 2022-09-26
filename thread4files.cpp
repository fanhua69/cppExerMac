/*题目：有四个线程1、2、3、4。线程1的功能就是输出1，线程2的功能就是输出2，以此类推.....
现在有四个文件ABCD。初始都为空。现要让四个文件呈如下格式：
A：1 2 3 4 1 2....
B：2 3 4 1 2 3....
C：3 4 1 2 3 4....
D：4 1 2 3 4 1....*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

const int nFileQty = 4;
FILE *fp[nFileQty];

std::mutex mymutexfile;
static condition_variable va;
int iFileData [4] = {1,2,3,4};


string filename(int X)
{
  char ss[10];
  sprintf_s(ss,"%d",X);

  string s = "D:\\" + string(ss) +".txt";
  return s;
}

void writedata(int i)
{
  char c = '1' + i - 1;
  for(int k=0;k<50;k++)
  {
    int fileOrder = -1;
    std::unique_lock<mutex> lk(mymutexfile);

    while(true)
    {
      for(int kk =0;kk<nFileQty ;kk++)
      {
        if(iFileData[kk] == i)
        {
          fileOrder = kk;
          break;
        }
      }
      if(fileOrder != -1)
      {
        break;
      }

      va.wait(lk);
    }


    fwrite(&c,1,1,fp[fileOrder]);
    iFileData[fileOrder] ++;
    if( iFileData[fileOrder] > 4)
    {
      iFileData[fileOrder] = 1;
    }
    va.notify_all ();
  }
}

void thread4files()
{
  for(int i = 0; i < nFileQty;i++)
  {
     string s = filename(i);
     fopen_s(&fp[i], s.c_str(),"wt");
  }

  thread a(writedata, 1);
  thread b(writedata, 2);
  thread c(writedata, 3);
  thread d(writedata, 4);

  a.join();
  b.join();
  c.join();
  d.join();




}