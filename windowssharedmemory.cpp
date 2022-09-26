

#include "windows.h"
#include <iostream>
#include <thread>

using namespace std;

constexpr int dwMemoryFileSize =11000;
constexpr char * sMemoryFileName = "memory_file";

const UINT wm_Message =
  RegisterWindowMessage("CC667211-7CE9-40c5-809A-1DA48E4014C4");//注册消息

void writememory()
{
  void *m_pViewOfFile = NULL;

  HANDLE m_hFileMapping = CreateFileMapping(
    INVALID_HANDLE_VALUE,           // system paging file
    NULL,                           // security attributes
    PAGE_READWRITE,                 // protection
    0,                              // high-order DWORD of size
    dwMemoryFileSize * sizeof(TCHAR), // low-order DWORD of size
    sMemoryFileName);               // name

  DWORD dwError = GetLastError();

  if(!m_hFileMapping)
  {
    cout << "Creating file mapping failed.\n";
  }
  else
  {
    m_pViewOfFile = MapViewOfFile (m_hFileMapping, FILE_MAP_WRITE,0,0,0);
    if(!m_pViewOfFile)
    {
      cout << "map view of file failed \n";
    }
  }

  if(m_pViewOfFile)
  {
    char * s = "tewst afdsafdsagfsagfsdag bbbbbb";
    int n =strlen(s);
    memcpy(m_pViewOfFile,s, n);
    ::PostMessage(HWND_BROADCAST, wm_Message,0,0);
  }

  while(((char*)m_pViewOfFile)[0] == 't')
  {
   this_thread::sleep_for (std::chrono::milliseconds(100));
  }

  //取消本进程地址空间的映射;   
  UnmapViewOfFile(m_pViewOfFile);

  m_pViewOfFile = NULL;

  //关闭文件映射内核文件  
  CloseHandle(m_hFileMapping);
}