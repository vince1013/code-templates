//以下代码实现了小根配对堆
struct Node {
    gg val;
    Node *child = nullptr, *sibling = nullptr, *prev = nullptr;
    Node(gg v) : val(v) {}
};
Node* findMin(Node* x) { return x; }
Node* merge(Node* a, Node* b) {
    if (not a) {
        return b;
    }
    if (not b) {
        return a;
    }
    if (a->val > b->val) {  //要改成大根配对堆，将这一行的>变成<即可
        swap(a, b);
    }
    a->prev = nullptr;
    b->prev = a;
    b->sibling = a->child;
    if (a->child) {
        a->child->prev = b;
    }
    a->child = b;
    return a;
}
Node* insert(Node* x, gg val) { return merge(x, new Node(val)); }
Node* merges(Node* x) {
    if (not x) {
        return x;
    }
    x->prev = nullptr;
    if (not x->sibling) {
        return x;
    }
    Node *a = x->sibling, *b = a->sibling;
    x->sibling = a->sibling = nullptr;
    a->prev = nullptr;
    return merge(merge(x, a), merges(b));
}
//如果先使用findMin，再使用deleteMin，务必不要将前面得到的findMin的返回值再合并到堆中，应该重建一个结点
Node* deleteMin(Node* x) { return merges(x->child); }
// root为堆的根，x为要操作的节点，v为新的权值，调用时需保证x->val>=v
Node* decreaseKey(Node* root, Node* x, gg v) {
    x->val = v;
    if (not x->prev)
        return x;
    if (x->prev->child == x) {
        x->prev->child = x->sibling;
    } else {
        x->prev->sibling = x->sibling;
    }
    x->sibling->prev = x->prev;
    x->sibling = nullptr;
    x->prev = nullptr;
    return merge(root, x);
}