#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int service(int days);
int fee(int month);
int appliance();
bool isLeapYear(int year);
int shopping();
int veg();
int fruits();
int dairy();
int wrod();
int bev();
int house();
int pers();
int beauty();
int budget();
void readFile(FILE * fPtr);
#define BUFFER_SIZE 1000
#define AMOUNT 0
#define VALID_INPUT_MIN 0
#define VALID_INPUT_MAX 1000
FILE *fPtr;
double total=0;
FILE *fptr;
FILE *fp;
int counter=0;
char op='N';
void copy(FILE *fPtr,FILE *fptr)
{
    char c;
    while ((c = getc(fPtr)) != EOF)
    {
        fputc(c, fptr);
    }
}
int main()
{

    int days,month,choice;
    char nm[30];
    printf("-----------------------------------------------------------\n");
    printf("Hi, Welcome to Home Manager!\n");
    printf("-----------------------------------------------------------\n");
    printf("Please enter your name: ");
    scanf("%[^\n]%*c", nm);
    printf("\t\tHi %s!!  :)",nm);
    printf("\n***********************************************************\n");
    printf("\n\n");
    fPtr=fopen("D:\\salary.txt","r");
    fptr=fopen("D:\\salary_temp.txt","a");
    copy(fPtr,fptr);
    fclose(fPtr);
    fclose(fptr);
    fPtr=fopen("D:\\fee.txt","r");
    fptr=fopen("D:\\fee_temp.txt","a");
    copy(fPtr,fptr);
    fclose(fPtr);
    fclose(fptr);
    fPtr=fopen("D:\\appliance.txt","r");
    fptr=fopen("D:\\appliance_temp.txt","a");
    copy(fPtr,fptr);
    fclose(fPtr);
    fclose(fptr);
    fPtr=fopen("D:\\grocery.txt","r");
    fptr=fopen("D:\\grocery_temp.txt","a");
    copy(fPtr,fptr);
    fclose(fPtr);
    fclose(fptr);
    do
    {

        printf("****Enter the task number which you want to perform****:\n1.Service Providers Salary/Bill\n2.Kids School/College and extracurricular Fees\n3.Appliance Performance and Maintenance\n4.Shopping\n5.Budget\n6.Quit\n\n");
        printf("===========================================================\n");
        scanf("%d",&choice);
        if(choice!=5)
        {
            system("cls");
        }
        switch(choice)
        {
        case 1:
            {
              printf("Enter Duration between two salaries:\n ");
              scanf("%d",&days);
              service(days);
              printf("-----------------------------------------------------------\n");
              printf("-----------------------------------------------------------\n\n");
              counter++;
            }break;
        case 2:
            {
                printf("enter the no of month of fees to be paid\n");
                scanf("%d",&month);
                fee(month);
                printf("-----------------------------------------------------------\n");
                printf("-----------------------------------------------------------\n\n");
                counter++;
            }break;
        case 3:
            {
                appliance();
                printf("-----------------------------------------------------------\n");
                printf("-----------------------------------------------------------\n\n");
                counter++;
            }break;
        case 4:
            {
                shopping();
                printf("-----------------------------------------------------------\n");
                printf("-----------------------------------------------------------\n\n");
                counter++;
            } break;
        case 5:
            {
                budget();
                printf("-----------------------------------------------------------\n");
                printf("-----------------------------------------------------------\n\n");
            }break;
        case 6:break;
        default:
            {
                printf("Invalid Input! Please enter a number between 1 to 6\n");
                printf("-----------------------------------------------------------\n");
                printf("-----------------------------------------------------------\n\n");
            }
        }
    }while(choice!=6);
    if(choice==6)
    {
        printf("\n\n***********************************************************");
        printf("\nThank You! Please visit again!");
        printf("\n***********************************************************");
    }

    return 0;
}

