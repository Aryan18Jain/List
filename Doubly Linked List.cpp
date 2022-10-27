#include <iostream>
using namespace std;

struct node{
    node*prev;
    int data;
    node*next;
};
int isfull()
{
	node * temp= new node;
	if(temp!=NULL)
	{
		delete(temp);
		return 0;
	}
	else
	{
		return 1;
	}		
}
int isempty(node * p)
{
	if(p==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
node*create(node*p,int n)
{
	if(isfull())
	{
		cout<<"Memory Full"<<endl;
		return p;
	}
    if(n<=0)
	{
        cout<<"Can't create doubly linked list"<<endl;
        return p;
    }
    else
	{
        int x;
        node*temp=new node;
        node*last;
        temp->prev=temp->next=NULL;
        cout<<"Enter 1 Element"<<endl;
        cin>>x;
        temp->data=x;
        p =temp;
        last=temp;
        if(n==1)
		{
            return p;
        }
        else
		{
            int i;
            for(i=2;i<=n;i++)
			{
                temp=new node;
                cout<<"Enter "<<i<<" Element"<<endl;
                cin>>x;
                temp->data=x;
                last->next=temp;
                temp->prev=last;
                temp->next=NULL;
                last=temp;
            }
            return p;
        }
    }
}
void display(node * p)
{
	if(p==NULL)
	{
		cout<<"No elements."<<endl;
	}
	cout<<"Elements are : ";
	while(p != NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}
int length(node * p)
{
	int len=0;
	while(p != NULL)
	{
		len++;
		p=p->next;
	}
	return len;
}
int find(node * p,int pos)
{
    int len =length(p);
    if(pos<0 || pos>len)
	{
        cout<<"Invalid position"<<endl;
        return -12345;
    }
    else
	{
       for(int i=1;i<=pos-1;i++)
	   {
         p=p->next;
       }
        return p->data;
    }
        return-1;
}
int search(node * p,int key)
{
    if(p==NULL)
	{
        cout<<"Empty linked list"<<endl;
        return -12345;
    }
    int pos=1;
    while(p!=NULL)
	{
        if(p->data!=key)
		{
        	p=p->next;
      		pos++;
    	}
    	else
		{
        return pos;
   		}
    }
    return -1;
}
node * insert(node*p,int pos,int x)
{
    int len=length(p);
    if(pos<0 || pos>len+1)
	{
        cout<<"Invalid position"<<endl;
        return p;
    }
    if(pos==1 && p!=NULL)
	{
        node*temp=new node;
        temp->prev=temp->next=NULL;
        temp->data=x;
        temp->next=p;
        p->prev=temp;
        p=temp;
        return p;
    }
    else if(pos==1 && p==NULL)
	{
        node*temp=new node;
        temp->prev=temp->next=NULL;
        temp->data=x;
        p=temp;
        return p;
    }
    else if(pos==len+1)
	{
        node*temp=new node;
        node*last=p;
        temp->data=x;
        temp->prev=temp->next=NULL;
        for(int i=1;i<len;i++)
		{
            last=last->next;
        }
        last->next=temp;
        temp->prev=last;
        return p;
    }
    else
	{
        node*q=p;
        node*c;
        for(int i=2;i<pos;i++)
		{
            q=q->next;
        }
        c=q->next;
        node*temp=new node;
        temp->prev=temp->next=NULL;
        temp->data=x;
        q->next=temp;
        temp->next=c;
        temp->prev=q;
        c->prev=temp;
        return p;
    }
}
node * del(node * p,int pos,int &x)
{
    node*c=p;
    node*r,*q;
    int len =length(p);
    if(pos<0 || pos>len)
	{
        cout<<"Invalid position"<<endl;
        return p;
    }
    if(pos==1)
	{
        x=p->data;
        c=c->next;
		delete p;
        return c;
    }
    else
	{
        for(int i=1;i<pos-1;i++)
		{
            c=c->next;
        }
        q=c->next;
        r=q->next;
        x=q->data;
        c->next=q->next;
        r->prev=q->prev;
        delete q;
        return p;
    }
}
void reverse(node * p)
{
	int len=length(p);
	for(int i=1;i<len;i++)
	{
		p=p->next;
	}
	cout<<"Reverse elements are:"<<endl;
	for(int i=1;i<=len;i++)
	{
		cout<<p->data<<" ";
		p=p->prev;
	}
}
int main()
{
    int n,pos,x,choice,key,len;
    node * start=NULL;
    while(1)
    {
    	cout<<endl<<endl;
    	cout<<"Aryan Jain"<<endl;
    	cout<<"1. Create"<<endl;
    	cout<<"2. Insert"<<endl;
    	cout<<"3. Deletion"<<endl;
    	cout<<"4. Output"<<endl;
    	cout<<"5. Find"<<endl;
    	cout<<"6. Search"<<endl;
    	cout<<"7. Isfull"<<endl;
    	cout<<"8. Isempty"<<endl;
    	cout<<"9. length"<<endl;
    	cout<<"10. Reverse"<<endl;
    	cout<<"11. Exit"<<endl<<endl;
    	cout<<"Enter your choice:";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			{
					cout<<"Enter size of linked list:";
		    		cin>>n;
		    		start=create(start,n);
		    		break;
		    	}
		    case 2:
		    	{
		    		int x;
		            cout<<"Enter the position where to insert data:"<<endl;
		            cin>>pos;
		            cout<<"Enter the data:";
		            cin>>x;
		            start=insert(start,pos,x);
		            break;
				}
			case 3:
				{
					cout<<"Enter the position to delete:";
					cin>>pos;
					start=del(start,pos,x);
					cout<<"Deleted element: "<<x;
					break;
				}
			case 4:
				{
					display(start);
					break;
				}
			case 5:
				{
					cout<<"Enter the position whose data you want:"<<endl;
			        cin>>pos;
			        pos=find(start,pos);
			        cout<<"Data at given position is : "<<pos<<endl;
			        break;
				}
			case 6:
				{
					cout<<"Enter the data to check:"<<endl;
			       	cin>>key;
			        key=search(start,key);
			        cout<<"Position at which data is present: "<<key<<endl;
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
					pos=isempty(start);
					if(pos==0)
					cout<<"Doubly Linked list is not empty."<<endl;
					else
					cout<<"Doubly Linked list is empty."<<endl;
					break;
				}
			case 9:
				{
					len=length(start);
					cout<<"Length of Doubly Linked list is:"<<len<<endl;
					break;
				}
			case 10:
				{
					reverse(start);
					break;	
				}
			case 11:
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
