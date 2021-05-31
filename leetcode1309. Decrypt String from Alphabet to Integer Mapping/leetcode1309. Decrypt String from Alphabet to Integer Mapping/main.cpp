#include <iostream>
#include <string>
//表哥的做法！！！！！！！
using namespace std;
    string freqAlphabets(string s) {
        string::reverse_iterator sb = s.rbegin();
        string r(""), rt("");
        while (sb != s.rend()){
            char t = 'a';
            if (*sb=='#'){
                sb+=1;
                t += *sb-'0'+10*(*(sb+1)-'0')-1;
                sb += 2;
            } else {
                t += *sb-'0'-1;
                sb += 1;
            }
            rt += t;
        }
        r.resize(rt.size());
        copy(rt.rbegin(), rt.rend(), r.begin());
        return r;
    }
int main()
{
    string s;
    cin>>s;
    cout<<freqAlphabets(s);

}
