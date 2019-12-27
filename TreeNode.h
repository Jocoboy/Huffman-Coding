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
    //Addons
    string code = "";
    TreeNode *lChild;
    TreeNode *rChild;

public:
    TreeNode(char, int, int,TreeNode *, TreeNode *);
    bool operator<(const TreeNode &);
    friend ostream &operator<<(ostream &, const TreeNode &);
    char get_ch() const;
    int get_tag() const;
    int get_freq() const;
    string get_code() const;
    void set_tag(int);
    //Addons
    void set_code(string);
    TreeNode *get_lChild();
    TreeNode *get_rChild();
};