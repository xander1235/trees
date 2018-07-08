#include <iostream>
#include<stdio.h>
#include<stack>
#include<cstdlib>
#include<map>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

void boundaryTraversal(struct Node *root);
/* Driver program to test size function*/
int main()
{
  int t,K=0;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
     boundaryTraversal(root);
     cout << endl;
  }
  return 0;
}

void boundaryTraversal(struct Node* root){
  struct Node *temp = new struct Node;
  stack <struct Node*> s1,s2;
  s1.push(root);
  while(!s1.empty() || !s2.empty()){
    while(!s1.empty()){
      temp = s1.top();
      s1.pop();
      cout <<temp->data <<" ";
      if(temp->right){
        s2.push(temp->right);
      }
      if(temp->left){
        s2.push(temp->left);
      }
    }
    while(!s2.empty()){
      temp = s2.top();
      s2.pop();
      cout <<temp->data <<" ";
      if(temp->left){
        s1.push(temp->left);
      }
      if(temp->right){
        s1.push(temp->right);
      }
    }
  }
}
