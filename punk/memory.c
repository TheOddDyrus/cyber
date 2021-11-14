#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 内存的操作
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
     * 函数分配第二个参数指定的内存量，并把第一个参数指针指向的之前分配的内容复制到新配的内存中，且复制的内容长度等于新旧内存区域中较小的那一个。
     * 即新内存大于原内存，则原内存所有内容复制到新内存，如果新内存小于原内存，只复制长度等于新内存空间的内容
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