#include <stdio.h>
#include <string.h>
int main (){
   char txt[] = "there is no point talking about this point - less topic";
   char pat[] = "point";
   int c=0;
   int M = strlen (pat);
   int N = strlen (txt);
   for (int i = 0; i <= N - M; i++){
      int j;
      for (j = 0; j < M; j++)
         if (txt[i + j] != pat[j])
         { c=c+1;
      break;}
      if (j == M)
      {c=c+1;
         printf ("Pattern matches at index %d \n", i);
      }
   }
   printf("operation count \n %d",c);
   return 0;
}