#include <stdio.h>
#include <stdlib.h>

#include "login.h"
#include "customer.h"
#include "billing.h"

int main()
{
    int choice;
    int loginChoice;

    while(1)
    {
        printf("\n====================================");
        printf("\n ELECTRICITY BILLING SYSTEM");
        printf("\n====================================");

        printf("\n1. Sign Up");
        printf("\n2. Login");
        printf("\n3. Exit");

        printf("\n\nEnter Choice : ");
        scanf("%d",&loginChoice);

        switch(loginChoice)
        {
            case 1:
                signUp();
                break;

            case 2:
                if(login())
                {
                    goto MENU;
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid Choice.\n");
        }
    }

MENU:

    while(1)
    {
        printf("\n====================================");
        printf("\n ELECTRICITY BILLING SYSTEM");
        printf("\n====================================");

        printf("\n1. Add Customer");
        printf("\n2. View Customers");
        printf("\n3. Search Customer");
        printf("\n4. Modify Customer");
        printf("\n5. Delete Customer");
        printf("\n6. Generate Bill");
        printf("\n7. Pay Bill");
        printf("\n8. Bill History");
        printf("\n9. Exit");

        printf("\n\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addCustomer();
                break;

            case 2:
                viewCustomers();
                break;

            case 3:
                searchCustomer();
                break;

            case 4:
                modifyCustomer();
                break;

            case 5:
                deleteCustomer();
                break;

            case 6:
                generateBill();
                break;

            case 7:
                payBill();
                break;

            case 8:
                billHistory();
                break;

            case 9:
                exit(0);

            default:
                printf("\nInvalid Choice.\n");
        }
    }

    return 0;
}
