bool isAlpha(char character)
{
    return (character < 91 && character > 64) 
    || (character < 123 && character > 96); 
  
}
std::string nextLetter(std::string str)
{
    for (auto& elem : str)
    {
        if (isAlpha(elem))
        {
          if (elem == 'Z')
            elem = 'A'; 
          else if (elem == 'z')
            elem = 'a'; 
          else
            elem = (elem + 1) ; 
          
        }
    }
    return str;
}