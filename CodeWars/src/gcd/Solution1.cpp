long long _min(long long a, long long b) {return a<=b? a : b;}
long long _max(long long a, long long b) {return a>=b? a : b;}
long long mygcd(long long a, long long b)
{
    long long A = _max(a,b);
    long long B = _min(a,b);
  
    long long r = A % B;
    while (r != 0)
    {
        A = B;
        B = r;
        r = A % B;
    }
    return B;
}
