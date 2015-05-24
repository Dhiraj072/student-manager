/*********************************************************************************HEADER FILES******************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>



/*********************************************************************************STRUCTURES USED***************************************************************************************************/


typedef struct
{
char rollno1[12];
char firstname[15];
char lastname[15];
char branch[4];
char age[3];
char father[30];
char mother[30];
char bgroup[3];
char cellno[10];
char address[100];
}biodata1;



struct subject
{
char rollno1[12];
char firstname[15];
char lastname[15];
float midsem1;
float midsem2;
float endsem;
float quiz1;
float quiz2;
float quiz3;
float quiz4;
float quiz5;
float lab;
float spi;
struct subject *next;};
typedef struct subject sub;




/************************************************************************INITIALIZATION OF FUNCTIONS************************************************************************************************/


void clearscreen(void);
void welcome(void);
int username();
int password(int a);
void biodata(void);
void mainmenu(void);
void mainmenu1(void);
void submenu2(void);
void submenu3(void);
void marks(void);
void swmarks(int);
sub *create_list();
void display_list(sub *);
void individual_marks(void);
void topheading(void);
void grade(void);
void display_grades(sub *);
void add_student(void);
void biodata2(void);
void delete_student(char rno[12]);
void edit_student(void);
void spi(void);
sub *link_maths();
sub *link_pds();
sub *link_phy();
sub *link_eng();
sub *link_eg();
sub *link_spi();
void t_spi(sub *);
void transverse_spi(sub *,sub *,sub *,sub *,sub *);
void achievement(void);
void scholarship(void);
void edit_marks(void);




/************************************************************************GLOBAL VARIABLE DECLARATION************************************************************************************************/


int subj;
char rollno[12];



/********************************************************************************MAIN***************************************************************************************************************/


int main()
{
	clearscreen();
       	welcome();
	int a,b,loginattempt=2,i=0;
	int choice;
	a=username();
	printf("\nYou have 3 login attempts\n");
	while(i<3)
	{
		b=password(a);
		clearscreen();
		topheading();
		welcome();	
		printf("\n");	
		i++;
		if(b==0)
		{
			printf("\nyou have %d login attempts left\n",loginattempt);
			loginattempt--;
			continue;
		}
		else
			break;
		}

	if(b==0)
	printf("\nYour all login attempts have ended!!!\n");
	clearscreen();


if(a==1 && b!=0) //student profile
{
                 
        	 mainmenu();
}

else if(a==2) //administrator profile
{
printf("\n");
mainmenu1();
}
return 0;
}



/****************************************************************************FUNCTION DECLARATIONS***************************************************************************************************/



/****************Function to clear screen****************/

void clearscreen(void) 
{
if (system( "clear" )) system( "cls" );
}



/****************Function to enter username****************/

int username()
{
char ans[15];
printf("\nAre you a student or administrator?\n");
scanf("%s",ans);
if(strcmp(ans,"student")==0 || strcmp(ans,"STUDENT")==0)
return 1;
else if(strcmp(ans,"administrator")==0 || strcmp(ans,"ADMINISTRATOR")==0)
return 2;
}



/****************Function for top heading******************/

void topheading(void)
{
                 printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tWELCOME TO IIT JODHPUR'S STUDENT DATABASE AND RESULT MAINTENANCE SYSTEM\n");
                 printf("\n\t\t\t\t\t\t\t\t\t\tTODAY'S DATE AND TIME IS");
                 const time_t timer = time(NULL);
                 printf(" %s\n", ctime(&timer));
}



/************Function to print welcome screen***************/

void welcome(void)
{

printf("\n\t\t\t\t\t\t\t\t\t\t$$      $$  $$$$$$$  $$      $$$$$$  $$$$$$$  $$$$  $$$$  $$$$$$$");
printf("\n\t\t\t\t\t\t\t\t\t\t$$      $$  $$       $$      $$      $$   $$  $$  $$  $$  $$     ");
printf("\n\t\t\t\t\t\t\t\t\t\t$$  $$  $$  $$$$$    $$      $$      $$   $$  $$  $$  $$  $$$$$  ");
printf("\n\t\t\t\t\t\t\t\t\t\t$$  $$  $$  $$       $$      $$      $$   $$  $$      $$  $$     ");
printf("\n\t\t\t\t\t\t\t\t\t\t$$$$$$$$$$  $$$$$$$  $$$$$$$ $$$$$$  $$$$$$$  $$      $$  $$$$$$$");
}



/****************Function to enter password****************/

int password(int a)
{
char password[15];
if(a==1)
{
printf("\nEnter student password\n");
scanf("%s",password);
if(strcmp(password,"student")==0)
return 1;
else
printf("\nWrong password!!!\n");
return 0;
}
else if(a==2)
{
printf("\nEnter administrator password\n");
scanf("%s",password);
if(strcmp(password,"administrator")==0)
return 2;
else
printf("\nWrong password!!!\n");
return 0;
}
}



/**************Function for reading biodata****************/

void biodata(void)
{
biodata1 bio;
char rno[12];
FILE *read;
if( (read = fopen("BIODATA1.txt","r")) == NULL)
          printf("File cannot be opened\n");
  
else
{
printf("\nEnter roll number of the student\n");
scanf("%s",rno);
while(!feof(read))
{
fgets(bio.rollno1,12,read);
if(strcmp(rno,bio.rollno1)==0)
{
fseek(read,1,SEEK_CUR);
break;
}

}
fscanf(read,"%s %s %s %s %s %s %s %s ",bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno);
printf("\nNAME\t\t:\t%s %s",bio.firstname, bio.lastname);
printf("\nBRANCH\t\t:\t%s",bio.branch);
printf("\nAGE\t\t:\t%s",bio.age);
printf("\nFATHER'S NAME\t:\t%s",bio.father);
printf("\nMOTHER'S NAME\t:\t%s",bio.mother);
printf("\nBLOOD GROUP\t:\t%s",bio.bgroup);
printf("\nCELL NUMBER\t:\t%s",bio.cellno);
fseek(read,0,SEEK_CUR);
fgets(bio.address,1000,read);
printf("\nADDRESS\t\t:\t%s\n",bio.address);
}
fclose(read);
}



/**************Function to print the main menu(STUDENT)****************/

void mainmenu(void)
{
int choice;
	
	topheading();
 	 welcome();
 	 printf("\n\t\t\t\t\t\t\t\t\t\t******************************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**   WELCOME TO STUDENT RECORD AND RESULT MAINTENANCE SYSTEM    **");
         printf("\n\t\t\t\t\t\t\t\t\t\t******************************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      1.BIODATA                  	       **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      2.ACADEMIC RECORDS                      **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      3.SPECIAL ACHIEVEMENTS                  **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      4.SCHOLARSHIPS                          **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      0.EXIT                                  **\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t******************************************************************");
         printf("\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE(1/2/3/4/0)? : ");
         scanf("%d", &choice);
        
      switch(choice)
	{
	case 1:biodata();
	printf("\n");	
	mainmenu();
	break;
	case 2:printf("\n");
	submenu2();
	break;
	case 3:printf("\n");
	achievement();
	mainmenu();
	break;
	case 4:printf("\n");
		scholarship();
		mainmenu();
		break;
	}
}







