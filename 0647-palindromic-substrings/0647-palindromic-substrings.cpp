class Solution {
public:
    int longestPalindrome(string s) {
       string s_prime = "#";
       for (char c : s) {
           s_prime += c;
           s_prime += "#";
       }


       int n = s_prime.length();
       vector<int> palindrome_radii(n, 0);
       int center = 0;
       int radius = 0;


       for (int i = 0; i < n; i++) {
           int mirror = 2 * center - i;


           if (i < radius) {
               palindrome_radii[i] = min(radius - i, palindrome_radii[mirror]);
           }


           while (i + 1 + palindrome_radii[i] < n &&
                  i - 1 - palindrome_radii[i] >= 0 &&
                  s_prime[i + 1 + palindrome_radii[i]] ==
                      s_prime[i - 1 - palindrome_radii[i]]) {
               palindrome_radii[i]++;
           }


           if (i + palindrome_radii[i] > radius) {
               center = i;
               radius = i + palindrome_radii[i];
           }
       }

        int ans=0;
        for(int i=0;i<palindrome_radii.size();i++)
        {
            ans+=(palindrome_radii[i]+1)/2;
        }
        return ans;

    
   }

    int countSubstrings(string s) {
        return longestPalindrome(s);
    }
};