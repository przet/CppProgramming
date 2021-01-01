bool isAlpha(char character)
{
    return (character < 91 && character > 64) 
    || (character < 123 && character > 96); 
  
}

bool isLower(char character)
{
    return (character < 123 && character > 96); 
}

std::string nextLetter(std::string str)
{
    for (auto& elem : str)
    {
       if (isAlpha(elem))
       {
           if (!isLower(elem))
           {
             elem = ((elem - 65 + 1) % 26) + 65;
           }

           else 
           {
             elem = ((elem - 97 + 1) % 26) + 97;
           }
       }
          
    }
    return str;
}