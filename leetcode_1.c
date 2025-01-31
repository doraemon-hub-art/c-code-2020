﻿给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。如果不存在最后一个单词，请返回 0 。
单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
示例 1：
输入：s = "Hello World"
输出：5
示例 2：
输入：s = " "
输出：0
提示：
1 <= s.length <= 104
s 仅有英文字母和空格 ' ' 组成

int lengthOfLastWord(char* s) {
    //求该字符串的长度
    int len = strlen(s);
    //count用来计数
    int count = 0;
    //从后面开始循环 
    for (int i = len - 1; i >= 0; i--)
    {
        //不是空格count+1
        if (s[i] != ' ')
        {
            count++;
        }
        //是空格就终止
        if (s[i] == ' ' && count != 0)
        {
            break;
        }
    }
    return count;
}
