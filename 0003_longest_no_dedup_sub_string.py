from collections import defaultdict
import queue

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = defaultdict(int)
        q = queue.Queue()
        max_len = 0
        for c in s:
            if d[c] != 0:
                if q.qsize() > max_len:
                    max_len = q.qsize()
                while True:
                    c1 = q.get()
                    d[c1] = 0
                    if c1 == c:
                        break
            q.put(c)
            d[c] = 1
        if q.qsize() > max_len:
            max_len = q.qsize()
        return max_len

s = Solution()

print(s.lengthOfLongestSubstring("abba"))

