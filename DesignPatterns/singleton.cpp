//Single Pattern with Simon Allardice (who uses Java for this) as a guide


//Implementation 1: Naive and will not be a true singleton - copying and assignment still allowed
class MySingletonInCPP
{
    private:
        MySingletonInCPP() {} //private ctor
        int hello; //non-static datamember
    private:
         static MySingletonInCPP *__me; //TODO:can't initialise to nullptr:
                                        //"non-const static data member must be initialised out of line";
                                        //I think it has something to do with static variables and the
                                        //way they set aside memory, but that is all at the moment
    public:
         static MySingletonInCPP* getInstance() //This is how you ask for the singleton.
                                          //Note function is static because it will work on
                                          // static data
         {
             if (__me == nullptr)
                 __me = new MySingletonInCPP();
             return __me; 
             
         }

};

MySingletonInCPP *MySingletonInCPP::__me = nullptr; //Needed or linker error will ensue: undefined ref to __me.
                                                    //Non-const static data members must be initialised out-of-line
//auto MySingletonInCPP::hello = 4; //error! Non-static data member defined out-of-line

int main()
{
    auto p = MySingletonInCPP::getInstance();

    return 0;
}
