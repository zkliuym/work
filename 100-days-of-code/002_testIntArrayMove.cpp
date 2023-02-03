// testIntArrayMove.cpp : 定义控制台应用程序的入口点。
//测试数组的快速数据插入，求和，求均值

#include "stdafx.h"

#include <stdlib.h>

#define ARRAYSIZE 20

int a[ARRAYSIZE];
int b[ARRAYSIZE];
int c[ARRAYSIZE];
int sumA;
int avgA;

void printAIntArray()
{
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        printf("%5d", a[i]);
    }
    printf("%5d", sumA);
    printf("%5d", avgA);
    printf("\n");
}

void addAArray(int data)
{
    memcpy(&a[1], a, (ARRAYSIZE - 1)*sizeof(int));
    a[0] = data;
    sumA = sumA + data - a[ARRAYSIZE - 1];
    avgA = int(sumA / ARRAYSIZE);
}

int main()
{
    printAIntArray();
    addAArray(3);
    printAIntArray();
    addAArray(5);
    printAIntArray();
    addAArray(7);
    printAIntArray();
    addAArray(8);
    printAIntArray();
    addAArray(345);
    printAIntArray();
    addAArray(12);
    printAIntArray();
    addAArray(22);
    printAIntArray();
    addAArray(32);
    printAIntArray();
    addAArray(152);
    printAIntArray();
    addAArray(0);
    printAIntArray();
    addAArray(51);
    printAIntArray();
    addAArray(0);
    printAIntArray();
    addAArray(89);
    printAIntArray();
    addAArray(35);
    printAIntArray();
    addAArray(112);
    printAIntArray();
    addAArray(225);
    printAIntArray();
    addAArray(132);
    printAIntArray();
    addAArray(52);
    printAIntArray();
    addAArray(22);
    printAIntArray();
    addAArray(99);
    printAIntArray();
    addAArray(88);
    printAIntArray();

    system("pause");
    return 0;
}

