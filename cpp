#####  weather: #####

#include<iostream>
using namespace std;

class weather
{
	int dom,htemp,ltemp,snow,rain;
	public:
	weather()
	{
		dom=0;
		htemp=100;
		ltemp=-10;
		snow=10;
		rain=10;
	}
	void getdata(int x);
	int display();
};

void weather::getdata(int x)
{
	dom=x;
	cout<<"enter high temp:";
	cin>>htemp;
	cout<<"enter low temp:";
	cin>>ltemp;
	cout<<"enter amount of rain:";
	cin>>rain;
	cout<<"enter amount of snow:";
	cin>>snow;
}

int weather::display()
{
	
	cout<<"\n"<<dom<<"\t"<<htemp<<"\t"<<ltemp<<"\t"<<rain<<"\t\t"<<snow;
	return 0;
}

int main()
{
	weather s[31][12];
	int day,month,choice,i;
	
	do
	{
		cout<<"\n1.getdata\n2.display\n3.Exit\n";
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"enter the month:";
				cin>>month;
				cout<<"enter the day:";
				cin>>day;
				s[day][month].getdata(day);
				break;
			case 2:
				cout<<"enter the month:";
				cin>>month;
				cout<<"\nDOM\thtemp\tltemp\tamt_rain\tamt_snow";
				for(i=1;i<31;i++)
				s[i][month].display();
				break;
		}
	}while(choice != 3);
	
}


####### Exception handling ######

#include<iostream>
using namespace std;

int main()
{
	int a,b;
	cout<<"Enter the value of a:";
	cin>>a;
	cout<<"Enter the value of b:";
	cin>>b;
	
	try
	{
		if(b==0)
		throw(b);
		cout<<"\nthe division is :"<<a/b;
	}
	
	catch(int x)
	{
		cout<<"\n The exception is zero....!\n";
	}
}


######## shape #######

#include<iostream>
using namespace std;

class shape
{
	protected:
	int d1,d2;
	public:
	virtual void getdata()=0;
	virtual void display()=0;
};

class tringle : public shape
{
	void getdata()
	{
		cout<<"Enter the hieght and base:\n";
		cin>>d1>>d2;
	}
	void display()
	{
		cout<<"The area of triangle is:"<<0.5*d1*d2<<"\n";
	}
};

class rectangle : public shape
{
	void getdata()
	{
		cout<<"Enter the length and width:\n";
		cin>>d1>>d2;
	}
	void display()
	{
		cout<<"The area of rectangle is:"<<d1*d2<<"\n";
	}
};

int main()
{
	shape *s;
	tringle t;
	rectangle r;
	
	s=&t;
	s->getdata();
	s->display();
	
	s=&r;
	s->getdata();
	s->display();
	
	return 0;
}



######## complex number ##########


#include<iostream>
using namespace std;

class complex
{
	int img,real;
	public:
	complex()
	{
		img=0;
		real=0;
	}
	void getdata();
	void display();
	friend complex operator+(complex,complex);
	friend complex operator-(complex,complex);
	complex operator*(complex c2);
	complex operator/(complex c2);
};

void complex :: getdata()
{
	cout<<"Enter the real number:";
	cin>>real;
	cout<<"Enter the img number:";
	cin>>img;
}

void complex :: display()
{
	cout<<"\nThe complex number is:"<<real<<"+"<<img<<"i";
}

complex operator+(complex a,complex b)
{
	complex c3;
	c3.real=a.real+b.real;
	c3.img=a.img+b.img;
	return c3;
}

complex operator-(complex a,complex b)
{
	complex c3;
	c3.real=a.real-b.real;
	c3.img=a.img-b.img;
	return c3;
}

complex complex :: operator*(complex c2)
{
	complex c3;
	c3.real=(real*c2.real)-(img*c2.img);
	c3.img=(real*c2.img)+(img*c2.real);
	return c3;
}