/**************Function to print the main menu(ADMINISTRATOR)****************/
void mainmenu1(void)
{
int choice;
	
	topheading();
 	 welcome();
 	 printf("\n\t\t\t\t\t\t\t\t\t\t******************************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**   WELCOME TO STUDENT RECORD AND RESULT MAINTENANCE SYSTEM    **");
         printf("\n\t\t\t\t\t\t\t\t\t\t******************************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      1.BIODATA                  	       **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      2.ACADEMIC RECORDS                      **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      3.SPECIAL ACHIEVEMENTS                  **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      4.SCHOLARSHIPS                          **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      0.EXIT                                  **\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t******************************************************************");
         printf("\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE(1/2/3/4/0)? : ");
         scanf("%d", &choice);
	int c;
	switch(choice)
	{
	case 1: printf("\n");
		biodata2();
		break;
	case 2: printf("\n");
		submenu3();
		break;
	case 3: 
		achievement();
		mainmenu1();		
		break;
	case 4: printf("\n");
		scholarship();
		mainmenu1();
		break;
		
	}
}


/**************Function to print submenu for Academic Records(STUDENT)****************/

void submenu2(void)
{
int choice;
       	 printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                1.MARKS                               **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                2.GRADES                              **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                3.CPI AND SPI                         **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                0.EXIT TO MAIN MENU                   **\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************");
	 printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************\n");	         
	 printf("\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE(1/2/3/0)? : ");
	 scanf("%d",&choice);

		switch(choice)
		{
		case 0: 
                        clearscreen();		
			mainmenu();
			break;
		case 1: 
			printf("\n");
			marks();
			break;
		case 2: printf("\n");
			grade();
			submenu2();
			break;
		case 3: printf("\n");
			spi();
			submenu2();
			break;
	
 		}	

}


/**************Function to print submenu for Academic Records(ADMINISTRATOR)****************/

void submenu3(void)
{
int choice;
	
	 printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                1.UPDATE MARKS                        **");
	 printf("\n\t\t\t\t\t\t\t\t\t\t**                2.SEE MARKS                           **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                3.GRADES                              **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                4.CPI AND SPI                         **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                0.EXIT TO MAIN MENU                   **\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************");
	 printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE(1/2/3/4/0)? : ");
	 scanf("%d",&choice);

		switch(choice)
		{
		case 0: 
                        clearscreen();		
			mainmenu1();
			break;
		case 1: 
			printf("\n");
			edit_marks();
			submenu3();
			break;
		case 2: printf("\n");
			marks();
			break;
		case 3: printf("\n");
			grade();
			submenu3();
			break;
		case 4: printf("\n");
			spi();
			submenu3();
			break;

 		}	

}



/**************Function to display submenu of marks****************/

void marks(void)
{
int choice;

 	 printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************");
         printf("\n\t\t\t\t\t\t\t\t\t\t**               WELCOME STUDENT                        **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                1.SUBJECT WISE MARKS                  **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                2.STUDENT'S INDIVIDUAL MARKS          **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                3.EXIT TO PREVIOUS MENU               **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                0.EXIT TO MAIN MENU                   **\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**********************************************************");
         printf("\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE(1/2/3/0)? : ");
	 scanf("%d",&choice);



	switch(choice)
	{
		case 1:
			printf("\nEnter the number corresponding to following subjects\n");
			printf("\n1-maths\n2-physics\n3-pds\n4-english\n5-eg\n");
			scanf("%d",&subj);
			swmarks(subj);
			marks();
			break;
		case 2:
			individual_marks();
			break;
		case 3: 
			clearscreen();			
			printf("\n");
			submenu2();			
			break;
		case 0:
			clearscreen();		
			printf("\n");
			mainmenu();
			break;
	}
}





//************************************FUNCTION SUBMENU BIODATA(ADMINISTRATOR)*********************

void biodata2(void)
{
int choice;
char rno[12];
	 printf("\n\t\t\t\t\t\t\t\t\t\t******************************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**   WELCOME TO STUDENT RECORD AND RESULT MAINTENANCE SYSTEM    **");
         printf("\n\t\t\t\t\t\t\t\t\t\t******************************************************************\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      1.BIODATA                  	       **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      2.ADD A STUDENT                         **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      3.DELETE A STUDENT                      **");
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      4.EDIT AN EXISTING STUDENT              **"); 
	 printf("\n\t\t\t\t\t\t\t\t\t\t**                      5.GO BACK TO MAIN MENU                  **");  
         printf("\n\t\t\t\t\t\t\t\t\t\t**                      0.EXIT                                  **\n");
         printf("\n\t\t\t\t\t\t\t\t\t\t******************************************************************");
         printf("\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE(1/2/3/4/5/0)? : ");
         scanf("%d", &choice);
	switch(choice)
	{
	case 1: biodata();
		biodata2();
		break;
	case 2: add_student();
		mainmenu1();
		break;
	case 3: 
		printf("\nEnter roll no of the student whose record is to be deleted : ");
		scanf("%s",rno);
		delete_student(rno);
		biodata2();
		break;
	case 4: 
		edit_student();
		biodata2();
		break;
	case 5: mainmenu1();
		break;	
	}

}





/**************Function to display marks of all the students****************/

void swmarks(int subj)
{
sub *head;
head=create_list();
display_list(head);
}




/********************Function for creating linked lists********************/

