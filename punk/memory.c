#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 内存的操作
 *
 * <1>alloca是向栈申请内存,因此无需释放
 * <2>malloc分配的内存是位于堆中的,并且没有初始化内存的内容,因此基本上malloc之后,调用函数memset来初始化这部分的内存空间
 * <3>calloc则将初始化这部分的内存,设置为0
 * <4>realloc则对malloc申请的内存进行大小的调整
 * <5>申请的内存最终需要通过函数free来释放
 */
int main()
{
    char name1[6] = "thomax";
    char *name2;
    char *name3;

    printf("name1 is %s\n", name1);

    //长度指定的内存
    name2 = (char *) calloc(2, sizeof(name1));
    strcpy(name2, "ThomaxThomax"); //如果拷贝的字符串长度超过 sizeof(name1) * 2，则会有问题
    printf("name2 is %s\n", name2);

    /* 重新分配内存：
     * 函数分配第二个参数指定的内存量，并把第一个参数指针指向的之前分配的内容复制到已创建的内存中，且复制的内容长度等于新旧内存区域中较小的那一个
     */
    realloc(name2, 3 * sizeof(name1));
    strcpy(name2, "ThomaxThomaxThomax");
    printf("new name2 is %s\n", name2);

    //动态分配内存
    name3 = (char *) malloc(2 * sizeof(name1));
    strcpy(name3, "ThomaxThomaxThomax");
    printf("name3 is %s\n", name3);

    //释放内存
    free(name2);
    free(name3);
}