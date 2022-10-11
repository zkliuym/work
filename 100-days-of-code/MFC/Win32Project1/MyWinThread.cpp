#include "stdafx.h"
#include "MyWinThread.h"

MY_IMPLEMENT_DYNAMIC(CMyWinThread,CMyCmdTarGet)
CMyWinThread::CMyWinThread()
{
}


CMyWinThread::~CMyWinThread()
{
}

BOOL CMyWinThread::InitInstance()
{
    return FALSE;
}

int CMyWinThread::Run()
{
    MSG msg;
    BOOL bRet;

    while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
    {
        if (bRet == -1)
        {
            break;
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return 0;
}
