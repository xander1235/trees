#include <iostream>
#include<stdio.h>
#include<stack>
#include<cstdlib>
#include<map>
#include<vector>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
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
     cout << isBST(root) << endl;
  }
  return 0;
}

bool isBST(struct Node *root){
  if(!root){
    return 1;
  }
  int i,k=1;
  struct Node *temp;
  temp = (struct Node*)malloc(sizeof(struct Node));
  stack < struct Node* > s;
  vector < int > v;
  while(1){
    while(root){
      s.push(root);
      root = root->left;
    }
    if(s.empty()){
      break;
    }
    else{
      temp = s.top();
      s.pop();
      v.push_back(temp->data);
      root = temp;
      root = root->right;
    }
  }
  for(i=0;i<v.size()-1;i++){
    if(v[i]<v[i+1]){
      k=1;
    }
    else{
      k=0;
      break;
    }
  }
  return k;
}
