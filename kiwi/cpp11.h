#ifndef __KIWI_CPP11_H__
#define __KIWI_CPP11_H__


// https://github.com/cexer/kiwi

#if __cplusplus <= 199711L && \
    (!defined(_MSC_VER) || _MSC_VER < 1600) && \
    (!defined(__GNUC__) || \
      (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__ < 40603))
    #include "./unique_ptr.hpp"
    //#include "boost/function.hpp"
    //#include "boost/bind.hpp"
    #undef _KIWI_HAS_CPP11
    #define _KIWI_UNIQUE_PTR boost::unique_ptr
    //#define _KIWI_FUNCTION   boost::function
    //#define _KIWI_BIND       boost::bind
#else
    #define _KIWI_HAS_CPP11
    //#include <functional>
    #include <memory>
    #define _KIWI_UNIQUE_PTR std::unique_ptr
    //#define _KIWI_FUNCTION   std::function
    //#define _KIWI_BIND       std::bind
#endif

namespace kiwi
{

template<class T>
class ValidCheckable
{
    typedef void (ValidCheckable::*_SafeBoolType)();
    void _safeTrue(){};

protected:
    ValidCheckable(){}
public:
    operator _SafeBoolType() const
    {
        return static_cast<const T*>(this)->isValid()
            ? &ValidCheckable::_safeTrue
            : 0;
    }
};

};



#endif //#ifndef __KIWI_CPP11_H__