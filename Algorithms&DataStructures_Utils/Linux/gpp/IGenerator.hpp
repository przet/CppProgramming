template <template <typename... > class Container, typename ContainerDataType>
struct IGenerator
{
    virtual const std::vector<std::pair<Container<ContainerDataType>,int>>& generateData() = 0; 
    virtual ~IGenerator(){}
};
