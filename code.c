poly
string
sll
seq
dll


sll

#include<stdio.h>
#include<malloc.h>
typedef struct node
   {
	int data;
	struct node *next;    //SELF REFERENTIAL POINTER
   }node;

 node* create();
 void display(node*);
 node* insert_beg(node*,int);
 node* insert_end(node*,int);
 void insert_bet(node*,int);
 node* delete_any(node*);
 void print_reverse(node *p);
 node* reverse(node *head);

 void main()
    {
	int ch,ch1,d;
	node *head;
	head=NULL;
	
     do
      {
	printf("\n***********SINGLY LINKED LIST***********");
	printf("\n1.Create SLL\n2.Display SLL\n3.Insert Element\n4.Delete Element\n5.Print Reverse SLL\n6.Reverse\n7.Exit");
	printf("\n Enter your choice:\n");
	scanf("%d",&ch);	
       switch(ch)
         {
	 case 1:
		head=create();
		break;
	 case 2:
		display(head);
		break;
	 case 3:
		printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert in Between");
		printf("\n Enter your choice:\n");
		scanf("%d",&ch1);

		printf("\n Enter data to insert:\n");
		scanf("%d",&d);

		switch(ch1)
		 {
		  case 1:
		        head=insert_beg(head,d);
			break;
		  case 2:
		        head=insert_end(head,d);
			break;
		  case 3:
		        insert_bet(head,d);
			break;
		 }
		  break;
	 case 4:
		head=delete_any(head);
		break;
	 case 5:
		printf("\nReversed List is:\n");
		print_reverse(head);
		break;
	 case 6:
		head=reverse(head);
		break;
	 }
       }while(ch!=7);
     }

   //**********Create SLL***********
    node* create()
     {
	node *head,*p,*last;
	int n,i;
	head=NULL;
	printf("\n Enter No. Of Nodes In SLL:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	 p=(node*)malloc(sizeof(node));
	 p->next=NULL;
	 printf("\n Enter The Data:\n");
	 scanf("%d",&p->data);

	if(head==NULL)
	 {
	   head=p;
	   last=p;
	 }
	else
	 {
	   last->next=p;
	   last=p;
	 }
	}
	return(head);
     }

    //**********Display List***********
     void display(node *head)
      {
	node *p;
	if(head==NULL)
	printf("\n SLL is Empty!!!!!!!!");
	else
       {
	printf("\n SLL is:\n");
	p=head;
	while(p!=NULL)
	{
	printf("%d->",p->data);	
	p=p->next;
	}
       }
      }

    //***********Insert at Beginning Of List***********
     node* insert_beg(node *head,int d)
      {
	node *p;
	p=(node*)malloc(sizeof(node));
	 p->data=d;
	if(head==NULL)
	
	head=p;
	
	else
	{
	 p->next=head;
	 head=p;
	}
	printf("\n Node Added Successfully........");
	display(head);
	return(head);
      }

     //***********Insert at End Of List***********
     node* insert_end(node *head,int d)
      {
	node *p,*q;
	p=(node*)malloc(sizeof(node));
	p->data=d;
	p->next=NULL;

	if(head==NULL)
	{
	head=p;
	}
	else
	{
	 q=head;
	 while(q->next!=NULL)
	 q=q->next;
	 q->next=p;
	}
	printf("\n Node Added Successfully........");
	display(head);
	return(head);
      }

    //***********Insert in Between Of List***********
     void insert_bet(node *head,int d)
      {
	node *p,*q,*r;
	int sd;
	printf("\n Enter data after which u want to insert new node:\n");
	scanf("%d",&sd);
	p=(node*)malloc(sizeof(node));
	p->data=d;
	p->next=NULL;
	q=head;
	while(q!=NULL)
	{
	 if(q->data==sd)
	{
	r=q->next;
	q->next=p;
	p->next=r;
	
	printf("\n Node added successfully........");
	display(head);
	return;
	}
	else
	q=q->next;
	}

	printf("\n Data after which node inserted not found........");
      }

    //***********Delete Any Node***********
      node* delete_any(node *head)
       {
	node *p,*prev;
	int sd;
	if(head==NULL)
	printf("\n Not Deleted Because Empty SLL........");
	else
	 {
  	  printf("\n Enter Data to Delete:\n");
	  scanf("%d",&sd);
	 p=prev=head;
	 while(p!=NULL)
	 {
	  if(p->data==sd)
	  {
	   if(head==p)
	     head=head->next;
	else
	prev->next=p->next;
	free(p);
	printf("\n Node deleted successfully........");
	display(head);
	return(head);
	}
	else
	prev=p;
	p=p->next;
	}
        }
	printf("\n Node not found.......");
	return(head);
       }

    void print_reverse(node *p)
     {
       if(p->next!=NULL)
	print_reverse(p->next);
	
	printf("\n%d->",p->data);
     }

    node* reverse(node *head)
     {
	node *p,*q,*r;
	if(head==NULL)
	{
	 printf("SLL is Empty!!!!!!!!");
	 return(head);
	}
	p=NULL;
	q=head;
	r=q->next;
	while(q!=NULL)
	{
	q->next=p;
	p=q;
	q=r;
 	
       if(q!=NULL)
	r=q->next;
        }
	head=p;
	display(head);
	return(head);
     }

