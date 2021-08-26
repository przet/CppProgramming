long long int groupSize(long long int S,long long int D)
{
    long long n, priorSum, T;
    if(S>1)
    {
        n = S - 1;
        priorSum = n*(n+1)/2;
        T = D + priorSum;
        
    }
    else
    {
        priorSum = 0;
        T = D;
      
    }
    return ceil((-1 + sqrt(1 + 8*T))/2);
    
    
}
