// Win32Project1.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Win32Project1.h"
#include "MyTestApp.h"
HINSTANCE g_hInstance;  //保存全局实例句柄
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
        //失败,则退出,其中initInstance是子类重写的,且里面是显示窗口,注册窗口类
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
