// Data Structures & Algorithm, sem-III
// Structures used: Linked lists.
// This program allows the user to view the availability of seats in a movie theatre & book them respectively.
// The booking can also be deleted if the user wishes to.


#include<iostream>
using namespace std;
 class node
 {
  public:
  int seat_no;
  char status;
  node *prev,*next;
 };
 class ticket
 {
  public:
  node *head[10],*last[10];
  ticket()
  {
   for(int i=0;i<10;i++)
   {
    head[i]=NULL;
    last[i]=NULL;
   }
  }
  public:
void  create_bookingsys();
void display();
void booking();
void cancel_booking();
};

void ticket::create_bookingsys()
 {
  int i,j;
  for(i=0;i<10;i++)
  {
   for(j=0;j<7;j++)
   {
    node *ptr;
    ptr=new node();
    ptr->prev=ptr->next=NULL;
    ptr->seat_no=j+1;
    ptr->status='F';
    if(head[i]==NULL)
    {
     head[i]=ptr;
     last[i]=ptr;
    }
    else
    {
     last[i]->next=ptr;
     ptr->prev=last[i];
     ptr->next=head[i];
     last[i]=ptr;
    }
   }
   head[i]->prev=last[i];
  }
 }
 void ticket::display()
 {
  node *temp;
  for(int i=0;i<10;i++)
  {
   temp=head[i];
   cout<<"ROW NO"<<" "<<i+1<<"->"<<"\t";
   do
   {
    cout<<temp->seat_no<<"("<<temp->status<<")""\t";
    temp=temp->next;
   }while(temp!=head[i]);
   cout<<"\n";
   }
 }
 
 
 void ticket::booking()
 {
  int flag =0;
  int row,seatno,count=0;
  node *temp;
  cout<<"ENTER THE ROW NO: ";
  cin>>row;
  cout<<"Enter the no of seats according to the availability: ";
  cin>>seatno;
  temp=head[row-1];
  
  
  do
  {
   if(temp->status=='F')
     count++;
   else if(temp->status=='B')
       count=0;
   if(count==seatno)
     {
      temp=head[row-1];
      if(temp->status!='F')
      {
        while(temp->status!='F')
        {
         temp=temp->next;
        }
        for(int i=0;i<seatno;i++)
        {
            int l;
         temp->status='B';
         temp=temp->next;
         l++;
        }
       }
      else
      {
       for(int i=0;i<seatno;i++)
       {
         temp->status='B';
         temp=temp->next;
       }
      }
    }
    temp=temp->next;
   }while(temp!=head[row-1]);
   if(seatno>count)
    cout<<"\e[1m\nSeats already blocked!! please reconsider your selection\n\n\e[0m";
 }
 
 
 void ticket::cancel_booking()
 {
  int row,seatno,loc;
  node *temp;
  cout<<"Enter the row from where you want to cancel booking: ";
  cin>>row;
  cout<<"Enter the location for canceling booking: ";
  cin>>loc;
  cout<<"Enter the no of seats are to be canceld: ";
  cin>>seatno;
  temp=head[row-1];
  for(int i=0;i<loc-1;i++)
  {
   temp=temp->next;
  }
  for(int i=0;i<seatno;i++)
  {
   temp->status='F';
   temp=temp->next;
  }
 }
int main()
{
 int ch;
 ticket c;
do
{
cout<<"\n\nMENU:\t1.View Seating\t2.Booking\t3.Cancel Booking\t4.Exit\nENTER YOUR CHOICE: ";
cin>>ch;
 
 switch (ch)
 {
  case 1:
        c.create_bookingsys();
        c.display();
        break;
  case 2:
        c.booking();
        c.display();
        break;
  case 3:
        c.cancel_booking();
        c.display();
        break;
  case 4: exit(0);
  break;
 }
}while(ch!=5);
 
 return 0;
}


