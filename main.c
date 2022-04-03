#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

struct information
{
    char account[50];
    char password[20];
    int end_paraghraph;
    int best_paraghraph;
    double score;
    double best_score;
}user[200];


struct changepass
{
    char account[20];
    char pass[20];

}Change_pass[200];


struct information Help;




struct name_score
{
    double score;
    char name[20];

}Name_Score[200];



char Name_[50];

                    //define name and password user globally

char pass_[50];




struct type_testing
{
    char each_line[100];
}Type_testing[200];




struct sort_users
{
    char line[100];
}Users[200];


struct link_passuser
{
    char pass[50];
    char user[50];
}link[200];



void mainmnue();
void start();
void SignIn();
void SignUp();
void Exit();
void type_testing();
void change_pass(char *account , char *old_pass);
void Search_users_by_names(char *name);
void Search_users_by_best_score(char *score);
void sorted_Statistical_info();



int searchup(FILE*ptr,char *s);
int Random();
void SetColor(int ForgC);
void store_score(char *name,double score,int paragraph);
int link_pass_account(char *name,char *pass);
void put_to_arry(char s[1000],char result[100][20]);
int number_of_word(char *a);

int main()
{
    system("COLOR F0");
    start();
    return 0;
}

//*******************************************************************************************
void start()
{
    printf("WELCOME\n");
    printf("================\n");
    printf("1-Sign in\n2-Sing up\n3-Exit\n");
    int FirstList;
    do
    {
        printf("What do you want to do: ");
        scanf("%d",&FirstList);
    }while(FirstList!=1 && FirstList!=2 && FirstList!=3);
    system("cls");
    if(FirstList == 1)
    {
        SignIn();
    }
    else if(FirstList == 2)
    {
        SignUP();
    }
    else
    {
        Exit();
    }
}
//**************************************************************************
void SignUP()
{
    FILE *fpU;
    FILE *fpP;
    /*fpU = fopen("username.txt","w");
    fpP = fopen("password.txt","w");
    fclose(fpU);
    fclose(fpP);*/

    fpU = fopen("username.txt","r+");
    fpP = fopen("password.txt","r+");

    char Name[50];
    char pass[50];
    char pass2[50];

    printf("enter your account  without space:");
    scanf("%s",Name);
    while(!searchup(fpU,Name))
    {
        printf("this account there is  in the system try again:");
        scanf("%s",Name);
    }
    printf("\nnenter your password:");
    scanf("%s",pass);
    printf("\nenter your password again:");
    scanf("%s",pass2);

    while(strcmp(pass,pass2))
    {
        printf("Your password does not match the first one\n");
        printf("enter your password:");
        scanf("%s",pass);
        printf("enter your password again:");
        scanf("%s",pass2);
    }

    int p = searchup(fpP,pass);
    if(p == 1)
        {   fseek(fpP,0,SEEK_END);
            fprintf(fpP,"%s\n",pass);
            fseek(fpU,0,SEEK_END);
            fprintf(fpU,"%s\n",Name);

        }
    else
        {
            system("cls");
            printf("this password use before you, try again\n\n");

        }
        fclose(fpU);
        fclose(fpP);
        start();


}
//*******************************************************************************************
void Exit()
{
    exit(0);
}
//************************************************************************************************

int searchup(FILE*ptr,char *s)  //ptr most be in mode r or w+
{
    fseek(ptr,0,SEEK_SET);
    char word[150];
    while(!feof(ptr))
        {fscanf(ptr,"%s",word);
        if(!strcmp(s,word))
        {
            return 0; //that means the word there is in the file

        }
    }
    return 1;        //that means the word there is not in the file
}


//*********************************************************************************

