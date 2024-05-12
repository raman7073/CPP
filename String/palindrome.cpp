/*
  Given a string s, determine if it can be arranged to form a palindrome.
*/

#include <iostream>
#include <string>
#include <vector>
/*
  Time complexity: O(n)
  Space complexity: O(1)
  The function uses an array to count the frequency of each character in the string.
  Then, it counts the number of characters with odd frequency.
*/
bool isPalindromePossible(std::string s)
{
    int count[26] = {0};
    for (char c : s)
    {
        count[c - 'a']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] % 2 != 0)
        {
            oddCount++;
        }
    }

    return oddCount <= 1;
}

/*
   A better way which also can be used to solve query based problems over a string.
   We can check if a substring from l to r can be arranged to form palindrome or not.
*/
bool isPalindromePossibleUsingXOR(std::string s)
{
    int mask = 0;
    for (char c : s)
    {
        mask ^= 1 << (c - 'a');
    }
    return mask == 0 || (mask & (mask - 1)) == 0;
}
/*
   Here a query based problem can be solved by using the following function.
*/
bool isPalindromePossibleQueryUsingXOR(std::vector<int> &v, int l, int r)
{
    int mask = v[r];
    if (l > 0)
    {
        mask ^= v[l - 1];
    }
    return mask == 0 || (mask & (mask - 1)) == 0;
}
int main()
{
    std::string s;
    std::cin >> s;

    // std::cout << (isPalindromePossible(s) ? "Yes" : "No") << std::endl;
    // std::cout << (isPalindromePossibleUsingXOR(s) ? "Yes" : "No") << std::endl;

    std::vector<int> v(s.length(), 0);
    // prepare the prefix XOR array
    v[0] = 1 << (s[0] - 'a');
    for (int i = 1; i < s.length(); i++)
    {
        v[i] = v[i - 1] ^ (1 << (s[i] - 'a'));
    }
    int q;
    std::cin >> q;
    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--;
        r--;
        std::cout << (isPalindromePossibleQueryUsingXOR(v, l, r) ? "Yes" : "No") << std::endl;
    }
    return 0;
}