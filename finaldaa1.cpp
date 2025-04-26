#include<iostream>
#include<string>
using namespace std;
class mobileuser
{
	private:
		string name;
		long mobno;
		double billamt;
		public:
			void accept();
			void display();
			int sequntial_search(mobileuser m1[100],int n,int key);
			int binary_search(mobileuser m1[100],int n,int key);
			int binary_searchrecc(mobileuser m1[100],int n,int key,int low,int high);
			int partition(mobileuser m1[100],int low,int high);
			void quick_sort(mobileuser m1[100],int low,int high);
			void adjust(mobileuser m1[100],int n,int i);
			void heap_sort(mobileuser m1[100],int n);
			void combine(mobileuser m1[100],int low,int mid,int high);
			void merge_sort(mobileuser m1[100],int low,int high);
};
void mobileuser::accept()
{
	cout<<"enter the user's name mobile number and bill amount"<<endl;
	cin>>name;
	cin>>mobno;
	cin>>billamt;
}
void mobileuser::display()
{
	cout<<name<<" "<<mobno<<" "<<billamt<<endl;
}
int mobileuser::sequntial_search(mobileuser m1[100],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(key==m1[i].mobno)
		return i;
	}
	return -1;
}
int mobileuser::binary_search(mobileuser m1[100],int n,int key)
{
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==m1[mid].mobno)
		return mid;
		else if(key<m1[mid].mobno)
		high=mid-1;
		else
		low=mid+1;
	}
	return -1;
}
int mobileuser::binary_searchrecc(mobileuser m1[100],int n,int key,int low,int high)
{
	int mid;
	  if(low<=high)
	{
      		mid=(low+high)/2;
		if(key==m1[mid].mobno)
		return mid;
		else if(key<m1[mid].mobno)
	      return binary_searchrecc(m1,n,key,low,mid-1);
		else
		 return binary_searchrecc(m1,n,key,mid+1,high);
	}
	return -1;
} 
void mobileuser::quick_sort(mobileuser m1[100],int low,int high)
{
	int j;
	 if(low<high)
	{
		j=partition(m1,low,high);
		quick_sort(m1,low,j-1);
		quick_sort(m1,j+1,high);
	}
}
int mobileuser::partition(mobileuser m1[100],int low,int high)
{
	int j,i;
	mobileuser temp,pivot;
	i=low;
	j=high;
	pivot=m1[low];
	while(i<j)
	{
		 while (m1[i].mobno <= pivot.mobno && i<=high)
            i++;
        while (m1[j].mobno > pivot.mobno && j>=low)
            j--;
        if (i < j)
        {
            temp = m1[i];
            m1[i] = m1[j];
            m1[j] = temp;
        }
	}
	  temp = m1[low];
    m1[low] = m1[j];
    m1[j] = temp;
    return j;
}
void mobileuser::heap_sort(mobileuser m1[100],int n)
{
	int i;
	mobileuser temp;
	for(i=n/2-1;i>=0;i--)
	{
		adjust(m1,n,i);
	}
	temp=m1[0];
	m1[0]=m1[n-1];
	m1[n-1]=temp;
	n--;
	adjust(m1,n,0);
}
void mobileuser::adjust(mobileuser m1[100],int n,int i)
{
	int j;
	mobileuser temp;
	while(2*i<=n)
	{
		j=2*i;
		if(m1[j].mobno<m1[j+1].mobno && j<=n)
		j=j+1;
		if(m1[i].mobno>m1[j].mobno)
		break;
		else
		{
			temp=m1[i];
			m1[i]=m1[j];
			m1[j]=temp;
			i=j;
		}
	}
}
void mobileuser::merge_sort(mobileuser m1[100],int low,int high)
{
   int mid;
     if(low<high)
   {
   	    mid=(low+high)/2;
   	   merge_sort(m1,low,mid);
   	   merge_sort(m1,mid+1,high);
   	   combine(m1,low,mid,high);
	}	
}
void mobileuser::combine(mobileuser m1[100],int low,int mid,int high)
{
	int i,j,k;
	mobileuser temp[100];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(m1[i].mobno<m1[j].mobno)
		{
			temp[k]=m1[i];
			i++;
		}
		else
		{
			temp[k]=m1[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		temp[k]=m1[i];
			i++;
		k++;
	}
	while(j<=high)
	{
		temp[k]=m1[j];
			j++;
		k++;
	}
	for(i=low;i<=high;i++)
	{
		m1[i]=temp[i];
	}
}
int main()
{
	int i,key,n,loc;
    int ch;
	mobileuser m1[100],m2;
	cout<<"enter the no of user's you wish to enter"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		m1[i].accept();
		m1[i].display();
	}
	cout<<"MENUE:1.SEUQUENTIAL SEARCH 2.BINARY SEARCH 3.BINARY SEARCH RECCURSSIVE 4.QUICK SORT 5.HEAP SORT 6.MERGE SORT"<<endl;
	cout<<"ENTER YOUR CHOICE"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
	 cout<<"enter the mobile no which is to be searched"<<endl;
	  cin>>key;
	  loc=m2.sequntial_search(m1,n,key);
	  if(loc==-1)
	  cout<<"key is not present!!"<<endl;
	  else
	  cout<<"key is present at location: "<<loc<<endl;
	  break;
	  case 2:
	 cout<<"enter the mobile no which is to be searched"<<endl;
	  cin>>key;
	  loc=m2.binary_search(m1,n,key);
	  if(loc==-1)
	  cout<<"key is not present!!"<<endl;
	  else
	  cout<<"key is present at location: "<<loc<<endl;
	  break;
	  case 3:
	 cout<<"enter the mobile no which is to be searched"<<endl;
	  cin>>key;
	  loc=m2.binary_searchrecc(m1,n,key,0,n-1);
	  if(loc==-1)
	  cout<<"key is not present!!"<<endl;
	  else
	  cout<<"key is present at location: "<<loc<<endl;
	  break;
    case 4:
    	m2.quick_sort(m1,0,n-1);
    	cout<<"Sorted Array:-"<<endl;
    	for(i=0;i<n;i++)
	{
		m1[i].display();
	}
	break;
	case 5:cout<<"Sorted Array:-"<<endl;
		m2.heap_sort(m1,n);
    	for(i=0;i<n;i++)
	{
		m1[i].display();
	}
	break;
	case 6:cout<<"Sorted Array:-"<<endl;
		m2.merge_sort(m1,0,n-1);
    	for(i=0;i<n;i++)
	{
		m1[i].display();
	}
	break;
	default:
	  	cout<<"Invalid Input!!"<<endl;
    }
     return 0;
}

