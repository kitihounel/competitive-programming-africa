/**
 * This problem can be solved with a segment tree.
 * https://algo.is/t-414-aflv-competitive-programming-course-2016/, SLIDES 3 about data structures.
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100'000;

struct Node {
    int from, to, value;
    Node *left, *right;
    Node(int from, int to): from(from), to(to), value(0), left(nullptr), right(nullptr) {}
    ~Node() {
        if (left != nullptr) delete left;
        if (right != nullptr) delete right;
    }
};

Node *createTree(const vector<int> &v, int l, int r) {
    if (l > r) return nullptr;
    Node *root = new Node(l, r);
    if (l == r)
        root->value = v[l];
    else {
        int m = (l + r) / 2;
        root->left = createTree(v, l, m);
        root->right = createTree(v, m + 1, r);
        root->value += root->left != nullptr? root->left->value: 0;
        root->value += root->right != nullptr? root->right->value: 0;
    }
    return root;
}

int query(Node *root, int l, int r) {
    if (root == nullptr) return 0;
    if (l <= root->from && root->to <= r) return root->value;
    if (root->to < l) return 0;
    if (r < root->from) return 0;
    return query(root->left, l, r) + query(root->right, l, r);
}

int update(Node *root, int i, int val) {
    if (root == nullptr) return 0;
    if (root->to < i) return root->value;
    if (i < root->from) return root->value;
    if (root->from == root->to && root->from == i)
        root->value = val;
    else
        root->value = update(root->left, i, val) + update(root->right, i, val);
    return root->value;
}

int main()
{
    int k, N;

    scanf("%d\n", &N);

    vector<int> v;

    for (int j = 0; j < N; ++j) {
        scanf("%d", &k);
        v.push_back(k);
    }

    Node *root = createTree(vector<int>(MAX_N + 2, 0), 0, MAX_N + 1);
    vector<int> counters(MAX_N + 1, 0);
    vector<int> queries(N, 0);

    for (int j = N - 1; j >= 0; --j) {
        k = v[j];
        queries[j] = query(root, k + 1, MAX_N + 1);
        ++counters[k];
        update(root, k, counters[k]);
    }

    for (const auto q: queries)
        printf("%d ", q);
    printf("\n");

    delete root;

    return 0;
}