string op

 /*Perform following operations with and without pointers to arrays(without using library
functions):a.substring, b.pallindrome, c.compare, d.copy, e.reverse.*/

#include<stdio.h>

void length(char str1[20],char str2[20])
{
int l,i;
l=0;
i=0;
while(str1[i]!='\0')
{
l++;
i++;
}
printf("\n length of first string=%d",l);

l=0;
i=0;
while(str2[i]!='\0')
{
l++;
i++;
}
printf("\n length of second string=%d\n",l);
}
void palindrome(char str[20])
{
  int i,j;
  j=0;
  while(str[j]!='\0')
  {
    j=j+1;
    j=j+1;
  }
  j=j-1;
  i=0;
  while(i<j)
  {
    temp=str[i];
    str[i]=str[j];
    str[j]=temp;
    i++;
    j--;
  }
  printf("\nReverse of string:%s",str);
}


void copy(char str[20],char str1[20])
{
  int i;
  i=0;
  while(str[i]!='\0')
  {
    str1[i]=str[i];
    i++;
  }
  str1[i]='\0';
  printf("\n\nCopied string is:%s",str1);
}

int compare(char str1[20],char str2[20])
{
  int i=0;
  while(str1[i]!='\0' && str2[i]!='\0')
  {
    if(str1[i]!=str2[i])
    {
      break;
    }
    i=i+1;
  }
  return(str1[i]-str2[i]);
}


void substring(char str1[20],char str2[20])
{
  int i,j,k;
  k=0;
  j=0;
  while(str1[k]!='\0' && str2[j]!='\0')
  {
    i=k;
    j=0;
    while(str1[i]!='\0' && str2[j]!='\0')
    {
      if(str1[i]!=str2[j])
      {
	break;
      }
      i++;
      j++;
    }
    k=k+1;
  }
  if(str2[j]=='\0')
  {
    printf("\n\nString is substring");
  }
  else
  {
    printf("\n\nString is not a substring");
  }
}


void main()
{
 int ch;
 char string1[20],string2[20],string3[20],choice;

 printf("\nenter string 1:");
scanf("%s",string1);
 printf("\nenter string 2:");
 scanf("%s",string2);
do
 {
   printf("\n1] Length \n2]palindrome\n3]compare\n4]copy without pointers\n5]reverse without pointers\n6]Find substring");
   
   printf("\nenter your choice:");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:length(string1,string2);
	    break;
     case 2:palindrome(string1);
	    break;
     case 3:if(compare(string1,string2)==0)
	    {
	      printf("\nstrings are same");
	    }
	    else
	    {
	      printf("\nstrings are not same");
	    }

	    break;
     case 4:copy(string1,string3);
	    break;
     case 5:reverse(string1);
            printf("\n string=%s",string1);
	    break;
     case 6:substring(string1,string2);
	    break;
   }
printf("\n\n DO U WANT TO CONTINUE(y/n)");
scanf(" %c",&choice);

 }while(choice=='y');

} }
Void palindrome(char str[20])
  j=j-1;

  i=0;
  while(i<j)
  {
    if(str[i]!=str[j])
    {
      printf("\n\n%s is not a palindrome",str);
      return;
    }
    i++;
    j--;
  }
  printf("\n\n%s is palindrome",str);
}

