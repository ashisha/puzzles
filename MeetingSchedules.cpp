// https://amazonindia.interviewstreet.com/challenges/dashboard/#problem/4fd651016cd04
#include<cstdio>
#include<bitset>

using namespace std;

int main()
{
    int M,K;
    bitset<24*60> bloomTime; // bit 0 represent free time (no-busy)

    scanf("%d %d", &M, &K);

    int h1,m1,h2,m2,t1,t2;
    for(int i=0; i<M; i++)
    {
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        t1=h1*60+m1;
        t2=h2*60+m2;
        if(t2<t1)t2=24*60+m2;

        for(int i=t1;i<t2;i++)
            bloomTime.set(i);
    }

    int start;
    for(int i=0;i<24*60;i++)
    {
        start=i;
        while(i<24*60 && !bloomTime[i])i++;
        if((i-start)>=K)
        {
            printf("%02d %02d %02d %02d\n", start/60, start%60, (i==24*60)?0:i/60,i%60);
        }
    }
    return 0;
}
