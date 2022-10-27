#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node * link;
};
int isfull()
{
    node * temp= new  node;
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
node * create(node * p , int n)
{
	if(n==0)
	{
		cout<<"Cant create list.";
		return p;
	}
	if(isfull())
	{
		cout<<"Memory Full. Cant create linked list.";
		return p;
	}
	else
	{
		int x;
		node * temp=new node;
		cout<<"Enter 1 element:";
		cin>>x;
		temp->data=x;
		temp->link=temp;
		p=temp;
		if(n==1)
		{
			return p;
		}
		else
		{
			for(int i=2;i<=n;i++)
			{
				node * temp=new node;
				cout<<"Enter "<<i<<" element:";
				cin>>x;
				temp->data=x;
				temp->link=p->link;
				p->link=temp;
				p=temp;
			}
			return p;
		}
	}
}
void display(node* p)
{
	if(isempty(p))
	{
		cout<<"Empty list."<<endl;
	}
	else
	{
		cout<<"Elements are : ";
		node *q=p->link;
		do
		{
			cout<<q->data<<" ";
			q=q->link;
		}while(q!=p->link);
	}
}
int length(node * p)
{
	int len=0;
	if(isempty(p))
	{
		return len;
	}
	node * q=p->link;
	do
	{
		q=q->link;
		len++;
	}while(q!=p->link);
	return len;
}
int find(node * p , int pos)
{
	int len=length(p);
	node*q=p->link;
	if(p==NULL)
	{
		cout<<"List Empty."<<endl;
		return 0;
	}
	if(pos>0 && pos<=len)
	{
		
		for(int i=1;i<pos;i++)
		{
			q=q->link;
		}	
		return q->data;
	}
	else
	{
		cout<<"Invalid Position."<<endl;
		return -54321;
	}
}
int search(node * p, int key)
{
	if(p==NULL)
	{
		cout<<"Empty List."<<endl;
		return 0;
	}
	else
	{
		int count=0;
		node * q=p->link;
		do
		{
			count++;
			if(q->data==key)
			return count;
			q=q->link;
		}while(q!=p->link);
	}
	return -1;
}
node * insert(node * p , int pos , int x)
{
	int len=length(p);
	node * temp=new node;
	if(pos > 0 && pos<=len+1)
	{
		if(pos==1 && len!=0)
		{
			temp=new node;
			temp->data=x;
			node * q=p->link;
			temp->link=q;
			p->link=temp;
			return p;
		}
		else if(pos ==1 && len==0)
		{
			temp=new node;
			temp->data=x;
			temp->link=temp;
			p=temp;
			return p;
		}
		if(pos==len+1)
		{
			temp=new node;
			temp->data=x;
			temp->link=p->link;
			p->link=temp;
			p=temp;
			return p;
		}
		else
		{
			temp=new node;
			node * q=p->link;
			for(int i=1;i<pos-1;i++)
			{
				q=q->link;
			}
			temp->data=x;
			temp->link=q->link;
			q->link=temp;
			return p;
		}
	}
	else
	{
		cout<<"Invalid position.";
		return p;
	}
}
node * del(node * p , int &x,int pos)
{
	int len=length(p);
	if(pos>0 && pos<=len)
	{
		if(isempty(p))
		{
			cout<<"Empty list.";
			return p;
		}
		else if(pos==1)
		{
			node * q=p->link;
			x=q->data;
			p->link=q->link;
			delete(q);
			return p;
		}
		else if(pos==len) 
		{
			node * q=p->link;
			for(int i=1;i<pos-1;i++)
			{
				q=q->link;
			}
			q->link=p->link;
			x=p->data;
			delete(p);
			return q;
		}
		else
		{
			node * q=p->link;
			for(int i=1;i<pos-1;i++)
			{
				q=q->link;
			}
			node * c=q->link;
			x=c->data;
			q->link=c->link;
			delete(c);
			return p;
		}
	}
	else
	{
		cout<<"Invalid position.";
		return p;
	}
}
int main()
{
    int n,pos,x,choice,key,len;
    node * last=NULL;
    while(1)
    {
    	cout<<endl<<endl<<endl;
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
    	cout<<"11. Shift to first place;"<<endl;
    	cout<<"12. Exit"<<endl<<endl<<endl;
    	cout<<"Enter your choice:";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			{
    				cout<<"Enter size of linked list:";
		    		cin>>n;
		    		last=create(last,n);
		    		break;
				}
			case 2:
		    	{
		    		int x;
		            cout<<"Enter the position where to insert data:"<<endl;
		            cin>>pos;
		            cout<<"Enter the data:";
		            cin>>x;
		            last=insert(last,pos,x);
		            break;
				}
			case 3:
				{
					cout<<"Enter the position to delete:";
					cin>>pos;
					last=del(last,x,pos);
					cout<<"Deleted element: "<<x;
					break;
				}
			case 4:
				{
					cout<<"Elements are : ";
					display(last);
					break;
				}
			case 5:
				{
					cout<<"Enter the position whose data you want:"<<endl;
			        cin>>pos;
			        pos=find(last,pos);
			        cout<<"Data at given position is : "<<pos<<endl;
			        break;
			    }
			case 6:
				{
					cout<<"Enter the data to check:"<<endl;
			       	cin>>key;
			        key=search(last,key);
			        cout<<"Position at which given data is present : "<<key<<endl;
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
					pos=isempty(last);
					if(pos==0)
					cout<<"Linked list is not empty."<<endl;
					else
					cout<<"Linked list is empty."<<endl;
					break;
				}
			case 9:
				{
					len=length(last);
					cout<<"Length of Linked list is:"<<len<<endl;
					break;
				}	
			case 12:
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
