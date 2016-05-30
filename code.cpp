/***********************************************************************
暴力的解法，遍历每一个子串，并判断是否为回文串，并实时更新串的长度
************************************************************************/
class Palindrome {
public:
    int getLongestPalindrome(string A, int n)
    {
        // write code here
        int maxR = 0;
        for(int i = 0; i <= n; ++i)
        {
            string str;
            for(int j = i; j <= n; ++j)
            {
                str += A[j];
                if(judegeR(str))
                {
                    int length = str.size();
                    if(length > maxR)
                        maxR = length;
                }                  
            }
            if(maxR > n/2)
                return maxR;
        }
        return maxR;
    }
private:
    bool judegeR(string a)
    {
        string temp = a;
        reverse(temp.begin(),temp.end());
        return a == temp;
    }
};
/*******************************************************************************
动态规划法，使用一个二维的[n][n]的数组，记录能达到的最大长度回文串可达距离
********************************************************************************/
class Palindrome {
public:
    int getLongestPalindrome(string A, int n) 
    {
        // write code here
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        vector<vector<int> > dp(n,vector<int>(n));
        int maxlen = 0;
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
            if(i < n-1 && A[i]==A[i+1])
            {
                dp[i][i+1] = 1;
                maxlen = 2;
            }    
        }
        
        for(int len = 3; len <= n; ++len)
        {
            for(int i = 0; i < n-len+1; ++i)//起点
            {
                int j = i + len -1;
                if(dp[i+1][j-1]==1 && A[i]==A[j])
                {
                    dp[i][j]=1;
                    if(len > maxlen)
                        maxlen = len;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return maxlen;
    }
};
/*****************************************************************************************
Manacher算法//  http://www.cnblogs.com/biyeymyhjob/archive/2012/10/04/2711527.html
******************************************************************************************/
 class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here

string t = "&#";
for (int i = 0; i < A.size();i++)
{
t += A[i];
t+="#";
}

vector<int> p(t.size(), 0);
int mx = 0, id = 0;//其中id为最大回文子串中心的位置，mx表示其半径
int resLen = 0, resCenter = 0;
for (int i = 1; i < t.size();i++)
{
p[i] = mx>i ? min(p[2 * id - i], mx - i) : 1;
while (t[i+p[i]] == t[i-p[i]])
{
p[i]++;
}

if (mx < i + p[i])
{
mx = i + p[i];
id = i;
}

if (resLen < p[i])
{
resLen = p[i];
resCenter = i;
}
}
return resLen - 1;
    }
}; 