void reverse(char str[20])
{
  int i,j;
  char temp;
  j=0;
  while(str[j]!='\0')
  {
 

dll

#include<stdio.h>
#include<malloc.h>

typedef struct node
{
   int rno;
   char name[20];
   float per;
   struct node *next;
     struct node *prev;
}node;

node* create();
void display(node*);
node* insert(node*);
node* delete_any(node*);
void modify(node*);
void reverse(node*);



void main()
{
  int ch,ch1,d;
  node *head;
  head=NULL;
  do
  {
    printf("\n********DATABASE USING DOUBLY LINKED LIST *************");
    printf("\n1.create Database\n2.Display Database\n3.Insert Record\n4.Delete Record\n5.Modify Record\n6.print Records in Reverse \n7.Exit");
    printf("\nENTER UR CHOICE");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1: head=create();
             break;
     case 2:display(head);
             break;
    case 3:head=insert(head);
                    break;
             
     case 4:head=delete_any(head);
             break;
    case 5:modify(head);
            break;
    case 6:reverse(head);
            break;




    }
  }while(ch!=7);

}

//***** CREATE SLL*************
 node* create()
{
  node *head,*p,*last;
  int n,i;
float f;
  head=NULL;
  printf("\n ENTER NO.OF students in database");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    
    p=(node*) malloc(sizeof(node));
    p->next=NULL;
    p->prev=NULL;
    printf("\n ENTER rno,name and percentage of student");
    scanf("%d%s%f",&p->rno,p->name,&f);
    p->per=f;
   if(head==NULL)
      {     
	head=p;
        last=p;
      }
   else
      {
       last->next=p;
       p->prev=last;
       last=p;
      }
  }
    
  return(head);
 }


//*****DISPLAY LIST ***************

void display(node *head)
{
  node *p;
  if(head==NULL)
   printf("\n DATABASE IS EMPTY !!!!!!!!!!!!");
  else
  {
   printf("\n DATABASE is  :");
printf("\nROLL no.\tName\t  percentage");
   p=head;
   
   while(p!=NULL)
   {
    printf("\n%d\t\t%s\t  %f",p->rno,p->name,p->per);
    p=p->next;
   }
  }
}

//*****Insert in between of List *********

node* insert(node *head)
{
 node *p,*q, *r;
float f;
r=NULL;
p=(node*) malloc(sizeof(node));
p->next=NULL;
p->prev=NULL;
printf("\n ENTER rno,name and percentage of student");
scanf("%d%s%f",&p->rno,p->name,&f);
p->per=f;
if(head==NULL)
head=p;
else
{
q=head;
while(q!=NULL)
{
 if(q->rno < p->rno)
  {
  r=q;
  q=q->next;
  }
  else
  {
    p->next=q;
    q->prev=p;
    if(q==head)
    head=p;
    else
    {
    r->next=p;
    p->prev=r;
    }   
    
    break;
 }
}
if(q==NULL)
{
 r->next=p;
 p->prev=r;
}

}

printf("\nRecord inserted Successfully................");
display(head);
return(head);
}

// Delete a Record**********************************
node* delete_any(node *head)
{
  node *p,*pr;
   int sd;
  if(head==NULL)
   printf("\n NOT DELETED... BCOZ EMPTY DATABASE.........");
  else
   {
     printf("\nEnterRollno.to delete");
      scanf("%d",&sd);
     p=pr=head;
    while(p!=NULL)
    {
       if(p->rno==sd)
        {
         if(head==p)
          {
          head=head->next;
          head->prev=NULL;
         }
         else
         {
        
         pr->next=p->next;
         if(p->next!=NULL)
         p->next->prev=pr;
         }
         free(p);
         printf("\nRecord deleted Successfully.................");
         display(head);
         return(head);
        }
        else
        {
          pr=p;
          p=p->next;
        }
           
     }
printf("\n Record not found.................");
  return(head);
}
}