void SignIn()
{
    FILE *fpU;
    FILE *fpP;
    fpU = fopen("username.txt","r+");
    fpP = fopen("password.txt","r+");

    printf("enter your account  without space:");
    scanf("%s",Name_);
    while(searchup(fpU,Name_)==1)
    {
        printf("this account not in the system try again:");
        scanf("%s",Name_);
    }
    printf("enter your password:");
    scanf("%s",pass_);
    while(searchup(fpP,pass_)== 1)
    {
        printf("this password not in the system try again:");
        scanf("%s",pass_);

    }



    if(!(searchup(fpP,pass_)) && (!searchup(fpU,Name_)))
    {

        fclose(fpP);
        fclose(fpU);
        if(link_pass_account(Name_,pass_))
        {
            mainmnue();
        }
        else
        {
            printf("password or username wrong\n\n");
            start();
        }

    }

    fclose(fpP);
    fclose(fpU);

}


//******************************************************************************



void mainmnue()
{
    int numberOFmainmnue;
    printf("1-Type Testing\n2-View sorted Statistical info\n3-Search users by their best scores\n4-Search users by names\n5-Change Password\n6-Logout");
    do
    {
       printf("\nWhat do you want to do: ");
       scanf("%d",&numberOFmainmnue);
    }
    while(numberOFmainmnue!=1 && numberOFmainmnue!=2 && numberOFmainmnue!=3 && numberOFmainmnue!=4 && numberOFmainmnue!=5 && numberOFmainmnue!=6);
    system("cls");
    if(numberOFmainmnue == 1)
    {

        type_testing();
        while(1 == 1)
        {


            printf("\nwhat do you want to do again?:\n");
            printf("1.type_testing again\n2.go to at first of program\n");
            int chose;
            scanf("%d",&chose);


                if(chose == 1)
                {
                    type_testing();
                }
                else if(chose == 2)
                {
                    mainmnue();
                }
        }
    }
    else if(numberOFmainmnue == 2)
    {
        sorted_Statistical_info();
        mainmnue();
    }
    else if(numberOFmainmnue == 3)
    {
        printf("enter the best score that you want to see detail about account of this score:");
        char score[10];
        scanf("%s",score);

        Search_users_by_best_score(score);
        mainmnue();
    }
    else if(numberOFmainmnue == 4)
    {
        char search_name[20];
        printf("enter the name that you want to search it:");
        scanf("%s",search_name);
        Search_users_by_names(search_name);
    }
    else if(numberOFmainmnue == 5)
    {
        char acc[20];
        printf("enter your account:");
        scanf("%s",acc);
        char pas[20];
        printf("enter your password:");
        scanf("%s",pas);
        change_pass(acc,pas);

    }
    else if(numberOFmainmnue == 6)
    {
        start();
    }
}

//******************************************************************************************************************
int Random()
{
    int a;
    srand(time(0));
    a = (rand()%3)+1 ;
    return a;
}
//**************************************************************************



