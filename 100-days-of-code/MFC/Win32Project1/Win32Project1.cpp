// Win32Project1.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Win32Project1.h"
#include "MyTestApp.h"
HINSTANCE g_hInstance;  //����ȫ��ʵ�����
HINSTANCE MyGetInstanceHandle()
{
    return g_hInstance;
}

CTestApp theApp;
CMyWinThread * MyGetThread()
{
    return &theApp;
}
int APIENTRY MyWMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPTSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    g_hInstance = hInstance;
    CMyWinThread *pThread = MyGetThread();
    if (!pThread->InitInstance())
    {
        //ʧ��,���˳�,����initInstance��������д��,����������ʾ����,ע�ᴰ����
        return 0;
    }
    pThread->Run();
    return TRUE;
}
#define MAX_LOADSTRING 100
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPTSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    return MyWMain(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
}
