auto lowbit = [](gg x) { return x & (-x); };
vector<gg> c(MAX);
void update(gg x, gg v) {
    for (gg i = x; i < c.size(); i += lowbit(i))
        c[i] += v;
}
gg getSum(gg x) {
    gg sum = 0;
    for (gg i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}
