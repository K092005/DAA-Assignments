#include<iostream>
using namespace std;
class user
{
    private:
		int user_id;
		int pass;
		user *next;
		friend class fb;
};
class fb
{
	public:
		user *head[100];
		int n;
	
			void accept_userdata();
			void display_userdata();
			void dft(int strver);
			void bft(int strver);
			void dft_rec(int s,int visit[100]);
			friend class stack;
			friend class queue;
};
void fb::accept_userdata()
{
	user *temp;
	user *curr;
	int i;
	char ch;
	cout<<"enter the number of users"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		head[i]=new user();
		cout<<"enter the users user id and password"<<endl;
		cin>>head[i]->user_id;
		cin>>head[i]->pass;
		head[i]->next=NULL;
	}
	  for(i=0;i<n;i++)
	  {
	  	  temp=head[i];
	  	do
	  	{
	  		cout<<"does user "<<head[i]->user_id<<" has any friends(y/n)"<<endl;
	  		cin>>ch;
	  		if(ch=='y')
	  		{ 
	  		    curr=new user();
				  cout<<"enter the friends user id and password"<<endl;
				  cin>>curr->user_id;
				  cin>>curr->pass;
				  temp->next=curr;
				  curr->next=NULL;
				  temp=curr;	
			}
		}
		   while(ch=='y');
	  }
}
void fb::display_userdata()
{
	user *temp;
	int i;
	for(i=0;i<n;i++)
	{
		temp=head[i];
		while(temp!=NULL)
		{
			cout<<temp->user_id<<" "<<temp->pass<<"->";
			temp=temp->next;
		}
		  cout<<endl;
	}
}
class stack
{
	public:
	int stack[100];
    int top=-1;
	int stkfull()
	{
		if(top==99)
			return 1;
			else 
			return 0;
	}
	int stkemp()
	{
		if(top==-1)
			return 1;
			else 
			return 0;
	}
	void push(int temp)
	{
		if(stkfull()==0)
		{
	   top++;
	   stack[top]=temp;
       } 
	   else
	   cout<<"stack is full";  
	}
	int pop()
	{
		int temp;
		if(stkemp()==0)
		{
			temp=stack[top];
			top--;
			return temp;
		}
		  else 
		  return 0;
	}
};
void fb::dft(int strver)
{
	int i,v;
	int visit[100];
	user *temp;
	stack s;
	s.push(strver);
	for(i=0;i<n;i++)
	{
		visit[i]=0;
	}
	while(s.stkemp()==0)
	{
		v=s.pop();
		if(visit[v]==0)
		{
			cout<<head[v]->user_id<<" "<<head[v]->pass<<endl;
			visit[v]=1;
		}
		  temp=head[v]->next;
		  while(temp!=NULL)
		  {
		  	if(visit[temp->user_id]==0)
		  	{
		  	    s.push(temp->user_id);
		    }
				temp=temp->next;	
		  }
	}
}
class queue
{
 public:
int queue[100];
  int front=-1;
  int rear=-1;
  int qempty()
  {
      if(front==rear)
      return 1;
      else 
      return 0;
  }
   void insert(int v)
   {
   rear++;
   queue[rear]=v;
   }
   int qdelete()
   {
       int t;
       front++;
       t=queue[front];
       return t;
   }
};
void fb::bft(int strver)
{
  int i,v;
	int visit[100];
	user *temp;
	queue q;
	q.insert(strver);
	for(i=0;i<n;i++)
	{
		visit[i]=0;
	}
	while(q.qempty()==0)
	{
		v=q.qdelete();
		if(visit[v]==0)
		{
			cout<<head[v]->user_id<<" "<<head[v]->pass<<endl;
			visit[v]=1;
		}
		  temp=head[v]->next;
		  while(temp!=NULL)
		  {
		  	if(visit[temp->user_id]==0)
		  	{
		  	     q.insert(temp->user_id);
		    }
				temp=temp->next;	
		  }
	}
}
void fb::dft_rec(int s,int visit[100])
{
       user *temp;
       cout<<head[s]->user_id<<" "<<head[s]->pass<<endl;
       visit[s]=1;
       temp=head[s]->next;
       while(temp!=NULL)
       {
            if(visit[temp->user_id]==0)
            dft_rec(temp->user_id,visit);
            temp=temp->next;
       }
}
int main()
{
	fb f;
	int s,ch;
	int  i,visit[100];
	f.accept_userdata();
	cout<<"the adjency list is:"<<endl;
	f.display_userdata();
	cout<<"MENUE:1.DEPTH FIRST TRAVERSAL 2.BREADTH FIRST TRAVERSAL 3.DEPTH FIRDT RECCURSIVE"<<endl;
	cout<<"enter the choice"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"enter the starting vertex"<<endl;
	cin>>s;
	f.dft(s);
	  break;
	  case 2:
	cout<<"enter the starting vertex"<<endl;
	cin>>s;
	f.bft(s);
	break;
	case 3:
	for(i=0;i<f.n;i++)
	{
	     visit[i]=0;
	}
	cout<<"enter the starting vertex"<<endl;
	cin>>s;
	f.dft_rec(s,visit);
	break;
	default:
		cout<<"Invalid Input!!!"<<endl;
}
	return 0;
}
