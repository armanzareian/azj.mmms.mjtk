#include<stdio.h>

void mabna (long int(n),long int(a)){
   long int d=0;
    if(n/a!=0){
        d=n/a;
        mabna(d,a);
    }
    printf("%ld",n%a);
}
int main(){
    long int n=0,a=0,x=0,w=0,e=0,sum=0,y=1,i=1,m=0;
     scanf("%ld%ld%ld",&n,&a,&x);
    m=n;
    while(n/i!=0){
        w=m%10;
        e=w*y;
        y=y*a;
        sum=sum+e;
        m=m/10;
        i*=10;
    }
    mabna(sum, x);
}
