class Solution {
// bool isPrime(int x) {
//     if (x < 2) return false;
//     if (x == 2) return true;
//     if (x % 2 == 0) return false;
//     for (int d = 3; d * d <= x; d += 2) {
//         if (x % d == 0)
//             return false;
//     }
//     return true;
// }
// private:
// vector<int>getPrimes(int left, int right){
//     vector<int>prime;
//     for(int i=left;i<=right;i++){
//         if(isPrime(i)){
//             prime.push_back(i);
//         }
//     }
//     return prime;
// }

// optimize algo for finding Primes in range[L,R]--->Prahlad_07

// Resources--->https://github.com/kimwalisch/primesieve/wiki/Segmented-sieve-of-Eratosthenes

private:
vector<int> getPrimes(int left, int right) {
    if (left > right) return {};
    
    int limit = sqrt(right) + 1;
    vector<bool> is_prime(limit + 1, true);
    vector<int> base_primes;
    
    // Step 1: Find primes up to sqrt(right) using Sieve of Eratosthenes
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            base_primes.push_back(i);
            for (int j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
    
    // Step 2: Mark non-primes in range [left, right]
    vector<bool> is_prime_range(right - left + 1, true);
    
    for (int p : base_primes) {
        int start = max(p * p, (left + p - 1) / p * p);
        for (int j = start; j <= right; j += p)
            is_prime_range[j - left] = false;
    }
    
    if (left == 1) is_prime_range[0] = false;
    
    // Step 3: Collect remaining primes
    vector<int> primes;
    for (int i = 0; i < is_prime_range.size(); i++) {
        if (is_prime_range[i])
            primes.push_back(i + left);
    }
    
    return primes;
}

vector<char> segmentedSieve(long long L, long long R) {
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}




public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes=getPrimes(left,right);
        if(primes.size()<2)return{-1,-1};
        int diff=INT_MAX;
        int a=-1,b=-1;
        for(int i=1;i<primes.size();i++){
            int temp=primes[i]-primes[i-1];
            if(temp<diff){
                a=primes[i-1];
                b=primes[i];
                diff=temp;
            }
        }
        return {a,b};
    }
};