complex complex :: operator/(complex c2)
{
	complex c3;
	c3.real=((real*c2.real)+(img*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
	c3.img=(-(real*c2.img)+(img*c2.real))/((c2.real*c2.real)+(c2.img*c2.img));
	return c3;
}

int main()
{
	int choice;
	complex c1,c2,c3;
	do
	{
		cout<<"\n****** COMPLEX NUMBER ******\n";
		cout<<"1.getdata\n2.display\n3.Addition\n4.Subtraction\n5.multiplication\n6.Division\n7.Exit\n";
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				c1.getdata();
				c2.getdata();
				break;
			case 2:
				c1.display();
				c2.display();
				break;
			case 3:
				c3=c1+c2;
				c3.display();
				break;
			case 4:
				c3=c1-c2;
				c3.display();
				break;
			case 5:
				c3=c1*c2;
				c3.display();
				break;
			case 6:
				c3=c1/c2;
				c3.display();
				break;
		}
	}while(choice != 7);
}

########### File operations ###########

#include<iostream>
#include<fstream>
using namespace std;

void creat(char fname[40])
{
	char data[100];
	ofstream outfile;
	outfile.open(fname);
	cout<<"Enter the data:";
	cin>>data;
	outfile<<data<<"\n";
	outfile.close();
	cout<<"\nFile created successfully.....!\n";
}

void display(char fname[40])
{
	ifstream infile;
	const int n=80;
	char line[n];
	infile.open(fname);
	cout<<"\nFile name:"<<fname<<"\n";
	cout<<"\n Data:\n\n";
	while(infile)
	{
		infile.getline(line,n);
		cout<<line<<"\n";
	}
	infile.close();
}

int main()
{
	char filename[30];
	int choice;
	do
	{
		cout<<"\n********File operations**********\n";
		cout<<"1.creat file\n2.Read file\nexit\n";
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the file name:";
				cin>>filename;
				cout<<"\n";
				creat(filename);
				break;
			case 2:
				display(filename);
				break;
		}
	}while(choice != 3);
}


######### employee data #########

#include<iostream>
using namespace std;
class personal
{
  protected:
    char name[50];
    char address[50];
    char birthdate[50];
    char gender;
  public:
    void get_personal();
};
class professional
{
  protected:
   int noofyearsexp;
   char orgname[50];
   char projname[50];
   char projdetails[50];
  public:
   void get_professional();
};
class academic
{
  protected:
   int year;
   int marks;
   int percentage;
   char Class[50];
  public:
   void get_academic();
};
 class biodata: public personal,public academic,public professional
   {
     public:
      void display();
   };
void personal::get_personal()
 {
 cout<<"Enter name::";
 cin>>name;
 cout<<"Enter address::";
 cin>>address;
 cout<<"Enter birthdate(dd/mm/yyyy)::";
 cin>>birthdate;
 cout<<"Enter gender(m/f)::";
 cin>>gender;
 }
void professional::get_professional()
 {
   cout<<"Enter no of years of exp::";
   cin>>noofyearsexp;
   cout<<"Enter org name::";
   cin>>orgname;
   cout<<"Enter project name::";
   cin>>projname;
   cout<<"Enter project details::";
   cin>>projdetails;
 }
void academic::get_academic()
 { 
  cout<<"Enter academic year::";
  cin>>year;
  cout<<"Enter total marks::";
  cin>>marks;
  cout<<"Enter percentage::";
  cin>>percentage;
  cout<<"Enter class::";
  cin>>Class;
 }
void biodata::display()
 {
   cout<<"**************************Employee Biodata******************************"<<endl;
   cout<<"__________________________________________________________________________"<<endl; 
   cout<<"---------------------------------Personal Details---------------------------------"<<endl;
   
   cout<<"name::"<<name<<endl;
   cout<<"address::"<<address<<endl;
   cout<<"birthdate::"<<birthdate<<endl;
   cout<<"gender::"<<gender<<endl;
    cout<<"__________________________________________________________________________"<<endl; 
    cout<<"--------------------------------- Academic Details---------------------------------"<<endl;
   cout<<"Academic Year"<<"marks"<<"percentage"<<"class"<<endl;
   cout<<year<<"\t\t"<<marks<<"\t"<<percentage<<"\t"<<Class<<endl;
   cout<<"__________________________________________________________________________"<<endl;
   cout<<"---------------------------------Profesional Details---------------------------------"<<endl;
   cout<<"\nOrganisation Name::"<<orgname;
   cout<<"\nYears of experience::"<<noofyearsexp;
   cout<<"\nProject Name::"<<projname;
   cout<<"\nProject Details::"<<projdetails;
  }
  int main()
   { 
     biodata b;
     b.get_personal();
     b.get_academic();
     b.get_professional();
     b.display();
   }
  



