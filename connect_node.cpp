#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cstdlib>
#include<stdio.h>
#include<map>

using namespace std;
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  struct Node *nextRight;
};
void connect(struct Node *p);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void printSpecial(Node *root)
{
   if (root == NULL)
     return;
   Node *node = root;
   while (node != NULL)
   {
      printf("%d ", node->data);
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     connect(root);
     printSpecial(root);
     printf("\n");
     inorder(root);
     printf("\n");
  }
  return 0;
}

void connect(Node *p)
{
   // Your Code Here
  struct Node *temp;
  //int l=0,lef=0,rit = 0;
  temp = (struct Node*)malloc(sizeof(struct Node));
  queue < struct Node* > q;
  q.push(p);
  q.push(NULL);
  while(!q.empty()){
    temp = q.front();
    q.pop();
    //cout <<temp->data <<" level " <<l <<" leftLevel " << lef << " rightLevel " << rit <<endl;
    if(temp==NULL){
      q.push(NULL);
      if(q.front()==NULL){
        break;
      }
    }
    else{
      temp->nextRight = q.front();
      if(temp->left){
        q.push(temp->left);
      //lef++;
      }
      if(temp->right){
        q.push(temp->right);
      //rit++;
      }
    //l++;
    }
  }
}
