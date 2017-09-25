#!/usr/bin/python
# encoding: utf-8
"""
@author: lawrence
@license: GPL Licence 
@file: run.py
@time: 9/25/17 21:54
"""


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if "" == s:
            return 0
        max_len = 1
        last_pos = {s[0]:0}
        i = 0
        for j in range(1, len(s)):
            c = s[j]
            if c in last_pos and last_pos[c] >= i:
                i = last_pos[c] + 1
            last_pos[c] = j
            # last_str = s[i:j+1]
            last_len = j-i+1
            max_len = last_len if last_len >= max_len else max_len
        return max_len

if __name__ == "__main__":
    main = Solution()
    print(main.lengthOfLongestSubstring("ggububgvfk"))
    print(main.lengthOfLongestSubstring("abcabcbb"))
    print(main.lengthOfLongestSubstring("bbbbb"))
    print(main.lengthOfLongestSubstring("pwwkew"))
    print(main.lengthOfLongestSubstring("au"))