############ Master ####################

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class base1
{
	char dob[10];
	char bg[3];
	public:
		char name[30];
		void get1();
		void disp1();

};

class base2
{
	float ht;
	float wt;
	public:
		void get2();
		void disp2();
};

class base3
{
	char policy[10];
	char address[50];
	public:
		void get3();
		void disp3();
};

class derived : public base1, public base2 ,public base3
{
	char telephone[10];
	char liscence[10];
	public:
		int present;
		derived();
		void get();
		void disp();
};

derived :: derived()
{
	present=0;
}

void base1 :: get1()
{
    cout<<"\nEnter Name: ";
    cin>>name;
    cout<<"\nEnter DOB: ";
    cin>>dob;
    cout<<"\nEnter Blood group: ";
    cin>>bg;
}

void base1 :: disp1()
{
	cout<<"\n"<<name<<"\t"<<dob<<"\t"<<bg;
}

void base2 :: get2()
{
      cout<<"\nEnter height: ";
      cin>>ht;
      cout<<"\nEnter weight: ";
      cin>>wt;
}

void base2 :: disp2()
{
      cout<<"\t"<<ht<<"\t"<<wt;
}

void base3 :: get3()
{
	cout<<"\nEnter policy number: ";
	cin>>policy;
	cout<<"\nEnter address: ";
	cin>>address ;
}

void base3 :: disp3()
{
   cout<<"\t"<<policy<<"\t"<<address;
}

void derived :: get()
{
   base1 :: get1();
   base2 :: get2();
   base3 :: get3();
   present=1;
   cout<<"\nEnter telephone number: ";
   cin>>telephone;
   cout<<"\nEnter liscence number: ";
   cin>>liscence;
}

void derived :: disp()
{
   base1::disp1();
   base2::disp2();
   base3::disp3();
   cout<<"\t"<<telephone<<"\t"<<liscence<<"\t";
}

int main()
{
	derived obj[50],temp;
	int ch,i,j=-1,no,flag=0;
	char key[10],ans;
	
	do
	{
		cout<<"\n\tMenu"
		    <<"\n1.Build Master Table"
		    <<"\n2.Display"
		    <<"\n3.Insert a new entry"
		    <<"\n4.Delete entry"
		    <<"\n5.Edit"
		    <<"\n6.Search for record"
		    <<"\n7.Exit"
		    <<"\nEnter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				do
				{
					j++;
					obj[j].get();
					cout<<"\nAdd another.....(y/n)?: ";
					cin>>ans;
				}while(ans=='Y' || ans=='y');
				break;

			case  2:		cout<<"\nName\tDOB\tB.G.\tHeight\tWeight\tPolicy\tAddres\tTeleNo\tLiscNo ";
				cout<<"\n-----------------------------------------------------------------------";
				for(i=0;i<=j;i++)
					obj[i].disp();
				break;

			case 3:
				cout<<"\n Enter the index no.: ";
				cin>>no;
				//if(no<=j)
				//{
					for(i=no;i<=j;i++)
					{
						temp=obj[i];
						obj[i+1]=temp;
					}
					obj[no].get();
					j++;
					cout<<"\nRecord Inserted Successfully.....";
				//}
				//else
				//	cout<<"\nERROR.....";
				break;

			case 4:
				if(j!=-1)
				{
					cout<<"\nEnter the record no. to delete: ";
					cin>>no;
					if(no<=j)
					{
						for(i=no;i<=j;i++)
						{
							temp=obj[i];
							obj[i]=obj[i+1];
						}
						j--;
						cout<<"\nRecord Deleted SuccessFully.....";
					}
					else
						cout<<"\nERROR.....";
				}
				else
						cout<<"\nNo Record to delete.....";
				break;

			case 5:
				if(j!=-1)
				{
					cout<<"\nEnter index no.";
					cin>>no;
					cout<<"\nEnter modified data: ";
					obj[no].get();
					cout<<"\nRecord modified Successfully.....";
				}
				else
						cout<<"\nNo Record to modify.....";
				break;

			case 6:
				if(j!=-1)
				{
					cout<<"Enter the name to be searched:" ;
					cin>>key;
					for(i=0;i<=j;i++)
					{
						if(strcmp(obj[i].name,key)==0)
						{
							cout<<"\nRecord Found.....";
							obj[i].disp();
							flag=1;
						}
					}
					if(flag==0)
						cout<<"\nRecord not found.....";
				}
				else
					cout<<"\nNo Record to search.....";
				break;

			case 7:
				exit(0);
			default:
				cout<<"\nInvalid Choice.....";
		}
	}while(ch!=7);
	return 0;
}


