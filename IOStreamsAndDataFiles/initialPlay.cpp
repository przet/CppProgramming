#include <fstream>    	
using std::fstream;   // I want to go over that SO article about why this is a bad idea. Well not this, but namespace std. 
			//And is this better ( I think it is - also check that Safari book that mentioned this topic also.
using std::ios;
int main()
{
char fileName[9] = "testFile"; //Dangerous but efficient (in terms of coding - don't need string header).
				// Remember that the compiler will add a '\0' as end of string terminator.
				// Interesting question - on Windows this will default to a .txt, but what
				// about here on Linux. And what does the compiler have to do with this,
				// if anything at all?

//TODO fileLocation variable, but how would one do this with char arrays? They shouldn't be able to concatenate...?

//Open file - won't do a check to see if it exists, happy with overrite.
fstream fileOutput(fileName, ios::out);

// Write to the file
fileOutput << "Hello there me hearties!!!"; //Investigate flushing the file buffer (and consequence etc, writing too etc, just have
						// a play.

fileOutput.close();




}
