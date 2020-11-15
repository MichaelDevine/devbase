
#include <algorithm> 
#include <limits>

// Structure for a tree
struct Node {
    Node *left;
    Node *right;
    long value;
};

// See function "largest_path_sum" below the following utility function for the call that 
// solves the problem

// Utility function to compute the largest path sum for paths inclusive of the current node, 
// and do this recursively for the given node and all children. This function
// is indended to be used as a utility to a function to compute the largest path
// sum anywhere within an entire tree.
//
// The largest path sum at the current node is stored in *p_max_path, 
// if it is greater than the value already stored there. This, unlike the 
// return value sum, may include paths that cannot be appended to paths
// above node. 
//
// The return value is the largest sum of a path including the current node
// that can be composed into a path including the parent of this node. 
long largest_composable_path_sum(Node *node, long *p_max_path) {

    if(node == nullptr) throw std::invalid_argument( "Node is null" ); 

    // There are four possible paths that include the current node in this subtree that need to be 
    // considered here: 
    // paths, the maximum of which is stored: 
    // 1. The current node itself as a path of one node. 
    // 2. The maximal path composible from the left child with the current node.
    // 3. The maximal path composible from the right child with the current node. 
    // 4. The maximal path composible from both the left and right child and through the 
    //    the current node. 

    // 1. The current node itself as a path of one node.
    long max_in_subtree = node->value;

    // 2. The maximal path composible from the left child with the current node.
    long max_sum_left = std::numeric_limits<long>::min(), 
         max_sum_right = std::numeric_limits<long>::min();
    if(node->left != nullptr) {
        max_sum_left = largest_composable_path_sum(node->left,p_max_path);
        max_in_subtree = std::max(max_in_subtree, 
            max_sum_left + node->value);
    }

    // 3. The maximal path composible from the right child with the current node. 
    if(node->right != nullptr) {
        max_sum_right = largest_composable_path_sum(node->right,p_max_path);
        max_in_subtree = std::max(max_in_subtree, 
            max_sum_right + node->value);
    }

    // 4. The maximal path composible from both the left and right child and through the 
    //    the current node. 
    if(node->left && node->right) {
        max_in_subtree = std::max(max_in_subtree, 
            max_sum_left + max_sum_right + node->value);
    }

    // Now, if the maximum path through the current node is greater than the maximum path 
    // stored anywhere else during the algorithm, store it
    *p_max_path = std::max(*p_max_path, max_in_subtree);

    // the maxium path that can be composed by the caller with a path it includes is returned
    return std::max(node->value, std::max(max_sum_left, max_sum_right) + node->value);
}

// Find the largest sum for a path within a tree starting at node.
long largest_path_sum(Node *node) {
    long largest = std::numeric_limits<long>::min();
    largest_composable_path_sum(node, &largest);
    return largest;
};


