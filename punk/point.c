#include <stdio.h>
#include "point.h"

/**
 * 指针的操作
 */
int main()
{
    //指针的赋值
    int num = 123;
    int *p;
    p = &num;
    printf("address of num: %p\n", &num);
    printf("address of p: %p\n", p);
    printf("value of p: %d\n", *p);
    printf("\n");

    //NULL指针
    int *p2 = NULL;
    printf("address of p2: %p\n", p2);
    printf("\n");

    //指针的算术运算
    printf("address of p + 1: %p\n", ++p);
    printf("value of p + 1: %d\n", *p);
    printf("address of p - 1: %p\n", --p);
    printf("value of p - 1: %d\n", *p);
    printf("\n");

    //指针操作数组
    int  var[] = {1, 10, 100};
    int  i, *ptr;
    ptr = var;
    for ( i = 0; i < 3; i++)
    {
        printf("address of arr[%d] -> %p\n", i, ptr);
        printf("value of arr[%d] -> %d\n", i, *ptr);
        ptr++;
    }
    i++;
    ptr++;
    printf("outer address of arr[%d] -> %p\n", i, ptr); //野指针，指向了程序中的上一块的内存区域:*p
    printf("outer value of arr[%d] -> %d\n", i, *ptr);
    printf("\n");

    //指向指针的指针
    int  **p3;
    p3 = &p;
    printf("address of p3: %p\n", p3);
    printf("value of p3: %p\n", *p3); //等于p的指针地址
    printf("\n");

    //引用传递和指针传递
    int n1 = 100;
    int n2 = 100;
    pass_ref(n1);
    pass_point(&n2);
    printf("param of pass_ref(): %d\n", n1);
    printf("param of pass_point(): %d\n", n2);
    printf("\n");

    //函数返回指针
    int *p4;
    p4 = return_point();
    printf("address of p4: %p\n", &p4);
    printf("value of p4: %d\n", *p4);
    printf("\n");

    //函数指针
    int (*p5)() = &func_point;
    printf("invoke p5 return: %d\n", p5(1, 2));
    printf("\n");

    //void指针
    char p6[] = "123";
    int p7 = 456;
    void_point(&p6, 1);
    void_point(&p7, 2);
    printf("\n");
}

void pass_ref(int n)
{
    ++n;
}

void pass_point(int *n)
{
    ++*n;
}

int *return_point()
{
    static int n = 200;
    return &n;
}

int func_point(int x, int y)
{
    return x + y;
}

void void_point(void *value, int type)
{
    switch (type) {
        case 1:
            printf("value is %s\n", (char *) value);
            break;
        case 2:
            printf("value is %d\n", *((int *) value));
            break;
        default:
            printf("type is not match!\n");
            break;
    }
}
