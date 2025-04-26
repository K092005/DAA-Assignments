#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class node
{
   string word;
   string mean;
   node *left;
   node *right;
   friend class avl;
};
class avl
{
       node *root;
       public:
       avl()
       {
             root=NULL;
       }
       void avl_modify();
       void avl_search();
       void inorder_traversal(node *root);
       void create();
       node* avl_rec(node *curr,node *root);
       node* balance(node *temp);
       int BF(node *temp);
       int height(node *temp);
       node* LL_rotation(node *temp);
       node* RR_rotation(node *temp);
       node* LR_rotation(node *temp);
       node* RL_rotation(node *temp);
};
void avl::avl_search()
{ 
string key;
     node *temp;
     cout<<"enter the keyword word ot be searched"<<endl;
     cin>>key;
     temp=root;
     while(temp!=NULL)
     {
     if(key==temp->word)
     {
          cout<<temp->mean;
          break;
     }
     else if(temp->word<key)
     {
         temp=temp->left;
     }
     else
     {
      temp=temp->right;
     }
     }
        cout<<"key is not found!!"<<endl;
}
void avl::avl_modify()
{ 
string key,m;
     node *temp;
     cout<<"enter the kewy word ot be searched"<<endl;
     cin>>key;
     cout<<"enter new meaning"<<endl;
     cin>>m;
     temp=root;
     while(temp!=NULL)
     {
     if(key==temp->word)
     {
     temp->mean=m;
          cout<<temp->mean;
          break;
     }
     else if(temp->word<key)
     {
         temp=temp->left;
     }
     else
     {
      temp=temp->right;
     }
     }
}
void avl::inorder_traversal(node *root)
{
   if(root!=NULL)
   { 
      inorder_traversal(root->left);
      cout<<root->word<<" ";
      cout<<root->mean<<endl;
      inorder_traversal(root->right);
   }
}
node* avl::LL_rotation(node *temp)
{
cout<<"LL rotation performed"<<endl;
   node *x;
   node *y;
   x=temp->left;
   y=x->right;
   x->right=temp;
   temp->left=y;
   return x;
   
}
node* avl::RR_rotation(node *temp)
{
cout<<"RR rotation performed"<<endl;
   node *x;
   node *y;
    x=temp->right;
   y=x->left;
   x->left=temp;
   temp->right=y;
   return x;
}
node* avl::LR_rotation(node *temp)
{
cout<<"LR rotation performed"<<endl;
   temp->left=RR_rotation(temp->left);
   return (LL_rotation(temp));
}
node* avl::RL_rotation(node *temp)
{
cout<<"RL rotation performed"<<endl;
    temp->right=LL_rotation(temp->right);
   return (RR_rotation(temp));
}
int avl::height(node *temp)
{
   if(temp==NULL)
   return 0;
   else
   return (max(height(temp->left),height(temp->right))+1);
}
int avl::BF(node *temp)
{
     int bf;
     bf=height(temp->left)-height(temp->right);
     return bf;
}
node* avl::balance(node *temp)
{
     int bf;
     bf=BF(temp);
     if(bf==2)
     {
        if(BF(temp->left)<0)
        {
        cout<<"balancing factor is"<<bf<<endl;
        temp=LR_rotation(temp);
        }
        else
        {
         cout<<"balancing factor is"<<bf<<endl;
        temp=LL_rotation(temp);
        }
     }
     else if(bf==-2)
     {
        if(BF(temp->right)<0)
        {
         cout<<"balancing factor is"<<bf<<endl;
        temp=RR_rotation(temp);
        }
        else
        {
        cout<<"balancing factor is"<<bf<<endl;
        temp=RL_rotation(temp);
        }
     }
     return temp;
}
node* avl::avl_rec(node *curr,node *root)
{
   if(root==NULL)
   {
       root=new node();
       root->word=curr->word;
       root->mean=curr->mean;
       root->left=NULL;
       root->right=NULL;
   }
   else if(curr->word<root->word)
   {
      root->left=avl_rec(curr,root->left);
      root=balance(root);
   }
   else
   {
      root->right=avl_rec(curr,root->right);
      root=balance(root);
   }
   return root;
}
void avl::create()
{
    char ch;
    node *curr;
    do
    {
    curr=new node();
    cout<<"enter the word and its meaning"<<endl;
    cin>>curr->word;
    cin>>curr->mean;
    curr->left=NULL;
    curr->right=NULL;
    root=avl_rec(curr,root);
     cout<<"do you want to add more nodes(y/n)"<<endl;
      cin>>ch;
    }
    while(ch=='y');
    avl_search();
    avl_modify();
    inorder_traversal(root);

}
int main()
{
avl a1;
a1.create();
return 0;
}
