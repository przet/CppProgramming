#include "HeaderFile1.h"  //This file includes sharedFunction (and its definition) via SharedHeader 
#include "HeaderFile2.h"  // This file does not include sharedFunction and its definition becuase of include guards
int main()
{
    // Result of compilation (Driver.obj) has a definition for sharedFunction.
    // Because SourceFile1.cpp incluldes HeaderFile1, the result of compilation of that translation unit (SourceFile1.obj) will also have
    // a defintion for sharedFunction - and LINK1169 (one or more multiple defined sybmols found) will result. It is LNK2005 for
    // "sharedFunction already defined in Driver obj in file SourceFile1.objj

}

