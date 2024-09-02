#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        if (s.find('[')==-1) return s;
        int cl=0,cr=0;
        string tempNumber="";
        string rez="";
        int number=0;
        string substring="";
        for (int i=0;i<s.size();++i)
        {

            if (s[i]=='[')
            {
                ++cl;
                number=stoi(tempNumber);
            }
            else if (s[i]==']') ++cr;


            if (!cl && '0'<=s[i] && s[i]<='9')
            {
                tempNumber+=s[i];
            }
            else if (cr==0 && cl==0 && 'a'<=s[i] && s[i]<='z') rez+=s[i];
            if (cl && cr<cl)
            {
                if (s[i]=='[' && cl==1)
                {
                    continue;
                }else
                substring+=s[i];
            }
            if (cr!=0 && cr==cl)
            {
                string stroka=decodeString(substring);
                for (int i=0;i<number;++i)
                rez+=stroka;
                cl=cr=0;
                tempNumber="";
                substring="";
            }
        }
        return rez;
    }
};


int main()
{
    string s="2[abc]3[cd]ef";
    Solution a;
    a.decodeString(s);
    return 0;
}
