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
        total = len(s)
        # max_sub = s[0]
        max_len = 1
        last_pos = {s[0]:0}
        i, j = 0, 1
        last_str = s[0]
        while j < total:
            if s[j] in last_str:
                i = last_pos[s[j]] + 1
            last_pos[s[j]] = j
            last_str = s[i:j+1]
            last_len = j-i+1
            if last_len >= max_len:
                # max_sub = last_str
                max_len = last_len
            j +=1
        # print(max_sub)
        return max_len

if __name__ == "__main__":
    main = Solution()
    print(main.lengthOfLongestSubstring("ggububgvfk"))
    print(main.lengthOfLongestSubstring("abcabcbb"))
    print(main.lengthOfLongestSubstring("bbbbb"))
    print(main.lengthOfLongestSubstring("pwwkew"))
