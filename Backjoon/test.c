#include <stdio.h>
void main()
{
static int ary[6][2] = { {'!','s'},{'d','r'},{'o','w'},{'k','c'},{'a','b'},{'c','d'} };
int *p = (int *)(ary+4);
for(++p; p>=(int *)ary; putchar(*p--));
}
