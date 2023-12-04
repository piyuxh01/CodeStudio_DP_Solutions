#include <bits/stdc++.h>
using namespace std;

string expandAroundCenter(string &str, int left, int right)
{
    int n = str.length();
    while (left >= 0 && right < n && str[left] == str[right])
    {
        left--;
        right++;
    }
    return str.substr(left + 1, right - left - 1);
}

string longestPalinSubstring(string &str)
{
    int n = str.length();
    if (n == 0)
        return "";

    string longestPalin = "";
    for (int i = 0; i < n; i++)
    {
        // Find the longest odd length palindromic substring with center at i
        string oddLengthPalin = expandAroundCenter(str, i, i);
        if (oddLengthPalin.length() > longestPalin.length())
            longestPalin = oddLengthPalin;

        // Find the longest even length palindromic substring with center at i and i+1
        string evenLengthPalin = expandAroundCenter(str, i, i + 1);
        if (evenLengthPalin.length() > longestPalin.length())
            longestPalin = evenLengthPalin;
    }

    return longestPalin;
}
