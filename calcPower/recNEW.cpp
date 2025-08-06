// const int M=1e9+7;

// int powm(int a, int b) {
//     if (b == 0) return 1;
//     ll res = powm(a, b / 2); // Use long long for intermediate results
//     res = (res * res) % M;  // Squaring the result
//     if (b & 1) {            // If b is odd
//         res = (res * a) % M;
//     }
//     return res;
// }