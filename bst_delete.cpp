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

void deletes(struct node *root,int data){
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  if(!root){
    cout <<"not a element in a tree" <<endl;
    return;
  }
  else{
    if(root->data == data){
      //one child
      if(root->left && root->right==NULL){
        temp = root->left->left;
        root->left = NULL;
        root = temp;
      }
      else if(root->right && root->left == NULL){
        temp = root->right;
        root = temp;
      }
      //two childs

    }
    else if(root->data > data){
      if(root->left){
        deletes(root->left,data);
      }
    }
    else{
      if(root->right){
        deletes(root->right,data);
      }
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
  struct node *root=NULL;
  for(i=0;i<n;i++){
    cin >>j;
    root = bst(root,j);
  }
  cin >>data;
  deletes(root,data);
  preorder(root);
  //levelOrder(root);
  cout <<endl;
  return 0;
}