sub *create_list()
{
if(subj==1)
{
FILE *maths;
sub *p,*head;
if( (maths = fopen("MATHS.txt","r")) == NULL)
          printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
fseek(maths, 62, SEEK_SET);
while(!feof(maths))	
{
fscanf(maths,"%s %s %s %f %f %f %f %f %f %f %f %f ", p->rollno1, p->firstname, p->lastname, &p->midsem1, &p->midsem2, &p->endsem, &p->quiz1, &p->quiz2, &p->quiz3, &p->quiz4, &p->quiz5, &p->lab);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(maths);
}


else if(subj==2)
{
FILE *physics;
sub *p,*head;
if( (physics = fopen("PHYSICS.txt","r")) == NULL)
          printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
fseek(physics, 62, SEEK_SET);
while(!feof(physics))	
{
fscanf(physics,"%s %s %s %f %f %f %f %f %f %f %f %f ", p->rollno1, p->firstname, p->lastname, &p->midsem1, &p->midsem2, &p->endsem, &p->quiz1, &p->quiz2, &p->quiz3, &p->quiz4, &p->quiz5, &p->lab);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(physics);
}


else if(subj==3)
{
FILE *pds;
sub *p,*head;
if( (pds = fopen("PDS.txt","r")) == NULL)
           printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
fseek(pds, 62, SEEK_SET);
while(!feof(pds))	
{
fscanf(pds,"%s %s %s %f %f %f %f %f %f %f %f %f ", p->rollno1, p->firstname, p->lastname, &p->midsem1, &p->midsem2, &p->endsem, &p->quiz1, &p->quiz2, &p->quiz3, &p->quiz4, &p->quiz5, &p->lab);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(pds);
}

else if(subj==4)
{
FILE *english;
sub *p,*head;
if( (english = fopen("ENGLISH.txt","r")) == NULL)
          printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
fseek(english, 62, SEEK_SET);
while(!feof(english))	
{
fscanf(english,"%s %s %s %f %f %f %f %f %f %f %f %f ", p->rollno1, p->firstname, p->lastname, &p->midsem1, &p->midsem2, &p->endsem, &p->quiz1, &p->quiz2, &p->quiz3, &p->quiz4, &p->quiz5, &p->lab);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(english);
}

else if(subj==5)
{
FILE *eg;
sub *p,*head;
if( (eg = fopen("EG.txt","r")) == NULL)
          printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
fseek(eg, 62, SEEK_SET);
while(!feof(eg))	
{
fscanf(eg,"%s %s %s %f %f %f %f %f %f %f %f %f ", p->rollno1, p->firstname, p->lastname, &p->midsem1, &p->midsem2, &p->endsem, &p->quiz1, &p->quiz2, &p->quiz3, &p->quiz4, &p->quiz5, &p->lab);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(eg);
}

}



/**********************Function to display linked list*************************/

void display_list(sub *head)
{
sub *p;
p=head;
printf("ROLLNO.\t\t");
printf("NAME\t\t\t\t");
printf("MID1\t");
printf("MID2\t");
printf("ENDSEM\t");
printf("QUIZ1\t");
printf("QUIZ2\t");
printf("QUIZ3\t");
printf("QUIZ4\t");
printf("QUIZ5\t");
printf("LAB EVALUATION\n");
while(p->next!=NULL)
{
printf("%11.11s\t",p->rollno1);
printf("%s ",p->firstname);
printf("%s\t\t\t",p->lastname);
printf("%2.2f\t",p->midsem1);
printf("%2.2f\t",p->midsem2);
printf("%2.2f\t",p->endsem);
printf("%2.2f\t",p->quiz1);
printf("%2.2f\t",p->quiz2);
printf("%2.2f\t",p->quiz3);
printf("%2.2f\t",p->quiz4);
printf("%2.2f\t",p->quiz5);
printf("%2.2f\t\n",p->lab);
p=p->next;
}
}



/**************Function to display individual marks of students****************/

void individual_marks(void)
{
sub ps;
char rno[12];
printf("\nEnter the roll no. of the student\n");
scanf("%s", rno);

FILE *maths,*physics,*pds,*english,*eg;
if( (maths = fopen("MATHS.txt","r")) == NULL)
          printf("File cannot be opened\n");
if( (physics = fopen("PHYSICS.txt","r")) == NULL)
          printf("File cannot be opened\n");
if( (pds = fopen("PDS.txt","r")) == NULL)
          printf("File cannot be opened\n");
if( (english = fopen("ENGLISH.txt","r")) == NULL)
          printf("File cannot be opened\n");
if( (eg = fopen("EG.txt","r")) == NULL)
          printf("File cannot be opened\n");

printf("SUBJECT\t\t\t\t");
printf("MID1\t");
printf("MID2\t");
printf("ENDSEM\t");
printf("QUIZ1\t");
printf("QUIZ2\t");
printf("QUIZ3\t");
printf("QUIZ4\t");
printf("QUIZ5\t");
printf("LAB EVALUATION\n");
while(!feof(maths))
{
fgets(ps.rollno1,12,maths);
if(strcmp(rno,ps.rollno1)==0)
{
fseek(maths,-12,SEEK_CUR);
break;
}
}
fscanf(maths,"%s %s %s %f %f %f %f %f %f %f %f %f ", ps.rollno1, ps.firstname, ps.lastname, &ps.midsem1, &ps.midsem2, &ps.endsem, &ps.quiz1, &ps.quiz2, &ps.quiz3, &ps.quiz4, &ps.quiz5, &ps.lab);
printf("%s\t\t\t\t","MATHS");
printf("%2.2f\t",ps.midsem1);
printf("%2.2f\t",ps.midsem2);
printf("%2.2f\t",ps.endsem);
printf("%2.2f\t",ps.quiz1);
printf("%2.2f\t",ps.quiz2);
printf("%2.2f\t",ps.quiz3);
printf("%2.2f\t",ps.quiz4);
printf("%2.2f\t",ps.quiz5);
printf("%2.2f\t\n",ps.lab);

while(!feof(physics))
{
fgets(ps.rollno1,12,physics);
if(strcmp(rno,ps.rollno1)==0)
{
fseek(physics,-12,SEEK_CUR);
break;
}
}
fscanf(physics,"%s %s %s %f %f %f %f %f %f %f %f %f ", ps.rollno1, ps.firstname, ps.lastname, &ps.midsem1, &ps.midsem2, &ps.endsem, &ps.quiz1, &ps.quiz2, &ps.quiz3, &ps.quiz4, &ps.quiz5, &ps.lab);
printf("%s\t\t\t\t","PHYSICS");
printf("%2.2f\t",ps.midsem1);
printf("%2.2f\t",ps.midsem2);
printf("%2.2f\t",ps.endsem);
printf("%2.2f\t",ps.quiz1);
printf("%2.2f\t",ps.quiz2);
printf("%2.2f\t",ps.quiz3);
printf("%2.2f\t",ps.quiz4);
printf("%2.2f\t",ps.quiz5);
printf("%2.2f\t\n",ps.lab);

while(!feof(pds))
{
fgets(ps.rollno1,12,pds);
if(strcmp(rno,ps.rollno1)==0)
{
fseek(pds,-12,SEEK_CUR);
break;
}
}
fscanf(pds,"%s %s %s %f %f %f %f %f %f %f %f %f ", ps.rollno1, ps.firstname, ps.lastname, &ps.midsem1, &ps.midsem2, &ps.endsem, &ps.quiz1, &ps.quiz2, &ps.quiz3, &ps.quiz4, &ps.quiz5, &ps.lab);
printf("%s\t\t\t\t","PDS");
printf("%2.2f\t",ps.midsem1);
printf("%2.2f\t",ps.midsem2);
printf("%2.2f\t",ps.endsem);
printf("%2.2f\t",ps.quiz1);
printf("%2.2f\t",ps.quiz2);
printf("%2.2f\t",ps.quiz3);
printf("%2.2f\t",ps.quiz4);
printf("%2.2f\t",ps.quiz5);
printf("%2.2f\t\n",ps.lab);

while(!feof(english))
{
fgets(ps.rollno1,12,english);
if(strcmp(rno,ps.rollno1)==0)
{
fseek(english,-12,SEEK_CUR);
break;
}
}
fscanf(english,"%s %s %s %f %f %f %f %f %f %f %f %f ", ps.rollno1, ps.firstname, ps.lastname, &ps.midsem1, &ps.midsem2, &ps.endsem, &ps.quiz1, &ps.quiz2, &ps.quiz3, &ps.quiz4, &ps.quiz5, &ps.lab);
printf("%s\t\t\t\t","ENGLISH");
printf("%2.2f\t",ps.midsem1);
printf("%2.2f\t",ps.midsem2);
printf("%2.2f\t",ps.endsem);
printf("%2.2f\t",ps.quiz1);
printf("%2.2f\t",ps.quiz2);
printf("%2.2f\t",ps.quiz3);
printf("%2.2f\t",ps.quiz4);
printf("%2.2f\t",ps.quiz5);
printf("%2.2f\t\n",ps.lab);

while(!feof(eg))
{
fgets(ps.rollno1,12,eg);
if(strcmp(rno,ps.rollno1)==0)
{
fseek(eg,-12,SEEK_CUR);
break;
}
}
fscanf(eg,"%s %s %s %f %f %f %f %f %f %f %f %f ", ps.rollno1, ps.firstname, ps.lastname, &ps.midsem1, &ps.midsem2, &ps.endsem, &ps.quiz1, &ps.quiz2, &ps.quiz3, &ps.quiz4, &ps.quiz5, &ps.lab);
printf("%s\t\t\t\t","EG");
printf("%2.2f\t",ps.midsem1);
printf("%2.2f\t",ps.midsem2);
printf("%2.2f\t",ps.endsem);
printf("%2.2f\t",ps.quiz1);
printf("%2.2f\t",ps.quiz2);
printf("%2.2f\t",ps.quiz3);
printf("%2.2f\t",ps.quiz4);
printf("%2.2f\t",ps.quiz5);
printf("%2.2f\t\n",ps.lab);
marks();
}





//***********************************FUNCTION TO DISPLAY GRADES*********************
void display_grades(sub *head)
{
sub *p;
p=head;
char grade;
float total,sum=0,avg,count=0;

while(p->next!=NULL)
			{
			total=0;
			if(subj==1 || subj==4)
			total=((p->midsem1*0.5)+(p->midsem2*0.5)+(p->endsem*0.5)+((p->quiz1+p->quiz2+p->quiz3+p->quiz4+p->quiz5)*0.2));
			else if(subj==2 || subj==3 || subj==5)
			total=((p->midsem1*0.25)+(p->midsem2*0.25)+(p->endsem*0.6)+((p->quiz1+p->quiz2+p->quiz3+p->quiz4+p->quiz5)*0.2)+p->lab);
			sum+=total;		
			count++;
			
			p=p->next;
			
			}
			avg=sum/count;
			printf("average= %2.2f\n",avg);
			printf("ROLL NO\t\tName\t\tSPI\tGRADES\n");
			p=head;
			while(p->next!=NULL)
			{
			total=0;
			
			if(subj==1 || subj==4)
			total=((p->midsem1*0.5)+(p->midsem2*0.5)+(p->endsem*0.5)+((p->quiz1+p->quiz2+p->quiz3+p->quiz4+p->quiz5)*0.2));
			else if(subj==2 || subj==3 || subj==5)
			total=((p->midsem1*0.25)+(p->midsem2*0.25)+(p->endsem*0.6)+((p->quiz1+p->quiz2+p->quiz3+p->quiz4+p->quiz5)*0.2)+p->lab);
			
			if(total>avg+(100-avg)*0.7)
			grade='A';
			else if(total>=avg && total<=avg+(100-avg)*0.7)
			grade='B';
			else if(total>=avg-(avg*0.3) && total<avg)
			grade='C';
			else if(total<avg-(avg*0.3) && total>avg-(avg*0.6))
			grade='D';
			else if(total<avg-(avg*0.6))
			grade='F';
			
						
			printf("%11.11s\t",p->rollno1);
			printf("%s %s\t",p->firstname,p->lastname);
			printf("%2.2f\t",total);
			printf("%c\n",grade);
			p=p->next;
			}
}




//***********************************FUNCTION TO CALCULATE AND DISPLAY GRADES*************

void grade(void)
{


			printf("\nEnter the number corresponding to the subject whose grades are to be printed\n");
			printf("\n1-maths\n2-physics\n3-pds\n4-english\n5-eg\n");
			scanf("%d",&subj);
			sub *head;
			head=create_list();
			display_grades(head);
			
			
}


//*****************************************************************
//*************************CALCULATION OF SPI**********************
//*****************************************************************


//MAIN FUNCTION TO CALCULATE SPI

void spi(void)
{
sub *head_m;
sub *head_phy;
sub *head_pds;
sub *head_eng;
sub *head_eg;
head_m=link_maths();
head_phy=link_phy();
head_pds=link_pds();
head_eng=link_eng();
head_eg=link_eg();
transverse_spi(head_m,head_phy,head_pds,head_eng,head_eg);
}




//CREATING LINKED LISTS

sub *link_maths()
{
FILE *maths;
sub *p,*head;
if( (maths = fopen("MATHS.txt","r")) == NULL)
          printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
fseek(maths, 62, SEEK_SET);
while(!feof(maths))	
{
fscanf(maths,"%s %s %s %f %f %f %f %f %f %f %f %f ", p->rollno1, p->firstname, p->lastname, &p->midsem1, &p->midsem2, &p->endsem, &p->quiz1, &p->quiz2, &p->quiz3, &p->quiz4, &p->quiz5, &p->lab);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(maths);
}


sub *link_phy()
{
FILE *physics;
sub *p,*head;
if( (physics = fopen("PHYSICS.txt","r")) == NULL)
          printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
fseek(physics, 62, SEEK_SET);
while(!feof(physics))	
{
fscanf(physics,"%s %s %s %f %f %f %f %f %f %f %f %f ", p->rollno1, p->firstname, p->lastname, &p->midsem1, &p->midsem2, &p->endsem, &p->quiz1, &p->quiz2, &p->quiz3, &p->quiz4, &p->quiz5, &p->lab);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(physics);
}


sub *link_pds()
{
FILE *pds;
sub *p,*head;
if( (pds = fopen("PDS.txt","r")) == NULL)
           printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
fseek(pds, 62, SEEK_SET);
while(!feof(pds))	
{
fscanf(pds,"%s %s %s %f %f %f %f %f %f %f %f %f ", p->rollno1, p->firstname, p->lastname, &p->midsem1, &p->midsem2, &p->endsem, &p->quiz1, &p->quiz2, &p->quiz3, &p->quiz4, &p->quiz5, &p->lab);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(pds);
}

sub *link_eng()
{
FILE *english;
sub *p,*head;
if( (english = fopen("ENGLISH.txt","r")) == NULL)
          printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
fseek(english, 62, SEEK_SET);
while(!feof(english))	
{
fscanf(english,"%s %s %s %f %f %f %f %f %f %f %f %f ", p->rollno1, p->firstname, p->lastname, &p->midsem1, &p->midsem2, &p->endsem, &p->quiz1, &p->quiz2, &p->quiz3, &p->quiz4, &p->quiz5, &p->lab);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(english);
}

sub *link_eg()
{
FILE *eg;
sub *p,*head;
if( (eg = fopen("EG.txt","r")) == NULL)
          printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
fseek(eg, 62, SEEK_SET);
while(!feof(eg))	
{
fscanf(eg,"%s %s %s %f %f %f %f %f %f %f %f %f ", p->rollno1, p->firstname, p->lastname, &p->midsem1, &p->midsem2, &p->endsem, &p->quiz1, &p->quiz2, &p->quiz3, &p->quiz4, &p->quiz5, &p->lab);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(eg);
}


//TRANSVERSING LINKED LISTS

void transverse_spi(sub *head_m,sub *head_phy,sub *head_pds,sub *head_eng,sub *head_eg)
{
float total,sum=0,avg=0;
int count=0;					
float point=0;
char grade;
sub *p_m;
sub *p_phy;
sub *p_pds;
sub *p_eng;
sub *p_eg;
sub *p_totalspi;
p_m=head_m;
p_phy=head_phy;
p_pds=head_pds;
p_eng=head_eng;
p_eg=head_eg;
while(p_m->next!=NULL)
			{
			total=0;
			total=((p_m->midsem1)*0.5+(p_m->midsem2)*0.5+(p_m->endsem)*0.5+(p_m->quiz1+p_m->quiz2+p_m->quiz3+p_m->quiz4+p_m->quiz5)*0.2);
			sum+=total;		
			count++;
			
			p_m=p_m->next;
			}
		
			avg=sum/count;
			
			p_m=head_m;
			while(p_m->next!=NULL)
			{
			total=0;
			total=((p_m->midsem1*0.5)+(p_m->midsem2*0.5)+(p_m->endsem*0.5)+((p_m->quiz1+p_m->quiz2+p_m->quiz3+p_m->quiz4+p_m->quiz5)*0.2));

			if(total>avg+(100-avg)*0.7){
			grade='A';point=10;}
			else if(total>=avg && total<=avg+(100-avg)*0.7){
			grade='B';point=8;}
			else if(total>=avg-(avg*0.3) && total<avg){
			grade='C';point=6;}
			else if(total<avg-(avg*0.3) && total>avg-(avg*0.6)){
			grade='D';point=4;}
			else if(total<avg-(avg*0.6)){
			grade='F';point=2;}
			
			p_m->spi=(4*point)/21;	//computing individual spi of maths:21-total credits of all subjects::4:credit of maths
		
			p_m=p_m->next;
			}
			sum=0;
while(p_pds->next!=NULL)
			{
			total=0;
			total=((p_pds->midsem1)*0.5+(p_pds->midsem2)*0.5+(p_pds->endsem)*0.5+(p_pds->quiz1+p_pds->quiz2+p_pds->quiz3+p_pds->quiz4+p_pds->quiz5)*0.2);
			sum+=total;		
			count++;
		
			p_pds=p_pds->next;
			}
			
			avg=sum/count;
			
			p_pds=head_pds;
			while(p_pds->next!=NULL)
			{
			total=0;
			total=((p_pds->midsem1)*0.5+(p_pds->midsem2)*0.5+(p_pds->endsem)*0.5+(p_pds->quiz1+p_pds->quiz2+p_pds->quiz3+p_pds->quiz4+p_pds->quiz5)*0.2);

			if(total>avg+(100-avg)*0.7){
			grade='A';point=10;}
			else if(total>=avg && total<=avg+(100-avg)*0.7){
			grade='B';point=8;}
			else if(total>=avg-(avg*0.3) && total<avg){
			grade='C';point=6;}
			else if(total<avg-(avg*0.3) && total>avg-(avg*0.6)){
			grade='D';point=4;}
			else if(total<avg-(avg*0.6)){
			grade='F';point=2;}
			
			p_pds->spi=(4*point)/21;	//computing individual spi of pds:21-total credits of all subjects::4:credit of maths

			p_pds=p_pds->next;
			}

sum=0;
while(p_phy->next!=NULL)
			{
			total=0;
			total=((p_phy->midsem1)*0.5+(p_phy->midsem2)*0.5+(p_phy->endsem)*0.5+(p_phy->quiz1+p_phy->quiz2+p_phy->quiz3+p_phy->quiz4+p_phy->quiz5)*0.2);
			sum+=total;		
			count++;
			p_phy=p_phy->next;
			}
			avg=sum/count;
			
			p_phy=head_phy;
			while(p_phy->next!=NULL)
			{
			total=0;
			total=((p_phy->midsem1)*0.5+(p_phy->midsem2)*0.5+(p_phy->endsem)*0.5+(p_phy->quiz1+p_phy->quiz2+p_phy->quiz3+p_phy->quiz4+p_phy->quiz5)*0.2);

			if(total>avg+(100-avg)*0.7){
			grade='A';point=10;}
			else if(total>=avg && total<=avg+(100-avg)*0.7){
			grade='B';point=8;}
			else if(total>=avg-(avg*0.3) && total<avg){
			grade='C';point=6;}
			else if(total<avg-(avg*0.3) && total>avg-(avg*0.6)){
			grade='D';point=4;}
			else if(total<avg-(avg*0.6)){
			grade='F';point=2;}
			
			p_phy->spi=(4*point)/21;	//computing individual spi of physics:21-total credits of all subjects::4:credit of maths

			p_phy=p_phy->next;
			}

sum=0;
while(p_eng->next!=NULL)
			{
			total=0;
			total=((p_eng->midsem1)*0.5+(p_eng->midsem2)*0.5+(p_eng->endsem)*0.5+(p_eng->quiz1+p_eng->quiz2+p_eng->quiz3+p_eng->quiz4+p_eng->quiz5)*0.2);
			sum+=total;		
			count++;
			p_eng=p_eng->next;
			}
			avg=sum/count;
			p_eng=head_eng;
			while(p_eng->next!=NULL)
			{
			total=0;
			total=((p_eng->midsem1)*0.5+(p_eng->midsem2)*0.5+(p_eng->endsem)*0.5+(p_eng->quiz1+p_eng->quiz2+p_eng->quiz3+p_eng->quiz4+p_eng->quiz5)*0.2);

			if(total>avg+(100-avg)*0.7){
			grade='A';point=10;}
			else if(total>=avg && total<=avg+(100-avg)*0.7){
			grade='B';point=8;}
			else if(total>=avg-(avg*0.3) && total<avg){
			grade='C';point=6;}
			else if(total<avg-(avg*0.3) && total>avg-(avg*0.6)){
			grade='D';point=4;}
			else if(total<avg-(avg*0.6)){
			grade='F';point=2;}
			
			p_eng->spi=(4*point)/21;	//computing individual spi of english:21-total credits of all subjects::4:credit of maths
			p_eng=p_eng->next;
			}

sum=0;
while(p_eg->next!=NULL)
			{
			total=0;
			total=((p_eg->midsem1)*0.5+(p_eg->midsem2)*0.5+(p_eg->endsem)*0.5+(p_eg->quiz1+p_eg->quiz2+p_eg->quiz3+p_eg->quiz4+p_eg->quiz5)*0.2);
			sum+=total;		
			count++;
			p_eg=p_eg->next;
			}
			avg=sum/count;
			p_eg=head_eg;
			while(p_eg->next!=NULL)
			{
			total=0;
			total=((p_eg->midsem1)*0.5+(p_eg->midsem2)*0.5+(p_eg->endsem)*0.5+(p_eg->quiz1+p_eg->quiz2+p_eg->quiz3+p_eg->quiz4+p_eg->quiz5)*0.2);

			if(total>avg+(100-avg)*0.7){
			grade='A';point=10;}
			else if(total>=avg && total<=avg+(100-avg)*0.7){
			grade='B';point=8;}
			else if(total>=avg-(avg*0.3) && total<avg){
			grade='C';point=6;}
			else if(total<avg-(avg*0.3) && total>avg-(avg*0.6)){
			grade='D';point=4;}
			else if(total<avg-(avg*0.6)){
			grade='F';point=2;}
			
			p_eg->spi=(4*point)/21;	//computing individual spi of eg:21-total credits of all subjects::4:credit of maths
			
			p_eg=p_eg->next;
			}


FILE *spi4;	
spi4=fopen("SPI.txt","w");			//file to store spi
float spi3;
p_m=head_m;
p_phy=head_phy;
p_pds=head_pds;
p_eng=head_eng;
p_eg=head_eg;
printf("\nROLL NO.\tNAME\t\tSPI\n");
while(p_m->next!=NULL && p_phy->next!=NULL && p_pds->next!=NULL && p_eng->next!=NULL && p_eg->next!=NULL){
		spi3=0;
		spi3=p_m->spi+p_phy->spi+p_pds->spi+p_eng->spi+p_eg->spi;
			printf("\n%11.11s\t",p_eg->rollno1);
			printf("%s %s\t",p_eg->firstname,p_eg->lastname);
			printf("%2.2f",spi3);
			fprintf(spi4,"%11.11s %s %s %2.2f\n",p_eg->rollno1,p_eg->firstname,p_eg->lastname,spi3);
	p_eg=p_eg->next;		
	p_eng=p_eng->next;
	p_pds=p_pds->next;
	p_phy=p_phy->next;
	p_m=p_m->next;
}
fclose(spi4);
}



//*************************************FUNCTION TO ADD STUDENT RECORD******************

void add_student(void)
{
biodata1 student;
FILE *read;
read = fopen("BIODATA1.txt","a+");
    
printf("\nEnter student's information:\n");
printf("Roll No.\t\t:");
scanf("%s",student.rollno1);
printf("First Name\t\t:");
scanf("%s",student.firstname);
printf("Last Name\t\t:");
scanf("%s",student.lastname);
printf("Branch\t\t\t:");
scanf("%s",student.branch);
printf("Age\t\t\t:");
scanf("%s",student.age);
printf("Father's Name\t\t:");
scanf("%s",student.father);
printf("Mother's Name\t\t:");
scanf("%s",student.mother);
printf("Blood Group\t\t:");
scanf("%s",student.bgroup);
printf("Cell No.\t\t:");
scanf("%s",student.cellno);
printf("Address\t\t\t:");
scanf(" %s",student.address);

fseek(read,1,SEEK_END);
fprintf(read,"%s %s %s %s %s %s %s %s %s %s\n",student.rollno1,student.firstname,student.lastname,student.branch,student.age,student.father,student.mother,student.bgroup,student.cellno,student.address);
printf("\nRecord successfully added!!!!\n");
fclose(read);

}

//*********************FUNCTION TO DELETE STUDENT RECORD******************
void delete_student(char rno[12])
{
char a[15],b[15],c[15];
int ch;
biodata1 bio;
FILE *read,*dummy;
read=fopen("BIODATA1.txt","r");
dummy=fopen("tmp.txt","w");
printf("\nThe details of the student are:\n");
while(!feof(read))
{
fgets(bio.rollno1,12,read);
if(strcmp(rno,bio.rollno1)==0)
{
fseek(read,1,SEEK_CUR);
break;
}

}
fscanf(read,"%s %s %s %s %s %s %s %s ",bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno);
printf("\nNAME\t\t:\t%s %s",bio.firstname, bio.lastname);
printf("\nBRANCH\t\t:\t%s",bio.branch);
printf("\nAGE\t\t:\t%s",bio.age);
printf("\nFATHER'S NAME\t:\t%s",bio.father);
printf("\nMOTHER'S NAME\t:\t%s",bio.mother);
printf("\nBLOOD GROUP\t:\t%s",bio.bgroup);
printf("\nCELL NUMBER\t:\t%s",bio.cellno);
fseek(read,0,SEEK_CUR);
fgets(bio.address,1000,read);
printf("\nADDRESS\t\t:\t%s\n",bio.address);


printf("\nAre you sure you want to delete this record[1.Yes/2.N0]");
scanf("%d",&ch);
rewind(read);
if(ch==1)
{
while(!feof(read))
{
fscanf(read,"%s %s %s %s %s %s %s %s %s %s %s %s",bio.rollno1,bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno,a,b,c);
if(strcmp(bio.rollno1,rno)==0) continue;
fprintf(dummy,"%s %s %s %s %s %s %s %s %s %s %s %s\n",bio.rollno1,bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno,a,b,c);
}
fclose(dummy);
fclose(read);
dummy=fopen("tmp.txt","r");
read=fopen("BIODATA1.txt","w");
while(!feof(dummy))
{
fscanf(dummy,"%s %s %s %s %s %s %s %s %s %s %s %s",bio.rollno1,bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno,a,b,c);
fprintf(read,"%s %s %s %s %s %s %s %s %s %s %s %s \n",bio.rollno1,bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno,a,b,c);
}
printf("\nRecord successfully deleted!!!");
}
else
printf("\nRecord not deleted");
fclose(dummy);
fclose(read);
}

void edit_student(void)
{
char rno[12],a[15],b[15],c[15];
biodata1 bio;
FILE *read,*dummy;
read = fopen("BIODATA1.txt","r");
dummy=fopen("tmp.txt","w");
printf("\nEnter roll no of the student whose record is to be edited:");
scanf("%s",rno);
while(!feof(read))
{
fscanf(read,"%s %s %s %s %s %s %s %s %s %s %s %s ",bio.rollno1,bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno,a,b,c);
if(strcmp(bio.rollno1,rno)==0) continue;
fprintf(dummy,"%s %s %s %s %s %s %s %s %s %s %s %s\n",bio.rollno1,bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno,a,b,c);
}
fclose(dummy);
fclose(read);
dummy=fopen("tmp.txt","r");
read=fopen("BIODATA1.txt","w");
while(!feof(dummy))
{
fscanf(dummy,"%s %s %s %s %s %s %s %s %s %s %s %s",bio.rollno1,bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno,a,b,c);
fprintf(read,"%s %s %s %s %s %s %s %s %s %s %s %s \n",bio.rollno1,bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno,a,b,c);
}
fclose(dummy);
fclose(read);   
read = fopen("BIODATA1.txt","a+");
printf("\nEnter new data for student:\n");
printf("Roll No.\t\t:");
scanf("%s",bio.rollno1);
printf("First Name\t\t:");
scanf("%s",bio.firstname);
printf("Last Name\t\t:");
scanf("%s",bio.lastname);
printf("Branch\t\t\t:");
scanf("%s",bio.branch);
printf("Age\t\t\t:");
scanf("%s",bio.age);
printf("Father's Name\t\t:");
scanf("%s",bio.father);
printf("Mother's Name\t\t:");
scanf("%s",bio.mother);
printf("Blood Group\t\t:");
scanf("%s",bio.bgroup);
printf("Cell No.\t\t:");
scanf("%s",bio.cellno);
printf("Address\t\t\t:");
scanf("%s",bio.address);

fseek(read,1,SEEK_END);
fprintf(read,"%s %s %s %s %s %s %s %s %s %s\n",bio.rollno1,bio.firstname,bio.lastname,bio.branch,bio.age,bio.father,bio.mother,bio.bgroup,bio.cellno,bio.address);
printf("Information updated successfully!!!");
fclose(read);
}


//******************************Function to edit marks*******************//

void edit_marks(void)
{
char rno[12],a[15],b[15],c[15],topline[65];
sub bio,biot;
printf("\nEnter roll no of the student whose marks are to be updated:");
scanf("%s",rno);
FILE *read,*dummy;
//updation of maths marks
read=fopen("MATHS.txt","r");
dummy=fopen("tmp.txt","w");
fseek(read,62,0);
while(!feof(read))
{
fgets(bio.rollno1,12,read);
if(strcmp(bio.rollno1,rno)==0)
{ 
fseek(read,-12,SEEK_CUR);
break;
}
}
fscanf(read,"%s %s %s",biot.rollno1,biot.firstname,biot.lastname);
rewind(read);
fprintf(dummy,"ROLLNO FIRSTNAME LASTNAME mid1 mid2 endsem q1 q2 q3 q4 q5 lab\n");
fseek(read,62,0);
fseek(dummy,62,0);
while(!feof(read))
{
fscanf(read,"%s %s %s %f %f %f %f %f %f %f %f %f", bio.rollno1, bio.firstname, bio.lastname, &bio.midsem1, &bio.midsem2, &bio.endsem, &bio.quiz1, &bio.quiz2, &bio.quiz3, &bio.quiz4, &bio.quiz5, &bio.lab);
if(strcmp(bio.rollno1,rno)==0) continue;
fprintf(dummy,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", bio.rollno1, bio.firstname, bio.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
}
fclose(dummy);
fclose(read);
dummy=fopen("tmp.txt","r");
read=fopen("MATHS.txt","w");
fprintf(read,"ROLLNO FIRSTNAME LASTNAME mid1 mid2 endsem q1 q2 q3 q4 q5 lab\n");
fseek(dummy,62,0);
fseek(read,62,0);
while(!feof(dummy))
{
fscanf(dummy,"%s %s %s %f %f %f %f %f %f %f %f %f", bio.rollno1, bio.firstname, bio.lastname, &bio.midsem1, &bio.midsem2, &bio.endsem, &bio.quiz1, &bio.quiz2, &bio.quiz3, &bio.quiz4, &bio.quiz5, &bio.lab);
fprintf(read,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", bio.rollno1, bio.firstname, bio.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
}
fclose(dummy);
fclose(read);   
read = fopen("MATHS.txt","a+");
printf("\nEnter updated marks of maths for this student:\n");
printf("Mid-sem I\t\t:");
scanf("%f",&bio.midsem1);
printf("Mid-sem II\t\t:");
scanf("%f",&bio.midsem2);
printf("End-sem\t\t\t:");
scanf("%f",&bio.endsem);
printf("Quiz1\t\t\t:");
scanf("%f",&bio.quiz1);
printf("Quiz2\t\t\t:");
scanf("%f",&bio.quiz2);
printf("Quiz3\t\t\t:");
scanf("%f",&bio.quiz3);
printf("Quiz4\t\t\t:");
scanf("%f",&bio.quiz4);
printf("Quiz5\t\t\t:");
scanf("%f",&bio.quiz5);
fseek(read,1,SEEK_END);
bio.lab=0;
fprintf(read,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", biot.rollno1, biot.firstname, biot.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
printf("Marks updated successfully!!!");
fclose(read);


//***************TO UPDATE ENGLISH MARKS

read=fopen("ENGLISH.txt","r");
dummy=fopen("tmp.txt","w");
fseek(read,62,0);
while(!feof(read))
{
fgets(bio.rollno1,12,read);
if(strcmp(bio.rollno1,rno)==0)
{ 
fseek(read,-12,SEEK_CUR);
break;
}
}
fscanf(read,"%s %s %s",biot.rollno1,biot.firstname,biot.lastname);
rewind(read);
fprintf(dummy,"ROLLNO FIRSTNAME LASTNAME mid1 mid2 endsem q1 q2 q3 q4 q5 lab\n");
fseek(read,62,0);
fseek(dummy,62,0);
while(!feof(read))
{
fscanf(read,"%s %s %s %f %f %f %f %f %f %f %f %f", bio.rollno1, bio.firstname, bio.lastname, &bio.midsem1, &bio.midsem2, &bio.endsem, &bio.quiz1, &bio.quiz2, &bio.quiz3, &bio.quiz4, &bio.quiz5, &bio.lab);
if(strcmp(bio.rollno1,rno)==0) continue;
fprintf(dummy,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", bio.rollno1, bio.firstname, bio.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
}
fclose(dummy);
fclose(read);
dummy=fopen("tmp.txt","r");
read=fopen("ENGLISH.txt","w");
fprintf(read,"ROLLNO FIRSTNAME LASTNAME mid1 mid2 endsem q1 q2 q3 q4 q5 lab\n");
fseek(dummy,62,0);
fseek(read,62,0);
while(!feof(dummy))
{
fscanf(dummy,"%s %s %s %f %f %f %f %f %f %f %f %f", bio.rollno1, bio.firstname, bio.lastname, &bio.midsem1, &bio.midsem2, &bio.endsem, &bio.quiz1, &bio.quiz2, &bio.quiz3, &bio.quiz4, &bio.quiz5, &bio.lab);
fprintf(read,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", bio.rollno1, bio.firstname, bio.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
}
fclose(dummy);
fclose(read);   
read = fopen("ENGLISH.txt","a+");
printf("\nEnter updated marks of english for this student:\n");
printf("Mid-sem I\t\t:");
scanf("%f",&bio.midsem1);
printf("Mid-sem II\t\t:");
scanf("%f",&bio.midsem2);
printf("End-sem\t\t\t:");
scanf("%f",&bio.endsem);
printf("Quiz1\t\t\t:");
scanf("%f",&bio.quiz1);
printf("Quiz2\t\t\t:");
scanf("%f",&bio.quiz2);
printf("Quiz3\t\t\t:");
scanf("%f",&bio.quiz3);
printf("Quiz4\t\t\t:");
scanf("%f",&bio.quiz4);
printf("Quiz5\t\t\t:");
scanf("%f",&bio.quiz5);
fseek(read,1,SEEK_END);
bio.lab=0;
fprintf(read,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", biot.rollno1, biot.firstname, biot.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
printf("Marks updated successfully!!!");
fclose(read);



//***************TO UPDATE PHYSICS MARKS


read=fopen("PHYSICS.txt","r");
dummy=fopen("tmp.txt","w");
fseek(read,62,0);
while(!feof(read))
{
fgets(bio.rollno1,12,read);
if(strcmp(bio.rollno1,rno)==0)
{ 
fseek(read,-12,SEEK_CUR);
break;
}
}
fscanf(read,"%s %s %s",biot.rollno1,biot.firstname,biot.lastname);
rewind(read);
fprintf(dummy,"ROLLNO FIRSTNAME LASTNAME mid1 mid2 endsem q1 q2 q3 q4 q5 lab\n");
fseek(read,62,0);
fseek(dummy,62,0);
while(!feof(read))
{
fscanf(read,"%s %s %s %f %f %f %f %f %f %f %f %f", bio.rollno1, bio.firstname, bio.lastname, &bio.midsem1, &bio.midsem2, &bio.endsem, &bio.quiz1, &bio.quiz2, &bio.quiz3, &bio.quiz4, &bio.quiz5, &bio.lab);
if(strcmp(bio.rollno1,rno)==0) continue;
fprintf(dummy,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", bio.rollno1, bio.firstname, bio.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
}
fclose(dummy);
fclose(read);
dummy=fopen("tmp.txt","r");
read=fopen("PHYSICS.txt","w");
fprintf(read,"ROLLNO FIRSTNAME LASTNAME mid1 mid2 endsem q1 q2 q3 q4 q5 lab\n");
fseek(dummy,62,0);
fseek(read,62,0);
while(!feof(dummy))
{
fscanf(dummy,"%s %s %s %f %f %f %f %f %f %f %f %f", bio.rollno1, bio.firstname, bio.lastname, &bio.midsem1, &bio.midsem2, &bio.endsem, &bio.quiz1, &bio.quiz2, &bio.quiz3, &bio.quiz4, &bio.quiz5, &bio.lab);
fprintf(read,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", bio.rollno1, bio.firstname, bio.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
}
fclose(dummy);
fclose(read);   
read = fopen("PHYSICS.txt","a+");
printf("\nEnter updated marks of physics for this student:\n");
printf("Mid-sem I\t\t:");
scanf("%f",&bio.midsem1);
printf("Mid-sem II\t\t:");
scanf("%f",&bio.midsem2);
printf("End-sem\t\t\t:");
scanf("%f",&bio.endsem);
printf("Quiz1\t\t\t:");
scanf("%f",&bio.quiz1);
printf("Quiz2\t\t\t:");
scanf("%f",&bio.quiz2);
printf("Quiz3\t\t\t:");
scanf("%f",&bio.quiz3);
printf("Quiz4\t\t\t:");
scanf("%f",&bio.quiz4);
printf("Quiz5\t\t\t:");
scanf("%f",&bio.quiz5);
printf("LAB-Evaluation\t\t:");
scanf("%f",&bio.lab);
fseek(read,1,SEEK_END);
fprintf(read,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", biot.rollno1, biot.firstname, biot.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
printf("Marks updated successfully!!!");
fclose(read);




//***************TO UPDATE PDS MARKS


read=fopen("PDS.txt","r");
dummy=fopen("tmp.txt","w");
fseek(read,62,0);
while(!feof(read))
{
fgets(bio.rollno1,12,read);
if(strcmp(bio.rollno1,rno)==0)
{ 
fseek(read,-12,SEEK_CUR);
break;
}
}
fscanf(read,"%s %s %s",biot.rollno1,biot.firstname,biot.lastname);
rewind(read);
fprintf(dummy,"ROLLNO FIRSTNAME LASTNAME mid1 mid2 endsem q1 q2 q3 q4 q5 lab\n");
fseek(read,62,0);
fseek(dummy,62,0);
while(!feof(read))
{
fscanf(read,"%s %s %s %f %f %f %f %f %f %f %f %f", bio.rollno1, bio.firstname, bio.lastname, &bio.midsem1, &bio.midsem2, &bio.endsem, &bio.quiz1, &bio.quiz2, &bio.quiz3, &bio.quiz4, &bio.quiz5, &bio.lab);
if(strcmp(bio.rollno1,rno)==0) continue;
fprintf(dummy,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", bio.rollno1, bio.firstname, bio.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
}
fclose(dummy);
fclose(read);
dummy=fopen("tmp.txt","r");
read=fopen("PDS.txt","w");
fprintf(read,"ROLLNO FIRSTNAME LASTNAME mid1 mid2 endsem q1 q2 q3 q4 q5 lab\n");
fseek(dummy,62,0);
fseek(read,62,0);
while(!feof(dummy))
{
fscanf(dummy,"%s %s %s %f %f %f %f %f %f %f %f %f", bio.rollno1, bio.firstname, bio.lastname, &bio.midsem1, &bio.midsem2, &bio.endsem, &bio.quiz1, &bio.quiz2, &bio.quiz3, &bio.quiz4, &bio.quiz5, &bio.lab);
fprintf(read,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", bio.rollno1, bio.firstname, bio.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
}
fclose(dummy);
fclose(read);   
read = fopen("PDS.txt","a+");
printf("\nEnter updated marks of PDS for this student:\n");
printf("Mid-sem I\t\t:");
scanf("%f",&bio.midsem1);
printf("Mid-sem II\t\t:");
scanf("%f",&bio.midsem2);
printf("End-sem\t\t\t:");
scanf("%f",&bio.endsem);
printf("Quiz1\t\t\t:");
scanf("%f",&bio.quiz1);
printf("Quiz2\t\t\t:");
scanf("%f",&bio.quiz2);
printf("Quiz3\t\t\t:");
scanf("%f",&bio.quiz3);
printf("Quiz4\t\t\t:");
scanf("%f",&bio.quiz4);
printf("Quiz5\t\t\t:");
scanf("%f",&bio.quiz5);
printf("LAB-Evaluation\t\t:");
scanf("%f",&bio.lab);
fseek(read,1,SEEK_END);
fprintf(read,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", biot.rollno1, biot.firstname, biot.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
printf("Marks updated successfully!!!");
fclose(read);




//***************TO UPDATE EG MARKS


read=fopen("EG.txt","r");
dummy=fopen("tmp.txt","w");
fseek(read,62,0);
while(!feof(read))
{
fgets(bio.rollno1,12,read);
if(strcmp(bio.rollno1,rno)==0)
{ 
fseek(read,-12,SEEK_CUR);
break;
}
}
fscanf(read,"%s %s %s",biot.rollno1,biot.firstname,biot.lastname);
rewind(read);
fprintf(dummy,"ROLLNO FIRSTNAME LASTNAME mid1 mid2 endsem q1 q2 q3 q4 q5 lab\n");
fseek(read,62,0);
fseek(dummy,62,0);
while(!feof(read))
{
fscanf(read,"%s %s %s %f %f %f %f %f %f %f %f %f", bio.rollno1, bio.firstname, bio.lastname, &bio.midsem1, &bio.midsem2, &bio.endsem, &bio.quiz1, &bio.quiz2, &bio.quiz3, &bio.quiz4, &bio.quiz5, &bio.lab);
if(strcmp(bio.rollno1,rno)==0) continue;
fprintf(dummy,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", bio.rollno1, bio.firstname, bio.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
}
fclose(dummy);
fclose(read);
dummy=fopen("tmp.txt","r");
read=fopen("EG.txt","w");
fprintf(read,"ROLLNO FIRSTNAME LASTNAME mid1 mid2 endsem q1 q2 q3 q4 q5 lab\n");
fseek(dummy,62,0);
fseek(read,62,0);
while(!feof(dummy))
{
fscanf(dummy,"%s %s %s %f %f %f %f %f %f %f %f %f", bio.rollno1, bio.firstname, bio.lastname, &bio.midsem1, &bio.midsem2, &bio.endsem, &bio.quiz1, &bio.quiz2, &bio.quiz3, &bio.quiz4, &bio.quiz5, &bio.lab);
fprintf(read,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", bio.rollno1, bio.firstname, bio.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
}
fclose(dummy);
fclose(read);   
read = fopen("EG.txt","a+");
printf("\nEnter updated marks of EG for this student:\n");
printf("Mid-sem I\t\t:");
scanf("%f",&bio.midsem1);
printf("Mid-sem II\t\t:");
scanf("%f",&bio.midsem2);
printf("End-sem\t\t\t:");
scanf("%f",&bio.endsem);
printf("Quiz1\t\t\t:");
scanf("%f",&bio.quiz1);
printf("Quiz2\t\t\t:");
scanf("%f",&bio.quiz2);
printf("Quiz3\t\t\t:");
scanf("%f",&bio.quiz3);
printf("Quiz4\t\t\t:");
scanf("%f",&bio.quiz4);
printf("Quiz5\t\t\t:");
scanf("%f",&bio.quiz5);
printf("LAB-Evaluation\t\t:");
scanf("%f",&bio.lab);
fseek(read,1,SEEK_END);
fprintf(read,"%s %s %s %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f %2.2f\n", biot.rollno1, biot.firstname, biot.lastname, bio.midsem1, bio.midsem2, bio.endsem, bio.quiz1, bio.quiz2, bio.quiz3, bio.quiz4, bio.quiz5, bio.lab);
printf("Marks updated successfully!!!");
fclose(read);
}




//FUNCTION TO PRINT SPECIAL ACHIEVEMENTS
void achievement(void)
{
FILE *ach;
ach=fopen("ACH.txt","r");
char line[200];
printf("\nSPECIAL ACHIEVEMENTS\n");
while(!feof(ach))
{
fgets(line,200,ach);
printf("%s",line);
}
fclose(ach);
}





//****************SCHOLARSHIP*****************//
void scholarship(void)
{
printf("\nSPI of students is as follows:\n");
spi();
sub *head;
head=link_spi();
t_spi(head);
}


sub *link_spi()
{
FILE *spi;
sub *p,*head;
if( (spi = fopen("SPI.txt","r")) == NULL)
          printf("File cannot be opened\n");
head=(sub *)malloc(sizeof(sub));
p=head;
while(!feof(spi))	
{
fscanf(spi,"%s %s %s %f", p->rollno1, p->firstname, p->lastname, &p->spi);
p->next=(sub*)malloc(sizeof(sub));
p=p->next;
}
p->next=NULL;
return(head);
fclose(spi);
}


void t_spi(sub *head_spi)
{
sub *p_spi;
p_spi=head_spi;
printf("\nStudents those who have been awarded scholarship are: \n");
while(p_spi->next!=NULL)
			{
		
			if((p_spi->spi)>9.00)
			{printf("\n%11.11s %s %s ",p_spi->rollno1, p_spi->firstname, p_spi->lastname);
			}		
			p_spi=p_spi->next;

			}
}


