gg mypow(gg x, gg n) {
    if (n == 0)
        return 1;
    gg t = mypow(x, n / 2);
    return t * t % mod * (n % 2 == 0 ? 1 : x) % mod;
}