long long int groupSize(long long int S,long long int D)
{
    long long T = S > 1? D + (S-1)*S/2 : D;
    return ceil((-1 + sqrt(1 + 8*T))/2);
}
