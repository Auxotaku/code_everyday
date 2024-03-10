#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int strStr(string s, string t) 
{
    for(int i=0;i<s.size();i++)
    {
        if(s.substr(i,t.size())==t)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << strStr(s, t) << endl;
    return 0;
}