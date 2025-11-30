long long modpow(long long a, long long e, long long mod = 1e9 + 7) {
    long long r = 1;
    while (e) {
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}

// Computes LCM of all numbers % mod in a feasible manner to avoid overflows of any kind.
// Time Complexity : O(n * sqrt(max_element(A))
long long lcm_mod(const vector<long long>& arr, long long mod = 1e9 + 7) {
    map<long long, long long> max_pow;

    for (long long x : arr) {
        long long n = x;
        for (long long p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                long long cnt = 0;
                while (n % p == 0) {
                    n /= p;
                    cnt++;
                }
                max_pow[p] = max(max_pow[p], cnt);
            }
        }
        if (n > 1) {
            max_pow[n] = max(max_pow[n], 1LL);
        }
    }

    long long ans = 1;
    for (auto &[prime, exp] : max_pow) {
        ans = (ans * modpow(prime % mod, exp)) % mod;
    }
    return ans;
}
