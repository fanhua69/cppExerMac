

//#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <ctime>

void pipelineclient()
{
  srand(time(NULL));

  DWORD wlen = 0;
  Sleep(1000);//�ȴ�pipe�Ĵ����ɹ���

  BOOL bRet = WaitNamedPipe(TEXT("\\\\.\\Pipe\\mypipe"), NMPWAIT_WAIT_FOREVER);

  if ( !bRet )
  {
    printf("connect the namedPipe failed!\n");
    return;
  }

  HANDLE hPipe = CreateFile(			//�ܵ�����һ��������ļ�
                            TEXT("\\\\.\\Pipe\\mypipe"),	//�������ļ���
                            GENERIC_READ | GENERIC_WRITE,	//�ļ�ģʽ
                            0,								//�Ƿ���
                            NULL,							//ָ��һ��SECURITY_ATTRIBUTES�ṹ��ָ��
                            OPEN_EXISTING,					//��������
                            FILE_ATTRIBUTE_NORMAL,			//�ļ�����(����,ֻ��)NORMALΪĬ������
                            NULL);							//ģ�崴���ļ��ľ��

  if ( INVALID_HANDLE_VALUE == hPipe )
  {
    printf("open the exit pipe failed!\n");
  }
  else
  {
    while ( true )
    {
      char buf[256] = "";
      sprintf_s(buf, "%s %d", buf, rand() % 1000);
      if ( WriteFile(hPipe, buf, sizeof(buf), &wlen, 0) == FALSE )	//���������������
      {
        printf("write to pipe failed!\n");
        break;
      }
      else
      {
        printf("To Server: data = %s, size = %d\n", buf, wlen);
        char rbuf[256] = "";
        DWORD rlen = 0;
        ReadFile(hPipe, rbuf, sizeof(rbuf), &rlen, 0);	//���ܷ����͹���������
        printf("From Server: data = %s, size = %d\n", rbuf, rlen);
      }
      Sleep(1000);
    }
    CloseHandle(hPipe);//�رչܵ�
  }

  system("PAUSE");
  return;
}