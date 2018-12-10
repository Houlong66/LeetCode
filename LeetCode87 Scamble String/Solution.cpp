// 笔记详情 http://note.youdao.com/noteshare?id=c0b80c687e4bfbe79d2f42f4d771850a

// Solution 1
class Solution {
public:
    bool isScramble(string s1, string s2) {
         if(s1.length()!=s2.length())
        return false;
    if(s1.length()==0)
        return true;
    bool res[s1.length()][s2.length()][s1.length()+1];
    for(int i=0;i<s1.length();i++)
    {
        for(int j=0;j<s2.length();j++)
        {
            for (int k = 1; k <= s1.length(); k++) {
                if (k == 1){
                    res[i][j][k] = s1.at(i)==s2.at(j);
                }
                else {
                    res[i][j][k] = false;
                }
            }
        }
    }
    for(int len=2;len<=s1.length();len++)
    {
        for(int i=0;i<s1.length()-len+1;i++)
        {
            for(int j=0;j<s2.length()-len+1;j++)
            {
                for(int k=1;k<len;k++)
                {
                    res[i][j][len] |= (res[i][j][k]&&res[i+k][j+k][len-k]) || (res[i][j+len-k][k]&&res[i+k][j][len-k]);
                }
            }
        }
    }
    return res[0][0][s1.length()];
    }
};

// Solution 2
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }
        string c1 = s1;
        string c2 = s2;
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        if (c1 != c2) {
            return false;
        }
        for (int i = 1; i < s1.length(); i++) {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))) {
                return true;
            }
            else if (isScramble(s1.substr(0,i), s2.substr(s2.length() - i)) && isScramble(s1.substr(i),s2.substr(0, s2.length() - i))) {
                return true;
            }
        }
        return false;
    }
};