long long _min(long long a, long long b) {return a<=b? a : b;}
long long _max(long long a, long long b) {return a>=b? a : b;}
bool divides(long long b, long long a) {return a % b == 0;}
long long mygcd(long long a, long long b)
{
    long long const min = _min(a,b);
    long long const max = _max(a,b); 
    if (divides(min,max))
        return min;
  
    long long d = 2;
    long long q = min/d;
    while (1)
    {
        if (divides(d,min))
        {
            q = min/d;
            if (divides(q,max) && divides(q,min))
                return q;
        }
        ++d;
    }
  
    // if we reach here, something went wrong
    return -1;
}