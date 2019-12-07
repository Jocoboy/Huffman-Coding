#pragma once
#include <iostream>
#include <ostream>
using namespace std;

class TreeNode
{
private:
    char ch;
    int tag;
    int freq;
    TreeNode *lChild;
    TreeNode *rChild;

public:
    TreeNode(char, int, int, TreeNode *, TreeNode *);
    bool operator<(const TreeNode &);
    friend ostream &operator<<(ostream &, const TreeNode &);
    char get_ch() const;
    int get_tag() const;
    void set_tag(int);
    int get_freq() const;
    TreeNode *get_lChild();
    TreeNode *get_rChild();
};