#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
/*class node{
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};*/
class Node 
{
    public:
    int data;
    Node *left;
    Node *right;
    Node* create(int data);
};
class Node* create(int data)
{
    class Node *n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void printlevelorder(Node* root){
    if(root==NULL)
    return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *t=q.front();
        q.pop();
        if(t!=NULL){
         cout<<t->data<<" ";
         if(t->left)
         q.push(t->left);
         if(t->right)
         q.push(t->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    } 
}
int count(Node* root)
{
    if(root==NULL)
    return 0;
    return count(root->left)+count(root->right)+1;
}
int sum(Node *root)
{
    if(root==NULL)
    return 0;
    return sum(root->left)+sum(root->right)+root->data;
}
int calheight(Node *root)
{
    if(root==NULL)
    return 0;
    return max(calheight(root->left),calheight(root->right))+1;
}
int caldia(Node *root)
{
    if(root==NULL)
    return 0;
    int lheight=calheight(root->left);
    int rheight=calheight(root->right);
    int curdia=lheight+rheight+1;
    int ldia=caldia(root->left);
    int rdia=caldia(root->right);
    return max(curdia,max(ldia,rdia));
}
//in o(n)
int caldia1(Node *root,int* height)
{
    if(root==NULL)
    {*height=0;
        return 0;}
    int lh=0,rh=0;
    
    int ldia=caldia1(root->left,&lh);
    int rdia=caldia1(root->right,&rh);
    int curdia=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(curdia,max(ldia,rdia));
}
//O(N)
int height(Node* root, int& ans)
{
    if (root == NULL)
        return 0;
 
    int left_height = height(root->left, ans);
 
    int right_height = height(root->right, ans);
 
    // update the answer, because diameter of a
    // tree is nothing but maximum value of
    // (left_height + right_height + 1) for each node
    ans = max(ans, 1 + left_height + right_height);
 
    return 1 + max(left_height, right_height);
}
 
/* Computes the diameter of binary tree with given root. */
int diameter(Node* root)
{
    if (root == NULL)
        return 0;
    int ans = INT_MIN; // This will store the final answer
    height(root, ans);
    return ans;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
class Node *root=create(1);
class Node *p=create(2);
class Node *p1=create(3);
class Node *p2=create(4);
class Node *p3=create(5);
class Node *p4=create(6);
class Node *p5=create(7);
root->left=p;
root->right=p1;
p->left=p2;
p->right=p3;
p1->left=p4;
p1->right=p5;
//printlevelorder(root);
//cout<<endl<<count(root)<<endl;
//cout<<"Sum of all Nodes "<<sum(root)<<endl;
//cout<<"Max diameter of the tree "<<caldia(root);
int height=0;
cout<<"Max diameter of the tree "<<caldia1(root,&height);
return 0;
}