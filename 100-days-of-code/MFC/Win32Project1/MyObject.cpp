#include "stdafx.h"
#include "MyObject.h"

const class CMyRuntimeClass CMyObject::classCMyObject =
{ "CMyObject", sizeof(CMyObject), 0xffff, NULL, NULL, NULL };
CMyObject::CMyObject()
{
}


CMyObject::~CMyObject()
{
}

CMyRuntimeClass *  CMyObject:: GetRuntimeClass() const
{
	return MY_RUNTIME_CLASS(CMyObject);
}
BOOL CMyObject:: isKindOf(const CMyRuntimeClass * pClass)const
{
	return FALSE;
}