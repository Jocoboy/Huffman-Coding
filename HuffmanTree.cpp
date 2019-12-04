#include "HuffmanTree.h"
#include "Comparator.hpp"

HuffmanTree::HuffmanTree(string input_text) : original_text(input_text)
{
    encoded_string = "";
    decoded_text = "";
    map<char, int> freq_map;
    for (int i = 0; i < original_text.length(); i++)
    {
        /******************************Counting module************************************/
        // Count the frequency of each character from the original text.
        char cur_ch = original_text[i];
        if (freq_map.count(cur_ch) == 1)
        {
            // If the character is already contained in the map.
            freq_map[cur_ch]++;
        }
        else
        {
            // If not.
            freq_map.insert(make_pair(cur_ch, 1));
        }
    }
    /******************************Counting module************************************/

    /******************************Sorting module************************************/
    for (auto it = freq_map.begin(); it != freq_map.end(); it++)
    {
        node_list.push_back(new TreeNode(it->first, 0, it->second, NULL, NULL));
    }
    node_list.sort(Comparator());
    // Debug here.
    // for (auto &e : node_list)
    // {
    //     cout << *e;
    // }
    /******************************Sorting module************************************/
    root_node = build_tree();
    // Debug here.
    // inorder_traversal(root_node);
}

TreeNode *HuffmanTree::build_tree()
{
    // Special judement.
    if (node_list.size() == 1)
    {
        TreeNode *temp_node = *node_list.begin();
        // node_list.erase(node_list.begin());
        node_list.pop_front();
        return new TreeNode(NULL, 0, temp_node->get_freq(), temp_node, NULL);
    }

    TreeNode *root_node = NULL;
    while (node_list.size() > 0)
    {
        TreeNode *l_node = *node_list.begin();
        node_list.pop_front();
        // node_list.erase(node_list.begin());
        TreeNode *r_node = *node_list.begin();
        // node_list.erase(node_list.begin());
        node_list.pop_front();

        l_node->set_tag(0);
        r_node->set_tag(1);
        if (node_list.size() == 0)
        {
            root_node = new TreeNode(NULL, 0, l_node->get_freq() + r_node->get_freq(), l_node, r_node);
        }
        else
        {
            TreeNode *temp_node = new TreeNode(NULL, 0, l_node->get_freq() + r_node->get_freq(), l_node, r_node);
            if (temp_node->get_freq() > (*--node_list.end())->get_freq())
            {
                node_list.push_back(temp_node);
            }
            else
            {
                for (auto it = node_list.begin(); it != node_list.end(); it++)
                {
                    if (temp_node->get_freq() <= (*it)->get_freq())
                    {
                        node_list.insert(it, temp_node);
                        break;
                    }
                }
            }
        }
    }
    return root_node;
}

void HuffmanTree::inorder_traversal(TreeNode *local_root_node)
{
    if (local_root_node != NULL)
    {
        inorder_traversal(local_root_node->get_lChild());
        cout << *local_root_node << " ";
        inorder_traversal(local_root_node->get_rChild());
    }
}

void HuffmanTree::find_path(TreeNode *local_root_node, string path)
{
    if (local_root_node->get_lChild() == NULL || local_root_node->get_rChild() == NULL)
    {
        path.push_back((char)(local_root_node->get_tag() + '0'));
        this->encode_table.insert(make_pair(local_root_node->get_ch(), path.substr(1)));
        return;
    }
    path.push_back((char)(local_root_node->get_tag() + '0'));
    if (local_root_node->get_lChild() != NULL)
    {
        find_path(local_root_node->get_lChild(), path);
    }
    if (local_root_node->get_rChild() != NULL)
    {
        find_path(local_root_node->get_rChild(), path);
    }
}

void HuffmanTree::encode()
{
    string path = "";
    find_path(root_node, path);
    for (int i = 0; i < original_text.length(); i++)
    {
        encoded_string.append(encode_table[original_text[i]]);
    }
    // print_encoded_string();
    // print_encode_table();
}

void HuffmanTree::print_encode_table()
{
    for (auto it = encode_table.begin(); it != encode_table.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

void HuffmanTree::print_encoded_string()
{
    cout << encoded_string << endl;
}

void HuffmanTree::decode()
{
    string copid_encoded_string = this->encoded_string;
    while (copid_encoded_string.length() > 0)
    {
        for (auto it = encode_table.begin(); it != encode_table.end(); it++)
        {
            if (copid_encoded_string.substr(0, it->second.length()) == it->second)
            {
                decoded_text.push_back(it->first);
                copid_encoded_string = copid_encoded_string.substr(it->second.length());
                break;
            }
        }
    }
}

void HuffmanTree::print_decoded_text()
{
    cout << decoded_text << endl;
}

void HuffmanTree::print_original_text()
{
    cout << original_text << endl;
}