#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<iomanip>
using namespace std;
int price,roll_no,code;
int count=0;
string name,author1,author2,title,classs,subject;
struct student{
	int roll_no;
	string name;
	string classs;
	struct book *b =NULL;
	student *next;
} issued_to;
struct book{
	string title;
	int code;
	string author1;
	string author2;
	string subject;
	int price;
	struct student *issued_to=NULL;
	book *next;
} b;
class linklist
{
 student *list;
 book *list1;
 public:
 		int c,roll;
 	linklist()
 	{
 		list =NULL;
 		list1=NULL;
	}
	bool isempty()
	{
		if(list==NULL)
		return true;
		return false;

	}
	bool isemptyb()
	{
			if(list1==NULL)
		return true;
		return false;	
	}
	void create()
	{
		if(isemptyb())
		{
			book *p;
			p=new book;
			cout<<"enter book details\n";
			cout<<"enter title\n";
			getline(cin,title);
			getline(cin,title);
			p->title=title;
			cout<<"enter book code\n";
			cin>>code;
			p->code=code;
			cout<<"enter author1\n";
			getline(cin,author1);
			getline(cin,author1);
			p->author1=author1;
			cout<<"enter author2\n";
			getline(cin,author2);
			p->author1=author2;
			cout<<"enter subject\n";
			getline(cin,subject);
			p->subject=subject;
			cout<<"enter price \n";
			cin>>price;
			p->price=price;
			p->next=NULL;
			list1=p;
			count++;
		}
	}
	void add_student()
	{
		student *q;
		q=new student;
		cout<<"enetr student details\n";
		cout<<"enter class\n";
		getline(cin,classs);
		getline(cin,classs);
		q->classs=classs;
		cout<<"enter ROLL NO\n";
		cin>>roll_no;
		q->roll_no=roll_no;
		cout<<"enter name\n";
		getline(cin,name);
		getline(cin,name);
		q->name=name;
		q->next=list;
		list=q;		
	 } 
void traverse()
	{
		cout<<setw(10)<<"BookNo"<<setw(25)<<"Title"<<setw(20)<<"Code"<<setw(15)<<"Author1"<<setw(15)<<"Author2"<<setw(20)<<"Subject"<<setw(20)<<"Price"<<endl;
		cout<<"________________________________________________________________________________________________________________________\n";
		int i=1;
		if(!isemptyb())
		{
			book *q=list1;
			while(q!=NULL)
			{
				cout<<setw(10)<<i<<setw(25)<<q->title<<setw(20)<<q->code<<setw(15)<<q->author1<<setw(15)<<q->author2<<setw(20)<<q->subject<<setw(20)<<q->price<<endl;
				q=q->next;
				i=i+1;
			}
			cout<<endl;
		}
	}
void traverse_student()
	{
		student *q=list;
			cout<<setw(25)<<"NAME"<<setw(11)<<"ROLL_NO"<<setw(10)<<"CLASS\n";
			cout<<setw(56)<<"_________________________________________\n";
		while(q!=NULL)
		{
			cout<<setw(25)<<q->name;
			cout<<setw(11)<<q->roll_no;
			cout<<setw(10)<<q->classs;
			cout<<endl;
			q=q->next;
		}
		cout<<endl;
	}
void insertb()
	{
		if(isemptyb())
		{
			create();
		}
		else
		{
			book *p;
			p=new book;
			cout<<"enter book details\n";
			cout<<"enter title\n";
			getline(cin,title);
			getline(cin,title);
			p->title=title;
			cout<<"enter book code\n";
			cin>>code;
			p->code=code;
			cout<<"enter author1\n";
			getline(cin,author1);
			getline(cin,author1);
			p->author1=author1;
			cout<<"enter author2\n";
			getline(cin,author2);
			p->author1=author2;
			cout<<"enter subject\n";
			getline(cin,subject);
			p->subject=subject;
			cout<<"enter price \n";
			cin>>price;
			p->price=price;
			p->next=NULL;
			book *q=list1;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=p;
			count++;
		}
	}
	void  re(){
		cout<<"enter book id if you want to issue book to student\n";
		cin>>c;
		cout<<"enter student roll no. u want to issue to book\n";
		cin>>roll;
		}
	void issue()
	{
		book *p=list1;
		student *q=list;
	
		cout<<"enter book id if you want to issue book to student\n";
		cin>>c;
		cout<<"enter student roll no. u want to issue to book\n";
		cin>>roll;
		
		while(q->roll_no!=roll)
		{
			q=q->next;
			if(q==NULL)
			{
				cout<<"invalid roll no \n";
				cout<<"reenter roll_no\n";
				re();
				q=list;
			}
		}
		
		while(p->code!=c )
		{
			p=p->next;
			if(p==NULL)
			{
				cout<<"invalid code \n";
				cout<<"reenter code\n";
				re();
				p=list1;
			}
		}
		if (p->code==c&&q->roll_no==roll)
		{
		p->issued_to=q;
		cout<<p->title <<"\tbook is issued to:" ""<<q->name<<" &" " Roll_no is:" ""<<q->roll_no<<"\n";
		}
	}
void check()
{
	int code;
	label:
	cout<<"enter code of book\n";
	cin>>code;
	book *p=list1;
	if(p!=NULL)
	{
		while(p->code!=code)
		{
			p=p->next;
			if(p==NULL)
			{
				cout<<"you have entered invalid code of book\n";
				system("pause");
				goto label;
			}
		}
		if(p->issued_to!=NULL)
		{
			cout<<"issued\t & issued to ROLL_NO:-"<<p->issued_to->roll_no <<"\t of class:-"<<p->issued_to->classs<<"\t name of student:-"<<p->issued_to->name <<endl;	
			system("pause\n");
		}
		else
		cout<<"available\n";
	}
	else
	{
		if(list1->code==code)
		{
			if(list1->issued_to->roll_no==0)
				cout<<"available\n";
			else
			cout<<"issued\t & issued to ROLL_NO:-"<<p->issued_to->roll_no <<"\t of class:-"<<p->issued_to->classs<<"\t name of student:-"<<p->issued_to->name <<endl;	
		}
	}
}
	book* remove()
	{
		book *p=list1;
		book *prev=0;
		int length,i;
		label:
		cout<<"enter code\n";
		cin>>code;
		while(p->code!=code)
		{
			prev=p;
			p=p->next;
			if(p==NULL)
			{
				cout<<"invalid code entered reenter code\n";
				goto label;
				p=list1;
				prev=0;
			}
		}
		if(prev==0)
		{
			list1=p->next;
		}
		else
		{
			prev->next=p->next;
		}
		cout<<"deleted: "<<p->title<<endl;
		delete p;
		return list1;
	}
	void return_book()
	{
		book *p;
		p=list1;
		label:
		cout<<"enter book code u want to return:\n";
		cin>>code;
		
		while(p->code!=code)
		{
			p=p->next;
			if(p==NULL)
			{
				cout<<"invalid code reenter code of book \n";
				goto label;
				p=list1;
			}
		}
		p->issued_to=NULL;
		cout<<"returned\n";
	}
	void total_price()
	{
		int sum=0;
		book *p;
		p=list1;
		while(p!=NULL)
		{
			sum=sum+p->price;
			p=p->next;
		}
		cout<<"Total price of books in library is :"<<sum<<endl;
	}
	void issued()
	{
		book *p=list1;
		if(p==NULL)
		cout<<"NO BOOK ISSUED\n";
		while(p!=NULL)
		{	
			if(p->issued_to!=NULL)	
			cout<<p->title<<" book is issued to "<<" Name :"<<p->issued_to->name<<"\t Roll No : "<<p->issued_to->roll_no<<"\tClass is :"<<p->issued_to->classs<<endl<<endl;
			p=p->next;
		}
		
	}
};
int main()
{
	int i;
	linklist l1;
	cout<<"choose one option from following:-\n";
	int ch;
	do
	{
		cout<<"1. Insert book detail\n2. Display book details\n3. Add student details\n4. Display student details\n5. To Issue a book\n6. Check status of any book\n7. Remove book\n8. Return Book\n9. Total Price Of Books\n10. Issued Books\n11. EXIT\n\n";
		cin>>ch;
		system("cls");
		if(ch==1)
			l1.insertb();
		else if(ch==2)
			l1.traverse();
		else if(ch==3)
			l1.add_student();
		else if(ch==4)
			l1.traverse_student();
		else if(ch==5)
			l1.issue();
		else if(ch==6)
			l1.check();
		else if(ch==7)
			l1.remove();
		else if(ch==8)
			l1.return_book();
		else if(ch==9)
			l1.total_price();
		else if(ch==10)
			l1.issued();
		else if(ch==11)
		{
	 		cout<<"\n\n\t\t\t******EXITING******\n\n";
	 		exit(0);
	 	}
	}while(ch<12);
	system("pause");
	return 0;
}
