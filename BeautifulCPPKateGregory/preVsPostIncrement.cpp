#include <iostream>
#include <vector>
int main ()
{
	int i = 1;
	std::cout << "\n\ni originally = " << i << std::endl;
	int ipp = i++;
	std::cout << "\ni++ = " << ipp << std::endl;
	std::cout << "\ni is now = " << i << std::endl;
	i = 1; //need to reassign to 1
	std::cout << "\nresetting i = " << i << std::endl;
	int ppi = ++i;
	std::cout << "\n++i = " << ppi << std::endl;
	std::cout << "i is now = " << ppi << '\n'<< std::endl;

	//Here are the implications:
	// "Bad" or non-STL way to count how many entries have the target value 2
	std::vector <int> v {2,2,3,4,5};
	int twos = 0;
	int const target = 2; //const as we don't want this to change
	for (int i = 0; i < v.size();) //NOT including the increment value in the for statement
		if (v[i++] == target)
			twos++;
	std::cout << twos << std::endl;

	//twos++ or ++twos is irrelevant: both will increment twos by 1, as seen in the output of the first
	//part of this code. HOWEVER, in v[i++], chaning this to v[++i] WILL matter: v[1] will be the first element
	//tested, v[0] will be skipped:
	twos = 0;
	for (int i = 0; i < v.size();) 
		if (v[++i] == target)
			twos++;
	std::cout << twos << std::endl;

	//Moreover, you also end up going one past the end of the vector, which althouhg everything worked fine here,
	//could lead to some undefined behaviour

	//In the context of the effect of the increment operator vs the value being sought (K&R chapter 2)
	//, as in the twos++ or ++twos it does not matter if we use pre or post fix incrmement operators.
	//If we were to write the incrment expressing in the for loop statement (i.e for (int i=0;i<...;++i))
	//it would not matter if we wrote i++ instead, as both the exect of incrementing (changing,mutating) i
	//to 0 + 1=1, and so on - the increment expression is an assignment expression to reassign the orignal i.
	//
	//The same goes for writing i++ or ++i in the body of the for expression, as int i is declared and defined to be 0
	//and is in scope of the for expression:
	twos = 0;
	for (int i = 0; i < v.size();)
	{	if (v[i] == target)
					twos++;
	    i++;
	}
	std::cout << twos << std::endl;
		
	//OR
	
	twos = 0;
	for (int i = 0; i < v.size();)
	{	if (v[i] == target)
					twos++;
		++i;
	}
	std::cout << twos << std::endl;
	
   // By the way, an intersting thing happened when I mistakenly ommited the curly braces in
   // the last two for statements - the program compiled, however the loops (well really only
   // the first one) ran for ever.
   //
   // That is because it had NO increment expression (the i++ should have been in braces, as I
   // corrected for
   //
   // In fact the loop will loop forever with i = 0, as we can show (be prepared to ctrl-c the program:
   
   twos = 0;
   for (int i = 0; i < v.size();)
       if (v[i] == target)
	   {	twos++;
			std::cout << i << std::endl;
	   }

   //Hmmm is there a way to throw and catch for this? Well its not really an exception, its more a bug in the program...

	

	return 0;
}
