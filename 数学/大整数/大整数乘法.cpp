string multiply(const string& num1, const string& num2) {
    gg m = num1.size(), n = num2.size();
    string ans(n + m, '0');
    for (gg i = m - 1; i >= 0; --i) {
        for (gg j = n - 1; j >= 0; --j) {
            gg k = (num1[i] - '0') * (num2[j] - '0');
            gg t = k + (ans[i + j + 1] - '0');
            ans[i + j] += t / 10;
            ans[i + j + 1] = t % 10 + '0';
        }
    }
    ans.erase(0, ans.find_first_not_of("0"));
    return ans.empty() ? "0" : ans;
}
