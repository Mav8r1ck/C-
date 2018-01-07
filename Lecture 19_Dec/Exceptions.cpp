#include "BinaryTree.h"

NullptrException::NullptrException(char const *message)

    : _message (message)
    /*
    const char* what() throw(){
        return _message;
    };
     */
{
}

const char *NullptrException::what() const {
    std::cout<<_message;
    return exception::what();
}

NotFindException::NotFindException(char const *message)
        : _message (message)
{
}

const char *NotFindException::what() const {
    std::cout<<_message;
    return exception::what();
}
