///CF7D Palindrome Degree
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int n;
ll dp[5000005];
char s[5000005];
ll cal[5000006];

int k,q,ans;

void init(){
    cal[0] = 1;
    for(int i = 1;i <= 5000005;i++){
        cal[i] = cal[i-1]*13;
    }
}

int main(void){
//    string s;
//    cin>>s;
    scanf("%s",s),n = strlen(s);
    int step = 0;
    init();
    for(int i = 0;i < n;i++){
        k = k*13+s[i];//前缀hash，十三进制
        q = q+cal[step++]*s[i];//和后缀hash，十三进制
        if(!(k^q)){///只要两个就更新
            dp[i]=dp[i-1>>1]+1;
            ans += dp[i];///答案就加上阶数之和
        }
    }
    printf("%d",ans);

    return 0;
}


///思路：
//如果不是回文串，阶数就是0
//否则f[i] = f[i/2]+1
//这里使用字符串hash
//
///数据量：5*10^6
//
///知识点：字符串hash，Manacher
//
///小知识：5*10^6 用cin读进string 超级慢
