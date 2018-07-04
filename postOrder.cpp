#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>

using namespace std;

struct node{
  int data;
  struct node *left, *right;
};

struct node* bst(struct node *root,int data){
  if(!root){
    root = (struct node*)malloc(sizeof(struct node));
    if(!root){
      cout <<"memory not alloted" <<endl;
    }
    else{
      root->data = data;
      root->left = NULL;
      root->right = NULL;
    }
  }
  else{
    if(root->data > data){
      root->left = bst(root->left,data);
    }
    else if(root->data < data){
      root->right = bst(root->right,data);
    }
  }
  return root;
}

void preorder(struct node *root){
  if(!root){
    return;
  }
  else{
    preorder(root->left);
    preorder(root->right);
    cout <<root->data <<" ";
  }
}

int main(){
  int n,i,j;
  cin >>n;
  struct node *root=NULL;
  for(i=0;i<n;i++){
    cin >>j;
    root = bst(root,j);
  }
  preorder(root);
  //levelOrder(root);
  cout <<endl;
  return 0;
}
