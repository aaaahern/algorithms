//333 https://leetcode.com/problems/largest-bst-subtree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//time: O(n)
class Solution {
public:
    // store info for every subtree
    struct node_info {
        bool isBST;
        int min_val;
        int max_val;
        int size;
        node_info(bool _isBST, int _min_val, int _max_val, int _size):
            isBST(_isBST), min_val(_min_val), max_val(_max_val), size(_size) {}
    };

    int largestBSTSubtree(TreeNode* root) {
        int max_size = 0;
        node_info root_info = helper(root, max_size);
        return max_size;
    }
    
    node_info helper(TreeNode* node, int& max_size) {
        //consider empty tree as valid BST
        if (!node) return node_info(true, 0, 0, 0);
        //leaf node
        if (!node->left && !node->right) {
            max_size = max(1, max_size);
            return node_info(true, node->val, node->val, 1);
        }
        node_info l_info = helper(node->left, max_size);
        node_info r_info = helper(node->right, max_size);
        
        if (!l_info.isBST || !r_info.isBST) return node_info(false, 0, 0, 0);
        
        if (l_info.size > 0 && node->val < l_info.max_val) 
            return node_info(false, 0, 0, 0);
        if (r_info.size > 0 && node->val > r_info.min_val) 
            return node_info(false, 0, 0, 0);
        max_size = max(l_info.size+r_info.size+1, max_size);
        if (l_info.size == 0)
            return node_info(true, node->val, r_info.max_val, l_info.size+r_info.size+1);
        else if (r_info.size == 0)
            return node_info(true, l_info.min_val, node->val, l_info.size+r_info.size+1);
        else
            return node_info(true, l_info.min_val, r_info.max_val, l_info.size+r_info.size+1);
        
    }
};