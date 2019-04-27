#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

/* Define and declare student's info structure */
typedef struct studentInfo
{
    long int studentID;
    char name[30];
    int birthYear;
    float grade;
    struct studentInfo *pNext;
}st;

/***********************************************************************************************************************
 * PROTOTYPE
***********************************************************************************************************************/
/*!
 * Funtion: {int} studentMenu()
 *@Brief: draw a main menu and select function to be exercuted
 *
 *@Param: <none>
 *
 *@Return: function signal
 */
int studentMenu();

/*!
 * Funtion: {void} studentInsert(st **addressPHead)
 *@Brief: insert student info and link to the student's linked list
 *
 *@Param: st **addressPHead
 *        store address of pointer to top of the student's linked list
 *
 *@Return: <none>
 */
void studentInsert(st **addressPHead);

/*!
 * Funtion: {int} studentInsertMenu()
 *@Brief: draw an insert menu and select function to be exercuted
 *
 *@Param: <none>
 *
 *@Return: function signal
 */
int studentInsertMenu();

/*!
 * Funtion: {st} studentInputNew(st *pHead)
 *@Brief: input first student's info
 *
 *@Param: <none>
 *
 *@Return: a structure of first student's info
 */
st *studentInputNew();

/*!
 * Funtion: {st} studentInputNext(st *pHead)
 *@Brief: input next student's info
 *
 *@Param: <none>
 *
 *@Return: a structure of new next student's info
 */
st *studentInputNext(st *addressHead);

/*!
 * Funtion: {void} studentInsertLast(st *addressHead)
 *@Brief: link a structure of student's info to the bottom of the student's linked list
 *
 *@Param: st *addressHead
 *        address of the first student's info
 *
 *@Return: <none>
 */
void studentInsertLast(st *addressHead);

/*!
 * Funtion: {void} studentPrintList(st *addressHead)
 *@Brief: output all database of students in the linked list
 *
 *@Param: st *addressHead
 *        address of the first student's info
 *
 *@Return: <none>
 */
void studentPrintList(st *addressHead);

/*!
 * Funtion: {void} studentSearch(st *addressHead)
 *@Brief: search for student by one of the info
 *
 *@Param: st *addressHead
 *        address of the first student's info
 *
 *@Return: <none>
 */
void studentSearch(st *addressHead);

/*!
 * Funtion: {int} studentSearchMenu()
 *@Brief: draw a search menu and select function to be exercuted
 *
 *@Param: <none>
 *
 *@Return: function signal
 */
int studentSearchMenu();

/*!
 * Funtion: {void} studentSearchByID(st *addressHead)
 *@Brief: find all students which have the inserted ID
 *
 *@Param: st *addressHead
 *        address of the first student's info
 *
 *@Return: <none>
 */
void studentSearchByID(st *addressHead);

/*!
 * Funtion: {void} studentSearchByName(st *addressHead)
 *@Brief: find all students which have the inserted name
 *
 *@Param: st *addressHead
 *        address of the first student's info
 *
 *@Return: <none>
 */
void studentSearchByName(st *addressHead);

/*!
 * Funtion: {void} studentSearchByBirthYear(st *addressHead)
 *@Brief: find all students which have the inserted birth year
 *
 *@Param: st *addressHead
 *        address of the first student's info
 *
 *@Return: <none>
 */
void studentSearchByBirthYear(st *addressHead);

/*!
 * Funtion: {void} studentSearchByGrade(st *addressHead)
 *@Brief: find all students which have the inserted grade
 *
 *@Param: st *addressHead
 *        address of the first student's info
 *
 *@Return: <none>
 */
void studentSearchByGrade(st *addressHead);

/*!
 * Funtion: {void} studentEdit(st *addressHead)
 *@Brief: draw an edit menu and select function to be exercuted
 *
 *@Param: st *addressHead
 *        address of the first student's info
 *
 *@Return: <none>
 */
void studentEdit(st *addressHead);

/*!
 * Funtion: {int} studentEditMenu()
 *@Brief: draw an edit menu
 *
 *@Param: <none>
 *
 *@Return: function signal
 */
int studentEditMenu();

/*!
 * Funtion: {void} studentEditByID(st *addressHead)
 *@Brief: find a student which have the inserted ID and select an option to edit
 *
 *@Param: st *addressHead
 *        address of the first student's info
 *
 *@Return: <none>
 */
void studentEditByID(st *addressHead);

/*!
 * Funtion: {int} studentEditByIDMenu()
 *@Brief: draw an edit option
 *
 *@Param: <none>
 *
 *@Return: function signal
 */
int studentEditByIDMenu();

/*!
 * Funtion: {void} studentEditID(st *pToEdit)
 *@Brief: edit a selected student's ID
 *
 *@Param: st *pToEdit
 *        address of the student who you want to edit
 *
 *@Return: <none>
 */
void studentEditID(st *pToEdit);

/*!
 * Funtion: {void} studentEditName(st *pToEdit)
 *@Brief: edit a selected student's name
 *
 *@Param: st *pToEdit
 *        address of the student who you want to edit
 *
 *@Return: <none>
 */
void studentEditName(st *pToEdit);

/*!
 * Funtion: {void} studentEditBirthYear(st *pToEdit)
 *@Brief: edit a selected student's birth year
 *
 *@Param: st *pToEdit
 *        address of the student who you want to edit
 *
 *@Return: <none>
 */
void studentEditBirthYear(st *pToEdit);

/*!
 * Funtion: {void} studentEditGrade(st *pToEdit)
 *@Brief: edit a selected student's grade
 *
 *@Param: st *pToEdit
 *        address of the student who you want to edit
 *
 *@Return: <none>
 */
void studentEditGrade(st *pToEdit);

/*!
 * Funtion: {void} studentDelete(st **addressPHead)
 *@Brief: delete student's info
 *
 *@Param: st *addressPHead
 *        address of the pointer to top of the student's linked list
 *
 *@Return: <none>
 */
void studentDelete(st **addressPHead);

/*!
 * Funtion: {int} studentDeleteMenu()
 *@Brief: draw a delete menu 
 *
 *@Param: <none>
 *
 *@Return: function signal
 */
int studentDeleteMenu();

/*!
 * Funtion: {void} studentDeleteByID(st **addressPHead)
 *@Brief: delete info of a student which have the inserted ID
 *
 *@Param: st *addressPHead
 *        address of the pointer to top of the student's linked list
 *
 *@Return: <none>
 */
void studentDeleteByID(st **addressPHead);

/*!
 * Function: {int} studentSort(st* pHead)
 *
 *@Brief: sort list student
 *
 *@Param: *pHead - address list student
 *
 *@Return: <none>
 */
int studentSort(st *pHead);

/*!
 * Function: {void} studentPutData(st *pHead)
 *
 *@Brief: create and put data to excel file
 *
 *@Param: *pHead - address list student
 *
 *@Return: <none>
 */
void studentPutData(st *pHead);

/*!
 * Function: {int} swap(st *p1, st *p2)
 *
 *@Brief: swap pointer
 *
 *@Param: st *p1, st *p2 - address of two student structure pointer
 *
 *@Return: <none>
 */
