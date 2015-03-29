#ifndef SINGLETON_H
#define SINGLETON_H

#include "NonCopyable.h"

template <class T>
class Singleton
{
public:
    static T* Instance()
    {
        static T myT;
        return &myT;
    }
};

#endif