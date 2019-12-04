#include "TreeNode.h"
#include "HuffmanTree.h"

int main(int argc, char const *argv[])
{
    HuffmanTree hf("aaabbbeeedacfwwwwddd");
    hf.print_original_text();
    hf.encode();
    hf.print_encoded_string();
    hf.print_encode_table();
    hf.decode();
    hf.print_decoded_text();
    return 0;
}