void swap(st *p1, st *p2);

/*!
 * Funtion: {int} checkIntegerPositive (char *arrayCheck)
 *@Brief: check if checking number is positive integer type or not
 *
 *@Param: char *arrayCheck
 *        string of check array
 *
 *@Return: check result
 */
int checkIntegerPositive (char *arrayCheck);

/*!
 * Funtion: {int} checkNumberFloat (char *arrayCheck)
 *@Brief: check if checking number is float type or not
 *
 *@Param: char *arrayCheck
 *        string of check array
 *
 *@Return: check result
 */
int checkNumberFloat (char *arrayCheck);

/*!
 * Funtion: {int} arrayToIntegerPositive (char *arrayCheck)
 *@Brief: convert array character to positive integer
 *
 *@Param: char *arrayCheck
 *        string of check array
 *
 *@Return: transform check array to float number
 */
int arrayToIntegerPositive (char *arrayCheck);

/*!
 * Funtion: {float} arrayToFloatNumber (char *arrayCheck)
 *@Brief: convert numeric characters to float numbers
 *
 *@Param: char *arrayCheck
 *        string of check array
 *
 *@Return: transform check array to float number
 */
float arrayToFloatNumber (char *arrayCheck);

/*!
 * Function: {void} cprintf(char *pText, int textLength, int color)
 *@Brief: print changed-color text
 *
 *@Param: char *pText - pointer to text
 *        int textLength - text's length
 *        int color - color to change to
 *
 *@Return: <none>
 */
void colorPrintf(char *pText, int textLength, int color);


/***********************************************************************************************************************
 * CODE
***********************************************************************************************************************/

int main(int argc, char *argv[])
{
    st *pHead = (st *)malloc(sizeof(st));
    pHead = NULL;
    int select, done = 0;
    int select8;
    system("color 0e");
    printf("\n\t\t\t"); colorPrintf("               WELCOME TO                    ", strlen("               WELCOME TO                    "), 11); printf("\n");
    printf("\n\t\t\t"); colorPrintf("            STUDENT  MANAGER                 ", strlen("            STUDENT  MANAGER                 "), 14);
    printf("\n\t\t\t            version beta 3.3                \n");
    printf("\n\t\t\t"); colorPrintf("       nham phim bat ki de bat dau          ", strlen("       nham phim bat ki de bat dau          "), 12);
    getch();
    fflush(stdin);
    system("cls");
    do
    {
        select = studentMenu();
        switch(select)
        {
            case 1:
            {
                studentInsert(&pHead);
                break;
            }
            case 2:
            {
                studentSearch(pHead);
                break;
            }
            case 3:
            {
                studentEdit(pHead);
                break;
            }
            case 4:
            {
                studentDelete(&pHead);
                break;
            }
            case 5:
            {
                studentSort(pHead);
                break;
            }
            case 6:
            {
                studentPrintList(pHead);
                break;
            }
            case 7:
            {
                studentPutData(pHead);
                break;
            }
            case 8:
            {
                system("cls");
                printf("\n\t\t"); colorPrintf("        LAY DU LIEU TU FILE      ", strlen("        LAY DU LIEU TU FILE      "), 11);
                printf("\n\t\t _______________________________ ");
                printf("\n\t\t|                               |");
                printf("\n\t\t|"); colorPrintf("         GET DATA MENU         ", strlen("         GET DATA MENU         "), 10); printf("|");
                printf("\n\t\t|_______________________________|");
                printf("\n\t\t|                               |");
                printf("\n\t\t| 1. Lay du lieu moi            |");
                printf("\n\t\t|_______________________________|");
                printf("\n\t\t|                               |");
                printf("\n\t\t|"); colorPrintf(" 0. Quay lai                   ", strlen(" 0. Quay lai                   "), 12); printf("|");
                printf("\n\t\t|_______________________________|");
                printf("\n\n\tVui long chon chuc nang ");
                do
                {
                    select8 = getch();
                }
                while(select8 < '0' || select8 > '1');
                switch(select8)
                {
                    case '1':
                    {
                        st *p1;
                        int i, check = 1;
                        char filePath[100], arrayCheck[100];
                        pHead = (st*)malloc(sizeof(st));
                        
                        p1 = (st*)malloc(sizeof(st));
                        printf("\nNhap link file (.csv hoac .txt): "); 
                        fgets(filePath, 100, stdin);
                        char* p = strchr(filePath, '\n');
                        if (p)
                        {
                            *p = '\0';
                        }
                        FILE *file = fopen(filePath, "r");
                        if (file == NULL)
                        {
                            printf("File khong ton tai!");
                            printf("\nBam phim bat ky de quay lai");
                            getch();
                        }
                        else
                        {
                            fgets(arrayCheck, 9, file);
                            pHead->studentID = arrayToIntegerPositive(arrayCheck);
                            fgets(arrayCheck, 2, file);
                            if (arrayCheck[0] != 44)
                            {
                                printf("Warning....File khong hop le!!");
                                check = 0;
                                break;
                            }
                            fgets(arrayCheck, 31, file);
                            i = 0;
                            do
                            {
                                i++;
                                if (arrayCheck[30 - i] != 32)
                                {
                                    arrayCheck[30 - i + 1] = 0;
                                    break;
                                }
                            }
                            while (1);
                            strcpy(pHead->name, arrayCheck);
                            fgets(arrayCheck, 2, file);
                            if (arrayCheck[0] != 44)
                            {
                                printf("Warning....File khong hop le!!");
                                check = 0;
                                break;
                            }
                            fgets(arrayCheck, 5, file);
                            pHead->birthYear =  arrayToIntegerPositive(arrayCheck);
                            fgets(arrayCheck, 2, file);
                            if (arrayCheck[0] != 44)
                            {
                                printf("Warning....File khong hop le!!");
                                check = 0;
                                break;
                            }
                            fscanf(file, "%s", arrayCheck);
                            pHead->grade = arrayToFloatNumber(arrayCheck);
                            p1 = pHead;
                            do
                            {
                                /* enter */
                                fgets(arrayCheck, 9, file);
                                /* get ID */
                                fgets(arrayCheck, 9, file);
                                /* check if this is the end of table */
                                if (strlen(arrayCheck) == 1)
                                {
                                    p1->pNext= NULL;
                                    break;
                                }
                                /* declare pointer */
                                p1->pNext = (st*)malloc(sizeof(st));
                                
                                p1 = p1->pNext;
                                p1->studentID = arrayToIntegerPositive(arrayCheck);
                                /* check if this is the right file */
                                fgets(arrayCheck, 2, file);
                                if (arrayCheck[0] != 44)
                                {
                                    printf("Warning....File khong hop le!!");
                                    check = 0;
                                    break;
                                }
                                /* get name*/
                                fgets(arrayCheck, 31, file);
                                /* xu ly dau cach */
                                i = 0;
                                do
                                {
                                    i++;
                                    if (arrayCheck[30 - i] != 32)
                                    {
                                        arrayCheck[30 - i + 1] = 0;
                                        break;
                                    }
                                }
                                while (1);
                                /* save name */
                                strcpy(p1->name, arrayCheck);
                                /* check right file */
                                fgets(arrayCheck, 2, file);
                                if (arrayCheck[0] != 44)
                                {
                                    printf("Warning....File khong hop le!!");
                                    check = 0;
                                    break;
                                }
                                /* get birth year */
                                fgets(arrayCheck, 5, file);
                                p1->birthYear =  arrayToIntegerPositive(arrayCheck);
                                /* check right file */
                                fgets(arrayCheck, 2, file);
                                if (arrayCheck[0] != 44)
                                {
                                    printf("Warning....File khong hop le!!");
                                    check = 0;
                                    break;
                                }
                                /* get grade */
                                fscanf(file, "%s", arrayCheck);
                                p1->grade = arrayToFloatNumber(arrayCheck);
                            }
                            while(1);
                            if (check == 1)
                            {
                                printf("Da doc file!");    
                            }
                            printf("\nBam phim bat ki de quay lai");
                            getch();
                        }
                        break;
                    }
                    case '0':
                    {
                        break;
                    }
                }
                break;
            }
            case 0:
            {
                done = 1;
                break;
            }
        }
    }
    while(done == 0);
    return 0;
}


