#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"
#include "billing.h"

#define CUSTOMER_FILE "customers.dat"

float calculateAmount(float units)
{
    float amount = 0;

    if (units <= 100)
    {
        amount = units * 1.5;
    }
    else if (units <= 200)
    {
        amount = (100 * 1.5) + ((units - 100) * 2.5);
    }
    else if (units <= 300)
    {
        amount = (100 * 1.5) + (100 * 2.5) + ((units - 200) * 4);
    }
    else
    {
        amount = (100 * 1.5) + (100 * 2.5) + (100 * 4) + ((units - 300) * 6);
    }

    return amount;
}

void generateBill()
{
    FILE *fp;
    Customer c;
    int id, found = 0;

    fp = fopen(CUSTOMER_FILE, "rb+");

    if (fp == NULL)
    {
        printf("\nCustomer file not found.\n");
        return;
    }

    printf("\nEnter Consumer ID : ");
    scanf("%d", &id);

    while (fread(&c, sizeof(Customer), 1, fp))
    {
        if (c.consumerId == id)
        {
            found = 1;

            c.units = c.currReading - c.prevReading;

            if (c.units < 0)
                c.units = 0;

            c.amount = calculateAmount(c.units);

            fseek(fp, -sizeof(Customer), SEEK_CUR);
            fwrite(&c, sizeof(Customer), 1, fp);

            printf("\n========== Electricity Bill ==========\n");
            printf("Consumer ID     : %d\n", c.consumerId);
            printf("Customer Name   : %s\n", c.name);
            printf("Units Consumed  : %.2f\n", c.units);
            printf("Bill Amount     : Rs. %.2f\n", c.amount);
            printf("Status          : %s\n",
                   c.paymentStatus ? "Paid" : "Pending");

            break;
        }
    }

    if (!found)
    {
        printf("\nCustomer Not Found.\n");
    }

    fclose(fp);
}

void payBill()
{
    FILE *fp;
    Customer c;
    int id, found = 0;

    fp = fopen(CUSTOMER_FILE, "rb+");

    if (fp == NULL)
    {
        printf("\nCustomer file not found.\n");
        return;
    }

    printf("\nEnter Consumer ID : ");
    scanf("%d", &id);

    while (fread(&c, sizeof(Customer), 1, fp))
    {
        if (c.consumerId == id)
        {
            found = 1;

            if (c.amount == 0)
            {
                printf("\nGenerate the bill first.\n");
                break;
            }

            if (c.paymentStatus)
            {
                printf("\nBill Already Paid.\n");
                break;
            }

            c.paymentStatus = 1;

            fseek(fp, -sizeof(Customer), SEEK_CUR);
            fwrite(&c, sizeof(Customer), 1, fp);

            printf("\nPayment Successful.\n");
            printf("Amount Paid : Rs. %.2f\n", c.amount);

            break;
        }
    }

    if (!found)
    {
        printf("\nCustomer Not Found.\n");
    }

    fclose(fp);
}

void billHistory()
{
    FILE *fp;
    Customer c;

    fp = fopen(CUSTOMER_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    printf("\n================ BILL HISTORY ================\n");

    while (fread(&c, sizeof(Customer), 1, fp))
    {
        printf("\n----------------------------------------------\n");
        printf("Consumer ID    : %d\n", c.consumerId);
        printf("Customer Name  : %s\n", c.name);
        printf("Units          : %.2f\n", c.units);
        printf("Bill Amount    : Rs. %.2f\n", c.amount);
        printf("Payment Status : %s\n",
               c.paymentStatus ? "Paid" : "Pending");
    }

    fclose(fp);
}
