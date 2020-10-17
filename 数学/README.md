1. 加减乘的同余式
$$(a+b)\ mod\ n=((a\ mod\ n)+(b\ mod\ n))\ mod\ n$$
$$(a-b)\ mod\ n=((a\ mod\ n)-(b\ mod\ n)+n)\ mod\ n$$
$$(ab)\ mod\ n=((a\ mod\ n)(b\ mod\ n))\ mod\ n$$
2. $a\equiv b (mod\ n)$的含义是是`a和b除以n的余数相同`，其充要条件是`a-b是n的整数倍`。
3. 如果$ax\equiv1(mod\ n)$，则称$x$为$a\ mod\ n$的逆元。当$gcd(a,n)=1$时，方程$ax\equiv1(mod\ n)$有唯一解；否则，该方程无解。
4. 通常$a\ mod\ n$的逆元可以计算为$a^{p-2}$（$p$为一个相当大的素数，例如$10^9+7$），那么$(\frac {a} {b})\ mod\ n=(a*b^{p-2})\ mod\ n$。
5. 有重复元素的全排列：有k种元素，第i种元素有$n_i$个，则$全排列个数=\frac {(n_1+n_2+ \cdots +n_k)!} {n_1!n_2! \cdots n_k!}$
6. 可重复选择的组合：有n个不同元素，每个元素可以选多次，一共选k个元素，则$方案数=C(k+n-1,k)$
