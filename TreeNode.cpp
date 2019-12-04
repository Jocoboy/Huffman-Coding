#include "TreeNode.h"

TreeNode::TreeNode(char ch, int tag, int freq, TreeNode *lChild, TreeNode *rChild)
{
    this->ch = ch;
    this->tag = tag;
    this->freq = freq;
    this->lChild = lChild;
    this->rChild = rChild;
}

bool TreeNode::operator<(const TreeNode &b)
{
    return this->freq < b.freq;
}

ostream &operator<<(ostream &os, const TreeNode &n)
{
    cout << n.ch << " " << n.tag << " " << n.freq << endl;
}

int TreeNode::get_ch() const
{
    return this->ch;
}

int TreeNode::get_tag() const
{
    return this->tag;
}

void TreeNode::set_tag(int tag)
{
    this->tag = tag;
}

int TreeNode::get_freq() const
{
    return this->freq;
}

TreeNode *TreeNode::get_lChild()
{
    return this->lChild;
}

TreeNode *TreeNode::get_rChild()
{
    return this->rChild;
}