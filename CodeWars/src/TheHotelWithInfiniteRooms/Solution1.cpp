long long int groupSize(long long int S,long long int D)
{
    long long T;
    if(S>1)
    {
        T = D + (S-1)*S/2;
        
    }
    else
    {
        T = D;
    }
    return ceil((-1 + sqrt(1 + 8*T))/2);
    
}
