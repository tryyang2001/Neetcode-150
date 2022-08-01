#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest_odd = "";
        string longest_even = "";
        //O(n) possible palindrome middle 
        for (int i = 0; i < s.size(); i++) {
            //find longest palindrome with odd length
            int left = i;
            int right = i;
            //O(n) check
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                //cout << left << " " << right << endl;
                if (right - left + 1 > longest_odd.size()) {
                    //cout << left << " " << right << endl;
                    longest_odd = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            //find longest palindrome with even length
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                //cout << left << " " << right << endl;
                if (right - left + 1 > longest_even.size()) {
                    //cout << left << " " << right << endl;
                    longest_even = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }
        }
        //cout << longest_odd << " ... " << longest_even << endl;
        return (longest_odd.size() > longest_even.size())? longest_odd : longest_even;
    }
};