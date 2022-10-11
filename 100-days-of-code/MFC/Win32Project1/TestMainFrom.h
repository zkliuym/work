#pragma once
#include "MyMainFrom.h"
class CTestMainFrom :
	public CMyMainFrom
{
	MY_DECLARE_DYNAMIC(CTestMainFrom)
public:
	CTestMainFrom();
	virtual ~CTestMainFrom();
};

