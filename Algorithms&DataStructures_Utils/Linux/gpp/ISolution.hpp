template <template <typename... > class Container, typename ContainerDataType>
struct ISolution
{
    virtual void Algorithm(const Container<ContainerDataType>& rInputData) = 0;
    virtual ~ISolution(){}
};