void type_testing()
{   int A;
    A = Random();
    FILE *ptr;
    if(A == 1)
    {
      ptr = fopen("1.txt","r");
    }
    else if(A ==2)
    {
        ptr = fopen("2.txt","r");
    }
    else if(A == 3)
    {
        ptr = fopen("3.txt","r");
    }
    if(ptr == NULL)
    {
        printf("your file not open");
        return;
    }


    char word[600];
    fgets(word,600,ptr);

    char help[600];
    strcpy(help,word);

    char for_checking[100][20];
    //printf("555\n");
    put_to_arry(help,for_checking);
    SetColor(1);
    printf("%s",word);

    SetColor(0);
    printf("\n\nstart to writting\n");


    char user_word[1000];

    clock_t begin = clock();

    char tmp;
    scanf("%c",&tmp);
    scanf("%[^\n]",user_word);
    clock_t end = clock();
    double time_spent = (((double)(end - begin) / CLOCKS_PER_SEC))/60;

    char check_user[100][20];
    put_to_arry(user_word,check_user);

    int count = 0;
    int Space = number_of_word(word);
    printf("words is :%d\n",Space);
    for(int i  = 0;i<Space;i++)
    {
        if(!strcmp(for_checking[i],check_user[i]))
        {
            count++;
        }
    }
    printf("currect words is :%d\n",count);
    double Score = (((100*count))/Space)+(2*time_spent);

    printf("your score is :%2.2lf",Score);
    fclose(ptr);
    store_score(Name_,Score,A);
}
//***********************************************************************
/*HOW TO CHANGE COLOR OF TEXT*/
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;

}
//****************************************************************************************
void change_pass(char *account , char *old_pass)
{
    FILE *ptr  = fopen("username.txt","r");
    FILE *secure  = fopen("password.txt","r");

    if(searchup(ptr,account))
    {
        printf("your account not in the system\n\n");
        fclose(ptr);
        fclose(secure);
        mainmnue();

    }

    else
    {
        if(searchup(secure,old_pass))
        {
            printf("this pass not in the system\n");
            fclose(secure);
            fclose(ptr);
            mainmnue();

        }
        else
        {
            int k = 0;
            int j = 0;
            fseek(ptr,0,SEEK_SET);
            fseek(secure,0,SEEK_SET);
            while(!feof(ptr))
            {
                fscanf(ptr,"%s",Change_pass[j].account);
                if(!strcmp(Change_pass[j].account,account))
                   {
                       k = j;
                   }
                j++;

            }

            for(int i = 0;i<j-1;i++)
            {
                fscanf(secure,"%s",Change_pass[i].pass);

            }
            char new_pss[20];
            printf("enter your new pass:");
            scanf("%s",new_pss);

            strcpy(Change_pass[k].pass,new_pss);

            fclose(ptr);
            fclose(secure);
            FILE *secure  = fopen("password.txt","w");
            for(int i = 0;i<j-1;i++)
            {
                fprintf(secure,"%s\n",Change_pass[i].pass);
            }
            printf("you change your password correctly\n");
            fclose(secure);
            mainmnue();

        }
    }
}

//***********************************************************************************

void store_score(char *name,double score,int paragraph)
{
    char word[100];
    char help[100];

    //The following arrays help to gets old paragraph and old score
    char help1[100];
    char help2[100];
    char help3[100];


    char *New_score;

    char new_score[10];

    FILE *ptr;
    ptr = fopen("type_testing.txt","r");
    int j = 0;           // that means there is not name in the ptr

    int counter = 0;     //it counts line of ptr to check which  line there is name
    int number;
    while(!feof(ptr))
    {
        fgets(word,100,ptr);
        if(strstr(word,name))
        {
            number = counter;
            j = 1; //that means there is name in the ptr


            sscanf(word,"%s\t%s\t%s\t",help1,help2,help3);

            char *old_score = strstr(help3,"**");

            sprintf(New_score,"#%2.2lf",score);


            sprintf(new_score,"**%2.2lf",score);

            if(strcmp(old_score,new_score)== -1)
            {

                sprintf(help,"name:%s\tlast_paragraph_lastscore:%d#%2.2lf\tparagraph-bestscore:%d**%2.2lf\n",name,paragraph,score,paragraph,score);
            }

            else
            {
                sprintf(help,"name:%s\tlast_paragraph_lastscore:%d#%2.2lf\t%s\n",name,paragraph,score,help3);
            }

            strcpy(word,help);

            int k = 0;
            rewind(ptr);

            while(!feof(ptr))
            {   char ch;
              ch = fgetc(ptr);
              if(ch == '\n')
              {
                k++;
              }
            }
            rewind(ptr);
            for(int i = 0;i<=k;i++)
            {
                fgets(Type_testing[i].each_line,100,ptr);
            }

            strcpy(Type_testing[number].each_line,word);
            fclose(ptr);
            ptr = fopen("type_testing.txt","w");
            for(int i = 0;i<=k;i++)
            {
                fputs(Type_testing[i].each_line,ptr);
            }
            fclose(ptr);
            return;



        }
        counter++;
    }
    if(j == 0)
    {
        fclose(ptr);
        ptr = fopen("type_testing.txt","a");
        fprintf(ptr,"name:%s\tlast_paragraph-lastscore:%d#%2.2lf\tparagraph-bestscore:%d**%2.2lf\n",name,paragraph,score,paragraph,score);
        fclose(ptr);
    }
}
//*******************************************************************************


