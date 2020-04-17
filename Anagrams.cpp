//Given two strings, write a function to determine whether they are anagrams.

//Solution


class Solution {
public:
    bool isAnagram(string s, string t) {
        int frequency_of_char[256];
        memset(frequency_of_char, 0, sizeof(frequency_of_char));
        for(int i=0;i<s.size();i++)
        {
            frequency_of_char[int(s[i])]++;
        }
        for(int i=0;i<t.size();i++)
        {
            frequency_of_char[int(t[i])]--;
        }
        for(int i=0;i<256;i++)
        {
            if(frequency_of_char[i]!=0)
            {
                return false;
            }
        }     
        return true;
    }
};


//Solution is solved and checked on leetcode!