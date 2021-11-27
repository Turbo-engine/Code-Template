int exgcd(int a, int b, int &x, int &y){
//返回值是gcd(a,b) 并求出解(引用带回)
    if(b==0){
        x = 1, y = 0;
        return a;
    }
    int x1,y1,gcd;
    gcd = exgcd(b, a%b, x1, y1);
    x = y1, y = x1 - a/b*y1;
    return gcd;
}
