#include <iostream>
#include "Goose.hpp"
#include "GooseToDuckAdapter.hpp"

int main(){
        Goose goose;
        GooseToDuckAdapter adapter(&goose);
        std::cout << adapter.Quack() << std::endl;
        return 0;
}
        
