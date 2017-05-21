int main()
{
int a;
char c;
scanf("%d%c", &a, &c);
if ((a<=0)||(a>=8)||(c != '\n')) 
    printf("Error");
else
{
    if (a==1) printf("Sunday");
    if (a==2) printf("Monday");
    if (a==3) printf("Tuesday");
    if (a==4) printf("Wednesday");
    if (a==5) printf("Thursday");
    if (a==6) printf("Friday");
    if (a==7) printf("Saturday");
}
return 0;
}
