//username: a
//password : 1
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>  
#include<string.h>   //For string functions
#include<windows.h>  // for sleep

void addingrec();
void displayrecord();
void searchrecstudent();
void deleterecstu();
void passwor();
 void welcome();
 void updaterecord();
struct student{
    char first_name[50];
    char last_name[25];
    int roll_no;
    char class[10];
    char add[20];
    float per;
};
int main(){
    
    passwor();


//     time_t t=time(NULL);
//     printf("current time is %ld\n",t);
//     struct tm date=*localtime(&t);
//     sprintf("current date is :%02d/%02d/%d",date.tm_year+1900,date.tm_mon+1,date.tm_mday);

    return 0;
}
void passwor(){
    int attempt=0;
    int max_attempt=3;
    char name[50]="a";
    char pass[40]="1";
    char n[50];
    char password[50];
    while(attempt<max_attempt){
    printf("\n\n\n\n\t\t\t\t\tEnter username:");
    scanf("%s",n);
    printf("\n\t\t\t\t\tEnter password:");
    scanf("%s",password);


    if(strcmp(name,n)==0&&strcmp(pass,password)==0){
        printf("\n\t\t\t\t\tYou have entered the correct password.\n");
        printf("\n\n\t\t\t\t\tEnter any key to go to main \n\n");
        getch();
        welcome();
    }
    else{
        printf("You entered wrong password error\n");
        system("cls");
        attempt++;
    
    }
    }
    if(attempt==max_attempt){
        printf("Maximum login attempts reached.Access denied.\n");
        exit(0);
    }
}

void welcome(){



    int choice;
printf("\n\t\t\t\t\t");
char message[]="WELCOME TO IOE PURWANCHAL CAMPUS";
int  i;
for(i=0;message[i]!='\0';i++){
  printf("%c",message[i]);            //to print each letter individually
 
 
  Sleep(400);//pause for 400 millisecond

}




while(1)
{
    printf("\n\n\t\t\t\t\t=====YOU ARE WELCOME TO IOE PURWANCHAL CAMPUS=====");
    printf("\n\n\t\t\t\t\t=====STUDENT DATABASE MANAGEMENT SYSTEM====");
    printf("\n\n\n\t\t\t\t\t 1.Add student record\n");
    printf("\n\t\t\t\t\t2.Student records are available here to watch it press 2\n");
     printf("\n\t\t\t\t\t3.Search  recorded student\n");
      printf("\n\t\t\t\t\t4.Delete student record\n");
      printf("\n\t\t\t\t\t5.Update record\n");
       printf("\n\t\t\t\t\t6.Exit\n");
       printf("\t\t\t\t\t__________________\n");
       printf("\t\t\t\t\t  ");
       scanf("%d",&choice);
       switch(choice){
        case 1:
        system("cls");
        addingrec();
        system("cls");
        break;
        case 2:
        system("cls");
        displayrecord();
        printf("\n\t\t\t\t\tPress any key to exit\n\n \t");
        getch();
        system("cls");
        break;



        case 3:
        system("cls");
        searchrecstudent();
        printf("\n\t\t\t\t\t Press any key to exit\n");
        getch();
        system("cls");
        break;



        case 4:
        system("cls");
        deleterecstu();
        printf("\n\n\n\t\t\t\t\t Press any key to exit\n");
        getch();
        system("cls");
        break;
        case 5:
        system("cls");
        updaterecord();
        printf("\n\n\t\t\t\t\tPress any key to exit\n");
        getch();
        break;
        case 6:
        exit(0);
        default: printf("\t\t\t\t\tInvalid Input");


       }
}

}





