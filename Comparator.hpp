#include "TreeNode.h"

class Comparator
{
public:
    bool operator()(const TreeNode *a, const TreeNode *b)
    {
        return a->get_freq() < b->get_freq();
    }
};