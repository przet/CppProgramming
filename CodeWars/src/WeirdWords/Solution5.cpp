bool isAlpha(char character)
{
    return (character < 91 && character > 64) 
    || (character < 123 && character > 96); 
  
}

bool isLower(char character)
{
    return (character < 123 && character > 96); 
}

char letterPlusOne(char elem)
{
      if (isAlpha(elem))
      {
         elem =  !isLower(elem) ?  ((elem - 65 + 1) % 26) + 65
             :((elem - 97 + 1) % 26) + 97;
      }
      return elem;
}

std::string nextLetter(std::string str)
{
    for (auto& elem : str)
       elem = letterPlusOne(elem);
  
    return str;
}