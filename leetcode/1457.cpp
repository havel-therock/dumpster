// 1457. Pseudo Palindromic Paths In Binary Tree



#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Definition for a bin
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};


// Imprve with finding which nodes has other child to check and after detecting the leafe just jump to the one that make
// sense and not step back by one
// not enough
// change the algorithm
//
//
// 1 idea use DFS to travers binary tree
//
// 2 idea going down the tree count values and just check at the leafs if the counts are even... or has on odd  valu
// incase of odd number of nodes
//
class Solution
{
  public:
    int pseudoPalindromicPaths(TreeNode* root)
    {
        //  uint32_t pseudo_counter = 0;
        //  std::vector<std::vector<uint8_t>> all_paths = generate_all_paths(root);


        //  for (auto path : all_paths) {
        //      if (is_pseudo_palindromic(path)) {
        //          pseudo_counter++;
        //      }
        //  }
        //  return pseudo_counter;
        return result_dfs_fast(root);
    }

  private:

    void dfs(TreeNode* node, std::array<bool, 10> pseudo_palindromic_check, uint32_t* counter) {
            if (node == nullptr){
                return;
            }
            // update_pseudo_palindromic_check(node->val, pseudo_palindromic_check);
            pseudo_palindromic_check[node->val] = !pseudo_palindromic_check[node->val];
            if (is_leaf_node(node)) {
                uint8_t check = 0;
                for (bool val : pseudo_palindromic_check) {
                   if(val) {
                        check++;
                   }
                }
                if(check < 2) {
                    (*counter)++;
                }
            } else {
                dfs(node->left, pseudo_palindromic_check, counter);
                dfs(node->right, pseudo_palindromic_check, counter);
            }
    }

    int result_dfs_fast(TreeNode* root) {
        std::array<bool, 10> pseudo_palindromic_check {};
        uint32_t counter = 0;

        dfs(root, pseudo_palindromic_check, &counter);

        return counter;
    }

    void update_pseudo_palindromic_check(uint8_t val, std::unordered_set<uint8_t>& pseudo_palindromic_check) {
            auto it = pseudo_palindromic_check.find(val);
            if (it == pseudo_palindromic_check.end()) {
                pseudo_palindromic_check.insert(val);
            } else {
                pseudo_palindromic_check.erase(it);
            }
    }

    bool is_pseudo_palindromic_fast(TreeNode* node, const std::unordered_map<TreeNode*, TreeNode*>& parents_map)
    {
        TreeNode* current = node;
        std::unordered_set<uint8_t> values_in_path;
        while (current != nullptr) {
            auto it = values_in_path.find(current->val);
            if (it == values_in_path.end()) {
                values_in_path.insert(current->val);
            } else {
                values_in_path.erase(it);
            }

            current = parents_map.at(current);
        }

        return values_in_path.size() < 2;
    }


    int resultDFS(TreeNode* root)
    {
        uint32_t counter = 0;
        TreeNode* current_node;
        std::unordered_map<TreeNode*, TreeNode*> parents_map;
        std::stack<TreeNode*> to_visit;
        std::unordered_set<TreeNode*> visited;

        to_visit.push(root);
        parents_map.insert({root, nullptr});

        while (!to_visit.empty()) {
            TreeNode* current_node = to_visit.top();
            to_visit.pop();
            visited.insert(current_node);
            if (is_leaf_node(current_node)) {
                if(is_pseudo_palindromic_fast(current_node, parents_map)) {
                    counter++;
               }
            } else /* add childs to (to_visit) */ {
                if (current_node->left != nullptr && visited.find(current_node->left) == visited.end()) {
                    to_visit.push(current_node->left);
                    parents_map.insert({current_node->left, current_node});
                }
                if (current_node->right != nullptr && visited.find(current_node->right) == visited.end()) {
                    to_visit.push(current_node->right);
                    parents_map.insert({current_node->right, current_node});
                }
            }
        }

        return counter;
    }


    inline bool is_leaf_node(TreeNode* node) { return (node->left == nullptr && node->right == nullptr); }

    std::vector<uint8_t> dump_path_finder(std::vector<TreeNode*> path_finder)
    {
        std::vector<uint8_t> path;
        for (auto node : path_finder) {

            path.push_back(node->val);
        }
        return path;
    }

    // std::vector<std::vector<uint8_t>> generate_all_paths(TreeNode* root)
    uint32_t result(TreeNode* root)
    {
        // std::vector<std::vector<uint8_t>> all_paths;
        std::vector<TreeNode*> path_finder;
        std::unordered_set<TreeNode*> visited_nodes;
        TreeNode* current_node = root;
        uint32_t counter = 0;
        auto push_back_both = [&path_finder, &visited_nodes](TreeNode* current_node) {
            path_finder.push_back(current_node);
            visited_nodes.insert(current_node);
        };

        push_back_both(current_node);
        while (!path_finder.empty()) {

            if (is_leaf_node(path_finder.back())) {
                if (is_pseudo_palindromic(path_finder)) {
                    counter++;
                }
            }

            if (current_node->left != nullptr && visited_nodes.find(current_node->left) == visited_nodes.end()) {

                current_node = current_node->left;
                push_back_both(current_node);
            } else if (current_node->right != nullptr &&
                       visited_nodes.find(current_node->right) == visited_nodes.end()) {

                current_node = current_node->right;
                push_back_both(current_node);
            } else /* both_visited or leaf */ {
                path_finder.pop_back();
                if (!path_finder.empty()) {
                    current_node = path_finder.back();
                }
            }
        }

        // return all_paths;
        return counter;
    }


    bool is_pseudo_palindromic(std::vector<TreeNode*> binary_path)
    {
        std::vector<uint8_t> bp;
        for (const auto& node : binary_path)
            bp.push_back(node->val);
        return is_pseudo_palindromic(bp);
    }
    bool is_pseudo_palindromic(std::vector<uint8_t> binary_path)
    {
        std::vector<uint8_t> binary_path_backup = binary_path;
        do {
            if (is_palindrom(binary_path)) {
                return true;
            }
            std::next_permutation(binary_path.begin(), binary_path.end());
        } while (binary_path_backup != binary_path);

        return false;
    }

    bool is_palindrom(std::vector<uint8_t> binary_path)
    {
        return std::equal(binary_path.begin(), binary_path.begin() + binary_path.size() / 2, binary_path.rbegin());
    }
};


int main(int argc, char** argv)
{
    Solution s;

    TreeNode root = TreeNode(2);
    root.left = new TreeNode(3);
    root.left->left = new TreeNode(3);
    root.left->right = new TreeNode(1);


    root.right = new TreeNode(1);
    root.right->right = new TreeNode(1);

    std::cout << s.pseudoPalindromicPaths(&root) << "\n";
    return 0;
}
