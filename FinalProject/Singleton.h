#pragma once

#include <assert.h>
#include <iostream>

// To make a class a singleton, you need to (a) have it inherit from this 
// class, and (b) define its s_Obj in its .cpp file.  Then you can call the
// static get() function from anywhere to get it.
template<class T>
class Singleton
{
protected:
    explicit Singleton()
    {
        if (!!s_Obj)
        {
            assert(s_Obj != this);
            std::cout << "Duplicate singleton creation!  Deleting the old one..." << std::endl;
            delete s_Obj;
        }
        s_Obj = (T*)this;
    }

    virtual ~Singleton() {}

public:
    static T& get()
    {
        if (!s_Obj)
        {
            new T;
        };
        assert(!!s_Obj);
        return *s_Obj;
    }

    static bool exists() { return !!s_Obj; }

private:
    static T* s_Obj;

private:
    // DELIBERATELY UNDEFINED
    Singleton(const Singleton& rhs);
    Singleton& operator=(const Singleton& rhs);
    bool operator==(const Singleton& rhs) const;
    bool operator<(const Singleton& rhs) const;
};