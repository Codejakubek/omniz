////////////////////////////////////////
//
// SigmaDev - Game Development and Multimedia Library
// Copyright (C) 2020-2021 Dawid Jakubowski (jakubowski.dawid@gmail.com)
//
// SigmaDev Library is licensed under MIT License (You can find it in the LICENSE file)
// Most recent version of the library is found on github repository: 
// https://github.com/Codedemens/SigmaDev/
// 
// 
// File: /impl/include/SigmaDev/Misc/Optional.h
// Description:
// Additional Notes:

#ifndef SD_OPTIONAL_H
#define SD_OPTIONAL_H

#include <memory>
#include <SigmaDev/Misc/Class.h>
#include <SigmaDev/Misc/Empty.h>

////////////////////////////////////////
template <typename T>
class SD_Optional {
public:

    SD_Optional() {}
    SD_Optional(const T& v) : v(v), initialized(true) {}
    SD_Optional(T&& v) : v(v), initialized(true) {}
    virtual ~SD_Optional() {} 

    inline bool Initialized() const {
        return initialized;
    }
    inline const T& Get() const {
        return v;
    }
    inline T& Get() {
        return v;
    }
protected:

    bool initialized = false;
    T v;
};
////////////////////////////////////////
template <typename T>
class SD_OptionalRawptr {
public:
    SD_OptionalRawptr() {}
    SD_OptionalRawptr(T* ptr) : ptr(ptr) {}
    SD_OptionalRawptr(const T* ptr) : ptr(ptr) {}
    virtual ~SD_OptionalRawptr() {}

    inline void SetPtr(T* ptr) {
        this->ptr = ptr;
    }
    inline T* Get() {
        return ptr;
    }
    inline const T* Get() const {
        return ptr;
    }
    inline T& Ref() {
        return *ptr;
    }
    inline const T& Ref() const {
        return *ptr;
    }
    inline bool Initialized() const {
        return !(ptr == nullptr);
    }
protected:
    T* ptr = nullptr;
};  
////////////////////////////////////////
template <typename T>
class SD_OptionalRef {
public:
    SD_OptionalRef() {}
    SD_OptionalRef(T& ref) : ref(&ref), initialized(true) {}

    inline bool Initialized() const {
        return initialized;
    }
    inline const T& Get() const {
        return *ref;
    }
    inline T& Get() {
        return *ref;
    }
protected:
    bool initialized = false;
    T* ref = nullptr;
};
////////////////////////////////////////
template <typename T>
class SD_OptionalConstRef {
public:
    SD_OptionalConstRef() {}
    SD_OptionalConstRef(const T& ref) : ref(&ref), initialized(true) {}

    inline bool Initialized() const {
        return initialized;
    }
    inline const T& Get() const {
        return *ref;
    }
protected:
    bool initialized = false;
    const T* ref = nullptr;
};
////////////////////////////////////////
template <typename T>
class SD_OptionalShared {
public:

    SD_OptionalShared() {

    } 
    SD_OptionalShared(
        const std::shared_ptr<T>& v
    ) :v(v), initialized(true) {

    }
    SD_OptionalShared(
        T* ptr
    ) : v(ptr), initialized(true) {

    }
    SD_OptionalShared(
        const SD_OptionalShared& cpy
    ) : v(cpy.Get()), initialized(v.Initialized()) {

    }
    SD_OptionalShared(
        SD_OptionalShared&& move
    ) : v(move.Get()), initialized(v.Initialized()) {

    }
    inline SD_OptionalShared<T>& operator=(const SD_OptionalShared<T>& b) {
        this->v = b.Get();
        return *this;
    }
    inline bool Initialized() const {
        return initialized && v;
    }
    inline const std::shared_ptr<T>& Get() const {
        return v;
    }
    inline std::shared_ptr<T>& Get() {
        return v;
    }
protected:

    
    bool initialized = false;
    std::shared_ptr<T> v;

};
template <typename T>
SD_OptionalShared<T> SD_MakeOptionalShared(const T& value) {
    return SD_OptionalShared<T>(std::make_shared<T>(value));
}
////////////////////////////////////////
template <typename T>
class SD_OptionalUnique {
public:

    SD_OptionalUnique() {

    } 
    SD_OptionalUnique(
        std::unique_ptr<T>&& v
    ) :v(std::move(v)), initialized(true) {

    }
    SD_OptionalUnique(
        T* ptr
    ) : v(ptr), initialized(true) {

    }
    SD_OptionalUnique(
        const SD_OptionalUnique& cpy
    ) : v(cpy.Get()), initialized(v.Initialized()) {

    }
    SD_OptionalUnique(
        SD_OptionalUnique&& move
    ) : v(move.Get()), initialized(v.Initialized()) {

    }
    inline SD_OptionalUnique<T>& operator=(const SD_OptionalUnique<T>& b) {
        this->v = b.Get();
        return *this;
    }
    inline bool Initialized() const {
        return initialized && v;
    }
    inline const std::unique_ptr<T>& Get() const {
        return v;
    }
    inline std::unique_ptr<T>& Get() {
        return v;
    }
protected:

    
    bool initialized = false;
    std::unique_ptr<T> v;

};
////////////////////////////////////////

#endif