############### 11 seqfile ###############

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Student
	{
		char Name[10];
		int Roll_No;
		public:
		Student()
		{ 
			Name[0]='\0';
			Roll_No=-1;
		}
		void get_Data();
		void put_Data();
		int return_Roll()
		{ 
			return Roll_No;
		}
			
	};

void Student::get_Data()
	{
	    cout<<"\nEnter Student Data";
	    cout<<"\nName";cin>>Name;
	    cout<<"\nRoll Number: ";cin>>Roll_No;
	}
void Student::put_Data()
	{
	     cout<<"\n"<<Roll_No<<"\t"<<Name;
	}    

class Seq_File
	{
		char File_Name[15];
		public:
		Seq_File();
		Seq_File(char F[]);		
		void Create();
		void Display();
		void Add();
		void Remove(int);
		void Modify(int);
	};
Seq_File::Seq_File()
	{
		    ofstream  File("Student.txt");
		    strcpy(File_Name," Student.txt");
		    cout<<"\nDefault Constructor";
		    if(File)
		       {
		          cout<<"\nFile opened Successfully";
		          File.close();
		       }
		    else cout<<"\nFile creation Error";   
		
	}
Seq_File::Seq_File(char F[15])
	{
		ofstream  File;
		strcpy(File_Name,F);
		File.open(F);
		    if(File)
		        {
		          cout<<"\nFile opened Successfully";
		          File.close();
		        }
		     else cout<<"\nFile creation Error";   
	}	
void Seq_File::Create()
	{
		ofstream  File;
		Student S;
		File.open(File_Name);
		S.get_Data();
		File.write(reinterpret_cast<char*>(&S),sizeof(S));
		File.close();
	}
	
void Seq_File::Display()
	{
		ifstream  File;
		Student S;
		File.open(File_Name);
		cout<<"\nRoll No\t Student Name";
		File.read(reinterpret_cast<char*>(&S),sizeof(S));
		while(!File.eof())
		            {
		                      S.put_Data();
		                      File.read(reinterpret_cast<char*>(&S),sizeof(S));
		            }
		File.close();
		
	}
void Seq_File::Add()
	{
		ofstream  File;
		Student S;
		File.open(File_Name,ios::app);
		S.get_Data();
		File.write(reinterpret_cast<char*>(&S),sizeof(S));
		File.close();
	}	
void Seq_File::Remove(int Roll)
	{
		 ifstream File;
		 ofstream Temp;
		 Student S;
		 int Flag=0;
		 File.open(File_Name);
		 Temp.open("Temp.Txt");
		 File.read(reinterpret_cast<char*>(&S),sizeof(S));
		while(!File.eof())
		            {
		                     if(Roll==S.return_Roll())
		                         {   S.put_Data(); Flag=1;}
		                      else
		                          Temp.write(reinterpret_cast<char*>(&S),sizeof(S));
		                      File.read(reinterpret_cast<char*>(&S),sizeof(S));
		            }
		 if(Flag==0) cout<<"Roll No. "<<Roll<<" does not present \n";      
		File.close();
		Temp.close();
		remove(File_Name);
		rename("Temp.Txt",File_Name); 
	}
