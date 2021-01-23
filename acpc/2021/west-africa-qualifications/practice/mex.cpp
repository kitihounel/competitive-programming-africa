#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 2'000'000'000;

struct SegmentTree {
    SegmentTree *left, *right;
    int from, to, value;
    SegmentTree(int from, int to): from(from), to(to), left(NULL), right(NULL), value(INF) {}
    ~SegmentTree() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};

SegmentTree *build(const vector<int> &arr, int l, int r) {
    if (l > r) {
        return NULL;
    }

    SegmentTree *tree = new SegmentTree(l, r);

    if (l == r) {
        tree->value = arr[l];
    } else {
        int m = (l + r) / 2;
        
        tree->left = build(arr, l, m);
        tree->right = build(arr, m + 1, r);
        
        if (tree->left != NULL) {
            tree->value = min(tree->value, tree->left->value);
        }
        if (tree->right != NULL) {
            tree->value = min(tree->value, tree->right->value);
        }
    }
    return tree;
}

int query(SegmentTree *tree, int l, int r) {
    if (tree == NULL) {
        return INF;
    }
    if (l <= tree->from && tree->to <= r) {
        return tree->value;
    }
    if (tree->to < l || r < tree->from)  {
        return INF;
    }

    return min(query(tree->left, l, r), query(tree->right, l, r));
}

// Update is not needed, but we give its implementation.
int update(SegmentTree *tree, int i, int value) {
    if (tree == NULL) {
        return INF;
    }
    if (tree->to < i || i < tree->from) {
        return tree->value;
    }

    if (tree->from == tree->to && tree->from == i) {
        tree->value = value;
    } else {
        tree->value = min(update(tree->left, i, value), update(tree->right, i, value));
    }

    return tree->value;
}

int main()
{
    int t;
    int n, q, l, r;
    int m;

    cin >> t;
    while (t > 0)
    {
        cin >> n >> q;

        vector<int> v(n);

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        SegmentTree *tree = build(v, 0, n - 1);

        for (int i = 0; i < q; ++i) {
            cin >> l >> r;
            --l;
            --r;
            m = min(query(tree, 0, l - 1), query(tree, r + 1, n - 1));
            // If the query asks mex(1, n) we have to return n + 1 instead of INF.
            cout << min(m, n + 1) << endl;
        }

        delete tree;
        --t;
    }
    
    return 0;
}
