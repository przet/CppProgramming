long long int groupSize(long long int S,long long int D)
{
    long long result = S;
    while (D - result > 0)
    {
        D -= result;
        result += 1;
      
    }
    return result;
}