int service(int days)
{
    char dst[50],p[50];
    fptr = fopen("D:\\salary_temp.txt","a");
    fPtr = fopen("D:\\salary.txt", "w");
    fp = fopen("D:\\date.txt","a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }
    int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int num,sal_per_day,leave,cost_per_cloth,cloth,date,month,year;
    double tsal;
    do{
    printf("Choose service provider:\n1.Cook\n2.Servant\n3.Newspaper bill\n4.Dairy\n5.Clothes Pressing\n6.If you want to Quit\n\n");
    scanf("%d",&num);
    fflush(stdin);
    printf("***********************************************************\n");


    switch(num)
    {
    case 1:
        {
            printf("Enter salary per day of cook: \n");
            scanf("%d",&sal_per_day);
            fflush(stdin);
            printf("Enter no. of leaves taken: \n");
            scanf("%d",&leave);
            tsal=(sal_per_day*days)-(leave*sal_per_day);
            total+=tsal;
            sprintf(dst,"Cook:   %lf",tsal);
            fputs(dst,fPtr);
            fputs("\n",fPtr);
            printf("\n\nThis month's Salary of cook is : Rs. %lf\n\n",tsal);
            if (counter==0){
                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }}
            printf("Next Salary to be paid on %d/%d/%d\n",date,month,year);

        }break;
    case 2:
        {
            printf("Enter salary per day of servant: \n");
            scanf("%d",&sal_per_day);
            fflush(stdin);
            printf("Enter no. of leaves taken: \n");
            scanf("%d",&leave);
            tsal=(sal_per_day*days)-(leave*sal_per_day);
            total+=tsal;
            sprintf(dst,"Servant:   %lf",tsal);
            fputs(dst,fPtr);
            fputs("\n",fPtr);
            printf("\n\nThis month's Salary of servant is : Rs. %lf\n\n",tsal);
            if (counter==0){
                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }}
            printf("Next Salary to be paid on %d/%d/%d\n",date,month,year);
        }break;
    case 3:
        {
            printf("Enter salary per day of Newspaper: \n");
            scanf("%d",&sal_per_day);
            fflush(stdin);
            printf("Enter no. of leaves taken: \n");
            scanf("%d",&leave);
            tsal=(sal_per_day*days)-(leave*sal_per_day);
            total+=tsal;
            sprintf(dst,"Newspaper:   %lf",tsal);
            fputs(dst,fPtr);
            fputs("\n",fPtr);
            printf("\n\nThis month's Bill of Newspaper is : Rs. %lf\n\n",tsal);
            if (counter==0){
                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }}
            printf("Next Salary to be paid on %d/%d/%d\n",date,month,year);
        }break;
    case 4:
        {
            printf("Enter salary per day of Dairy: \n");
            scanf("%d",&sal_per_day);
            fflush(stdin);
            printf("Enter no. of leaves taken: \n");
            scanf("%d",&leave);
            tsal=(sal_per_day*days)-(leave*sal_per_day);
            total+=tsal;
            sprintf(dst,"Dairy:   %lf",tsal);
            fputs(dst,fPtr);
            fputs("\n",fPtr);
            printf("\n\nThis month's Bill of Dairy is : Rs. %lf\n\n",tsal);
            if (counter==0){
                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }}
            printf("Next Salary to be paid on %d/%d/%d\n",date,month,year);
        }break;
    case 5:
        {
            printf("Enter cost per cloth of Istriwaala: \n");
            scanf("%d",&cost_per_cloth);
            fflush(stdin);
            printf("Enter no. of clothes given this week : \n");
            scanf("%d",&cloth);
            tsal=(cost_per_cloth*cloth*4);
            total+=tsal;
            sprintf(dst,"Istriwaala:   %lf",tsal);
            fputs(dst,fPtr);
            fputs("\n",fPtr);
            printf("\n\nThis month's Salary of Istriwaala is : Rs. %lf\n\n",tsal);
            if (counter==0){
                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }}
            printf("Next Salary to be paid on %d/%d/%d\n",date,month,year);
        }break;
        case 6:break;
    /*case 6:
        {
            printf("Enter bill this month : \n");
            scanf("%d",&sal_per_day);
            tsal=(sal_per_day*days);
            printf("\n\n Bill of Electricity is : Rs. %d\n\n",tsal);

        }*/
    default:
        {
            printf("Invalid Input! Please enter a number between 1 to 6\n");
        }
    }}while(num!=6);
    fclose(fPtr);
    fclose(fptr);
    fclose(fp);
    return 0;
}

