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

struct node* findMax(struct node *root){
  if(!root){
    return root;
  }
  else if(root->right == NULL){
    return root;
  }
  else{
    return findMax(root->right);
  }

}

struct node* deletes(struct node *root,int data){
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  if(!root){
    return root;
  }
  if(root->data > data){
    root->left = deletes(root->left,data);
  }
  if(root->data < data){
    root->right = deletes(root->right,data);
  }
  else{
    //if(root->left == NULL && root->right == NULL){
    //  root = NULL;
    //  return root;
    //}
    if(root->left && root->right){
      temp = findMax(root->left);
      root->data = temp->data;
      root->left = deletes(root->left,temp->data);
      return root;
    }
    else if(root->right==NULL){
      temp = root;
      root = root->left;
      free(temp);
      return root;
    }
    else if(root->left==NULL){
      temp = root;
      root = root->right;
      free(temp);
      return root;
    }
  }
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

int main(){
  int n,i,j,data;
  cin >>n;
  struct node *root=NULL,*temp = NULL;
  for(i=0;i<n;i++){
    cin >>j;
    root = bst(root,j);
  }
  cin >>data;
  temp = root;
  deletes(temp,data);
  preorder(root);
  //levelOrder(root);
  cout <<endl;
  return 0;
}