void Seq_File::Modify(int Roll)
	{
		 ifstream File;
		 ofstream Temp;
		 Student S;
		 int Flag=0;
		 File.open(File_Name);
		 Temp.open("Temp.Txt");
		 File.read(reinterpret_cast<char*>(&S),sizeof(S));
		while(!File.eof())
		            {
		                     if(Roll==S.return_Roll())
		                          {
		                                S.put_Data();
		                                cout<<"\n Enter data to modify";
		                                S.get_Data();
		                                Flag=1;                                
		                           }     
		                     Temp.write(reinterpret_cast<char*>(&S),sizeof(S));
		                      File.read(reinterpret_cast<char*>(&S),sizeof(S));
		            }
		 if(Flag==0) cout<<"Roll No. "<<Roll<<" does not present \n";      
		File.close();
		Temp.close();
		remove(File_Name);
		rename("Temp.Txt",File_Name); 
	}
int main()
      {
	int Choice;
	char F[15];
	int R;
	cout<<"\nEnter File Name : ";
	cin>>F;
	Seq_File  sFile(F);      	
	do
	{
	  cout<<"\n1: Create Database\n2: Display Database\n3: Add a record\n4: Delete a record\n5: Modify a record\nEnter your choice: ";
	  cin>>Choice;
	  switch(Choice)
	                {
		case 1:
	                                    sFile.Create();
	                                    break;
	                    case 2:               		                
	                                    sFile.Display();
	                                    break;
	                    case 3:
	                                    sFile.Add();
	                                    break;
	                    case 4:
	                                    cout<<"\nEnter Roll No to delete";
                         	                cin>>R;
	                                    sFile.Remove( R);
	                                    break;
	                    case 5:                                                                
	                                    cout<<"\nEnter Roll No to Modify";
                         	                cin>>R;
	                                    sFile.Modify( R);
	                                    break;
	                }
                     }  while(Choice<6);	            
 	cout<<"\n";
   	return 1;
      }



############### template ################


//Implementation of function template on matrix operation
#include<iostream>
#define max 50
using namespace std;

template <class t>
void initmat(t *mat1,int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
	for(j=0;j<col;j++)
	{
	   mat1[i][j]=0;
	}
    }
}

template <class t>
int getmat(t *mat1,int& row,int& col,int flag)
{
    int i,j;
    cout<<"\nEnter the no of rows of matrix:";
    cin>>row;
    cout<<"Enter the no of columns of matrix:";
    cin>>col;
    for(i=0;i<row;i++)
    {
       for(j=0;j<col;j++)
       {
	 cout<<"Enter data:";
	 cin>>mat1[i][j];
       }
    }
    if(flag==1)
	return row;
    else
	return col;
}
template <class t1,class t2,class t3>
void addmat(t1 *mat,int r3,int c3,t2 *m1,int r1,int c1,t3 *m2,int r2,int c2)
{
   int i,j;
   if(r1==r2 && c1==c2)
   {
      for(i=0;i<r3;i++)
      {
	for(j=0;j<c3;j++)
	{
	   mat[i][j]=m1[i][j]+m2[i][j];
	}
      }
   }
   else
      cout<<"\nMatrices can't be added";
}
template <class t1,class t2,class t3> 
void submat(t1 *mat,int r3,int c3,t2 *m1,int r1,int c1,t3 *m2,int r2,int c2)
{
   int i,j;
   if(r1==r2 && c1==c2)
   {
	  for(i=0;i<r3;i++)
	  {
	for(j=0;j<c3;j++)
	{
	   mat[i][j]=m1[i][j]-m2[i][j];
	}
	  }
   }
   else
	  cout<<"\nMatrices can't be subtracted";
}