int fee(int months)
{
    fp = fopen("D:\\date.txt","a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }
    int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char dst1[50];
    fPtr = fopen("D:\\fee.txt", "w");
    fptr = fopen("D:\\fee_temp.txt", "a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }

  int nm,fee_per_year,fee_per_month,month1,date,month,year,days;
  double tfee;
  days=months * 30;
  char category[50];

    do{
    printf("choose the fees you want to calculate:\n1.school fees\n2.bus fees\n3.sports fee\n4.dance fee\n5.tution fee\n6.Other fee\n7.Quit\n\n");
    scanf("%d",&nm);
    fflush(stdin);
    printf("***********************************************************\n");
    system("cls");
    switch(nm)
    {
        case 1:
        {
            printf("enter annual fee of school:\n");
            scanf("%d",&fee_per_year);
            fflush(stdin);
            tfee=fee_per_year/12;
            total+=tfee;
            sprintf(dst1,"School:   %lf",tfee);
            fputs(dst1,fPtr);
            fputs("\n",fPtr);
            printf("your school fees per month is:Rs.%lf\n",tfee);

                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }
            printf("Next fee to be paid on %d/%d/%d\n",date,month,year);
        }break;
         case 2:
        {
            printf("enter monthly fare of bus:\n");
            scanf("%d",&fee_per_month);
            fflush(stdin);
            tfee=fee_per_month*month;
            total+=tfee;
            sprintf(dst1,"Bus:   %lf",tfee);
            fputs(dst1,fPtr);
            fputs("\n",fPtr);
            printf("your yearly bus fair is:Rs.%lf\n",tfee);

                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }
            printf("Next fee to be paid on %d/%d/%d\n",date,month,year);
        }break;
         case 3:
        {
            printf("enter monthly fee of sports academy:\n");
            scanf("%d",&fee_per_month);
            fflush(stdin);
            tfee=fee_per_month*month;
            total+=tfee;
            sprintf(dst1,"Sports Academy:   %lf",tfee);
            fputs(dst1,fPtr);
            fputs("\n",fPtr);
            printf("your yearly sports academy fee is:Rs.%lf\n",tfee);

                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }
            printf("Next fee to be paid on %d/%d/%d\n",date,month,year);
        } break;
        case 4:
        {
            printf("enter monthly fee of dance class:\n");
            scanf("%d",&fee_per_month);
            fflush(stdin);
            tfee=fee_per_month*month;
            total+=tfee;
            sprintf(dst1,"Dance class:   %lf",tfee);
            fputs(dst1,fPtr);
            fputs("\n",fPtr);
            printf("your yearly dance class fee is:Rs.%lf\n",tfee);

                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }
            printf("Next fee to be paid on %d/%d/%d\n",date,month,year);
        }break;
         case 5:
        {
            printf("enter monthly fee of tution:\n");
            scanf("%d",&fee_per_month);
            fflush(stdin);
            tfee=fee_per_month*month;
            total+=tfee;
            sprintf(dst1,"Tution:   %lf",tfee);
            fputs(dst1,fPtr);
            fputs("\n",fPtr);
            printf("your yearly tution fee is:Rs.%lf\n",tfee);

                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }
            printf("Next fee to be paid on %d/%d/%d\n",date,month,year);
        }break;
         case 6:
        {
            printf("Enter the category of fees: ");
            scanf("%[^\n]%*c", category);
            fflush(stdin);
            printf("enter the no of month of fees to be paid\n");
            scanf("%d",&month1);
            fflush(stdin);
            printf("enter monthly fee of %s:\n",category);
            scanf("%d",&fee_per_month);
            tfee=fee_per_month*month1;
            total+=tfee;
            sprintf(dst1,"%s:   %lf",category,tfee);
            fputs(dst1,fPtr);
            fputs("\n",fPtr);
            printf("your yearly %s fee is:Rs.%lf\n",category,tfee);

                printf("Enter last date of payment(dd mm yyyy):");
                scanf("%d%d%d",&date,&month,&year);
                for(int j=0;j<days;j++)
                    {
                        date++;
                        if (date > daysPerMonth[month-1] || ( month==2 && date==29 && !isLeapYear(year) ) )
                        {
                            date = 1;
                            month++;
                            if (month==13)
                            {
                                month= 1;
                                year++;
                            }
                        }
                    }
            printf("Next fee to be paid on %d/%d/%d\n",date,month,year);
        }break;
        case 7:break;
        default:
        {
            printf("Invalid Input! Please enter a number between 1 to 7\n");
        }


    }}while(nm!=7);
    fclose(fPtr);
    fclose(fptr);
    return 0;
}

