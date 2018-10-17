#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
    std::vector<int> a{1,2,3,4,5};
    auto b=a; //just making a copy for play
    
    //The "old" way- iterators and normal for loop
    for (auto it = begin(b); it != end(b); ++it)
        *it=0;
    
    //A better way: the ranged for:
    for (auto &i:b) //ahhhh...it has to be reference if you want to change elements in b - otherwise it just changes its
        //own copy of the elements of b, and does nothing to our actual elements of b! Yes of course, this is just your standard pass by ref vs pass by value, but it did
        //NOT click with me until Kate mentioned it! Note this is _probably_ why the lambdas take in & when it is required to change the real value
        i =1;
    
    //using for_each:
    std::for_each(begin(b),end(b),[](auto& i){i=2;}); //Need the reference to change elements of b, not just a local copy (which would happen with pass by value)
    
    //In these cases, when the entire collection is being used, Kate thinks just ranged for is the best, however where for_each is good for is in cases where
    //you are NOT searching the entire collection, like:
    b=a;
    auto firstThree = std::find(begin(b),end(b),3);
    std::for_each(firstThree, end(b), [](auto& i){i=0;});


    return 0;
}
