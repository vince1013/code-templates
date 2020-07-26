gg read() {
    gg x = 0;
    int f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}