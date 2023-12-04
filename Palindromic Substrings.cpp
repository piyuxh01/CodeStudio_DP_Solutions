int palindromicSubstrings(string input)
{
    int count = 0;
    int n = input.length();

    // Expand around each character as the center
    for (int center = 0; center < n; center++) {
        int left = center;
        int right = center;

        // Expand for odd-length palindromic substrings
        while (left >= 0 && right < n && input[left] == input[right]) {
            count++;
            left--;
            right++;
        }

        left = center;
        right = center + 1;

        // Expand for even-length palindromic substrings
        while (left >= 0 && right < n && input[left] == input[right]) {
            count++;
            left--;
            right++;
        }
    }

    return count;
    //Write your code here
}