template <class t1,class t2,class t3> 
void mulmat(t1 *mat,int r3,int c3,t2 *m1,int r1,int c1,t3 *m2,int r2,int c2)
{
   int i,j,k;
   if(c1==r2)
   {
	  for(i=0;i<r1;i++)
	  {
	 for(j=0;j<c2;j++)
	 {
		 for(k=0;k<r2;k++)
		 {
		mat[i][j]+=m1[i][k]*m2[k][j];
		 }
	 }
	  }
   }
   else
	   cout<<"\nMatrices can't be multiplied";
}

template <class t>
void display(t *mat1,int row,int col)
{
   int i,j;
   cout<<"\nThe Resultant matrix is:";
   for(i=0;i<row;i++)
   {
	  cout<<"\n";
	  for(j=0;j<col;j++)
	  {
	 cout<<"\t"<<mat1[i][j];
	  }
   }
}

int main()
{
   int r1,c1,r2,c2,r3,c3,r4,c4,r5,c5,r6,c6;
   int m1[max][max],m2[max][max],m3[max][max];
   float m4[max][max],m5[max][max],m6[max][max];
   char ans;
   int choice,ch;
   do
   {
	   
	   cout<<"\n\nMenu";
	   cout<<"\n\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Exit";
	   cout<<"\n\nEnter your choice:";
	   cin>>choice;
	   switch(choice)
	   {
	  case 1:
	  {
		   cout<<"\nMenu for addition";
		   cout<<"\n1.Integer Addition\n2.Float Addition";
		   cout<<"\nEnter your  choice:";
		   cin>>ch;
		   if(ch==1)
		   {
		  r3=getmat(m1,r1,c1,1);
		  c3=getmat(m2,r2,c2,2);
		  initmat(m3,r3,c3);
		  addmat(m3,r3,c3,m1,r1,c1,m2,r2,c2);
		  display(m3,r3,c3);
		   }
		   else
		   {
		   r6=getmat(m4,r4,c4,1);
		   c6=getmat(m5,r5,c5,2);
		   initmat(m6,r6,c6);
		   addmat(m6,r6,c6,m4,r4,c4,m5,r5,c5);
		   display(m6,r6,c6);
		   }
		   break;
	  }

	  case 2:

	  {
		   cout<<"\nMenu for Subtraction";
		   cout<<"\n1.Integer Subtraction\n2.Float Subtraction";
		   cout<<"\nEnter your  choice:";
		   cin>>ch;
		   if(ch==1)
		   {
		  r3=getmat(m1,r1,c1,1);
		  c3=getmat(m2,r2,c2,2);
		  initmat(m3,r3,c3);
		  submat(m3,r3,c3,m1,r1,c1,m2,r2,c2);
		  display(m3,r3,c3);
		   }
		   else
		   {
		   r6=getmat(m4,r4,c4,1);
		   c6=getmat(m5,r5,c5,2);
		   initmat(m6,r6,c6);
		   submat(m6,r6,c6,m4,r4,c4,m5,r5,c5);
		   display(m6,r6,c6);
		   }
		   break;
	  }

	  case 3:
	  {
		   cout<<"\nMenu for multiplication";
		   cout<<"\n1.Integer Multiplication\n2.Float Multipliacation";
		   cout<<"\nEnter your choice:";
		   cin>>ch;
		   if(ch==1)
		   {
			r3=getmat(m1,r1,c1,1);
			c3=getmat(m2,r2,c2,2);
			initmat(m3,r3,c3);
			mulmat(m3,r3,c3,m1,r1,c1,m2,r2,c2);
			display(m3,r3,c3);
		   }
		   else
		   {
			r6=getmat(m4,r4,c4,1);
			c6=getmat(m5,r5,c5,2);
			initmat(m6,r6,c6);
			mulmat(m6,r6,c6,m4,r4,c4,m5,r5,c5);
			display(m6,r6,c6);
		}
		break;
	  }

	  case 4:break;
		   
	}
	cout<<"\n\nDo you want to continue?";
	cin>>ans;
   }while(ans=='y');
   return 0;
}

