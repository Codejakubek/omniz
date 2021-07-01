////////////////////////////////////////
//
// SigmaDev - Game Development and Multimedia Library
// Copyright (C) 2020-2021 Dawid Jakubowski (jakubowski.dawid@gmail.com)
//
// SigmaDev Library is licensed under MIT License (You can find it in the LICENSE file)
// Most recent version of the library is found on gitchub repository: 
// https://github.com/Codedemens/SigmaDev/
// 
// 
// File: /impl/include/SigmaDev/Misc/Class.h
// Description:
// Additional Notes:
////////////////////////////////////////

#ifndef SD_CLASS_H
#define SD_CLASS_H

#include <typeindex>
#include <string>

#define SD_DECLARE_CLASS_CPP(CLASS_NAME) \
    std::type_index CLASS_NAME::ClassType() const { \
        return typeid(CLASS_NAME); \
    } \
    std::string CLASS_NAME::ClassTypeName() const { \
         return std::string( #CLASS_NAME );\
    }

#define SD_DECLARE_CLASS_CPP_TEMPLATE_1(CLASS_NAME, TEMPLATE_PARAM_1)    \
    template<>    \
    std::type_index CLASS_NAME<TEMPLATE_PARAM_1>::ClassType() const {   \
        return typeid(CLASS_NAME<TEMPLATE_PARAM_1>);   \
    }   \
    template<>   \
    std::string CLASS_NAME<TEMPLATE_PARAM_1>::ClassTypeName() const {   \
        return std::string( std::string() + #CLASS_NAME + "<" + #TEMPLATE_PARAM_1 + ">");   \
    }       \


#define SD_DECLARE_CLASS_CPP_NESTED1(PARENT_CLASS_NAME, CLASS_NAME) \
    std::type_index PARENT_CLASS_NAME::CLASS_NAME::ClassType() const { \
        return typeid(PARENT_CLASS_NAME::CLASS_NAME); \
    } \
    std::string PARENT_CLASS_NAME::CLASS_NAME::ClassTypeName() const { \
         return std::string(#PARENT_CLASS_NAME) + std::string("::") + std::string(#CLASS_NAME); \
    }

#define SD_DECLARE_CLASS_CPP_NESTED2(PARENT_CLASS_NAME_2, PARENT_CLASS_NAME, CLASS_NAME) \
    std::type_index PARENT_CLASS_NAME::CLASS_NAME::ClassType() const { \
        return typeid(PARENT_CLASS_NAME_2::PARENT_CLASS_NAME::CLASS_NAME); \
    } \
    std::string PARENT_CLASS_NAME::CLASS_NAME::ClassTypeName() const { \
         return std::string(#PARENT_CLASS_NAME_2) + std::string("::") +std::string(#PARENT_CLASS_NAME) + std::string("::") + std::string(#CLASS_NAME); \
    }

#define SD_DECLARE_CLASS_H() \
    virtual std::type_index ClassType() const override; \
    virtual std::string ClassTypeName() const override; \


class SD_Class {
public:
    SD_Class() = default;
    virtual ~SD_Class() = default;

    virtual std::type_index ClassType() const = 0;
    virtual std::string ClassTypeName() const = 0;
    template <typename CLASS_TYPE>
    bool ClassIsOfType() const {
        if (std::type_index(typeid(CLASS_TYPE)) == ClassType()) {
            return true;
        } else {
            return false;
        }
    }
protected:

};

#endif