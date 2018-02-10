#include<string>
#include <fstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <regex>
#include <algorithm>
#include <map>



std::vector<std::string> DirStrExtr(std::string const& batchFileLOC_NAME, std::string const& configFileLOC_NAME)
{
    std::fstream batchFile;
    std::fstream configFile;
    //TODO do the one steam fstream initialisation (using its constructor)
   
    batchFile.open(batchFileLOC_NAME, std::ios::in);
    if (batchFile.fail())
        std::cerr << "Wrong batch file name and/or location.\n"
        "You entered:  " << batchFileLOC_NAME << std::endl;
    
    //Check each line as its read in against a reg expression.
    //We only want the line with the pattern "set MEC"
    std::regex set_mec_dir_regex("set MEC");
    std::string lines;
    while (std::getline(batchFile, lines))
        if (std::regex_search(lines, set_mec_dir_regex))
            break;
    
    //Store the 




    configFile.open(fileToOpen,
        std::ios::in);
    if (configFile.fail())
        std::cout <<"Oi! This don't exist yo. Why don't you make sure the file exists!! DO IT NOW!";
    std::vector<std::string> linesVec;
    std::string lines;
    while (std::getline(configFile, lines))
        std::back_inserter(linesVec) = lines;

    

    std::vector<std::string> dirVec;
    std::regex colon_backslash_regex(R"(:\\|:/)");
    //TODO Regex runtime engine exception handler
    for (const auto &line : linesVec)
        if (std::regex_search(line, colon_backslash_regex))
            std::back_inserter(dirVec) = line;
    
    configFile.close();
    return dirVec;

}

//Thanks to SO user 'nobar' for this one (answer posted Jun21 2016)
//TODO put this in a different file
//UPDATE: Not needed at the moment
//std::string do_replace(std::string const &in, std::string const &from, std::string const &to)
//{
//    return std::regex_replace(in, std::regex(from), to);
//}


//TODO: CL Args
////CONSOLE DEBUGGING
//printf("%d", argc);
//printf("%s", argv[0]);
//printf("%s", argv[1]);
////----------------------
//
////Thanks to K&R for the framework of the cl arg passing (pg 117, 'The C Programming Language'.)
//int c, except = 0, number = 0, found = 0;
//std::string fileToOpen;
//while (--argc > 0 && (*++argv)[0] == '-')
//while (c = *++argv[0])
//switch (c)
//{
//case 'e':
//    std::cout << "\n input filename to open :  ";
//    std::cin >> fileToOpen;
//    break;
//default:
//    std::cout << "illegal option" << std::endl;
//}
//{
//    if (argc == 1)
//        fileToOpen = "testfileForStringDirectoryConvertor.txt";
//    std::cout << "\n we are here now hello there" << std::endl;
//}

//TODO come back to this later (this is an advancement which tries to minimise the structure imposed in 
// the config text file.
////search linesVec for a string with "Batch or Script" in it, and with "Executable or Program or mec" in it
//// (not case sensitive)
//std::regex batch_like_regex("[Bb]at[ch]"); //TODO: case insensitve, and an OR with script
//std::regex exe_like_regex("[Ee]xe"); //TODO: case insensitve, and an OR with Prog, mec 

//
//    

//for (const auto &line : linesVec)
//    if (empty(line))
//        continue;
//    else if (std::regex_search(line,batch_like_regex))
//    {

//    }
//        std::regex_