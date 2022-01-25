#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct User
{
    char UserName[50];
    char UserId[15];
    char UserAadhar[20];
    char Vaccine_name[100];
    char UserContactNum[15];

} User;

void createAccount();
void displayInfo();
void updateInfo();
void deleteInfo();
void searchInfo();

int main()
{
    char option;

    while (option != '0')
    {
        system("cls");
        printf("\t\t====== Vaccine Registration System ======\n");
        printf("\n\t\t\t1. Create User Account");
        printf("\n\t\t\t2. Display All Users Information");
        printf("\n\t\t\t3. Update User Information");
        printf("\n\t\t\t4. Delete User Information");
        printf("\n\t\t\t5. Search User Information");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            createAccount();
            break;
        case '2':
            displayInfo();
            break;
        case '3':
            updateInfo();
            break;
        case '4':
            deleteInfo();
            break;
        case '5':
            searchInfo();
            break;
        case '0':
            printf("\n\t\t\t====== Thank You ======");
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
    return 0;
}

void createAccount()
{
    FILE *fileOne = fopen("UserInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    User Info;

    system("cls");

    printf("\t\t\t====== Create User Account ======\n");

    printf("\n\t\t\tEnter User's Name : ");
    getchar();
    gets(Info.UserName);
    printf("\t\t\tEnter User's ID : ");
    gets(Info.UserId);
    printf("\t\t\tEnter User's Aadhaar : ");
    gets(Info.UserAadhar);
    printf("\t\t\tEnter User's Vaccine : ");
    gets(Info.Vaccine_name);
    printf("\t\t\tEnter User's Contact Number : ");
    gets(Info.UserContactNum);

    fwrite(&Info, sizeof(Info), 1, fileOne);

    printf("\n\n\t\t\tInformations have been stored sucessfully\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void displayInfo()
{
    FILE *fileOne = fopen("UserInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    User Info;

    system("cls");

    printf("\t\t\t\t====== All Users Information ======\n");

    printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%", "Name", "ID", "Aadhaar", "Vaccine", "Contact");
    printf("\t\t----------------------------------------------------------------------------------------");

    while (fread(&Info, sizeof(Info), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%", Info.UserName, Info.UserId, Info.UserAadhar, Info.Vaccine_name, Info.UserContactNum);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void updateInfo()
{
    FILE *fileOne = fopen("UserInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    User Info, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Update Users Information ======\n");

    printf("\n\t\t\tEnter User's ID : ");
    getchar();
    gets(tempInformation.UserId);

    while (fread(&Info, sizeof(Info), 1, fileOne) == 1)
    {
        if (strcmp(Info.UserId, tempInformation.UserId) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update User Name\n\t\t\t2.Update User ID\n\t\t\t3.Update User Aadhaar\n\t\t\t4.Update User Contact No.");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter User's Name to Update: ");
                getchar();
                gets(tempInformation.UserName);
                strcpy(Info.UserName, tempInformation.UserName);

                fwrite(&Info, sizeof(Info), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter User's ID to Update: ");
                getchar();
                gets(tempInformation.UserAadhar);
                strcpy(Info.UserAadhar, tempInformation.UserAadhar);

                fwrite(&Info, sizeof(Info), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter User's Aadhaar to Update: ");
                getchar();
                gets(tempInformation.Vaccine_name);
                strcpy(Info.Vaccine_name, tempInformation.Vaccine_name);

                fwrite(&Info, sizeof(Info), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter User's Contact No. to Update: ");
                getchar();
                gets(tempInformation.UserContactNum);
                strcpy(Info.UserContactNum, tempInformation.UserContactNum);

                fwrite(&Info, sizeof(Info), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&Info, sizeof(Info), 1, temp);
            }
        }
        else
        {
            fwrite(&Info, sizeof(Info), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("UserInfo.bin");
    rename("temp.bin", "UserInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tUser Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void deleteInfo()
{
    FILE *fileOne = fopen("UserInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    User Info, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Delete User Information ======\n");

    printf("\n\t\t\tEnter User's ID : ");
    getchar();
    gets(tempInformation.UserId);

    while (fread(&Info, sizeof(Info), 1, fileOne) == 1)
    {
        if (strcmp(Info.UserId, tempInformation.UserId) == 0)
        {
            flag++;
            printf("\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\n\t\t\tInformation has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&Info, sizeof(Info), 1, temp);
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&Info, sizeof(Info), 1, temp);
            }
        }
        else
        {
            fwrite(&Info, sizeof(Info), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("UserInfo.bin");
    rename("temp.bin", "UserInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tUser Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void searchInfo()
{
    FILE *fileOne = fopen("UserInfo.bin", "rb");

    User Info;

    int choice, flag = 0;
    char UserID[20], UserAadhar[20];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Search User Information ======\n");

    printf("\n\t\t\tChoose your option :\n\t\t\t1.Search by User ID\n\t\t\t2.Search by Aadhaar");
    printf("\n\n\t\t\tEnter Your Option : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("\t\t\t\t====== Search User Information ======\n");
        printf("\n\n\t\t\tEnter User ID : ");
        getchar();
        gets(UserID);
        while (fread(&Info, sizeof(Info), 1, fileOne) == 1)
        {
            if (strcmp(Info.UserId, UserID) == 0)
            {
                flag++;
                printf("\n\t\t\tUser Name : %s\n\t\t\tUser ID : %s\n\t\t\tUser Aadhaar : %s\n\t\t\tUser Vaccine : %s\n\t\t\tUser Contact No. : %s", Info.UserName, Info.UserId, Info.UserAadhar, Info.Vaccine_name, Info.UserContactNum);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tUser Id is not found");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("\t\t\t\t====== Search User Information ======\n");
        printf("\n\n\t\t\tEnter User Aadhaar : ");
        getchar();
        gets(UserAadhar);
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "Name", "ID", "Dept.", "Address", "Contact");
        printf("\t\t----------------------------------------------------------------------------------------");
        while (fread(&Info, sizeof(Info), 1, fileOne) == 1)
        {
            if (stricmp(Info.UserAadhar, UserAadhar) == 0)
            {
                flag++;
                printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%", Info.UserName, Info.UserId, Info.UserAadhar, Info.Vaccine_name, Info.UserContactNum);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tUser Id is not found");
        }
    }
    else
    {
        printf("\n\t\t\tInvalid Option");
    }

    fclose(fileOne);

    printf("\n\n\n\t\t\tEnter any keys to continue.......");
    getch();
}