void addingrec(){
    char another;
    FILE *fp;
    struct student s;
    do{
        system("cls");
        printf("\t\t\t\t\t=====Add student info====\n\n\n");
        fp=fopen("student_info","a");
      
        printf("\n\t\t\t Enter first name:");
        scanf("%s",&s.first_name);

          printf("\n\t\t\t Enter last name:");
        scanf("%s",&s.last_name);
          printf("\n\t\t\t Enter roll no:");
        scanf("%d",&s.roll_no);
          printf("\n\t\t\t Enter class:");
        scanf("%s",&s.class);

          printf("\n\t\t\t Enter address:");
        scanf("%s",&s.add);
          printf("\n\t\t\t Enter percentage:");
        scanf("%f",&s.per);
        printf("\n\t\t\t_______________________\n");
        if(fp==NULL){
            printf("\n\t\t\t File cannot be opened\n");

        }
        else{
            printf("\n\t\t\t Record stored successfully\n");
        }
        fwrite(&s,sizeof(struct student),1,fp);
        fclose(fp);
        printf("\n\t\t\t Do you want to add another record?(y/n)");
        scanf("%s",&another);
    
    

        
    }
    while(another =='y'||another=='Y');
}



    void displayrecord(){
    FILE *fp;
    struct student s;
    fp=fopen("student_info","r");
    printf("\t\t\t\t\t\t======= Student Record====\n\n");
    if(fp==NULL){
         printf("\n\t\t\t File cannot be opened\n");
    }
    else{
        printf("\t\t\t\tRecords\n\n\n");

    }
    while(fread(&s,sizeof(struct student),1,fp)){
        printf("\n\t\t\t\t Student name:%s %s",s.first_name,s.last_name);
        printf("\n\t\t\t\t Roll no:%d",s.roll_no);
        printf("\n\t\t\t\t Student class:%s",s.class);
        printf("\n\t\t\t\t Student address:%s",s.add);
        printf("\n\t\t\t\t Student percentage:%f",s.per);

        printf("\n\t\t\t\t______________________________________________\n\n");
    }
    fclose(fp);
}


void searchrecstudent(){
    FILE *fp;
    struct student s;
    int roll_no,found=0;
    fp=fopen("student_info","r");
    printf("\t\t\t\t\t====Search Student=======\n\n\n");
    printf("\t\t\t\t\tEnter roll no :");
    scanf("%d",&roll_no);


    while(fread(&s,sizeof(struct student),1,fp)){


if(s.roll_no==roll_no){
    found=1;
        
        printf("\n\t\t\t\t Student name:%s %s",s.first_name,s.last_name);
        printf("\n\t\t\t\t Roll no:%d",s.roll_no);
        printf("\n\t\t\t\t Student class:%s",s.class);
        printf("\n\t\t\t\t Student address:%s",s.add);
        printf("\n\t\t\t\t Student percentage:%f",s.per);

        printf("\n\t\t\t\t______________________________________________\n\n");
    }
    }
    if(found==0){
        printf("\n\n\t\t\t Record not found\n\n");
    }

    fclose(fp);
}




void deleterecstu(){
     FILE *fp,*fp1;
    struct student s;
    int roll_no,found=0;
    printf("\t\t\t\t\t======Delete record====\n\n");
    fp=fopen("student_info","r");
    fp1=fopen("temp.txt","w");
    printf("\t\t\t\t\t Enter roll no:");
    scanf("%d",&roll_no);

     if(fp==NULL){
         printf("\n\t\t\t\t\t File cannot be opened\n");
     }

      while(fread(&s,sizeof(struct student),1,fp)){


if(s.roll_no==roll_no){
    found=1;}
    else{
        fwrite(&s,sizeof(struct student),1,fp1);

    }
      }
      fclose(fp);
      fclose(fp1);
      if(found){
        remove("student_info");
        rename("temp.txt","student_info");
        printf("\n\n\t\t\t\t\t Record deleted successfully!\n\t");

      }
      if(!found){
        printf("\n\t\t\t\t\tRecored is not available!");
      }


}



void updaterecord(){
    struct student s;
FILE *fp,*fp1;
int roll,found=0;
printf("Enter the roll no you want to update:");
scanf("%d",&roll);
fp=fopen("student_info","r");
fp1=fopen("copy.dat","w");

if(fp==NULL){
  printf("File cannot be opened");
  exit(0);

}
while(fread(&s,sizeof(struct student),1,fp)){
  if(s.roll_no==roll){
    found=1;
  }
  else{
    fwrite(&s,sizeof(struct student),1,fp1);
  }
  
  
}

 printf("\n\t\t\t Enter first name:");
        scanf("%s",&s.first_name);

          printf("\n\t\t\t Enter last name:");
        scanf("%s",&s.last_name);
          printf("\n\t\t\t Enter roll no:");
        scanf("%d",&s.roll_no);
          printf("\n\t\t\t Enter class:");
        scanf("%s",&s.class);

          printf("\n\t\t\t Enter address:");
        scanf("%s",&s.add);
          printf("\n\t\t\t Enter percentage:");
        scanf("%f",&s.per);
        fwrite(&s,sizeof(struct student),1,fp1);
        fclose(fp);
        fclose(fp1);
        if(found){
        remove("student_info");
        rename("copy.dat","student_info");
        printf("\t\t\tRecord updated successfully!!");
        system("cls");
        }

         if(!found){
        printf("\n\t\t\tRecord is not available!");
      }

}