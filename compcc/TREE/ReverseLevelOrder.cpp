// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

 // } Driver Code Ends
/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    stack<vector<int>> reverseLevelOrder(Node* node)
    {
      //Your code here
      stack<vector<int>> stk;
      if (node == nullptr) {
          return stk;
      }
      queue<Node*> q;
      q.push(node);

      
      Node* curr = new Node();
      int level = 1;
      
      while (q.empty() == false) {
            int sibLen = q.size();
            // cout << "\nlevel " << level++ << " : ";
            vector<int> stckans;
            while (sibLen--) {

                curr = q.front();
                // cout << curr->data << " ";
                q.pop();
                stckans.push_back(curr->data);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            stk.push(stckans);
          
      }
      
    //   return ans;
      return stk;
    }
};



/* Driver program to test above functions*/
int main()
{
    struct Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
 
    cout << "Level Order traversal of binary tree is \n";
    
    Solution ob;
    stack<vector <int>> res = ob.reverseLevelOrder(root);
    int j = 1;
    while (res.empty() == false) {
        vector<int> ans = res.top();
        res.pop();
        cout << "Level " << j++ << " : ";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    // for (int i : res) cout << i << " ";
    cout << endl;

    return 0;
}

  // } Driver Code Ends