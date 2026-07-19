#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

#define ADMIN_FILE "admin.dat"

typedef struct
{
    char username[30];
    char password[30];
} Admin;

void signUp()
{
    FILE *fp;
    Admin admin, temp;

    fp = fopen(ADMIN_FILE, "ab+");

    if(fp == NULL)
    {
        printf("\nUnable to open file.\n");
        return;
    }

    printf("\n========== SIGN UP ==========\n");

    printf("Username : ");
    scanf("%s", admin.username);

    rewind(fp);

    while(fread(&temp, sizeof(Admin), 1, fp))
    {
        if(strcmp(temp.username, admin.username) == 0)
        {
            printf("\nUsername already exists.\n");
            fclose(fp);
            return;
        }
    }

    printf("Password : ");
    scanf("%s", admin.password);

    fwrite(&admin, sizeof(Admin), 1, fp);

    fclose(fp);

    printf("\nAccount Created Successfully.\n");
}

int login()
{
    FILE *fp;
    Admin admin;

    char username[30];
    char password[30];

    int attempts = 3;

    fp = fopen(ADMIN_FILE, "rb");

    if(fp == NULL)
    {
        printf("\nNo Admin Account Found.\n");
        printf("Please Sign Up First.\n");
        return 0;
    }

    while(attempts--)
    {
        printf("\n========== LOGIN ==========\n");

        printf("Username : ");
        scanf("%s", username);

        printf("Password : ");
        scanf("%s", password);

        rewind(fp);

        while(fread(&admin, sizeof(Admin), 1, fp))
        {
            if(strcmp(username, admin.username) == 0 &&
               strcmp(password, admin.password) == 0)
            {
                fclose(fp);
                printf("\nLogin Successful.\n");
                return 1;
            }
        }

        printf("\nInvalid Username or Password.\n");
        printf("Remaining Attempts : %d\n", attempts);
    }

    fclose(fp);

    printf("\nLogin Failed.\n");

    return 0;
}