void modify(node *head)
{
  node *p,*pr;
  float percentage;
   int sd;
  if(head==NULL)
   printf("\n...  NO RECORDS IN LIST.........");
  else
   {
     printf("\nEnter Rollno.to modify");
      scanf("%d",&sd);
     p=pr=head;
    while(p!=NULL)
    {
       if(p->rno==sd)
        {
         printf("\n Enter new Roll no., Name, percentage");
         scanf("%d%s%f",&p->rno,p->name,&percentage);
         p->per=percentage;
         printf("\nRecord modified Successfully.................");
         display(head);
         return;
        
        }
        else
        {
          pr=p;
          p=p->next;
        }
           
     }
printf("\n Record not found.................");

}
}




void reverse(node *head)
{
 node *p;
if(head==NULL)
 {
  printf("\n LIST IS EMPTY!!!!!!!!!!");
  return;
 }
 p=head;

 while(p->next!=NULL)
 {
  p=p->next;
 }
printf("\n Records in reverse order: \n");
printf("\nROLL no.\tName\t  percentage");
 while(p!=NULL)
 {
  printf("\n%d\t\t%s\t  %f",p->rno,p->name,p->per);
  p=p->prev;
 }
}


poly



/*
 Represent a Polynomal using a circular linked list and write
 menu driven program to perform addition,multiplication and
 evaluation.
*/
#include <stdio.h>
#include<malloc.h>
#include <math.h>
 
typedef struct  node
 { int power;
  int coeff;
   struct node *next;
 }node;
 
      node *  insert(node *head,int power1,int coeff1);
      node *  create();
      node *  padd(node *p1,node *p2);
      node *  pmul(node *p1,node *p2);
      float eval(node *p1,int x);
      void print(node *head);
int power(int x,int p);
 
 
node *insert(node *head,int power1,int coeff1)
      {  node *p,*q;
     /*terms are store in increasing order of power*/
     /*pointer is used to locate the correct place of insertion.
       pointer p is used to store the address of the node created for
       the current term.If a term with same power is found,coefficients
       are added*/
       p=(node*) malloc(sizeof(node));
       p->power=power1;
       p->coeff=coeff1;
       p->next=NULL;
       if(head==NULL)
     {
          head=p;
          head->next=head;
          return(head);
     }
       if(power1>head->power)
      {
          p->next=head->next;
          head->next=p;
          head=p;
          return(head);
      }
       if(power1==head->power)
      {
          head->coeff=head->coeff+coeff1;
          return(head);
      }
 
     q=head;
     while(q->next!=head && power1>=q->next->power)
           q=q->next;
     if(p->power==q->power)
           q->coeff=q->coeff+coeff1;
     else
       {
           p->next=q->next;
           q->next=p;
       }
    return(head);
  }
 
 
 node *create()
   {
       int n,i,power1;
      int coeff1;
       node *head=NULL;
       printf("\nEnter No. of Terms:");
       scanf("%d",&n);
       printf("\nenter a term as a tuple of (power,coefficient) : ");
       for(i=1;i<=n;i++)
     {   scanf("%d%d",&power1,&coeff1);
         head=insert(head,power1,coeff1);
     }
       return(head);
  }
 
 node * padd(node *p1,node *p2)
 {   node *p;
     node *head=NULL;
     int power, coeff;
     p=p1->next;
     do
     {
         head=insert(head,p->power,p->coeff);
         p=p->next;
     } while(p!=p1->next);
     p=p2->next;
     do
     {
         head=insert(head,p->power,p->coeff);
         p=p->next;
     } while(p!=p2->next);
     return(head);
  }
 
 node *pmul(node *p1,node *p2)
 {   node *head1,*head2;
     node *head=NULL;
     head2=p2->next;
      do
       {  head1=p1->next;
      do
        {
 // for(p=head1;p!=NULL;p=p->next)
         head=insert(head,head1->power+head2->power,head1->coeff * head2->coeff);
         head1=head1->next;
       }while(head1!=p1->next);
    head2=head2->next;
       }while(head2!=p2->next);
     return(head);
 }
 
 float eval(node *head,int x)
 {  int value=0;
    node *p;
    p=head->next;
    do
       {  value=value+p->coeff * power(x,p->power);
      p=p->next;
       }while(p!=head->next);
    return(value);
 }
 
 void print( node *head)
 {  node *p;
    p=head->next;
    printf("\n");
    do
     {
    printf("%dx^%d+",p->coeff,p->power);
    p=p->next;
     }while(p!=head->next);
 }

