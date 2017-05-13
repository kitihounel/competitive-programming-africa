#include <iostream>
#include <stdio.h>
//#include <stdint.h>
ty
int64_t gcd(int64_t a, int64_t b)
{
    int64_t r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int j=0, t;
    int64_t x, n, y, m, i, c1, c2;
    std::cin >> t;
    while(j!=t)
    {
        std::cin >> x >> n >> y >> m;
        c1=0, c2=x;
        if (m != 0) {
            for(i=1;i<=m;++i)
            {
                if(c1<c2) c1+=c2;
                else c2+=c1;
                if(i==n){
                    if(c1<c2) c2+=y;
                    else c1+=y;
                }
            }
        }
        std::cout << "Case " << j + 1 << ": " << gcd(c1,c2) << std::endl;
        ++j;
    }
    return 0;

}
