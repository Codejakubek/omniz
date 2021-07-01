/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/



#ifndef OZ_CLASS_H
#define OZ_CLASS_H
#include <typeindex>
#include <string>
#define OZ_DECLARE_CLASS_CPP(CLASS_NAME) \
    std::type_index CLASS_NAME::ClassType() const { \
        return typeid(CLASS_NAME); \
    } \
    std::string CLASS_NAME::ClassTypeName() const { \
         return std::string( #CLASS_NAME );\
    }

#define OZ_DECLARE_CLASS_H() \
    virtual std::type_index ClassType() const override; \
    virtual std::string ClassTypeName() const override; \


class OZ_Class {
public:
    OZ_Class() = default;
    virtual ~OZ_Class() = default;

    virtual std::type_index ClassType() const = 0;
    virtual std::string ClassTypeName() const = 0;
    template <typename CLASS_TYPE>
    bool ClassIfOfType() {
        if (std::type_index(typeid(CLASS_TYPE)) == ClassType()) {
            return true;
        } else {
            return false;
        }
    }
protected:

};

#endif