int appliance()
{
    char dst2[50];
    fPtr = fopen("D:\\appliance.txt", "w");
    fptr = fopen("D:\\appliance_temp.txt", "a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }

    int ch,d,m,y,unit,warranty,d1,m1,y1;
    double cost;
    int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char app[50];
    do{
    printf("Choose option:\n1.Enter appliance name\n2.Quit\n\n");
    scanf("%d",&ch);
    printf("***********************************************************\n");
    fflush(stdin);
    if(ch>2)
    {
        printf("\nInvalid Input! Please enter a number between 1 to 2");
    }
    if(ch==1)
    {
        printf("Enter appliance name:\n");
        scanf("%[^\n]%*c",app);
        printf("Enter the number of units of %s: \n",app);
        scanf("%d",&unit);
        fflush(stdin);
            for(int i=1;i<=unit;i++)
            {
                printf("Enter the Date of Purchase:(dd mm yyyy)\n");
                scanf("%d%d%d",&d,&m,&y);
                printf("Enter Cost : ");
                scanf("%lf",&cost);
                total+=cost;
                sprintf(dst2,"%s:   %lf",app,cost);
                fputs(dst2,fPtr);
                fputs("\n",fPtr);
                d1=d;m1=m;y1=y;
                printf("Enter warranty in days: \n");
                scanf("%d",&warranty);
                fflush(stdin);
                for(int j=0;j<warranty;j++)
                    {
                        d++;
                        if (d > daysPerMonth[m-1] || ( m==2 && d==29 && !isLeapYear(y) ) )
                        {
                            d = 1;
                            m++;
                            if (m==13)
                            {
                                m = 1;
                                y++;
                            }
                        }
                    }
                printf("Date of Purchase of %s %d is: %d/%d/%d\n",app,i,d1,m1,y1);
                printf("Date of expiry of %s %d is: %d/%d/%d\n",app,i,d,m,y);
                printf("-----------------------------------------------------------\n");
            }

        }
    }while(ch!=2);
    fclose(fPtr);
    fclose(fptr);
    return 0;
}
bool isLeapYear(int year)
{
    if (year%400==0) return true;
    if (year%100==0) return false;
    return (year%4==0);
}
int shopping()
{
    int ch;
    double amount;
    printf("*************Shopping by category***************\n");
    printf("-----------------------------------------------------------\n");
    printf("-----------------------------------------------------------\n");
    do
    {
        system("cls");
        printf("Choose category:\n1.Vegetables\n2.Fruits\n3.Dairy\n4.Wheat,Rice,Oil,Dal\n5.Beverage\n6.Household supplies\n7.Personal Care\n8.Beauty\n9.Quit\n\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:veg();
            break;
            case 2:fruits();
            break;
            case 3:dairy();
            break;
            case 4:wrod();
            break;
            case 5:bev();
            break;
            case 6:house();
            break;
            case 7:pers();
            break;
            case 8:beauty();
            break;
            case 9:break;
            default:
                {
                    printf("Invalid Input. Please enter a number between 1 and 9");
                }
        }
    }while(ch!=9);
    fflush(stdin);
    printf("Have you shopped these items?(Y/N)");
    scanf("%c",&op);
    if(op=='Y')
    {
        printf("Enter Bill amount :");
        scanf("%lf",&amount);
        total+=amount;
    }

    return 0;
}
int veg()
{
    char dst3[50];
    fPtr = fopen("D:\\grocery.txt", "w");
    fptr = fopen("D:\\grocery_temp.txt", "a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }

    double am;
    char veg[22][50]={"Tomatoes   ","Potatoes   ","Brinjal    ","Capsicum   ","LadyFinger ","Cucumber   ","Carrot     ","Coriander  ","Mint       ","Methi      ","Onion      ","Cabbage    ","Cauliflower","Drumstick  ","Pumpkin    ","Spinach    ","GreenChilli","CurryLeaves","Arbi       ","BitterGourd","RichGourd  "};

        printf("\nITEM\tQUANTITY(kg)\n");
        printf("-----------------------------------------------------------\n");
        printf("**VEGETABLES**\n");
        for(int i=1;i<=21;i++)
        {
            printf("%s ",veg[i-1]);
            scanf("%lf",&am);
            sprintf(dst3,"%s:   %lf",veg[i-1],am);
            fputs(dst3,fPtr);
            fputs("\n",fPtr);
            printf("\n");
            fflush(stdin);
        }
        fclose(fPtr);
        fclose(fptr);

    return 0;
}
int fruits()
{
    char dst3[50];
    fPtr = fopen("D:\\grocery.txt", "w");
    fptr = fopen("D:\\grocery_temp.txt", "a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }

    double am;
    char fru[11][50]={"Apple      ","Banana     ","Orange     ","Watermelon ","Muskmelon  ","Pear       ","Grapes     ","Mango      ","Pomegranate","Guava      ","Pineapple  "};
        printf("\nITEM\tQUANTITY(kg)\n");
        printf("-----------------------------------------------------------\n");
        printf("**FRUITS**\n");
        for(int i=1;i<=11;i++)
        {
            printf("%s ",fru[i-1]);
            scanf("%lf",&am);
            sprintf(dst3,"%s:  %lf",fru[i-1],am);
            fputs(dst3,fPtr);
            fputs("\n",fPtr);
            printf("\n");
            fflush(stdin);
        }
        fclose(fPtr);
        fclose(fptr);

    return 0;
}
int dairy()
{
    char dst3[50];
    fPtr = fopen("D:\\grocery.txt", "w");
    fptr = fopen("D:\\grocery_temp.txt", "a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }

    double am;
    char dai[5][50]={"Milk          ","Cheese        ","Cottage Cheese","Yogurt        ","Butter        "};
        printf("\nITEM\tQUANTITY(kg Or lit)\n");
        printf("-----------------------------------------------------------\n");
        printf("**DAIRY**\n");
        for(int i=1;i<=5;i++)
        {
            printf("%s ",dai[i-1]);
            scanf("%lf",&am);
            sprintf(dst3,"%s:   %lf",dai[i-1],am);
            fputs(dst3,fPtr);
            fputs("\n",fPtr);
            printf("\n");
            fflush(stdin);
        }
        fclose(fPtr);
        fclose(fptr);

    return 0;
}
int wrod()
{
    char dst3[50];
    fPtr = fopen("D:\\grocery.txt", "w");
    fptr = fopen("D:\\grocery_temp.txt", "a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }

    double am;
    char arr[4][50]={"Wheat","Rice ","Oil  ","Dal  "};
        printf("\nITEM\tQUANTITY(kg Or lit)\n");
        printf("-----------------------------------------------------------\n");
        printf("**RATION**\n");
        for(int i=1;i<=4;i++)
        {
            printf("%s ",arr[i-1]);
            scanf("%lf",&am);
            sprintf(dst3,"%s:   %lf",arr[i-1],am);
            fputs(dst3,fPtr);
            fputs("\n",fPtr);
            printf("\n");
            fflush(stdin);
        }
        fclose(fPtr);
        fclose(fptr);

    return 0;
}
int bev()
{
    char dst3[50];
    fPtr = fopen("D:\\grocery.txt", "w");
    fptr = fopen("D:\\grocery_temp.txt", "a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }

    double am;
    char arr[2][50]={"Tea   ","Coffee"};
        printf("\nITEM\tQUANTITY(kg)\n");
        printf("-----------------------------------------------------------\n");
        printf("**BEVERAGE**\n");
        for(int i=1;i<=2;i++)
        {
            printf("%s ",arr[i-1]);
            scanf("%lf",&am);
            sprintf(dst3,"%s:   %lf",arr[i-1],am);
            fputs(dst3,fPtr);
            fputs("\n",fPtr);
            printf("\n");
            fflush(stdin);
        }
        fclose(fPtr);
        fclose(fptr);

    return 0;
}
int pers()
{
    char dst3[50];
    fPtr = fopen("D:\\grocery.txt", "w");
    fptr = fopen("D:\\grocery_temp.txt", "a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }

    double am;
    char arr[14][50]={"Shampoo         ","Conditioner     ","Soap            ","Face Wash       ","Toothpaste      ","Toothbrush      ","Mouthwash       ","Shaving Cream   ","Shaving Brush   ","Razor           ","Feminine Hygiene","Baby Diaper     ","Baby Powder     ","Baby cleansing  "};
        printf("\nITEM\tQUANTITY\n");
        printf("-----------------------------------------------------------\n");
        printf("**PERSONAL HYGIENE**\n");
        for(int i=1;i<=14;i++)
        {
            printf("%s ",arr[i-1]);
            scanf("%lf",&am);
            sprintf(dst3,"%s:   %lf",arr[i-1],am);
            fputs(dst3,fPtr);
            fputs("\n",fPtr);
            printf("\n");
            fflush(stdin);
        }
        fclose(fPtr);
        fclose(fptr);

    return 0;
}
int house()
{
    char dst3[50];
    fPtr = fopen("D:\\grocery.txt", "w");
    fptr = fopen("D:\\grocery_temp.txt", "a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }

    double am;
    char arr[11][50]={"Bathroom Cleaner","Toilet Cleaner  ","Hand wash       ","Toilet Tissue   ","Dish washer     ","Air freshener   ","Detergents      ","Batteries       ","Fabric Care     ","Cleaning Supply ","Paper Towels    "};
        printf("\nITEM\tQUANTITY\n");
        printf("-----------------------------------------------------------\n");
        printf("**HOUSEHOLD SUPPLIES**\n");
        for(int i=1;i<=11;i++)
        {
            printf("%s ",arr[i-1]);
            scanf("%lf",&am);
            sprintf(dst3,"%s:   %lf",arr[i-1],am);
            fputs(dst3,fPtr);
            fputs("\n",fPtr);
            printf("\n");
            fflush(stdin);
        }
        fclose(fPtr);
        fclose(fptr);

    return 0;
}
int beauty()
{
    char dst3[50];
    fPtr = fopen("D:\\grocery.txt", "w");
    fptr = fopen("D:\\grocery_temp.txt", "a");
    if (fPtr == NULL || fptr == NULL)
    {
        printf("Please check whether file exists and you have write privilege.\n");
        exit(0);
    }

    double am;
    char arr[9][50]={"Face Wash       ","Face Cream      ","Sunscreen       ","Body Lotion     ","Scrubs and Packs","Lip Gloss       ","Eye make-up     ","Face make-up    ","Perfume         "};
        printf("\nITEM\tQUANTITY\n");
        printf("-----------------------------------------------------------\n");
        printf("**BEAUTY**\n");
        for(int i=1;i<=9;i++)
        {
            printf("%s ",arr[i-1]);
            scanf("%lf",&am);
            sprintf(dst3,"%s:   %lf",arr[i-1],am);
            fputs(dst3,fPtr);
            fputs("\n",fPtr);
            printf("\n");
            fflush(stdin);
        }
        fclose(fPtr);
        fclose(fptr);

    return 0;
}
int budget()
{
        fp = fopen("D:\\budgets.txt","r");
        char t[50];
        system("cls");
        printf("\n\n\n===========================================================\n");

        printf("*****       BUDGET       *****\n\n");
        printf("\tSALARIES :\n");
        fPtr = freopen("D:\\salary.txt", "r", fPtr);
        fptr=freopen("D:\\salary_temp.txt","r",fptr);
        if(counter>0)
            readFile(fPtr);
        else
            readFile(fptr);
        fclose(fPtr);
        printf("----------------------------------------------------------\n");
        printf("\tBILLS/FEE :\n");
        fPtr = freopen("D:\\fee.txt", "r", fPtr);
        fptr=freopen("D:\\fee_temp.txt","r",fptr);
        if(counter>0)
            readFile(fPtr);
        else
            readFile(fptr);
        fclose(fPtr);
        fclose(fptr);
        printf("----------------------------------------------------------\n");
        printf("\tAPPLIANCE :\n");
        fPtr = freopen("D:\\appliance.txt", "r", fPtr);
        fptr=freopen("D:\\appliance_temp.txt","r",fptr);
        if(counter>0)
            readFile(fPtr);
        else
            readFile(fptr);
        fclose(fPtr);
        fclose(fptr);
        printf("----------------------------------------------------------\n");
        printf("\tSHOPPING :\n");
        fPtr = freopen("D:\\grocery.txt", "r", fPtr);
        fptr=freopen("D:\\grocery_temp.txt","r",fptr);
        if(counter>0)
            readFile(fPtr);
        else
            readFile(fptr);
        fclose(fPtr);
        fclose(fptr);
        if(op=='N'){
        printf("----------------------------------------------------------\n");
        printf("\n\nYOUR GRAND TOTAL IS (excluding shopping list)= Rs %lf\n",total);
        printf("-----------------------------------------------------------\n");}
        else
        {
            printf("----------------------------------------------------------\n");
            printf("\n\nYOUR GRAND TOTAL IS (including shopping list)= Rs %lf\n",total);
            printf("-----------------------------------------------------------\n");
        }
        readFile(fp);
        fclose(fp);
        fp = freopen("D:\\budgets.txt","a",fp);
        sprintf(t,"PREVIOUS BUDGET :   %d",total);
        fputs(t,fp);
        fclose(fp);
        return 0;
}
void readFile(FILE * fPtr)
{
    char ch;

    do
    {
        ch = fgetc(fPtr);

        putchar(ch);

    } while (ch != EOF);
}

