#include <stdio.h>
#include <string.h>

/**
 * 字符串的操作
 */
int main()
{
    char str1[] = {'L','e','t','s'};
    char str2[] = "begin";
    printf("st1: %s", str1);
    printf("\n");
    printf("st2: %s", str2);
    printf("\n");

    char str3[] = "str3";
    strcpy(str3, str2);
    printf("copy str2 to st3: %s", str3);
    printf("\n");

    char str4[] = "str4";
    strcat(str4, str3);
    printf("append str3 to st4: %s", str4);
    printf("\n");
    printf("length of st4: %d", strlen(str4));
    printf("\n");

    char str5[] = "begin";
    char str6[] = "begin";
    printf("equals of str5 and str6: %d", strcmp(str5, str6));
    printf("\n");

    char *p = strstr(str6, "gi");
    printf("point of gi in str6: %p", p);
    printf("\n");
    printf("value of gi in str6: %c", *p);

    return 0;

}