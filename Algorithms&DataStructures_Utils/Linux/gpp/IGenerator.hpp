struct IGenerator
{
    virtual void Generate() = 0;
    // TODO template this. There was some syntax trouble with vector, pair 
    virtual const std::vector<std::pair<std::vector<int>,int>>& generatedData() = 0; 
    virtual ~IGenerator(){}
};
