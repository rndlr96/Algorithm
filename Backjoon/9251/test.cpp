//다음 프로그램이 올바르게 동작하도록 밑줄 친 부분을 완성하여라. 
//(1)은 선언문이고 (2)는 실행문이다. 단 컴파일시 경고오류도 발생하지 않아야 한다.

#include  <stdio.h>
#include  <stdlib.h>
int main(void){
   int i, j;
   int *p[10];

   for (i = 0; i < 10; i++){
      p[i] = (int*)malloc(sizeof(int)*10);
      for (j = 0; j < 10; j++){
         p[i][j] = i * 10 + j;
      }
   }

   printf("%d\n", p[9][9]);

   return 0;
}
