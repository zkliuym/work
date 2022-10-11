#pragma once
#include "MyCmdTarGet.h"
class CMyWinThread :
    public CMyCmdTarGet
{
	MY_DECLARE_DYNAMIC(CMyWinThread)
public:
    CMyWinThread();
    virtual ~CMyWinThread();
    virtual BOOL InitInstance();
    virtual int Run();
};

