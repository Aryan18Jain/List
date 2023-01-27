#include <iostream>
using namespace std;
struct node{
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
node * create(node * p,int n)
{
    if(n==0)
    {
        cout<<"Invalid size.";
        return p;
    }
    if(isfull())
    {
        cout<<"No Memory.";
        return p;
    }
    if(n>=1)
    {
        int x;
        node * temp= new node;
        node * last;
        cout<<"Enter 1 data:";
        cin>>x;
        temp->data=x;
        temp->link=NULL;
        p=temp;
        last=temp;
        if(n==1)
        return p;
        else
        {
            int x;
            for(int i=2;i<=n;i++)
            {
                node * temp = new node;
                cout<<"Enter "<<i<<" data:";
                cin>>x;
                temp->data=x;
                temp->link=NULL;
                last->link=temp;
                last=temp;
            }
            return p;
        }
    }
    return p;
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
        p=p->link;
    }
    cout<<endl;
}
int length(node * p)
{
	int len=0;
    while(p != NULL)
    {
        len++;
        p=p->link;
    }
    return len;
}
int find(node * p,int pos)
{
	int len=length(p);
    if(pos<1 || pos>len)
    {
        cout<<"Invalid position.";
        return -54321;
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            p=p->link;
        }
        return p->data;
    }
}
int search(node * p,int key)
{
    int pos=0;
    while(p!=NULL)
    {
        pos++;
        if(p->data==key)
        {
            return pos;
        }
        p=p->link;
    }
    return -1;
}
node * insert(node * p,int pos,int x)
{
	int len=length(p);
	if(p==NULL)
	{
		cout<<"Linked list not created"<<endl;
	}
    else if(pos>0 || pos<len+2)
    {
        if(pos==1)
        {
            node * temp=new node;
            temp->data=x;
            temp->link=p;
            p=temp;
            return p;
        }
        else
        {
            node * q=p;
            for(int i=2;i<pos;i++)
            {
                q=q->link;
            }
            node * temp=new node;
            temp->data=x;
            temp->link=q->link;
            q->link=temp;
            return p;
        }
    }
    else 
	{
        cout<<"Invalid position."<<endl;
    }
}
node * del(node * p, int &x,int pos)
{
	int len=length(p);
	if(p==NULL)
	{
		cout<<"Linked list not created."<<endl;
	}
	else if(pos>0 && pos<=len)
	{
		if(pos==1)
		{
			node *q=p;
			p=q->link;
			x=q->data;
			delete(q);
			return p;
		}
		else
		{
			node* q;
			node *temp=p;
			for(int i=1;i<pos-1;i++)
			{
				temp=temp->link;
			}
			q=temp->link;
			temp->link=q->link;
			x=q->data;
			delete(q);
			len--;
			return p;
		}
	}
	else
	{
		cout<<"Wrong position."<<endl;
	}
}
void reverse(node * p)
{
	int i=1,j=length(p);
	node *q=p;
	q=p;
	while(i<j)
	{
		for(int k=0;k<i-1;k++)
		{
			q=q->link;
		}
		node *c;
		c=q;
		for(int k=i;k<j;k++)
		{
			q=q->link;
		}
		int x;
		x=c->data;
		c->data=q->data;
		q->data=x;
		i++;
		j--;
		q=p;
	}
}
node * shift_to_first(node * p, int key)
{
	int count=1;
	if(p==NULL)
	{
		cout<<"Empty list"<<endl;
		return p;
	}
	if(p->data==key)
	{
		cout<<"It is first position only."<<endl;
		return p;
	}
	node * r=p;
	node * q=p;
	while(p!=NULL)
	{
		if(p->data==key)
		{
			for(int i=2;i<count;i++)
			q=q->link;
			q->link=p->link;
			p->link=r;
			r=p;
			return r;
		}
		else
		{
			p=p->link;
			count++;
		}
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
    	cout<<"11. Shift to first place"<<endl;
    	cout<<"12. Exit"<<endl<<endl;
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
					start=del(start,x,pos);
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
					cout<<"Linked list is not empty."<<endl;
					else
					cout<<"Linked list is empty."<<endl;
					break;
				}
			case 9:
				{
					len=length(start);
					cout<<"Length of Linked list is:"<<len<<endl;
					break;
				}
			case 10:
				{
					reverse(start);
					display(start);
					break;	
				}
			case 11:
				{
					cout<<"Enter the position to shift to first:"<<endl;
			       	cin>>key;
					start=shift_to_first(start,key);
					display(start);
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
