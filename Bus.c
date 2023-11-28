#include <stdio.h>
#include <string.h>

#define MAX_BUSES 10                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         \]1342''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
{
    char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
};

struct Bus bus[MAX_BUSES];

void vline(char ch)
{
    for (int i = 80; i > 0; i--)
        printf("%c", ch);
}

void install()
{
    printf("Enter bus no: ");
    scanf("%s", bus[p].busn);
    printf("\nEnter Driver's name: ");
    scanf("%s", bus[p].driver);
    printf("\nArrival time: ");
    scanf("%s", bus[p].arrival);
    printf("\nDeparture: ");
    scanf("%s", bus[p].depart);
    printf("\nFrom: \t\t\t");
    scanf("%s", bus[p].from);
    printf("\nTo: \t\t\t");
    scanf("%s", bus[p].to);
    p++;
}

void allotment()
{
    int seat;
    char number[5];
top:
    printf("Bus no: ");
    scanf("%s", number);
    int n;
    for (n = 0; n < p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }
    while (n < p)
    {
        printf("\nSeat Number: ");
        scanf("%d", &seat);
        if (seat > 32)
        {
            printf("\nThere are only 32 seats available in this bus.");
        }
        else
        {
            if (strcmp(bus[n].seat[seat / 4][(seat % 4) - 1], "Empty") == 0)
            {
                printf("Enter passenger's name: ");
                scanf("%s", bus[n].seat[seat / 4][(seat % 4) - 1]);
                break;
            }
            else
                printf("The seat no. is already reserved.\n");
        }
    }
    if (n == p)
    {
        printf("Enter the correct bus no.\n");
        goto top;
    }
}

void empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}

void show()
{
    int n;
    char number[5];
    printf("Enter bus no: ");
    scanf("%s", number);
    for (n = 0; n < p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }
    if (n == p)
    {
        printf("Enter the correct bus no: ");
        return;
    }

    vline('*');
    printf("Bus no: \t%s\nDriver: \t%s\t\tArrival time: \t%s\tDeparture time:%s\nFrom: \t\t%s\t\tTo: \t\t%s\n",
           bus[n].busn, bus[n].driver, bus[n].arrival, bus[n].depart, bus[n].from, bus[n].to);
    vline('*');
    int a = 1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a++;
            if (strcmp(bus[n].seat[i][j], "Empty") != 0)
                printf("\nThe seat no %d is reserved for %s.", (a - 1), bus[n].seat[i][j]);
        }
    }
}

void position(int l)
{
    int s = 0;
    p = 0;
    for (int i = 0; i < 8; i++)
    {
        printf("\n");
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(bus[l].seat[i][j], "Empty") == 0)
            {
                printf("%5d.%10s", s, bus[l].seat[i][j]);
                p++;
            }
            else
            {
                printf("%5d.%10s", s, bus[l].seat[i][j]);
            }
        }
    }
    printf("\n\nThere are %d seats empty in Bus No: %s", p, bus[l].busn);
}

void avail()
{
    for (int n = 0; n < p; n++)
    {
        vline('*');
        printf("Bus no: \t%s\nDriver: \t%s\t\tArrival time: \t%s\tDeparture Time: \t%s\nFrom: \t\t%s\t\tTo: \t\t%s\n",
               bus[n].busn, bus[n].driver, bus[n].arrival, bus[n].depart, bus[n].from, bus[n].to);
        vline('*');
        vline('_');
    }
}

int main()
{
    int w;
    while (1)
    {
        printf("\n\n");
        printf("\t\t***SIMPLE BUS RESERVATION SYSTEM***");
        printf("\n\n");
        printf("\t\t\t 1.Install\n\t\t\t"
               "2.Reservation\n\t\t\t"
               "3.Show\n\t\t\t"
               "4.Buses Available\n\t\t\t"
               "5.Exit");
        printf("\n\t\t\tEnter your choice:- ");
        scanf("%d", &w);

        switch (w)
        {
        case 1:
            install();
            break;
        case 2:
            allotment();
            break;
        case 3:
            show();
            break;
        case 4:
            avail();
            break;
        case 5:
            return 0;
        }
    }

    return 0;
}
