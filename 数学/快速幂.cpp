//返回a^n%m
gg powMod(gg a, gg n, gg m) {
    if (n == 0)
        return 1 % m;
    gg x = a * a % m;
    return n % 2 == 0 ? powMod(x, n / 2, m) % m : a * powMod(x, n / 2, m) % m;
}