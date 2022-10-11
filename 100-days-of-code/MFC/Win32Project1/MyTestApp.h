#pragma once
#include "MyWinApp.h"
class CTestApp :
    public CMyWinApp
{
public:
	CTestApp();
	virtual ~CTestApp();
    virtual BOOL InitInstance();
};

