#ifndef KD_TREE_HXX
#define KD_TREE_HXX

#include <list>
#include <queue>
#include <vector>

struct feature {
    float x;
    float y;
    std::vector<float> key;

    feature ();
    feature (float x, float y, int n);
};

struct kd_node {
    kd_node *left;
    kd_node *right;
    int     ki;
    float   kv;
    std::list<int> idx_list;  // the list of the feature index

    kd_node ();
};


struct mq_node {
    kd_node *node;
    float dist;
    mq_node(kd_node *, float);
};
struct mq_node_comparator {
    inline bool operator() (const mq_node& a, const mq_node& b) 
    {
        return a.dist > b.dist;
    }
};

class kd_tree {
    private :
        kd_node *root;
        int     nKey;
        std::vector<feature> feat_list;

        void set_partition(kd_node *);
        void divide_kd_node(kd_node *);

    public : 
        kd_tree(std::vector<feature> feat_list, int nKey);
        int bbf_search(const feature &feat, const int M=5); 
};


#endif