int studentMenu()
{
    /* Store function signal */
    char select;
    system("cls");
    /* Draw a main menu */
    printf("\n\t\t"); colorPrintf("        STUDENT MANAGER 3.3      ", strlen("        STUDENT MANAGER 3.0      "), 11);
    printf("\n\t\t _______________________________ ");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf("           MAIN MENU           ", strlen("           MAIN MENU           "), 10); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t| 1. Them sinh vien             |");
    printf("\n\t\t| 2. Tim sinh vien              |");
    printf("\n\t\t| 3. Sua thong tin              |");
    printf("\n\t\t| 4. Xoa thong tin              |");
    printf("\n\t\t| 5. Sap xep danh sach          |");
    printf("\n\t\t| 6. In danh sach               |");
    printf("\n\t\t| 7. Luu vao file               |");
    printf("\n\t\t| 8. Lay du lieu tu file        |");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf(" 0. Thoat                   ", strlen(" 0. Thoat                   "), 12); printf("   |");   
    printf("\n\t\t|_______________________________|");
    printf("\n\n\tVui long chon chuc nang ");
    do
    {
        /* Get a valid character from keyboard to choose function*/
        select = getch();
    } 
    while (select < '0' || select > '8');
    return select - '0';
}

void studentInsert(st **addressPHead)
{
    /* Get function signal */
    int select, done = 0;
    do
    {
        select = studentInsertMenu();
        switch(select)
        {
            case 1:
            {
                if(*addressPHead == NULL)
                {
                    *addressPHead = studentInputNew();
                }
                else
                {
                    studentInsertLast(*addressPHead);
                }
                break;
            }
            case 0:
            {
                done = 1;
                break;
            }
        }
    }
    while(done == 0);
}

int studentInsertMenu()
{
    char select;
    system("cls");
    printf("\n\t\t"); colorPrintf("  NHAP DU LIEU CHO SINH VIEN MOI ", strlen("  NHAP DU LIEU CHO SINH VIEN MOI "), 11);
    printf("\n\t\t _______________________________ ");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf("          INSERT MENU          ", strlen("          INSERT MENU          "), 10); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t| 1. Nhap du lieu sinh vien     |");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf(" 0. Quay lai                   ", strlen(" 0. Quay lai                   "), 12); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\n\tVui long chon chuc nang ");
    do
    {
        select = getch();
    }
    while(select < '0' || select > '1');
    return select - '0';
}

