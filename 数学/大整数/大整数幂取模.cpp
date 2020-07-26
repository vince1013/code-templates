//?a^n%m
long long powMod(long long a, long long n, long long m) {
    if (n == 0)
        return 1;
    long long x = a * a % m;
    return n % 2 == 0 ? powMod(x, n / 2, m) % m : a * powMod(x, n / 2, m) % m;
}
gg superPow(long long a, string& b, long long mod) {
    a %= mod;
    if (b.empty())
        return 1;
    gg k = b.back();
    b.pop_back();
    return powMod(superPow(a, b), 10) * powMod(a, k) % mod;
}
