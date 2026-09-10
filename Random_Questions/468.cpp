// 468. Validate IP Address

// Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.

// A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.

// A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

// 1 <= xi.length <= 4
// xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
// Leading zeros are allowed in xi.
// For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

// Example 1:

// Input: queryIP = "172.16.254.1"
// Output: "IPv4"
// Explanation: This is a valid IPv4 address, return "IPv4".
// Example 2:

// Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
// Output: "IPv6"
// Explanation: This is a valid IPv6 address, return "IPv6".
// Example 3:

// Input: queryIP = "256.256.256.256"
// Output: "Neither"
// Explanation: This is neither a IPv4 address nor a IPv6 address.

// Constraints:

// queryIP consists only of English letters, digits and the characters '.' and ':'.

class Solution
{
public:
    string validateIPv4(string ip)
    {
        if (ip.front() == '.' || ip.back() == '.')
            return "Neither";
        vector<string> components;
        string current;
        for (char ch : ip)
        {
            if (ch == '.')
            {
                components.push_back(current);
                current.clear();
            }
            else
            {
                current += ch;
            }
        }
        components.push_back(current);
        if (components.size() != 4)
            return "Neither";
        for (string comp : components)
        {
            if (comp.empty() || comp.length() > 3)
                return "Neither"; // Leading zero is not allowed
            if (comp.length() > 1 && comp[0] == '0')
                return "Neither";
            int num = 0;
            for (char ch : comp)
            {
                if (ch < '0' || ch > '9')
                    return "Neither";
                num = num * 10 + (ch - '0');
            }
            if (num > 255)
                return "Neither";
        }
        return "IPv4";
    }
    string validateIPv6(string ip)
    {
        if (ip.front() == ':' || ip.back() == ':')
            return "Neither";
        vector<string> components;
        string current;
        for (char ch : ip)
        {
            if (ch == ':')
            {
                components.push_back(current);
                current.clear();
            }
            else
            {
                current += ch;
            }
        }
        components.push_back(current);
        if (components.size() != 8)
            return "Neither";
        for (string comp : components)
        {
            if (comp.empty() || comp.length() > 4)
                return "Neither";
            for (char ch : comp)
            {
                ch = tolower(ch);
                if (!((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f')))
                {
                    return "Neither";
                }
            }
        }
        return "IPv6";
    }
    string validIPAddress(string IP)
    {
        if (IP.empty())
            return "Neither";
        if (IP.find('.') != string::npos)
            return validateIPv4(IP);
        if (IP.find(':') != string::npos)
            return validateIPv6(IP);
        return "Neither";
    }
};
// TC-->O(N)