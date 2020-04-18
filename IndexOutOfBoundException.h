#include <exception>
#include <string>

class IndexOutOfBoundException: public std::exception
{   
    public:
        IndexOutOfBoundException(unsigned int req_index, unsigned int length);
        
    private:
        unsigned int req_index;
        unsigned int length;
        
        virtual const char* what() const throw();
};