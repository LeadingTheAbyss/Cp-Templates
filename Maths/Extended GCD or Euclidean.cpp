// Extended GCD/Euclidean Algorithm :
// Its used to :
//  1. Find x, y for eqns where => ax + by = gcd(a, b)
//  2. Solve linear diophantine eqns. ax + by = c, where c is a multiple of gcd(a, b)
//  3. Solve linear congruences like => ax ≡ b (mod m)  
// Time Complexity : O(log n)
long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}
