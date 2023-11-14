#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    int t1;
    int t2;

    len = _printf("Let's try to printf a simple sentence.\n%n", &t1);
    len2 = printf("Let's try to printf a simple sentence.\n%n", &t2);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");
    printf("Percent:[%%]\n");
    printf("%d %d\n", len, len2);
    printf("%d %d\n", t1, t2);

    return (0);
}
