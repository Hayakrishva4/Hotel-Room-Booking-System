#include <stdio.h>
#include <string.h>
struct Hotel
{
    int roomNo;
    char name[30];
    int days;
};
void addBooking(struct Hotel h[], int *n);
void viewBooking();
void searchBooking();
int main()
{
    struct Hotel h[20];
    int n = 0, choice;
    while (1)
    {
        printf("\n===== HOTEL MANAGEMENT SYSTEM =====");
        printf("\n1. Add Booking");
        printf("\n2. View Booking");
        printf("\n3. Search Booking");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBooking(h, &n);
            break;
        case 2:
            viewBooking();
            break;
        case 3:
            searchBooking();
            break;
        case 4:
            printf("Thank You!\n");
            return 0;
        default:
            printf("Invalid Choice!\n");
        }
    }
}
void addBooking(struct Hotel h[], int *n)
{
    FILE *fp = fopen("hotel.txt", "a");
    if (fp == NULL)
    {
        printf("File cannot be opened!\n");
        return;
    }
    printf("Enter Room Number: ");
    scanf("%d", &h[*n].roomNo);
    printf("Enter Customer Name: ");
    scanf("%s", h[*n].name);
    printf("Enter Number of Days: ");
    scanf("%d", &h[*n].days);
    fprintf(fp, "%d %s %d\n", h[*n].roomNo, h[*n].name, h[*n].days);
    fclose(fp);
    (*n)++;
    printf("Booking Added Successfully!\n");
}
void viewBooking()
{
    FILE *fp = fopen("hotel.txt", "r");
    struct Hotel h;
    if (fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }
    printf("\nRoom No\tName\tDays\n");
    printf("---------------------------\n");
    while (fscanf(fp, "%d %s %d", &h.roomNo, h.name, &h.days) == 3)
    {
        printf("%d\t%s\t%d\n", h.roomNo, h.name, h.days);
    }
    fclose(fp);
}
void searchBooking()
{
    FILE *fp = fopen("hotel.txt", "r");
    struct Hotel h;
    int room, found = 0;
    if (fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }
    printf("Enter Room Number to Search: ");
    scanf("%d", &room);
    while (fscanf(fp, "%d %s %d", &h.roomNo, h.name, &h.days) == 3)
    {
        if (h.roomNo == room)
        {
            printf("\nBooking Found\n");
            printf("Room Number : %d\n", h.roomNo);
            printf("Customer Name : %s\n", h.name);
            printf("Days : %d\n", h.days);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Booking Not Found!\n");
    fclose(fp);
}