
#include <windows.h>
#include <stdio.h>
void commonmemserver()
{
  //�������Ϊ����������
  HANDLE hShmem;
  char param[1024];
  STARTUPINFOA si;
  PROCESS_INFORMATION pi;

  hShmem = CreateFileMapping(INVALID_HANDLE_VALUE, 0, PAGE_READWRITE, 0, 256, 0); //���������ڴ����
  SetHandleInformation(hShmem, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT); //ʹ�þ�����Լ̳е��ӽ���

  char *stringName = "commonmem";
  sprintf_s(param, "\"%s\" %x", stringName, (unsigned int)hShmem);
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  CreateProcessA(stringName, param, 0, 0, TRUE, 0, 0, 0, &si, &pi);
  WaitForSingleObject(pi.hProcess, INFINITE); //�ȴ��ӽ������н���
  
  char *pstr = (char*)MapViewOfFile(hShmem, FILE_MAP_WRITE, 0, 0, 0); //�������ڴ�����е��ڴ��ӳ�䵽��ǰ����
  puts(pstr);
  UnmapViewOfFile(pstr);
  CloseHandle(hShmem);
  return;
}