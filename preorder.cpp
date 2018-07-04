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
    cout <<root->data <<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

void levelOrder(struct node *root){
  struct node *temp;
  //int l=0,lef=0,rit = 0;
  temp = (struct node*)malloc(sizeof(struct node));
  queue < struct node* > q;
  q.push(root);
  while(!q.empty()){
    temp = q.front();
    q.pop();
    //cout <<temp->data <<" level " <<l <<" leftLevel " << lef << " rightLevel " << rit <<endl;
    cout <<temp->data <<" ";
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