int power(int x,int p)
{
  int i,pow1=1;
 for(i=1;i<=p;i++)
  pow1=pow1*x;
return(pow1);
}
 
 
 void main()
 { node *p1,*p2,*p3;
   int op;
 int value,x;
   p1=p2=p3=NULL;
   
   do
     { printf("\n\n\n1)Create first polynomial");
       printf("\n2)Create second polynomial");
       printf("\n3)Print first polynomial");
       printf("\n4)Print second polynomial");
       printf("\n5)Add\n6)Multiply\n7)Evaluate First Polynomial\n8)Quit");
       printf("\nEnter Your Choice: ");
       scanf("%d",&op);
       switch(op)
    { case 1: p1=create();break;
      case 2: p2=create();break;
      case 3:printf("\n\n First Polynomial: ");
             print(p1);
		break;
      case 4:  printf("\n\n Second Polynomial: ");
             print(p2);
		break;
      case 5: p3=padd(p1,p2);
		printf("\n\n First Polynomial: ");
             print(p1);
	    printf("\nSecond Polynomial: ");
             print(p2);
		printf("\nAddition of Polynomials: ");
          print(p3);break;
      case 6: p3=pmul(p1,p2);
             printf("\n\n First Polynomial: ");
             print(p1);
	    printf("\n\n Second Polynomial: ");
             print(p2);
		printf("\n\n Multiplication of Polynomials: ");
          print(p3);break;
      case 7: printf("\nEnter the value of X:");
          scanf("%d",&x);
          value=eval(p1,x);
	printf("\n\n First Polynomial: ");
             print(p1);
          printf("\nEvaluated value = %d",value);
          break;
      }
       }while(op!=8);
 }


employee

