#include "TreeNode.h"
#include "HuffmanTree.h"

int main(int argc, char const *argv[])
{
    /************************module test_1****************************/
    HuffmanTree hf_1("@Jocoboy");
    hf_1.print_original_text();
    hf_1.encode();
    hf_1.print_encoded_string();
    hf_1.print_encode_table();
    hf_1.decode();
    hf_1.print_decoded_text();
    hf_1.inorder_traversal(hf_1.get_root());
    // hf_1.save_as_txt();
    /************************module test_1****************************/

    /************************module test_2****************************/
    // HuffmanTree hf_2(HuffmanTree::get_inner_text());
    // hf_2.print_original_text();
    // hf_2.encode();
    // hf_2.print_encoded_string();
    // hf_2.print_encode_table();
    // hf_2.decode();
    // hf_2.print_decoded_text();
    // hf_2.append_to_txt();
    /************************module test_2****************************/

    return 0;
}


// F:\Github\repositories\Huffman-Coding\original_text.txt
// F:\Github\repositories\Huffman-Coding\huffman_tree.txt