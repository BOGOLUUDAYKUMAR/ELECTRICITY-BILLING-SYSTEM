#ifndef CUSTOMER_H
#define CUSTOMER_H

#define NAME_LENGTH 50
#define ADDRESS_LENGTH 100
#define PHONE_LENGTH 15

typedef struct
{
    int consumerId;
    char name[NAME_LENGTH];
    char address[ADDRESS_LENGTH];
    char phone[PHONE_LENGTH];
    float prevReading;
    float currReading;
    float units;
    float amount;
    int paymentStatus;
} Customer;

void addCustomer();
void viewCustomers();
void searchCustomer();
void modifyCustomer();
void deleteCustomer();

#endif
