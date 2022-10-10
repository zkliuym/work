// test02.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>


//////////////////////////////////////////////////////////////////////////
class CClassAddress
{
public:
    CClassAddress();
    int getNum1();
    void setNum1(int a);
private:
    int mPrvNum1;
public:
    char mPubChar1;
};
CClassAddress::CClassAddress()
{
    std::cout << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << "\tlocation is\t" << (void*)&(__FUNCTION__) << std::endl;
    mPrvNum1 = 0;
    mPubChar1 = 0;
}

int CClassAddress::getNum1()
{
    std::cout << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << "\tlocation is\t" << (void*)&(__FUNCTION__) << std::endl;
    std::cout << "mPrvNum1 location is\t" << (void*)&(mPrvNum1) << std::endl;
    return mPrvNum1;
}

void CClassAddress::setNum1(int a)
{
    std::cout << __FILE__ << ":" << __LINE__ << ":" << __FUNCTION__ << "\tlocation is " << (void*)&(__FUNCTION__) << std::endl;
    std::cout << "fun setNum1 para a address is: " << (void*)&a << std::endl;
    this->mPrvNum1 = a;
}

//////////////////////////////////////////////////////////////////////////
int g_nData = 0;
static int s_nStaticGlobal = 9;
char *g_pChar;
std::string g_s;

int fib(int N) 
{
    std::cout << "fun fib address: " << (void*)&(__FUNCTION__) << std::endl;
    std::cout << "fun fib para N address is: " << (void*)&N << std::endl;

    if (N == 1 || N == 2) return 1;
    return fib(N - 1) + fib(N - 2);
}

int sum(int n, int m)
{
    std::cout << "fun sum address: " << (void*)&(__FUNCTION__) << std::endl;
    std::cout << "fun sum para n address is: " << (void*)&n << std::endl;
    std::cout << "fun sum para m address is: " << (void*)&m << std::endl;

    static int s_StaticInFun = 3;
    std::cout << "static s_StaticInFun address is: " << (void*)&s_StaticInFun << std::endl;

    return n + m;
}

int main()
{
    std::cout << "main fun address: " << (void*)&(__FUNCTION__) << std::endl;

    std::cout << "g_nData address is: " << (void*)&g_nData << std::endl;
    std::cout << "static s_nStaticGlobal address is: " << (void*)&s_nStaticGlobal << std::endl;


    std::cout << "g_pChar address is: " << (void*)&g_pChar << std::endl;
    g_pChar = (char *)malloc(6);
    memcpy(g_pChar, "hello", 6);
    std::cout << "g_pChar value is: " << (void*)*g_pChar << std::endl;

    std::cout << "g_s address is: " << (void*)&g_s << std::endl;
    g_s = "5555555555555555555555555555555555555555555555555555555";
    std::cout << "g_s value is: " << g_s << std::endl;

    static int s_StaticInMain = 6;
    std::cout << "static s_StaticInMain address is: " << (void*)&s_StaticInMain << std::endl;

    int f = sum(3, 5);

    std::cout << "fib(5) = " << fib(5) << std::endl;

    int b; 
    std::cout << "&b address is: " << (void*)&b << std::endl;

    char s[] = "abc"; 
    std::cout << "&s[] address is: " << (void*)&s << std::endl;

    char *p2; //栈 
    p2 = (char *)malloc(20);  //堆 
    memcpy(g_pChar, "helloworld", 11);
    std::cout << "&p2 address is: " << (void*)&p2 << std::endl;
    std::cout << "&p2 value is: " << (void*)*p2 << std::endl;
    std::cout << p2 << std::endl;

    char *p3 = "123456"; //123456\0在常量区，p3在栈上。 
    std::cout << "&p3 address is: " << (void*)&p3 << std::endl;
    std::cout << "&p3 value is: " << (void*)*p3 << std::endl;

    static int c = 0; //全局（静态）初始化区   
    std::cout << "static c address is: " << (void*)&c << std::endl;    

    CClassAddress classAdd;
    std::cout << __FILE__ << ":" << __LINE__ << ":" << "local classAdd: location is\t" << (void*)&classAdd << std::endl;
    std::cout << "classAdd size is: " << sizeof(classAdd) << std::endl;
    classAdd.setNum1(10);
    int a = classAdd.getNum1();
    std::cout << __FILE__ << ":" << __LINE__ << ":" << "local a: location is\t" << (void*)&a << std::endl;
    std::cout << __FILE__ << ":" << __LINE__ << ":" << "public classAdd.mPubChar1: location is\t" << (void*)&classAdd.mPubChar1 << std::endl;

    CClassAddress *p_classAdd = new CClassAddress();
    std::cout << __FILE__ << ":" << __LINE__ << ":" << "local *p_classAdd: location is\t" << (void*)&p_classAdd << std::endl;
    std::cout << __FILE__ << ":" << __LINE__ << ":" << "local &(*p_classAdd): location is\t" << &(*p_classAdd) << std::endl;
    p_classAdd->setNum1(11);
    p_classAdd->getNum1();
    std::cout << __FILE__ << ":" << __LINE__ << ":" << "public p_classAdd->mPubChar1: location is\t" << (void*)&(p_classAdd->mPubChar1) << std::endl;
    delete p_classAdd;

    system("pause");
    return 0;
}