#pragma once
#include "MyWnd.h"
class CMyView :
	public CMyWnd
{
	MY_DECLARE_DYNAMIC(CMyView)//添加类方法和成员.
public:
	CMyView();
	virtual ~CMyView();
};

