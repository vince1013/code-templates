void extendGcd(gg a, gg b, gg& d, gg& x, gg& y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    } else {
        extendGcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
