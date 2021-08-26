long long int groupSize(long long int S,long long int D)
{
    long long T;
    if(S>1)
    {
        long long n = S - 1;
        long long priorSum = n*(n+1)/2;
        T = D + priorSum;
        
    }
    else
    {
        T = D;
    }
    return ceil((-1 + sqrt(1 + 8*T))/2);
    
    
}
