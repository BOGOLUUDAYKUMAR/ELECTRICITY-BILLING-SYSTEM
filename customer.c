#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

#define CUSTOMER_FILE "customers.dat"

void addCustomer()
{
    FILE *fp;
    Customer c;

    fp = fopen(CUSTOMER_FILE, "ab");

    if (fp == NULL)
    {
        printf("\nUnable to open file!\n");
        return;
    }

    printf("\n========== Add Customer ==========\n");

    printf("Consumer ID : ");
    scanf("%d", &c.consumerId);

    getchar();

    printf("Name : ");
    fgets(c.name, NAME_LENGTH, stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    printf("Address : ");
    fgets(c.address, ADDRESS_LENGTH, stdin);
    c.address[strcspn(c.address, "\n")] = '\0';

    printf("Phone : ");
    fgets(c.phone, PHONE_LENGTH, stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("Previous Reading : ");
    scanf("%f", &c.prevReading);

    printf("Current Reading : ");
    scanf("%f", &c.currReading);

    c.units = 0;
    c.amount = 0;
    c.paymentStatus = 0;

    fwrite(&c, sizeof(Customer), 1, fp);

    fclose(fp);

    printf("\nCustomer Added Successfully.\n");
}

void viewCustomers()
{
    FILE *fp;
    Customer c;

    fp = fopen(CUSTOMER_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nNo customer records found.\n");
        return;
    }

    printf("\n========== Customer List ==========\n");

    while (fread(&c, sizeof(Customer), 1, fp))
    {
        printf("\n---------------------------------\n");
        printf("Consumer ID     : %d\n", c.consumerId);
        printf("Name            : %s\n", c.name);
        printf("Address         : %s\n", c.address);
        printf("Phone           : %s\n", c.phone);
        printf("Previous Read   : %.2f\n", c.prevReading);
        printf("Current Read    : %.2f\n", c.currReading);
        printf("Units           : %.2f\n", c.units);
        printf("Amount          : %.2f\n", c.amount);
        printf("Payment Status  : %s\n",
               c.paymentStatus ? "Paid" : "Pending");
    }

    fclose(fp);
}

void searchCustomer()
{
    FILE *fp;
    Customer c;
    int id, found = 0;

    fp = fopen(CUSTOMER_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }

    printf("\nEnter Consumer ID : ");
    scanf("%d", &id);

    while (fread(&c, sizeof(Customer), 1, fp))
    {
        if (c.consumerId == id)
        {
            found = 1;

            printf("\nCustomer Found\n");
            printf("-------------------------\n");
            printf("Consumer ID : %d\n", c.consumerId);
            printf("Name        : %s\n", c.name);
            printf("Address     : %s\n", c.address);
            printf("Phone       : %s\n", c.phone);
            printf("Prev Read   : %.2f\n", c.prevReading);
            printf("Curr Read   : %.2f\n", c.currReading);
            printf("Units       : %.2f\n", c.units);
            printf("Amount      : %.2f\n", c.amount);
            printf("Status      : %s\n",
                   c.paymentStatus ? "Paid" : "Pending");
            break;
        }
    }

    if (!found)
        printf("\nCustomer Not Found.\n");

    fclose(fp);
}

void modifyCustomer()
{
    FILE *fp;
    Customer c;
    int id, found = 0;

    fp = fopen(CUSTOMER_FILE, "rb+");

    if (fp == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }

    printf("\nEnter Consumer ID : ");
    scanf("%d", &id);

    while (fread(&c, sizeof(Customer), 1, fp))
    {
        if (c.consumerId == id)
        {
            found = 1;

            getchar();

            printf("New Name : ");
            fgets(c.name, NAME_LENGTH, stdin);
            c.name[strcspn(c.name, "\n")] = '\0';

            printf("New Address : ");
            fgets(c.address, ADDRESS_LENGTH, stdin);
            c.address[strcspn(c.address, "\n")] = '\0';

            printf("New Phone : ");
            fgets(c.phone, PHONE_LENGTH, stdin);
            c.phone[strcspn(c.phone, "\n")] = '\0';

            printf("Previous Reading : ");
            scanf("%f", &c.prevReading);

            printf("Current Reading : ");
            scanf("%f", &c.currReading);

            fseek(fp, -sizeof(Customer), SEEK_CUR);

            fwrite(&c, sizeof(Customer), 1, fp);

            printf("\nCustomer Updated Successfully.\n");

            break;
        }
    }

    if (!found)
        printf("\nCustomer Not Found.\n");

    fclose(fp);
}

void deleteCustomer()
{
    FILE *fp, *temp;
    Customer c;
    int id, found = 0;

    fp = fopen(CUSTOMER_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    printf("\nEnter Consumer ID : ");
    scanf("%d", &id);

    while (fread(&c, sizeof(Customer), 1, fp))
    {
        if (c.consumerId == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&c, sizeof(Customer), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(CUSTOMER_FILE);
    rename("temp.dat", CUSTOMER_FILE);

    if (found)
        printf("\nCustomer Deleted Successfully.\n");
    else
        printf("\nCustomer Not Found.\n");
}
