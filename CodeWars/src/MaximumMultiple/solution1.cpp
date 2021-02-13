int maxMultiple(int divisor, int bound) 
{
    int result = bound;
    while(1)
    {
        if (result % divisor == 0)
          return result;
        --result;
    }
}
