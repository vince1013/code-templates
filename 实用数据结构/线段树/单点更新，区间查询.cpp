struct Node {
    gg left = -1, right = -1, sum = 0;
};
vector<Node> tree(n << 1);  // n为原序列中数字的个数
gg getIndex(gg i) {  //将序列A的下标i转换成对应的tree中的下标
    gg n = tree.size() >> 1, k = (1 << (gg)log2(n + n - 1)) - n;
    return (n + i - 1 + k) % n + n;
}
void createTree(vector<gg>& A) {  //建树
    gg n = tree.size() >> 1;
    for (gg i = 1; i <= n; ++i) {
        gg p = getIndex(i);
        tree[p].left = tree[p].right = i;
        tree[p].sum = A[i];
    }
    for (gg i = n - 1; i > 0; --i) {
        tree[i].left = min(tree[i << 1].left, tree[(i << 1) + 1].left);
        tree[i].right = max(tree[i << 1].right, tree[(i << 1) + 1].right);
        tree[i].sum = tree[i << 1].sum + tree[(i << 1) + 1].sum;
    }
}
void update(gg p, gg v) {  //将A[p]增加v
    for (gg i = getIndex(p); i > 0; i >>= 1)
        tree[i].sum += v;
}
gg query(gg root, gg left, gg right) {  //查询A的[left,right]区间的和
    if (tree[root].left >= left && tree[root].right <= right)
        return tree[root].sum;
    gg sum = 0, mid = tree[root].left + (tree[root].right - tree[root].left) / 2;
    gg child = root << 1;
    if (child < tree.size() && left <= mid)
        sum += query(child, left, right);
    if (child + 1 < tree.size() && right > mid)
        sum += query(child + 1, left, right);
    return sum;
}
