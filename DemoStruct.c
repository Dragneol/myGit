#include <stdio.h>
#include <windows.h>

	typedef struct hocsinh 
					{
					char MSSV[10];
					char Name[30];
					float GPA;
					} Hocsinh;
					
					int main()
					{
						Hocsinh hs[100] ;
						int n;
						scanf("%d", &n);
						int i;
						for (i = 0; i < n; i++)
						 scanf("%s%s%f",&hs[i].MSSV, &hs[i].Name, &hs[i].GPA);
						 system("cls");
						for (i = 0; i < n; i++)
						 printf("%s %s %0.1f\n",hs[i].MSSV, hs[i].Name, hs[i].GPA);
						 return 0;
					}