void Search_users_by_names(char *name)
{
    FILE *ptr = fopen("type_testing.txt","r");
    char word[100];
    int j = 0;
    while(!feof(ptr))
    {
        fgets(word,100,ptr);
        if(strstr(word,name))
        {
            j = 1;
            printf("%s",word);

        }
    }
    fclose(ptr);
    if(j == 0)
    {
        printf("\nyour account not in the system\n");
    }
    mainmnue();
}
//*****************************************************************************

void Search_users_by_best_score(char *score)
{
    FILE *ptr = fopen("type_testing.txt","r");
    char word[100];
    int j =0;

    while(!feof(ptr))
    {
        fgets(word,100,ptr);
        if(strstr(word,score))
        {
            j = 1;
            printf("%s",word);
            break;
        }
    }
    fclose(ptr);
    if(j == 0)
    {
        printf("\nthis score  not in the system\n");
    }
    mainmnue();
}
//***************************************************************************************
void sorted_Statistical_info()
{
    FILE *ptr ;
    ptr = fopen("type_testing.txt","r");
    int k  = 0;
    while(!feof(ptr))
    {
        fgets(Users[k].line,100,ptr);
        k++;
    }
    fclose(ptr);
    char *temp1;
    char *temp2;
    char help[100];

    for(int i= 0 ;i<k-1;i++)
    {

        for(int j = 0;j<k-2;j++)
        {
            temp1 = strstr(Users[j].line,"**");
            temp2 = strstr(Users[j+1].line,"**");
            if(strcmp(temp1,temp2) == -1)
            {
                strcpy(help,Users[j].line);
                strcpy(Users[j].line,Users[j+1].line);
                strcpy(Users[j+1].line,help);
            }
        }
    }
    for(int i = 0;i<k-1;i++)
    {
        printf("%s",Users[i].line);

    }
    printf("\n");


}

//******************************************************************************


int link_pass_account(char *name,char *pass)
{
    FILE *ptr = fopen("username.txt","r");
    FILE *ptr1 = fopen("password.txt","r");
    FILE *ptr2 = fopen("link_pass_username.txt","w+");
    char word[100];

    int k = 0;
    while(!feof(ptr))
    {
        fscanf(ptr,"%s",link[k].user);
        fscanf(ptr1,"%s",link[k].pass);
        k++;

    }
    for(int i = 0;i<k;i++)
    {
        fprintf(ptr2,"%s\t%s\n",link[i].user,link[i].pass);
    }

    fclose(ptr);
    fclose(ptr1);

    rewind(ptr2);
    char help[100];

    int j = 0;

    while(!feof(ptr2))
    {

        fgets(help,100,ptr2);



        if((strstr(help,name)) && (strstr(help,pass)))
        {
            j = 1;
            fclose(ptr2);

            return j;   //that means username and pass liked together
        }
    }
    fclose(ptr2);
    return j;

}
//************************************************************************************

//result is an empty array

void put_to_arry(char s[1000],char result[100][20]) //s is array that we want to put concept of it to result without space
{

    // Returns first token
    char *token = strtok(s, " ");
    //*

    // Keep printing tokens while one of the
    // delimiters present in s[].
    int i = 0;
    while (token != NULL)
    {

        strcpy(result[i],token);


        token = strtok(NULL, " ");

        i++;
    }

}

//**************************************************************************


int number_of_word(char *a)
{
    int space = 0;
    int counter = strlen(a);
    for(int i = 0;i<counter;i++)
    {

        if(a[i] == ' ')
        {
            space++;
        }
    }
    space++;
    return space;

}


//**********************************************


