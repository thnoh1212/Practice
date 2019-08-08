int gcd(int a,int b)
{ //반복문을 이용한 방법
    int mod = a % b;
    while(mod > 0)
    {
        a = b;
        b = mod;
        mod = a % b;
    }
    return b;
}
 
int gcd2(int a,int b)
{ //재귀 함수형
    if( a % b == 0 )
        return b;
    else
        return gcd2(b, a % b);
}
 
int gcd3(int a, int b)
{ //삼항 연산자 축약형 
    return (a % b == 0 ? b : gcd3(b,a%b));
}

/*  f(a, b) = gcd(a, b)라 합시다. 이 때 a mod b = 0 이라면, f(a, b) = b임이 자명함을 알 수 있습니다.
    이 때 a mod b이 0이 아닌 경우, f(a, b) = f(b, a mod b)가 성립하고, 이를 유클리드 호제법이라고 합니다. */
   
