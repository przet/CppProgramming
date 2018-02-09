/*
What I want to do here:
navigate to the path specified by the CLI. If default, then
go to config foleder, where a text file will be there. So
write this functionality first. 

Read the text file in line by line, and then do:
1) find the part with the "", and store that.
2) in the "" strings, find all occurances of \ replace this
with \\ N.B this will be good for regex practice, BUT could
boost do this with fs complete? 

N.B Don't forget to put this in a docker container?
Hand on that may reduce the functionality of running it
straight from windows, so maybe not.



*/
#include <fstream>
#include <string>
















