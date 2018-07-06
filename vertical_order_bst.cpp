#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<stack>
#include<map>
#include<vector>

using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
Node *newNode(int k)
{
    return new Node(k);
}
// Method that prints the bottom view.
void bottomView(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}

void bottomView(struct Node *root){
  map < int,vector <int> > m;
  stack<struct Node*> s;
  stack<int> l;
  struct Node *temp;
  temp = (struct Node*)malloc(sizeof(struct Node));
  int i,level = 0;
  if(!root){
    return;
  }
  while(1){
    while(root){
      s.push(root);
      l.push(level);
      m[level].push_back(root->data);
      root = root->left;
      level--;
    }
    if(s.empty()){
      break;
    }
    else{
      temp = s.top();
      level = l.top();
      //cout <<level <<" " <<temp->data <<endl;
      l.pop();
      s.pop();
      root = temp;
      root = root->right;
      level++;
    }
  }
  map <int,vector <int> > :: iterator it;
  for(it =m.begin(); it!=m.end();it++){
    for(i=0;i<(it->second).size();i++){
      cout <<it->second[i] <<" ";
    }
    cout <<"$";
  }
}
