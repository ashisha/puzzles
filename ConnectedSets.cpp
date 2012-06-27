// https://amazonindia.interviewstreet.com/challenges/dashboard/#problem/4fd6570bd51e1
#include<cstdio>

using namespace std;

void flood(int m, int n, int (*arr)[1010], int N)
{
    if(m<0 || n>=N) return;
    if(arr[m][n]==0) return;

    arr[m][n]=0;
    flood(m-1,n-1, arr, N);
    flood(m-1,n, arr, N);
    flood(m-1,n+1, arr, N);
    flood(m,n-1, arr, N);
    flood(m,n+1, arr, N);
    flood(m+1,n-1, arr, N);
    flood(m+1,n, arr, N);
    flood(m+1,n+1, arr, N);
}

int main()
{
    int T,N,d,r;
    scanf("%d", &T);
    
    // save malloc time, occupy the array on stack
    int arr[1010][1010];

    for(int t=0;t<T;t++)
    {
        r=0;
        scanf("%d", &N);
        for(int m=0;m<N;m++) 
        for(int n=0;n<N;n++) 
        {
            scanf("%d", &d);
            arr[m][n]=d;
        }

        for(int m=0;m<N;m++) 
        for(int n=0;n<N;n++) 
        {
            if(arr[m][n]==1)
            {
                r++;
                flood(m,n,arr,N);
            }
        }
        printf("%d\n", r);
    }
}
