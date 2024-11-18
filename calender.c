#include<stdio.h>
int getweekDay(int year)//for year
{
    int d;
    d=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
    return d;
}
int main()
{
    int year,month,day,daysinmonth,weekDay=0,stday;
    printf("ENTER THE YEAR THAT'S CALENDER YOU WANTS:\n");
    scanf("%d",&year);
    char *months[]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0 && year%100 !=0)|| year%400==0)
    {
        monthDay[1]=29;
    }
    stday=getweekDay(year);
    for(month=0;month<12;month++)
    {
        daysinmonth=monthDay[month];
        printf("\n\n...............%s..................\n",months[month]);
        printf("\n  SUN  MON  TUE  WED  THU  FRI  SAT \n  ");
        printf("\n");
        for(weekDay=0; weekDay<stday;weekDay++)
        printf("     ");
        
        for(day=1;day<=monthDay[month];day++)
        {  // printf("\t");
            printf("%5d",day);
            if(++weekDay>6)
            {
                printf("\n");
                weekDay=0;
            }
            stday=weekDay;
        }
    }
}