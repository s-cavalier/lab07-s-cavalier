#include "strFuncs.h"
#include <cctype>
#include <cstring>
#include <string>

using namespace std;


/* Precondition: s1 is a valid string that may contain upper or lower case alphabets, no spaces or special characters
 * Postcondition: Returns true if s1 is a palindrome, false otherwise
 *
 * Palindromes are NOT case-sensitive - "RaCecaR" is a valid palindrome
 *
 *You should provide a recursive solution*/
bool isPalindrome(const string s1){
    char start = tolower(s1[0]);
    char end = tolower(s1[s1.size() - 1]);
    bool out = true;
    if (start != end) return false;
    if (s1.size() < 3 && start == end) return true;

    out = isPalindrome(s1.substr(1, s1.size() - 2));
    //STUB: Replace the following with the correct code.
    return out;
}
