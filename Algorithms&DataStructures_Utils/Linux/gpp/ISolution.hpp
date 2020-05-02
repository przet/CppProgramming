#ifndef __ISolution__H
#define __ISolution__H

template <template <typename... > class Container, typename ContainerDataType>
struct ISolution
{
    virtual void Algorithm(const Container<ContainerDataType>& rInputData) = 0;
    virtual ~ISolution(){}
};

#endif
