/*  One way is to store all the nodes, in an array and then return. But we can do something better, instead of saving everything in an array we can use iterative inorder traversal
    and while going from bottom to up keep on checking if(--k==0) return value.

    TC: O(H+K) O(H) to reach the smallest node in the BST & O(K) to find the kth smallest from there doing an inorder search.
    Space: O(H)

 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (!s.empty() || curr)
        {
            if(curr)
            {
                s.push(curr);
                curr=curr->left;    //going left
            }
            else
            {
                curr = s.top();   //going top
                s.pop();
                if(--k == 0)
                    return curr->val;

                curr=curr->right;    //going right
            }
        }
            
        return 0;
    }
};