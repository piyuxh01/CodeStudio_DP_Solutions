int mod = 1000000007;

long long func(vector<long long> &sumArray, long long x, long long n) {

 

    // Number of times the given array comes completely upto index x.

    long long count = (x / n) % mod;

 

    long long res = (count * sumArray[(int) n]) % mod;

 

    // Adding the remaining elements sum.

    res = (res + sumArray[(int) (x % n)]) % mod;

 

    return res;

}

 

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {

 

    // It stores answer for each query.

    vector<int> ans;

 

    // It store cumulative sum where sumArray[i] = sum(A[0]+..A[i]).

    vector<long long> sumArray(n + 1);

 

    for (int i = 1; i <= n; i++) {

        sumArray[i] = (sumArray[i - 1] + arr[i - 1]) % mod;

    }

 

    // Traversing the given queries.

    for (int i = 0; i < queries.size(); i++) {

        vector<long long> range = queries[i];

        long long l = range[0];

        long long r = range[1];

 

        // It stores the prefix sum from index 0 to index r in an infinite array.

        long long rsum = func(sumArray, r, n);

 

        // It stores the prefix sum from index 0 to index l-1 in an infinite array.

        long long lsum = func(sumArray, l - 1, n);

 

        // Add answer for each query.

        ans.push_back((int) ((rsum - lsum + mod) % mod));

 

    }

 

    return ans;

    
 }

