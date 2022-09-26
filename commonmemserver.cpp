
#include <windows.h>
#include <stdio.h>
void commonmemserver()
{
  //如果是作为主进程运行
  HANDLE hShmem;
  char param[1024];
  STARTUPINFOA si;
  PROCESS_INFORMATION pi;

  hShmem = CreateFileMapping(INVALID_HANDLE_VALUE, 0, PAGE_READWRITE, 0, 256, 0); //创建共享内存对象
  SetHandleInformation(hShmem, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT); //使得句柄可以继承到子进程

  char *stringName = "commonmem";
  sprintf_s(param, "\"%s\" %x", stringName, (unsigned int)hShmem);
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  CreateProcessA(stringName, param, 0, 0, TRUE, 0, 0, 0, &si, &pi);
  WaitForSingleObject(pi.hProcess, INFINITE); //等待子进程运行结束
  
  char *pstr = (char*)MapViewOfFile(hShmem, FILE_MAP_WRITE, 0, 0, 0); //将共享内存对象中的内存块映射到当前进程
  puts(pstr);
  UnmapViewOfFile(pstr);
  CloseHandle(hShmem);
  return;
}