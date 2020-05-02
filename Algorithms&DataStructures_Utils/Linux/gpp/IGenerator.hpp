#ifndef __IGenerator__H
#define __IGenerator__H
#include <vector>

template <template <typename... > class Container, typename ContainerDataType>
struct IGenerator
{
    virtual const std::vector<std::pair<Container<ContainerDataType>,int>>& generateData() = 0; 
    virtual ~IGenerator(){}
};

#endif
