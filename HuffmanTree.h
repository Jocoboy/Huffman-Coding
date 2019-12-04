#pragma once;
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

class HuffmanTree
{

private:
    string original_text;
    string encoded_string;
    string decoded_text;
    list<TreeNode *> node_list;
    TreeNode *root_node;
    map<char, string> encode_table;
    TreeNode *build_tree();

public:
    HuffmanTree(string);
    void inorder_traversal(TreeNode *);
    void find_path(TreeNode *, string);
    void encode();
    void decode();
    void print_encode_table();
    void print_encoded_string();
    void print_decoded_text();
    void print_original_text();
};