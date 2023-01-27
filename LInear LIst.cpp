#include <iostream>
#define MAXSIZE 100
using namespace std;

int size=0;
int linear[MAXSIZE];
void create(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"enter "<<i+1<<" element";
        cin>>linear[i];
    }
    size=n;
}
int isempty()
{
    if(size==0)
    return 1;
    else
    return 0;
}
int isfull()
{
    if(size==MAXSIZE)
    return 1;
    else
    return 0;
}
int find(int k)
{
    if(k>=0 && k<=size)
    return linear[k];
    else
    {
        cout<<"Invalid index"<<endl;
        return -1;
    }
}
int search(int n)
{
	if(isempty())
	{
		cout<<"Empty List"<<endl;
		return -1;
	}
    for(int i=0;i<size;i++)
    {
    if(linear[i]==n)
    return i;
    }
    cout<<"Element not found"<<endl;
    return -2;
}
void insert(int k,int x)
{
	if(isempty() || isfull())
	{
		cout<<"Cant Insert data";
		return;
	}
	int i;
	if(k>=1 && k<=size+1)
	{
	    for(i=size-1;i>=k-1;i--)
	    {
		linear[i+1]=linear[i];
	    }
	    linear[k-1]=x;
	    size++;
	}
	else
	{
	    cout<<"Position Wrong"<<endl;
	}
}
void del(int k, int &x)
{
    if(isempty())
    {
	    cout<<"Cant delete data";
	    return;
    }
    if(k>=1 && k<=size)
    {
	    x=linear[k-1];
	    for(int i=k;i<size;i++)
	    linear[i-1]=linear[i];
	    size--;
    }
    else
    {
	    cout<<"Position Wrong"<<endl;
    }	
}
void display()
{
	if(isempty())
	{
		cout<<"Empty List"<<endl;
		return;
	}
    for(int i=0;i<size;i++)
    cout<<linear[i]<<" ";
}
int main()
{
    int n,x,pos,choice,key;
    while(1)
    {
    	cout<<endl<<endl<<endl;
    	cout<<"Aryan Jain"<<endl;
    	cout<<"1. Create"<<endl;
    	cout<<"2. Insert"<<endl;
    	cout<<"3. Deletion"<<endl;
    	cout<<"4. Output"<<endl;
    	cout<<"5. Find"<<endl;
    	cout<<"6. Search"<<endl;
    	cout<<"7. Isfull"<<endl;
    	cout<<"8. Isempty"<<endl;
    	cout<<"9. Exit"<<endl<<endl<<endl<<endl;
    	cout<<"Enter your choice:";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			{
					cout<<"Enter size of linked list:";
		    		cin>>n;
		    		create(n);
		    		break;
		    	}
		    case 2:
		    	{
		            cout<<"Enter the position where to insert data:"<<endl;
		            cin>>pos;
		            cout<<"Enter the data:";
		            cin>>x;
					insert(pos,x);
		            break;
				}
			case 3:
				{
					cout<<"Enter the position to delete:";
					cin>>pos;
					del(pos,x);
					cout<<"Deleted element: "<<x;
					break;
				}
			case 4:
				{
					display();
					break;
				}
			case 5:
				{
					cout<<"Enter the position whose data you want:"<<endl;
			        cin>>pos;
			        pos=find(pos);
			        cout<<"Data at given position is : "<<pos<<endl;
			        break;
				}
			case 6:
				{
					cout<<"Enter the data to check:"<<endl;
			       	cin>>key;
			        key=search(key);
			        cout<<"Position of data: "<<key+1<<endl;
			        break;
				}
			case 7:
				{
					pos=isfull();
					if (pos==0)
					cout<<"Memory is available to create more elements."<<endl;
					else
					cout<<"Memory full."<<endl;
					break;
				}
			case 8:
				{
					pos=isempty();
					if(pos==0)
					cout<<"Linear list is not empty."<<endl;
					else
					cout<<"Linear list is empty."<<endl;
					break;
				}
			case 9:
				{
					exit(1);
					break;
				}
			default:
				cout<<"Wrong Choice.";
		}
	}
	return 0;
}
