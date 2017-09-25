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
        print(s)

if __name__ == "__main__":
    main = Solution()
    main.lengthOfLongestSubstring("abcabcbb")
    main.lengthOfLongestSubstring("bbbbb")
    main.lengthOfLongestSubstring("pwwkew")
