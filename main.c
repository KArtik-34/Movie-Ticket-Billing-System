#include <stdio.h>
int rw, stno, trtp;

char name[20];
int age, aadhr, mob_no;
//hohohoh
char mvnm[3][20] = {"Robot", " KGF", "Avatar"};
char shtm[4][20] = {"10:00-12:00", "13:00-15:00", "15:00-17:00", "18:00-20:00"};
int slct, shlct;

char tier[3][20] = {"Silver", "Gold", "Platinum"};
char *row[3][4] = {{"A", "B", "C", "D"}, {"E", "F", "G", "H"}, {"I", "J", "K", "L"}};
char row_S[4][10] = {"A", "B", "C", "D"};
char row_G[4][10] = {"E", "F", "G", "H"};
char row_P[1][5] = {"I"};
//heyheyhey

int cust()
{
    printf("Enter Your Name: ");
    gets(name);
    printf("Enter your Age: ");
    scanf("%d", &age);
    printf("Enter your aadhaar no.:");
    scanf("%d", &aadhr);
    printf("Enter Mobile No.:");
    scanf("%d", &mob_no);
}


int Mvsh()
{
    for (int i = 0; i < 3; ++i)
    {
        printf("%s\t", mvnm[i]);
    }
    printf("\nSelect the name of the movie (1,2,3):");

    scanf("%d", &slct);
    if (slct == 1 || (slct == 2) || (slct == 3))
    {
        for (int i = 0; i < 4; ++i)
        {
            printf("%s\t", shtm[i]);
        }
    }
    else
    {
        printf("Enter a valid number");
    }
    printf("\nSelect the time-slot (1,2,3,4):");
    scanf("%d", &shlct);
}


int sngl_bk()
{

    //    int rw,stno,trtp;
    FILE *f;
    f = fopen("booking_Details.txt", "a");
    for (int i = 0; i < 3; ++i)
    {
        printf("%s\t", tier[i]);
    }
    printf("\nSelect Tier (1,2,3): ");
    scanf("%d", &trtp);
    switch (trtp)
    {
    case 1:
        for (int i = 0; i < 4; ++i)
        {
            printf("%s\t", row_S[i]);
        }
        printf("\nSelect Row (1,2,3,4): ");
        scanf("%d", &rw);

        break;
    case 2:
        for (int i = 0; i < 4; ++i)
        {
            printf("%s\t", row_G[i]);
        }
        printf("\nSelect Row (1,2,3,4): ");
        scanf("%d", &rw);
        break;
    case 3:
        for (int i = 0; i < 1; ++i)
        {
            printf("You Selected the Platinum row: %s\n", row_P[i]);
        }
        break;
    }
    printf("Select Seat No. (1-50): ");
    scanf("%d", &stno);
    // fprintf(f,)
    fprintf(f, "%s %s %d %s %d %s %d", name, mvnm[slct - 1], age, row[trtp - 1][rw], mob_no, shtm[shlct - 1], aadhr);
    fclose(f);
}


void cancel()
{
    FILE *f;
    f = fopen("booking_Details.txt", "w");
    printf("Cancelled Successfully\n");
    fclose(f);
}


int main()
{
    int opt;
    printf("Welcome to cineplex\nplease register yourself\n");
    cust();

    do
    {
        printf("1.Book ticket\n2.Cancel Ticket\n3.exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            Mvsh();
            sngl_bk();
            printf("Thank You for Booking With Us\nHere is your movie Ticket:\n");
            printf("%s\t\t%s\n%d\t\t%s-%d\n%d\t%s\n", name, mvnm[slct - 1], age, row[trtp - 1][rw], stno, mob_no, shtm[shlct - 1]);
            break;
        }
        case 2:
        {
            cancel();
            break;
        }
        case 3:
        {
            printf("\nThankyou");
            break;
//            exit();
        }
        default:
        {
            printf("Invalid choice. Please try again.\n");
        }
        }
    } while (opt != 3);
}
