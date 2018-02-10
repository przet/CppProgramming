#ifndef MYCLASS_H_V2
#include "C++_ExeLauncher_VS\C++_ExeLauncher_VS\RunItV2.h"  //I think I should play around with the config manager to not have to include
                                                            // the path?
#endif  


int main(int argc, char *argv[])
{
    
    RunBatch runBatch;
    RunProgram runProgram;
    //TODO. This feels or seems wrong, to have to instatiate like this...
    runBatch.SetParamsAndRun(NULL, "open", "testBatch.bat",
        NULL, "N:\\Programming\\C++\\CppProgramming\\Projects\\C++_ExeLauncher\\BatchFiles",
        SW_NORMAL);
    
    runProgram.SetParamsAndRun(NULL, "open", "notepad.exe",
        NULL, "C:\\Windows",
        SW_NORMAL);
    

}
