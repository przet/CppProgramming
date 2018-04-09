#include <functional>

bool isTrue()
{
    return true;
}
bool oneBigFunction(int i, std::function<bool()> f)
{
   if (i == 1)
        return f();
   return false;
}

int main ()
{
    
   oneBigFunction(1,isTrue); 

}

//Pay *close* attention to the syntax:
//if you call, in main, oneBigFunction(1,isTrue()) you will get a compiler error (both gcc and clang, and no its not the gcc 4.8 bug you might
//find mentioned on the internets) stating:
//
//"canditate function not viable: no know conversion from 'bool' to std::function<bool()>"
//
//Remove the operator () after isTrue
//
//The other thing to watch for is in the body of 'oneBigFunction': do not wrtie 'return f' unless you want to get the following error:
//
// no viable conversion from returned value of type 'std::function<bool ()>' to function return type 'bool'.
//
// Here we _add_ the operator () after f