st *studentInputNew()
{
    st *newStudent = (st *)malloc(sizeof(st));
    int i;
    /* Declare checker */
    char arrayCheck[30];
    int check;

    printf("\n");
    /* Get ID */
    do
    {
        printf("Nhap ma so sinh vien: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkIntegerPositive(arrayCheck);
        if(strlen(arrayCheck) != 8)
        {
            check = 0;
        }
        if(!check)
        {
            printf("Ma so sinh vien khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    newStudent->studentID = arrayToIntegerPositive(arrayCheck);

    /* Get name */
    do
    {
        printf("Nhap ten sinh vien: ");
        fflush(stdin);
        gets(newStudent->name);

        if(strlen(newStudent->name) == 0)
        {
            printf("Ten khong hop le! Nhap lai: ");
            check = 0;
        }
        else
        {
            strlwr(newStudent->name);
            newStudent->name[0] = newStudent->name[0] - 32;
            for(i = 1; i < strlen(newStudent->name); i++)
            {
                if(newStudent->name[i] == ' ')
                {
                    newStudent->name[i + 1] = newStudent->name[i + 1] - 32;
                }
            }
            check = 1;
        }
    }
    while(!check);
    
    /* Get birth year */
    do
    {
        printf("Nhap nam sinh cua sinh vien: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkIntegerPositive(arrayCheck);
        if (strlen(arrayCheck) == 0)
        {
            check = 0; 
        }
        if(!check)
        {
            printf("Nam sinh khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    newStudent->birthYear = arrayToIntegerPositive(arrayCheck);
    
    /* Get grade */
    do
    {
        printf("Nhap diem cua sinh vien: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkNumberFloat(arrayCheck);
        if (strlen(arrayCheck) == 0)
        {
            check = 0; 
        }
        if(!check)
        {
            printf("Diem khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    newStudent->grade = arrayToFloatNumber(arrayCheck);

    /* Link */
    newStudent->pNext = NULL;

    /* Return new student structure */
    return newStudent;
}

st *studentInputNext(st *addressHead)
{
    st *newStudent = (st *)malloc(sizeof(st));
    st *pTemp = (st *)malloc(sizeof(st));
    pTemp = addressHead;
    int i, check;
    /* Declare checker */
    char arrayCheck[30];

    printf("\n");
    /* Get ID */
    do
    {
        printf("Nhap ma so sinh vien: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkIntegerPositive(arrayCheck);
        if(strlen(arrayCheck) == 0)
        {
            check = 0;
        }
        if(!check)
        {
            printf("Ma so sinh vien khong hop le! Nhap lai: ");
        }
        else
        {
            while(pTemp != NULL)
            {
                if(pTemp->studentID == arrayToIntegerPositive(arrayCheck))
                {
                    check = 0;
                    printf("Ma so sinh vien da ton tai! Nhap lai: ");
                    break;
                }
                else
                {
                    pTemp = pTemp->pNext;
                }
            }
        }
    }
    while(!check);
    newStudent->studentID = arrayToIntegerPositive(arrayCheck);

    /* Get name */
    do
    {
        printf("Nhap ten sinh vien: ");
        fflush(stdin);
        gets(newStudent->name);

        if(strlen(newStudent->name) == 0)
        {
            printf("Ten khong hop le! Nhap lai: ");
            check = 0;
        }
        else
        {
            strlwr(newStudent->name);
            newStudent->name[0] = newStudent->name[0] - 32;
            for(i = 1; i < strlen(newStudent->name); i++)
            {
                if(newStudent->name[i] == ' ')
                {
                    newStudent->name[i + 1] = newStudent->name[i + 1] - 32;
                }
            }
            check = 1;
        }
    }
    while(!check);
    
    /* Get birth year */
    do
    {
        printf("Nhap nam sinh cua sinh vien: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkIntegerPositive(arrayCheck);
        if (strlen(arrayCheck) == 0)
        {
            check = 0; 
        }
        if(!check)
        {
            printf("Nam sinh khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    newStudent->birthYear = arrayToIntegerPositive(arrayCheck);
    
    /* Get grade */
    do
    {
        printf("Nhap diem cua sinh vien: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkNumberFloat(arrayCheck);
        if (strlen(arrayCheck) == 0)
        {
            check = 0;
        }
        if(!check)
        {
            printf("Diem khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    newStudent->grade = arrayToFloatNumber(arrayCheck);

    /* Link */
    newStudent->pNext = NULL;

    /* Return new student structure */
    return newStudent;
}

void studentInsertLast(st *addressHead)
{
    st *pTemp = addressHead;
    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = studentInputNext(addressHead);
}

void studentPrintList(st *addressHead)
{
    st *pTemp = addressHead;
    /*Draw a table*/
    system("cls");
    printf("\n ________________________________________________________________________________ ");
    printf("\n|                                                                                |");
    printf("\n|                                  DANH SACH                                     |");
    printf("\n|________________________________________________________________________________|");
    printf("\n|                 |                                              |      |        |");
    printf("\n| MA SO SINH VIEN |                  HO VA TEN                   | SINH |  DIEM  |");
    printf("\n|_________________|______________________________________________|______|________|");


    /*Output student's info using temperate pointer*/
    if(pTemp == NULL)
    {
        printf("\n|                                                                                |");
        printf("\n|                                DANH SACH TRONG                                 |");
        printf("\n|________________________________________________________________________________|");
    }
    else
    {
        while(pTemp != NULL)
        {
            printf("\n| %-16ld| %-45s| %-5d| %-7.2f|", pTemp->studentID, pTemp->name, pTemp->birthYear, pTemp->grade);
            pTemp = pTemp->pNext;
        }
        printf("\n|_________________|______________________________________________|______|________|");
    }

    printf("\n\n\tNhan phim bat ki de quay lai");
    getch();
}

void studentSearch(st *addressHead)
{
    int select, done = 0;

    do
    {
        select = studentSearchMenu();
        switch(select)
        {
            case 1: 
            {
                studentSearchByID(addressHead);
                break;
            }
            case 2:
            {
                studentSearchByName(addressHead);
                break;
            }
            case 3:
            {
                studentSearchByBirthYear(addressHead);
                break;
            }
            case 4:
            {
                studentSearchByGrade(addressHead);
                break;
            }
            case 0:
            {
                done = 1;
            }
        }
    }
    while(done == 0);
}

int studentSearchMenu()
{
    int select;
    system("cls");
    printf("\n\t\t"); colorPrintf("        TIM KIEM SINH VIEN       ", strlen("        TIM KIEM SINH VIEN       "), 11);
    printf("\n\t\t _______________________________ ");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf("          SEARCH MENU          ", strlen("          SEARCH MENU          "), 10); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t| 1. Tim theo ma so sinh vien   |");
    printf("\n\t\t| 2. Tim theo ten               |");
    printf("\n\t\t| 3. Tim theo nam sinh          |");
    printf("\n\t\t| 4. Tim theo diem              |");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf(" 0. Quay lai                   ", strlen(" 0. Quay lai                   "), 12); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\n\tVui long chon chuc nang ");
    do
    {
        select = getch();
    }
    while(select < '0' || select > '4');
    return select - '0';
}

void studentSearchByID(st *addressHead)
{
    st *pTemp = (st *)malloc(sizeof(st));
    pTemp = addressHead;

    long int tempID;
    bool checkEx = false;
    char arrayCheck[30];
    int check;
    
    system("cls");
    printf("\n");
    do
    {
        printf("Nhap ma so sinh vien can tim: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkIntegerPositive(arrayCheck);
        if(strlen(arrayCheck) == 0)
        {
            check = 0;
        }
        if(!check)
        {
            printf("Ma so sinh vien khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    tempID = arrayToIntegerPositive(arrayCheck);

    /*Draw a table*/
    printf("\n ________________________________________________________________________________ ");
    printf("\n|                                                                                |");
    printf("\n|                                  DANH SACH                                     |");
    printf("\n|________________________________________________________________________________|");
    printf("\n|                 |                                              |      |        |");
    printf("\n| MA SO SINH VIEN |                  HO VA TEN                   | SINH |  DIEM  |");
    printf("\n|_________________|______________________________________________|______|________|");
    /*Find ID*/
    while(pTemp != NULL)
    {
        if(pTemp->studentID == tempID)
        {
            printf("\n| %-16ld| %-45s| %-5d| %-7.2f|", pTemp->studentID, pTemp->name, pTemp->birthYear, pTemp->grade);
            checkEx = true;
        }
        pTemp = pTemp->pNext;
    }
    /*End of table*/
    if(checkEx)
    {
        printf("\n|_________________|______________________________________________|______|________|");
    }
    else
    {
        printf("\n|                                                                                |");
        printf("\n|                        KHONG TIM THAY SINH VIEN THOA MAN                       |");
        printf("\n|________________________________________________________________________________|");
    }
    /*Go back*/
    printf("\n\n\tNhan phim bat ki de quay lai");
    getch();
}

void studentSearchByGrade(st *addressHead)
{
    st *pTemp = (st *)malloc(sizeof(st));
    pTemp = addressHead;

    float tempGrade;
    bool checkEx = false;
    char arrayCheck[30];
    int check;
    
    system("cls");
    printf("\n");
    do
    {
        printf("Nhap diem can tim: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkNumberFloat(arrayCheck);
        if (strlen(arrayCheck) == 0)
        {
            check = 0;
        }
        if(!check)
        {
            printf("Diem khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    tempGrade = arrayToFloatNumber(arrayCheck);
    /*Draw a table*/
    printf("\n ________________________________________________________________________________ ");
    printf("\n|                                                                                |");
    printf("\n|                                  DANH SACH                                     |");
    printf("\n|________________________________________________________________________________|");
    printf("\n|                 |                                              |      |        |");
    printf("\n| MA SO SINH VIEN |                  HO VA TEN                   | SINH |  DIEM  |");
    printf("\n|_________________|______________________________________________|______|________|");
    /*Find grade*/
    while(pTemp != NULL)
    {
        if(pTemp->grade == tempGrade)
        {
            printf("\n| %-16ld| %-45s| %-5d| %-7.2f|", pTemp->studentID, pTemp->name, pTemp->birthYear, pTemp->grade);
            checkEx = true;
        }
        pTemp = pTemp->pNext;
    }
    /*End of table*/
    if(checkEx)
    {
        printf("\n|_________________|______________________________________________|______|________|");
    }
    else
    {
        printf("\n|                                                                                |");
        printf("\n|                        KHONG TIM THAY SINH VIEN THOA MAN                       |");
        printf("\n|________________________________________________________________________________|");
    }
    /*Go back*/
    printf("\n\n\tNhan phim bat ki de quay lai");
    getch();
}


void studentSearchByBirthYear(st *addressHead)
{
    st *pTemp = (st *)malloc(sizeof(st));
    pTemp = addressHead;

    int tempBirthYear;
    bool checkEx = false;
    char arrayCheck[30];
    int check;
    
    system("cls");
    printf("\n");
    do
    {
        printf("Nhap nam sinh can tim: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkIntegerPositive(arrayCheck);
        if (strlen(arrayCheck) == 0)
        {
            check = 0;
        }
        if(!check)
        {
            printf("Nam sinh khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    tempBirthYear = arrayToIntegerPositive(arrayCheck);
    /*Draw a table*/
    printf("\n ________________________________________________________________________________ ");
    printf("\n|                                                                                |");
    printf("\n|                                  DANH SACH                                     |");
    printf("\n|________________________________________________________________________________|");
    printf("\n|                 |                                              |      |        |");
    printf("\n| MA SO SINH VIEN |                  HO VA TEN                   | SINH |  DIEM  |");
    printf("\n|_________________|______________________________________________|______|________|");
    /*Find birth year*/
    while(pTemp != NULL)
    {
        if(pTemp->birthYear == tempBirthYear)
        {
            printf("\n| %-16ld| %-45s| %-5d| %-7.2f|", pTemp->studentID, pTemp->name, pTemp->birthYear, pTemp->grade);
            checkEx = true;
        }
        pTemp = pTemp->pNext;
    }
    /*End of table*/
    if(checkEx)
    {
        printf("\n|_________________|______________________________________________|______|________|");
    }
    else
    {
        printf("\n|                                                                                |");
        printf("\n|                        KHONG TIM THAY SINH VIEN THOA MAN                       |");
        printf("\n|________________________________________________________________________________|");
    }
    /*Go back*/
    printf("\n\n\tNhan phim bat ki de quay lai");
    getch();
}


void studentSearchByName(st *addressHead)
{
    st *pTemp = (st *)malloc(sizeof(st));
    pTemp = addressHead;

    char tempName[30];
    int i;
    bool checkCom;
    bool checkEx = false;
    int check;
    
    system("cls");
    printf("\n");
    do
    {
        printf("\nNhap ten sinh vien can tim: ");
        fflush(stdin);
        gets(tempName);
        if(strlen(tempName) == 0)
        {
            check = 0;
            printf("Ten khong hop le! Nhap lai: ");
        }
        else 
        {
            check = 1;
        }
    }
    while(!check);
    
    /*Draw a table*/
    printf("\n ________________________________________________________________________________ ");
    printf("\n|                                                                                |");
    printf("\n|                                  DANH SACH                                     |");
    printf("\n|________________________________________________________________________________|");
    printf("\n|                 |                                              |      |        |");
    printf("\n| MA SO SINH VIEN |                  HO VA TEN                   | SINH |  DIEM  |");
    printf("\n|_________________|______________________________________________|______|________|");
    
    /*Find name*/
    while(pTemp != NULL)
    {
        checkCom = true;
        strlwr(tempName);
        strlwr(pTemp->name);
        if(strcmp(tempName, pTemp->name) != 0)
        {
            checkCom = false;
        }
        else
        {
            for(i = 0; i < strlen(tempName); i++)
            {
                if(tempName[i] != pTemp->name[i])
                {
                    checkCom = false;
                    break;
                }
            }
        }
        
        pTemp->name[0] = pTemp->name[0] - 32;
        for(i = 1; i < strlen(pTemp->name); i++)
        {
            if(pTemp->name[i] == ' ')
            {
                pTemp->name[i + 1] = pTemp->name[i + 1] - 32;
            }
        }

        if(checkCom)
        {
            printf("\n| %-16ld| %-45s| %-5d| %-7.2f|", pTemp->studentID, pTemp->name, pTemp->birthYear, pTemp->grade);
            checkEx = true;
        }
        pTemp = pTemp->pNext;
    }
    /*End of table*/
    if(checkEx)
    {
        printf("\n|_________________|______________________________________________|______|________|");
    }
    else
    {
        printf("\n|                                                                                |");
        printf("\n|                        KHONG TIM THAY SINH VIEN THOA MAN                       |");
        printf("\n|________________________________________________________________________________|");
    }
    /*Go back*/
    printf("\n\n\tNhan phim bat ki de quay lai");
    getch();
}

void studentEdit(st *addressHead)
{
    int select, done = 0;

    do
    {
        select = studentEditMenu();
        switch(select)
        {
            case 1:
            {
                studentEditByID(addressHead);
                break;
            }
            case 0:
            {
                done = 1;
                break;
            }
        }
    }
    while(done == 0);
}

int studentEditMenu()
{
    char select;

    system("cls");
    printf("\n\t\t"); colorPrintf("      SUA THONG TIN SINH VIEN    ", strlen("      SUA THONG TIN SINH VIEN    "), 11);
    printf("\n\t\t _______________________________ ");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf("           EDIT MENU           ", strlen("           EDIT MENU           "), 10);
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t| 1. Tiep tuc sua thong tin     |");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf(" 0. Quay lai                   ", strlen(" 0. Quay lai                   "), 12); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\n\tVui long chon chuc nang ");
    do
    {
        select = getch();
    }
    while(select < '0' || select > '1');
    return select - '0';
}

void studentEditByID(st *addressHead)
{
    st *pTemp = (st *)malloc(sizeof(st));
    pTemp = addressHead;
    int tempID;
    int select, done = 0;
    bool checkEx = false;
    char arrayCheck[30];
    int check;
    
    system("cls");
    do
    {
        printf("Nhap ma so sinh vien cua sinh vien ban muon chinh sua: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkIntegerPositive(arrayCheck);
        if(strlen(arrayCheck) != 8)
        {
            check = 0;
        }
        if(!check)
        {
            printf("Ma so sinh vien khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    tempID = arrayToIntegerPositive(arrayCheck);
    
    while(pTemp != NULL)
    {
        if(pTemp->studentID == tempID)
        {
            checkEx = true;
            break;
        }
        pTemp = pTemp->pNext;
    }
    
    if(!checkEx)
    {
        printf("\nKhong tim thay sinh vien thoa man ma so sinh vien %d", tempID);
        printf("\nBam phim bat ki de quay lai");
        getch();
    }
    else
    {
        do
        {
            system("cls");
            printf("\nThong tin sinh vien can chinh sua: ");
            printf("\nMa so sinh vien: %d", pTemp->studentID);
            printf("\nHo va ten: %s", pTemp->name);
            printf("\nNam sinh: %d", pTemp->birthYear);
            printf("\nDiem: %.2f", pTemp->grade);
        
            select = studentEditByIDMenu();
            switch(select)
            {
                case 1:
                {
                    studentEditID(pTemp);
                    break;
                }
                case 2:
                {
                    studentEditName(pTemp);
                    break;
                }
                case 3:
                {
                    studentEditBirthYear(pTemp);
                    break;
                }
                case 4:
                {
                    studentEditGrade(pTemp);
                    break;
                }
                case 0:
                {
                    done = 1;
                    break;
                }
            }
        }
        while(!done);
    }
}


int studentEditByIDMenu()
{
    char select;
    printf("\n\t\t"); colorPrintf("    LUA CHON MUC DE CHINH SUA    ", strlen("    LUA CHON MUC DE CHINH SUA    "), 11);
    printf("\n\t\t _______________________________ ");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf("          EDIT OPTION          ", strlen("          EDIT OPTION          "), 10); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t| 1. Sua ma so sinh vien        |");
    printf("\n\t\t| 2. Sua ten                    |");
    printf("\n\t\t| 3. Sua nam sinh               |");
    printf("\n\t\t| 4. Sua diem                   |");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf(" 0. Quay lai                   ", strlen(" 0. Quay lai                   "), 12); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\n\tVui long chon chuc nang ");
    do
    {
        select = getch();
    }
    while(select < '0' || select > '4');
    return select - '0';
}

void studentEditID(st *pToEdit)
{
    int check;
    char arrayCheck[30];

    printf("\n");
    do
    {
        printf("Nhap ma so sinh vien moi: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkIntegerPositive(arrayCheck);
        if(strlen(arrayCheck) == 0)
        {
            check = 0;
        }
        if(!check)
        {
            printf("Ma so sinh vien khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    pToEdit->studentID = arrayToIntegerPositive(arrayCheck);
}

void studentEditName(st *pToEdit)
{
    int i;
    int check;

    printf("\n");
    do
    {
        printf("Nhap ten moi: ");
        fflush(stdin);
        gets(pToEdit->name);

        if(strlen(pToEdit->name) == 0)
        {
            printf("Ten khong hop le! Nhap lai: ");
            check = 0;
        }
        else
        {
            strlwr(pToEdit->name);
            pToEdit->name[0] = pToEdit->name[0] - 32;
            for(i = 1; i < strlen(pToEdit->name); i++)
            {
                if(pToEdit->name[i] == ' ')
                {
                    pToEdit->name[i + 1] = pToEdit->name[i + 1] - 32;
                }
            }
            check = 1;
        }
    }
    while(!check);
}

void studentEditBirthYear(st *pToEdit)
{
    int check;
    char arrayCheck[30];

    printf("\n");
    do
    {
        printf("Nhap nam sinh moi: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkIntegerPositive(arrayCheck);
        if (strlen(arrayCheck) == 0)
        {
            check = 0; 
        }
        if(!check)
        {
            printf("Nam sinh khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    pToEdit->birthYear = arrayToIntegerPositive(arrayCheck);
}

void studentEditGrade(st *pToEdit)
{
    int check;
    char arrayCheck[30];

    printf("\n");
    do
    {
        printf("Nhap diem moi: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkNumberFloat(arrayCheck);
        if (strlen(arrayCheck) == 0)
        {
            check = 0; 
        }
        if(!check)
        {
            printf("Diem khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    pToEdit->grade = arrayToFloatNumber(arrayCheck);
}

void studentDelete(st **addressPHead)
{
    int select, done = 0;

    do
    {
        select = studentDeleteMenu();
        switch(select)
        {
            case 1:
            {
                studentDeleteByID(addressPHead);
                break;
            }
            case 0:
            {
                done = 1;
                break;
            }
        }
    }
    while(!done);
}

int studentDeleteMenu()
{
    char select;
    system("cls");
    printf("\n\t\t"); colorPrintf("      XOA THONG TIN SINH VIEN    ", strlen("      XOA THONG TIN SINH VIEN    "), 11);
    printf("\n\t\t _______________________________ ");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf("          DELETE MENU          ", strlen("          DELETE MENU          "), 10);
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t| 1. Tiep tuc xoa thong tin     |");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf(" 0. Quay lai                   ", strlen(" 0. Quay lai                   "), 12); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\n\tVui long chon chuc nang ");
    do
    {
        select = getch();
    }
    while(select < '0' || select > '1');
    return select - '0';
}

void studentDeleteByID(st **addressPHead)
{
    st *pTemp = (st *)malloc(sizeof(st));
    st *pPrev = (st *)malloc(sizeof(st));
    pPrev = *addressPHead;
    char select;
    int tempID;
    bool checkEx = false;
    int check;
    char arrayCheck[30];

    system("cls");
    do
    {
        printf("Nhap ma so sinh vien cua sinh vien ban muon xoa thong tin: ");
        fflush(stdin);
        gets(arrayCheck);
        check = checkIntegerPositive(arrayCheck);
        if(strlen(arrayCheck) == 0)
        {
            check = 0;
        }
        if(!check)
        {
            printf("Ma so sinh vien khong hop le! Nhap lai: ");
        }
    }
    while(!check);
    tempID = arrayToIntegerPositive(arrayCheck);

    if((*addressPHead) == NULL)
    {
        printf("Danh sach sinh vien hien tai dang trong!");
        printf("\nBam phim bat ki de quay lai");
        getch();
    }
    else if((*addressPHead)->studentID == tempID)
    {
        checkEx = true;
        pTemp = *addressPHead;
        if(!checkEx)
        {
            printf("\nKhong tim thay sinh vien thoa man ma so sinh vien %d", tempID);
            printf("\nBam phim bat ki de quay lai");
            getch();
        }
        else
        {
            printf("\nThong tin sinh vien ban muon xoa:");
            printf("\nMa so sinh vien: %d", (*addressPHead)->studentID);
            printf("\nHo va ten: %s", (*addressPHead)->name);
            printf("\nNam sinh: %d", (*addressPHead)->birthYear);
            printf("\nDiem: %.2f", (*addressPHead)->grade);
            printf("\n\nBAN CO CHAC CHAN MUON XOA SINH VIEN NAY?");
            printf("\n\t1. Co\t\t2. Khong, quay lai");
            do
            {
                select = getch();
            }
            while(select < '1' || select > '2');
            select = select - '0';
            switch(select)
            {
                case 1:
                {
                    *addressPHead = (*addressPHead)->pNext;
                    free(pTemp);
                    printf("\nDa xoa sinh vien");
                    printf("\nBam phim bat ki de quay lai");
                    getch();
                    break;
                }
                case 2:
                {
                    break;
                }
            }

        }
    }
    else
    {
        while(pPrev != NULL)
        {
            pTemp = pPrev->pNext;
            if(pTemp == NULL)
            {
                break;
            }
            else if(pTemp->studentID == tempID)
            {
                checkEx = true;
                break;
            }
            pPrev = pPrev->pNext;
        }
        
        if(!checkEx)
        {
            printf("\nKhong tim thay sinh vien thoa man ma so sinh vien %d", tempID);
            printf("\nBam phim bat ki de quay lai");
            getch();
        }
        else
        {
            printf("\nThong tin sinh vien ban muon xoa:");
            printf("\nMa so sinh vien: %d", pTemp->studentID);
            printf("\nHo va ten: %s", pTemp->name);
            printf("\nNam sinh: %d", pTemp->birthYear);
            printf("\nDiem: %.2f", pTemp->grade);
            printf("\n\nBAN CO CHAC CHAN MUON XOA SINH VIEN NAY?");
            printf("\n\t1. Co\t\t2. Khong, quay lai");
            do
            {
                select = getch();
            }
            while(select < '1' || select > '2');
            select = select - '0';
            switch(select)
            {
                case 1:
                {
                    pPrev->pNext = pTemp->pNext;
                    free(pTemp);
                    printf("\nDa xoa sinh vien");
                    printf("\nBam phim bat ki de quay lai");
                    getch();
                    break;
                }
                case 2:
                {
                    break;
                }
            }

        }
    }
}

int studentSort(st *pHead)
{
    st *p1, *p2;
    int i;
    char select;
    system("cls");
    /* Draw a main menu */
    printf("\n\t\t _______________________________ ");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf("              MENU             ", strlen("              MENU             "), 10); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t| 1. Sap xep theo ten(ABC)      |");
    printf("\n\t\t| 2. Sap xep theo diem          |");
    printf("\n\t\t| 3. Sap xep theo nam sinh      |");
    printf("\n\t\t|_______________________________|");
    printf("\n\t\t|                               |");
    printf("\n\t\t|"); colorPrintf(" 0. Quay lai                   ", strlen(" 0. Quay lai                   "), 12); printf("|");
    printf("\n\t\t|_______________________________|");
    printf("\n\n\tVui long chon chuc nang ");
    if(pHead != NULL)
    {
        do
        {
            /* Get a valid character from keyboard to choose function*/
            select = getch();
        } 
        while (select < '0' || select > '3');
        switch (select)
        {
            case '0':
            {
                break;
            }
            case '1':
            {
                p1 = (st*)malloc(sizeof(st));
                p2 = (st*)malloc(sizeof(st)); 
                p1 = pHead;
                do
                {
                    if ((p1->name[0] >= 97) && (p1->name[0] <= 122))
                    {
                        p1->name[0] = p1->name[0] - 32;
                        p1->name[29] = p1->name[0];
                    }
                    for (i = 0; i < strlen(p1->name); i++)
                    {
                        if (p1->name[i] == 32)
                        {
                            if ((p1->name[i + 1] >= 97) && (p1->name[i + 1] <= 122))
                            {
                                p1->name[i + 1] = p1->name[i + 1] - 32;
                            }
                            p1->name[29] = p1->name[i + 1];
                        }
                    }
                    p1 = p1->pNext;
                }
                while (p1 != NULL);
                p1 = pHead;
                do
                {
                    p2 = p1;
                    while (p2->pNext != NULL)
                    {
                        p2 = p2->pNext;
                        if (p1->name[29] > p2->name[29])
                        {
                            swap(p1, p2);
                        }
                    }
                    p1 = p1->pNext;
                }
                while (p1 != NULL);
                printf("\nDa sap xep thanh cong!");
                printf("\nBam phim bat ki de quay lai");
                getch();
                break; 
            }
            case '2':
            {
                p1 = (st*)malloc(sizeof(st));
                p2 = (st*)malloc(sizeof(st)); 
                p1 = pHead;
                do
                {
                    p2 = p1;
                    while (p2->pNext != NULL)
                    {
                        p2 = p2->pNext;
                        if (p1->grade > p2->grade)
                        {
                            swap(p1, p2);
                        }
                    }
                    p1 = p1->pNext;
                }
                while (p1 != NULL);
                printf("\nDa sap xep thanh cong!");
                printf("\nBam phim bat ki de quay lai");
                getch();
                break; 
            }
            case '3':
            {
                p1 = (st*)malloc(sizeof(st));
                p2 = (st*)malloc(sizeof(st)); 
                p1 = pHead;
                do
                {
                    p2 = p1;
                    while (p2->pNext != NULL)
                    {
                        p2 = p2->pNext;
                        if (p1->birthYear > p2->birthYear)
                        {
                            swap(p1, p2);
                        }
                    }
                    p1 = p1->pNext;
                }
                while (p1 != NULL);
                printf("\nDa sap xep thanh cong!");
                printf("\nBam phim bat ki de quay lai");
                getch();
                break; 
            }
        }
        
    }
    else
    {
        do
        {
            /* Get a valid character from keyboard to choose function*/
            select = getch();
        } 
        while (select < '0' || select > '3');
        if(select != '0')
        {
            printf("\nDanh sach con trong!! Vui long them sinh vien vao danh sach");
            printf("\nBam phim bat ki de quay lai");
            getch();
        }
    }
    return 0;
}

void studentPutData(st *pHead)
{
    st *p1;
    char filePath[400], *pFilePath, nameFile[200];
    p1 = (st*)malloc(sizeof(st));
    char select;
    if (pHead == NULL)
    {
        system("cls");
        printf("Danh sach trong!!!!");
        printf("\nBam phim bat ki de quay lai");
        getch();
    }
    else
    {
        system("cls");
        printf("\n\t\t"); colorPrintf("       XUAT DU LIEU RA FILE      ", strlen("       XUAT DU LIEU RA FILE      "), 11);
        printf("\n\t\t _______________________________ ");
        printf("\n\t\t|                               |");
        printf("\n\t\t|"); colorPrintf("         PUT DATA MENU         ", strlen("         PUT DATA MENU         "), 10); printf("|");
        printf("\n\t\t|_______________________________|");
        printf("\n\t\t|                               |");
        printf("\n\t\t| 1. Tiep tuc xuat du lieu      |");
        printf("\n\t\t|_______________________________|");
        printf("\n\t\t|                               |");
        printf("\n\t\t|"); colorPrintf(" 0. Quay lai                   ", strlen(" 0. Quay lai                   "), 12); printf("|");
        printf("\n\t\t|_______________________________|");
        printf("\n\n\tVui long chon chuc nang ");

        do
        {
            select = getch();
        }
        while(select < '0' || select > '1');
        switch(select)
        {
            case '1':
            {
                printf("\nNhap vao dia chi noi luu file: ");
                fgets(filePath, 200, stdin);
                char* p = strchr(filePath, '\n');
                if (p) 
                {
                    *p = '\0';
                }
                strcat(filePath, "/");
                printf("Nhap vao ten file: ");
                fgets(nameFile, 200, stdin);
                p = strchr(nameFile, '\n');
                if (p) 
                {
                    *p = '\0';
                }
                /* save nane file*/
                strcat(filePath, nameFile);
                strcat(filePath, ".csv");
                p = strchr(filePath, '\n');
                if (p) 
                {
                    *p = '\0';
                }
                /* open new file */
                FILE *file = fopen(filePath, "w+");
                fclose(file);
                file = fopen(filePath, "r");
                if (file == NULL)
                {
                    printf("File khong ton tai!");
                    printf("\nBam phim bat ky de quay lai");
                    getch();
                    fclose(file);
                }
                else
                {
                    fclose(file);
                    file = fopen(filePath, "w+");
                    /*  write to file*/
                    
                    p1 = pHead;
                    do
                    {
                        fprintf(file, "%d,%30s,%d,%f\n", p1->studentID, p1->name, p1->birthYear, p1->grade);
                        p1 = p1->pNext;
                    }
                    while(p1 != NULL);
                    printf("Da luu file!");
                    fclose(file);
                    getch();
                    break;
                }
            }
            case '0':
            {
                break;
            }
        }
    }
          
}

void swap(st *p1, st *p2)
{
    long int idSwap;
    char nameSwap[30];
    int birthSwap, gradeSwap;
    idSwap = p1->studentID;
    p1->studentID = p2->studentID;
    p2->studentID = idSwap;
    strcpy(nameSwap, p1->name);
    strcpy(p1->name, p2->name);
    strcpy(p2->name, nameSwap);
    birthSwap = p1->birthYear;
    p1->birthYear = p2->birthYear;
    p2->birthYear = birthSwap;
    gradeSwap = p1->grade;
    p1->grade = p2->grade;
    p2->grade = gradeSwap;
}

void colorPrintf(char *pText, int textLength, int color)
{
    HANDLE hTextColor;
    hTextColor = GetStdHandle(STD_OUTPUT_HANDLE);
    int i;
    for(i = 0; i < textLength; ++i)
    {
        SetConsoleTextAttribute(hTextColor, color);
        printf("%c", *(pText + i));
    }
    SetConsoleTextAttribute(hTextColor, 14);
}



/* Check */
int checkIntegerPositive (char *arrayCheck)
{
    int i, check = 1;
    /* Check character in the array check*/
    if(strlen(arrayCheck) == 0)
    {
        check = 0;
    }
    else
    {
        for (i = 0; i < strlen(arrayCheck); i++)
        {
            if (((int)(arrayCheck[i]) < 47) || ((int)(arrayCheck[i]) > 58))
            {
                check = 0;
                break;
            }
        }
    }
    return check;
}

int checkNumberFloat (char *arrayCheck)
{
    int i, check = 1, check46 = 0;
    /* Check the existence of "-"*/
    if ((int)(arrayCheck[0]) == 45)
    {
        check = 1;
    }
    else if (((int)(arrayCheck[0]) < 47) || ((int)(arrayCheck[0]) > 58))
    {
        check = 0;
    }
    /* Check the remaining characters*/
    if (check == 1)
    {
        for (i = 1; i < strlen(arrayCheck); i++)
        {
            if (((int)(arrayCheck[i]) < 47) || ((int)(arrayCheck[i]) > 58))
            {
                check = 0;
            }
            /* Check the existence of "."*/
            if (((int)(arrayCheck[i]) == 46) && (check46 < 1))
            {
                check = 1;
                check46 ++;
            }
        }
    }
    return check;
}

int arrayToIntegerPositive (char *arrayCheck)
{
    int i, number = 0;
    for (i = 0; i < strlen(arrayCheck); i++)
    {
        number = number * 10 + (int)(arrayCheck[i] - '0');
    }
    return number;
}

float arrayToFloatNumber (char *arrayCheck)
{
    int i, check46 = 0, check = 0;
    float number = 0;
    /* Process if it is negative*/
    if ((int)(arrayCheck[0]) == 45)
    {
        check = 1;
    }
    else
    {
        number = (int)(arrayCheck[0] - '0');
    }
    /* Check the remaining characters*/
    for (i = 1; i < strlen(arrayCheck); i++)
    {
        if ((int)(arrayCheck[i]) == 46)
        {
            check46 = i + 1;
            continue;
        }
        number = number * 10 + (int)(arrayCheck[i] - '0');
    }
    /* Converts to negative numbers*/
    if (check == 1)
    {
        number = number * (-1);
    }
    /* Converts to float numbers*/
    if (check46 != 0)
    {
        number = number / pow(10, (strlen(arrayCheck) - check46));
    }
    return number;
}










/*!
 * Function: {int} studentGetData(st *pHead)
 *
 *@Brief: 
 *
 *@Param: *pHead - address list student
 *
 *@Return: <none>
 */
/*int studentGetData(st **pHead)
{
    st *p1 = (st *)malloc(sizeof(st));
    int i;
    char filePath[100], arrayCheck[100];
    do
    {
        printf("\nNhap vao 0 de thoat!");
        printf("\nNhap link file: ");
        fgets(filePath, 100, stdin);
        char *p = strchr(filePath, '\n');
        if (p) 
        {
            *p = '\0';
        }
        FILE *file = fopen(filePath, "r");
        
        if (file == NULL)
        {
            printf("File khong ton tai");
            fclose(file);
            continue;
        }
        else
        {
            fclose(file);
            break;
        }
    }
    while(1);
    FILE *file = fopen(filePath, "r");
    
    fgets(arrayCheck, 9, file);
    
    (*pHead)->studentID = arrayToIntegerPositive(arrayCheck);

    fgets(arrayCheck, 2, file);
    fgets(arrayCheck, 31, file);
    i = 0;
    do
    {
        i++;
        if (arrayCheck[30 - i] != 32)
        {
            arrayCheck[30 - i + 1] = 0;
            break;
        }
    }
    while (1);
    strcpy((*pHead)->name, arrayCheck);
    printf("\nID=%s", arrayCheck);
    fgets(arrayCheck, 2, file);
    fgets(arrayCheck, 5, file);
    (*pHead)->birthYear =  arrayToIntegerPositive(arrayCheck);
    fgets(arrayCheck, 2, file);
    fscanf(file, "%s", arrayCheck);
    (*pHead)->grade = arrayToFloatNumber(arrayCheck);

    //(*pHead)->pNext = NULL;

    p1 = *pHead;
    p1->pNext = NULL;
    do
    {
        

        p1 = p1->pNext;
        p1 = (st*)malloc(sizeof(st));

        fgets(arrayCheck, 9, file);
        fgets(arrayCheck, 9, file);
        if (strlen(arrayCheck) == 1)
        {
            break;
            p1 = NULL;
        }
        printf("\nID=%s", arrayCheck);
        p1->studentID = arrayToIntegerPositive(arrayCheck);
        fgets(arrayCheck, 2, file);
        fgets(arrayCheck, 31, file);
        i = 0;
        do
        {
            i++;
            if (arrayCheck[30 - i] != 32)
            {
                arrayCheck[30 - i + 1] = 0;
                break;
            }
        }
        while (1);
        strcpy(p1->name, arrayCheck);
        fgets(arrayCheck, 2, file);
        fgets(arrayCheck, 5, file);
        p1->birthYear =  arrayToIntegerPositive(arrayCheck);
        fgets(arrayCheck, 2, file);
        fscanf(file, "%s", arrayCheck);
        p1->grade = arrayToFloatNumber(arrayCheck);
        
    }
    while(1);
    return 0;
}*/

