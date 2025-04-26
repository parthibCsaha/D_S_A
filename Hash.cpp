mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const long long B = uniform_int_distribution<long long>(277, 2e18)(rng);

class HashedString {
private:
    long long M = 1e9 + 9;
    // long long B = 9973;
    vector<long long> pow;
    vector<long long> p_hash;
public:
    HashedString(string s) {
        p_hash.resize(s.size() + 1);
        pow.push_back(1);
        while (pow.size() <= s.size()) { 
            pow.push_back((1LL * pow.back() * (B % M)) % M); 
        }
        p_hash[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            p_hash[i + 1] = ((p_hash[i] * (B % M)) % M + s[i]) % M;
        }
    }
    long long get_hash(int start, int end) {
        long long raw_val = (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
        return (raw_val % M + M) % M;
    }
};
