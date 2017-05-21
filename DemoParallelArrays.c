/* Sach: tua(char 20), gia (double)
   Demo Quan lý mot mang cac cuon sach
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 50
/* Them 1 sach */
void add (char tua[][21], double gia[], int *pn)
{  if ((*pn)==MAXN) puts("Mang day!!!");
   else /* them 1 quyen sach */
   {  char ts[21];
      int g;
      printf("Nhap tua sach moi:");
      fflush(stdin);
      scanf("%20[^\n]", ts);
      printf("Nhap gia cua sach moi:");
      scanf("%d", &g);      /* DUa data vao 2 mang */
      strcpy(tua[*pn], ts);
      gia[*pn]= g;
      (*pn)++;/* Mang co them 1 phan tu*/
   }
}
/* sx theo gia tang, cung gia thi tua tang */
void sort(char tua[][21], double gia[], int n)
{  int i, j;
   for (i=0;i<n-1; i++)
     for (j=n-1; j>i; j--)
      { int dt= strcmp(tua[j], tua[j-1]); /* chenh lech tua */
        if (gia[j]<gia[j-1]||
             (gia[j]==gia[j-1] & dt<0))
          { /* Doi tua */
            char t[21];
            strcpy(t, tua[j]);
            strcpy(tua[j], tua[j-1]);
            strcpy(tua[j-1], t);
            /* doi gia */
            double tg = gia[j];
            gia[j]=gia[j-1];
            gia[j-1]=tg; 
          }
      }
}
/* Xuat thong tin ve cac sach */
void xuat(char tua[][21], double gia[], int n)
{ int i;
  for (i=0; i<n; i++)
    printf("%-20s, %10.2lf\n", tua[i], gia[i]);
}
int main()
{  char tua[MAXN][21];
   double gia[MAXN];
   int n=0;
   int i=0;
   /* Nhap 3 cuon sach */
   for (i=1; i<=3; i++) add(tua, gia, &n);
   /* sap xep */
   sort(tua, gia, n);
   /* xuat ket qua */
   xuat(tua, gia, n);
   system("pause");
   return 0;
}