#include<stdio.h>
#include<string.h>
struct employee
{
int id;
char name[20];
float salary;
};
void create();
void display();
int add();
void search();
void modify();
int delete();
FILE *fp;
int main()
{
int choice;
int n,ch;
printf("..................EMPLOYEE DATABASE...............");
do
{
printf("\n1.CREATE DATABASE\n2.DISPLAY DATABASE\n3.ADD RECORD\n4.SEARCH RECORD\n5.MODIFY RECORD\n6.DELETE RECORD");
printf("\nENTER UR CHOICE:");
scanf("%d",&ch);
switch(ch)
{
case 1 : create();
         break;
case 2 : display();
         break;
case 3 : if(add()==1);
           {
             printf("RECORD ADDED SUCCESSFULLY....");
             display();
            }
         break;
case 4 : search();
         break;
case 5 : modify();
         display();
         break;
case 6 : if(delete()==1)
            {
             printf("RECORD DELETED SUCCESSFULLY....");
             display();
             }
         break;
}
printf("\nDO U WANTS TO CONTINUE(1/0)");
scanf("%d",&choice);
}
while(choice==1);
return 0;
}
//CREATE DATABASE
void create()
{
int i,n;
float p1;
struct employee emp;
fp=fopen("abc.txt","w");
printf("\nENTER HOW MANY RECORD:");
scanf("%d",&n);
if(fp!=NULL)
{
printf("\nENTER %d EMPLOYEE DATA(ID,NAME,SALARY) : ",n);
for(i=0;i<n;i++)
{
scanf("\n%d%s%f",&emp.id,emp.name,&p1);
emp.salary=p1;
fprintf(fp,"\n%d\t%s\t%f",emp.id,emp.name,emp.salary);
}
printf("\nDATABASE CREATED SUCCESSFULLY.....");
fclose(fp);
}
else
{
printf("FILE IS NOT CREATED...");
}
}
//DISPLAY DATABASE
void display()
{
int i;
struct employee emp;
fp=fopen("abc.txt","r");
if(fp!=NULL)
{
printf("..................EMPLOYEE DATABASE...............");
printf("\nID\tNAME\tSALARY");
while(!feof(fp))
{
fscanf(fp,"\n%d\t%s\t%f",&emp.id,emp.name,&emp.salary);
printf("\n%d\t%s\t%f",emp.id,emp.name,emp.salary);
}
fclose(fp);
}
else
{
printf("\nFILE IS NOT OPENED.......");
}
}
//ADD DATABASE
int add()
{
 //float p1;
 struct employee emp;
 fp=fopen("abc.txt","a");
 printf("\nENTER EMPLOYEE DATA(ID,NAME,SALARY) :");
 scanf("%d%s%f",&emp.id,emp.name,&emp.salary);
 //emp.salary=p1;
 fprintf(fp,"\n%d\t%s\t%f",emp.id,emp.name,emp.salary);
 fclose(fp);
 return 1;
}
//SERACH DATABASE
void search()
{
int id;
struct employee emp;
fp=fopen("abc.txt","r");
printf("ENTER EMPLOYEE ID TO SREACH:");
scanf("%d",&id);
while(!feof(fp))
{
fscanf(fp,"%d%s%f",&emp.id,emp.name,&emp.salary);
if(emp.id==id)
{
printf("\nRECORD FOUND...");
printf("\n%d\t%s\t%f",emp.id,emp.name,emp.salary);
fclose(fp);
}
}
printf("\nRECORD NOT FOUND.....");
}
//MODIFY DATABASE
void modify()
{
int id,flag=0;
float p1;
struct employee emp;
FILE *fp1;
fp=fopen("abc.txt","r");
fp1=fopen("new.txt","w");
printf("\nENTER EMPLOYEE ID TO MODIFY...");
scanf("%d",&id);
while(!feof(fp))
{
fscanf(fp,"%d%s%f",&emp.id,emp.name,&emp.salary);
if(emp.id==id)
{
printf("\nRECORD FOUND..");
printf("\nENTER NEW ID,NAME,SALARY");
scanf("%d%s%f",&emp.id,emp.name,&p1);
emp.salary=p1;
flag=1;
}
fprintf(fp1,"\n%d%s%f",emp.id,emp.name,emp.salary);
}
fclose(fp);
fclose(fp1);
if(flag==1)
{
printf("RECORD FOUND.....");
fp=fopen("abc.txt","w");
fp1=fopen("new.txt","r");
while(!feof(fp1))
{
fscanf(fp1,"%d%s%f",&emp.id,emp.name,&emp.salary);
fprintf(fp,"\n%d%s%f",emp.id,emp.name,emp.salary);
}
fclose(fp);
fclose(fp1);
}
else
{
printf("RECORD NOT FOUND.....");
}
}
//DELETE DATABASE
int delete()
{
int id,flag=0;
struct employee emp;
FILE *fp1;
fp=fopen("abc.txt","r");
fp1=fopen("new.txt","w");
printf("\nENTER EMPLOYEE ID TO DELETE");
scanf("%d",&id);
while(!feof(fp))
{
fscanf(fp,"%d%s%f",&emp.id,emp.name,&emp.salary);
if(emp.id==id)
{
printf("\nRECORD FOUND..");
flag=1;
}
else
{
fprintf(fp1,"\n%d%s%f",emp.id,emp.name,emp.salary);
}
}
fclose(fp);
fclose(fp1);
if(flag==1)
{
fp=fopen("abc.txt","w");
fp1=fopen("new.txt","r");
while(!feof(fp1))
{
fscanf(fp1,"%d%s%f",&emp.id,emp.name,&emp.salary);
fprintf(fp,"\n%d%s%f",emp.id,emp.name,emp.salary);
}
fclose(fp);
fclose(fp1);
return 1;
}
else
{
printf("\nRECORD NOT FOUND...");
return 0;
}
}
  




















