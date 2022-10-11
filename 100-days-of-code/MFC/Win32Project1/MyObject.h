#pragma once

extern HINSTANCE MyGetInstanceHandle();
class CMyRuntimeClass;
#define MY_RUNTIME_CLASS(class_name) ((CMyRuntimeClass*)(&class_name::class##class_name))

#define MY_DECLARE_DYNAMIC(class_name) \
public: \
	static const CMyRuntimeClass class##class_name; \
	virtual CMyRuntimeClass* GetRuntimeClass() const; \


#define MY_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	const CMyRuntimeClass class_name::class##class_name = { \
#class_name, sizeof(class class_name), wSchema, pfnNew, \
	MY_RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CMyRuntimeClass* class_name::GetRuntimeClass() const \
{ return MY_RUNTIME_CLASS(class_name); }

#define MY_IMPLEMENT_DYNAMIC(class_name, base_class_name) \
	MY_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL, NULL)


class CMyObject
{
public:
    CMyObject();
    virtual ~CMyObject();
	virtual CMyRuntimeClass * GetRuntimeClass() const;
	BOOL isKindOf(const CMyRuntimeClass * pClass)const;
public:
	static const CMyRuntimeClass classCMyObject;
};

class CMyRuntimeClass
{
public:
	// Attributes
	LPCSTR m_lpszClassName;
	int m_nObjectSize;
	UINT m_wSchema;
	CMyObject* (*m_pfnCreateObject)();
	CMyRuntimeClass* m_pBaseClass;
	CMyRuntimeClass* m_pNextClass;
	void *pInit;
};
