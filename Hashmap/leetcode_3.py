'''
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
'''

import collections

def lengthOfLongestSubstring_1(s: str) -> int:
    if len(s) == 0:
        return 0
    
    answer_table = collections.defaultdict(int)
    curr_i = 0
    ls = ''
    
    for i, char in enumerate(s):
        answer_table[i] += 1
        if i == 0:
            ls = char
        elif char in ls:
            # This part is wrong
            curr_i = i
            ls = char
        else:
            answer_table[curr_i] += 1
            ls += char
    
    return max(answer_table.values())

'''
lengthOfLongestSubstring_1()
s = "dvdf"
Output : 2
Expected : 3
'''

def lengthOfLongestSubstring_2(s: str) -> int:
    if len(s) == 0:
        return 0
    
    answer_table = collections.defaultdict(int)
    curr_i = 0
    ls = ''
    
    for i, char in enumerate(s):
        answer_table[i] += 1
        char_idx = ls.find(char)
        
        if char_idx == -1:
            ls += char
        else:
            # 이게 잘못되었다.
            curr_i = char_idx + 1
            ls = s[curr_i:i+1]
        answer_table[curr_i] = len(ls)
    
    return max(answer_table.values())


def lengthOfLongestSubstring_3(s: str) -> int:
    ans = {}
    max_length = start = 0

    for i, char in enumerate(s):
        if char in ans:
            start = ans[char] + 1
        else:
            max_length = max(max_length, i - start + 1)
        
        ans[char] = i
    
    return max_length


if __name__ == '__main__':
    # test_input_1 = "abcabcbb"
    # print(lengthOfLongestSubstring_2(test_input_1))
    
    # test_input_2 = "pwwkew"
    # print(lengthOfLongestSubstring_2(test_input_2))
    
    # test_input_3 = "bbbbb"
    # print(lengthOfLongestSubstring_2(test_input_3))
    
    test_input_4 = "tmmzuxt"
    print(lengthOfLongestSubstring_3(test_input_4))