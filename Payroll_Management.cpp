#include<iostream>
using namespace std;
class Node
{
	public://PUBLIC USED AS VARIABLES ARE HEAVILY USED THROUGHOUT THE PROGRAM
	string name,id,cont,desig;
	int whrs;
	float basic,hra,da,meall,medall,trnall,rate;
	float tax;
	float gross;
	Node* next;//POINTER MEMBER TO CONNECT INSTANCES OF CLASS
	Node()//DEFAULT CONSTRUCTOR
	{
        name=id=cont=desig="";
	    whrs=0;
	    basic=hra=da=meall=medall=trnall=rate=tax=gross=0.0;
	}
};

 Node* head= new Node;//DYNAMIC MEMORY ALLOCATION TO EASILY RESIZE DURING RUNTIME


void emprecord(string name,string id,string cont,string desig,int whrs,float meall,float medall,float trnall,float rate,float tax)
{
	Node*t =new Node;//DECLARATION OF AN OBJECT
	t->name=name;
	t->id=id;
	t->cont=cont;
	t->desig=desig;
	t->whrs=whrs;
	t->basic=(whrs*rate);;
	t->hra=(t->basic*0.2);
	t->da=(t->basic*0.6);
	t->meall=meall;
	t->medall=medall;
	t->trnall=trnall;
	t->tax=(t->basic*(tax/100));
	t->gross=t->basic+t->hra+t->da-t->tax+meall+medall+trnall;
	//INSERT AT BEGINNING
	if (head == NULL|| (head->id >= t->id))
	{
        t->next = head;
        head = t;
    }

    // INSERT AT NEXT POSITION
    else {
        Node* c = head;
        while (c->next != NULL&& c->next->id < t->id)
            {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }

    cout << "Record Inserted "
         << "Successfully\n";
}
void  display()
{
    Node* p = head;//TO TRAVERSE THROUGH LINKED LIST
    if(!head)
	{
        cout << "No Record Available\n";
    }
    else
	{
		while (p != NULL)//TILL END OF LINKED LIST IS NOT REACHED
		{
		cout<<"Employee's Name                : "<<p->name<<endl;
		cout<<"Employee's ID                  : "<<p->id<<endl;
		cout<<"Employee's Contact             : "<<p->cont<<endl;
		cout<<"Employee's Basic Pay           : "<<p->basic<<endl;
		cout<<"Employee's HRA(20% of basic)   : "<<p->hra<<endl;
		cout<<"Employee's DA(60% of basic)    : "<<p->da<<endl;
		cout<<"Employee's Meal Allowance      : "<<p->meall<<endl;
		cout<<"Employee's Medical Allowance   : "<<p->medall<<endl;
		cout<<"Employee's Transport Allowance : "<<p->trnall<<endl;
		cout<<"Employee's Tax deducted        : "<<p->tax<<endl;
		cout<<"Employee's Gross Pay           : "<<p->gross<<endl;
		p = p->next;
		}
	}
}
void seek(string id)
{
	if(!head)
    {
	  cout << "No Record Available\n";
        return;
    }
	else
	{
		  Node*p =head;
		  while(p)
		  {
			  if(p->id==id)
			  {
		        cout<<"Employee's Name                : "<<p->name<<endl;
		        cout<<"Employee's ID                  : "<<p->id<<endl;
		        cout<<"Employee's Contact             : "<<p->cont<<endl;
		        cout<<"Employee's Basic Pay           : "<<p->basic<<endl;
		        cout<<"Employee's HRA(20% of basic)   : "<<p->hra<<endl;
		        cout<<"Employee's DA(60% of basic)    : "<<p->da<<endl;
		        cout<<"Employee's Meal Allowance      : "<<p->meall<<endl;
		        cout<<"Employee's Medical Allowance   : "<<p->medall<<endl;
		        cout<<"Employee's Transport Allowance : "<<p->trnall<<endl;
		        cout<<"Employee's Tax deducted        : "<<p->tax<<endl;
		        cout<<"Employee's Gross Pay           : "<<p->gross<<endl;
		       return ;
		     }
		    p=p->next;
         }
		  if (p == NULL)
            cout << "No such Record Available\n";

      }
}
void update(string id)
{
    if(!head)
    {
	  cout << "No such Record Available\n";
        return;
    }
	else
	{
		  Node*p =head;
		  while(p)
		  {
			  if(p->id==id)
			  {
		 cout<<"Enter Name                  : ";
		cin>>p->name;
		cout<<"Enter id                    : ";
		cin>>p->id;
		cout<<"Enter designation           : ";
		cin>>p->desig;
		cout<<"Enter contact               : ";
		cin>>p->cont;
		cout<<"Enter per hour pay          : ";
		cin>>p->rate;
		cout<<"Enter Working hours         : ";
		cin>>p->whrs;
		cout<<"Enter Meal allowance        : ";
		cin>>p->meall;
		cout<<"Enter Medical allowance     : ";
		cin>>p->medall;
		cout<<"Enter Transport allowance   : ";
		cin>>p->trnall;
		cout<<"Enter the tax percentage    : ";
		cin>>p->tax;
		p->basic=(p->whrs*p->rate);
		p->hra=(p->basic*0.2);
		p->da=(p->basic*0.6);
		p->tax=(p->basic*(p->tax/100));
		p->gross=p->basic+p->hra+p->da-p->tax+p->meall+p->medall+p->trnall;
		return ;
		}
		p=p->next;
		  }
		  if (p == NULL)
            cout << "No such Record Available\n";

      }
      return ;
}
int del(string id)
{
	Node* t = head;
    Node* p = NULL;
	if (t != NULL && (t->id) == id)
	{
        head = t->next;
        delete t;

        cout << "Record Deleted Successfully\n";
             return 0;

    }
    else
        {


	 while (t != NULL && t->id != id)
        {
        p = t;
        t = t->next;
        }
    if (t == NULL)
        {
        cout << "Record does not Exist\n";
        return -1;
        }
        p->next = t->next;

        delete t;
        cout << "Record Deleted "
             << "Successfully\n";

        return 0;
    }

}
int main()
{
	head = NULL;
	string Name,Id,Cont,Desig;
	int Whrs;
	float Basic,Hra,Da,Meall,Medall,Trnall,Rate;
	float Tax;
	float Gross;
	cout<<"\t\t\t\t~~~PAYROLL MANAGEMENT SYSTEM USING C++~"<<endl;
	cout<<"\t\t\t\t`````SHREYA SINGH RAGHUVANSHI,2017038````"<<endl;
	int ch;
	do{
    cout<<"Enter your choice to manipulate records:"<<endl;
	cout<<"1 to Enter data"<<endl;
	cout<<"2 to Delete data"<<endl;
	cout<<"3 to Seek data"<<endl;
	cout<<"4 to Display data"<<endl;
	cout<<"5 to update"<<endl;
	cout<<"6 to Exit"<<endl;
	cin>>ch;
	system("CLS");
	switch(ch)
	{
		case 1:
		{
           cout<<"Enter Name                  : ";
		cin>>Name;
		cout<<"Enter id                    : ";
		cin>>Id;
		cout<<"Enter designation           : ";
		cin>>Desig;
		cout<<"Enter contact               : ";
		cin>>Cont;
		cout<<"Enter per hour pay          : ";
		cin>>Rate;
		cout<<"Enter Working hours         : ";
		cin>>Whrs;
		cout<<"Enter Meal allowance        : ";
		cin>>Meall;
		cout<<"Enter Medical allowance     : ";
		cin>>Medall;
		cout<<"Enter Transport allowance   : ";
		cin>>Trnall;
		cout<<"Enter the tax percentage    : ";
		cin>>Tax;

			emprecord(Name,Id,Cont,Desig,Whrs,Meall,Medall,Trnall,Rate,Tax);
		}
			break;
		case 2:
		{
			cout<<"\nEnter id to delete:";
			cin>>Id;
            del(Id);
		}
			break;
		case 3:
		{
            cout << "Enter ID whose "
                    "record you want to Search\n";
            cin >>Id;
            seek(Id);
		}

			break;
		case 4:
			display();
			break;
		case 5:
		    {
                cout<<"Enter id to update:";
                cin>>Id;
                update(Id);
            }

			break;
        case 6:
            exit(0);
            break;
		default:
			cout<<"\aInvalid Choice"<<endl;
          break;
	}
}while(ch>0&&ch<=6);

  return 0;
}
