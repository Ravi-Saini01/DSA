// 420. Strong Password Checker

// A password is considered strong if the below conditions are all met:

// It has at least 6 characters and at most 20 characters.
// It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
// It does not contain three repeating characters in a row (i.e., "Baaabb0" is weak, but "Baaba0" is strong).
// Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.

// In one step, you can:

// Insert one character to password,
// Delete one character from password, or
// Replace one character of password with another character.

// Example 1:

// Input: password = "a"
// Output: 5
// Example 2:

// Input: password = "aA1"
// Output: 3
// Example 3:

// Input: password = "1337C0d3"
// Output: 0

// Constraints:

// 1 <= password.length <= 50
// password consists of letters, digits, dot '.' or exclamation mark '!'.

class Solution
{
public:
    int strongPasswordChecker(string password)
    {
        int n = password.size();

        bool hasLower = false, hasUpper = false, hasDigit = false;

        for (char c : password)
        {
            if (islower(c))
                hasLower = true;
            else if (isupper(c))
                hasUpper = true;
            else if (isdigit(c))
                hasDigit = true;
        }

        int missingTypes = (!hasLower) + (!hasUpper) + (!hasDigit);

        // Find repeating sequences
        vector<int> repeats;
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && password[j] == password[i])
                j++;
            int len = j - i;
            if (len >= 3)
                repeats.push_back(len);
            i = j;
        }

        // Case 1: Length < 6
        if (n < 6)
        {
            return max(missingTypes, 6 - n);
        }

        // Count replacements needed without deletions
        int replace = 0;
        vector<int> mods(3, 0);

        for (int len : repeats)
        {
            replace += len / 3;
            mods[len % 3]++;
        }

        // Case 2: Length <= 20
        if (n <= 20)
        {
            return max(missingTypes, replace);
        }

        // Case 3: Length > 20
        int deleteCount = n - 20;
        int remainDelete = deleteCount;

        // Use deletions to reduce replacements

        // First delete 1 char from groups where len % 3 == 0
        int use = min(mods[0], remainDelete);
        replace -= use;
        remainDelete -= use;

        // Then delete 2 chars from groups where len % 3 == 1
        use = min(mods[1] * 2, remainDelete);
        replace -= use / 2;
        remainDelete -= use;

        // Finally delete 3 chars from remaining groups
        replace -= remainDelete / 3;

        return deleteCount + max(missingTypes, replace);
    }
};
// TC-->O(N)