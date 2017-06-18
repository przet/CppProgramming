// m div n
#include <iostream>


int main()
{
    // initialise the two integers to be stored from input
    int m = 0, n = 0;
    std::cout << "Please enter two integers \n";

    // read in two inputs
    std::cin >> m;
    std::cin >> n;

    // store m - n. Will be useful for the loop later on, and some preliminary checks
    int store = (m - n);

    // check if store > n. If it is continue, if not we return m div n = 1
    if (n > store && m > n)
        std::cout << "m div n = " << 1 << "\n";
        
    // check if m == n and return m div n = 1
    else if (m == n)
        std::cout << "m div n = " << 1 << "\n";    // I am assuming it is safe just to return "1" without any declaration before hand? Or should I store it first?

    // check if m < n and return m div n = 0
    else if (m < n)
        std::cout << "m div n = " << 0 << "\n";     // same comment applies for returnin "0" direct. We do so in a main funciton (return(0)) so should be fine....?

    //otherwise, execute the (integer) division
    else if (m > n)                                 // STRANGE. I just did else before, and if m == n, this else loop is still entered. But if m < n then 0 is returned correctly and program terminates.
    {
        // setting a counter and store variable for use in a loop

        int count = 1;
        int i = 1;

        // the loop with the logic of division via subtraction
                
        for (store, i = 1; store >= n; ++i)  // Thanks for tutorial point for firming up the basics for me - the condition gets evaluated second and if it is true, the loop executes, otherwise the next statement after the loop (so no looping) occurs.

                                            // I had store == 0 - this was false! store != 0 is the right way. However I need to change this to not equal to less than zero. I had it the wrong way around, and this just firms up my fundamentals, my concepts :)

        {
            // the count until store equals zero or less is the div result (after we add one to it after the loop as we are starting at (m-n) instead of m. Yes we could of started the for loop at i =2, but we didn't)
            count = i;

            // n is subrtacted from (m-n) until store = 0 or less
            store -= n;
        }

        // output the div result to screen

        std::cout << "m div n = " << count + 1;
    }

}