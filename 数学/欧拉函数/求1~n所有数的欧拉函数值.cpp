void phi_table(gg n, vector<gg>& phi) {
    for (gg i = 2; i <= n; i++)
        phi[i] = 0;
    phi[1] = 1;
    for (gg i = 2; i <= n; i++)
        if (phi[i] == 0)
            for (gg j = i; j <= n; j += i) {
                if (phi[j] == 0)
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
}
