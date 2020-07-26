struct Node {
    gg left = -1, right = -1, sum = 0, lazy = 0;
};
vector<Node> tree(n << 1);  // n为原序列中数字的个数
gg getIndex(gg i) {
    gg n = tree.size() >> 1, k = (1 << (gg)log2(n + n - 1)) - n;
    return (n + i - 1 + k) % n + n;
}
void createTree(vector<gg>& A) {
    gg n = tree.size() >> 1;
    for (gg i = 1; i <= n; ++i) {
        gg p = getIndex(i);
        tree[p].left = tree[p].right = i;
        tree[p].sum = A[i];
        tree[p].lazy = 0;
    }
    for (gg i = n - 1; i > 0; --i) {
        gg child = i << 1;
        tree[i].left = min(tree[child].left, tree[child + 1].left);
        tree[i].right = max(tree[child].right, tree[child + 1].right);
        tree[i].sum = tree[child].sum + tree[child + 1].sum;
        tree[i].lazy = 0;
    }
}
void pushdown(gg i) {  //更新下层区间的值
    gg child = i << 1;
    if (child < tree.size()) {
        tree[child].lazy += tree[i].lazy;  //左子树标记累加
        tree[child].sum += tree[i].lazy * (tree[child].right - tree[child].left + 1);
    }
    if (child + 1 < tree.size()) {
        tree[child + 1].lazy += tree[i].lazy;  //右子树标记累加
        tree[child + 1].sum +=
            tree[i].lazy * (tree[child + 1].right - tree[child + 1].left + 1);
    }
    tree[i].lazy = 0;  //标记传递后清空为0
}
void update(gg root, gg left, gg right, gg v) {  //将A[left]~A[right]都增加v
    if (tree[root].left >= left && tree[root].right <= right) {
        tree[root].lazy += v;
        tree[root].sum += v * (tree[root].right - tree[root].left + 1);
        return;
    }
    gg mid = tree[root].left + (tree[root].right - tree[root].left) / 2;
    gg child = root << 1;
    tree[root].sum = 0;
    if (child < tree.size() && left <= mid) {
        update(child, left, right, v);  //往左更新
        tree[root].sum += tree[child].sum;
    }
    if (child + 1 < tree.size() && right > mid) {
        update(child + 1, left, right, v);  //往右更新
        tree[root].sum += tree[child + 1].sum;
    }
}
gg query(gg root, gg left, gg right) {
    if (tree[root].left >= left && tree[root].right <= right)
        return tree[root].sum;
    if (tree[root].lazy != 0)
        pushdown(root);
    gg sum = 0, mid = tree[root].left + (tree[root].right - tree[root].left) / 2;
    gg child = root << 1;
    if (child < tree.size() && left <= mid)
        sum += query(child, left, right);
    if (child + 1 < tree.size() && right > mid)
        sum += query(child + 1, left, right);
    return sum;
}
