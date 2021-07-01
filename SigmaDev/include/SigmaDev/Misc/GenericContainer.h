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
// File: /impl/include/SigmaDev/Misc/GenericContainer.h
// Description:
// Additional Notes:

#ifndef SD_GENERIC_CONTAINER_H
#define SD_GENERIC_CONTAINER_H

#include <string>
#include <map>
#include <memory>
#include <sol/sol.hpp>
#include <nlohmann/json.hpp>
#include <SigmaDev/Misc/Class.h>
#include <SFML/Graphics.hpp>
#include <SigmaDev/Misc/Path.h>
#include <SigmaDev/Misc/Optional.h>

// TODO: (in this order)
//     DONE: Create SD_GenericVariable and SD_GenericValue 
//         DONE: Tests (sd_generic_variable)
//
//
//     TODO: Create Create Simple SD_GenericVariable concretes
//         TODO: Tests (sd_generic_variable_concretes)
//
//
//     TODO: Create simple API for insertion & erasion & find (use SD_StringPath for tree insertion & erason & find)
//         TODO: Tests (sd_generic_variable_access)
//
//
//     TODO: Create SD_GenericVariableLoadingRules
//         TODO: Tests (sd_generic_variable_loading_rules)
//
//
//     TODO: JSON Loading
//         TODO: Tests (sd_generic_variable_json_loading)
//
//
//     TODO: JSON Saving
//         TODO: Tests (sd_generic_variable_json_saving)
//
//
//     TODO: Create API for SD_GenericVariableLoadingRules creation 
//         TODO: Tests (sd_generic_variable_loading_rules_api)
//
//
//     TODO: Loading via LUA
//         TODO: Tests (sd_generic_variable_luatesting)
//
//
//     TODO: Start working on SD_GUIObject

////////////////////////////////////////
class SD_GenericVariable;
class SD_ObjectValue;
////////////////////////////////////////
class SD_IGenericValue : public SD_Class {
public:
    SD_IGenericValue() {}
    virtual ~SD_IGenericValue() {}

    inline bool Initialized() const {
        return initialized;
    }
    std::type_index ValueTypeClass() const;
protected:
    bool initialized = false;
};
////////////////////////////////////////
template <typename VALUE_TYPE>
class SD_GenericValue : public SD_IGenericValue {
public:
    SD_DECLARE_CLASS_H()

    SD_GenericValue() {}
    virtual ~SD_GenericValue() {}

    const VALUE_TYPE& GetValue() const;
    VALUE_TYPE& GetValue();
    void SetValue(const VALUE_TYPE& value);

    std::type_index ValueTypeClass() const{
        return typeid(VALUE_TYPE);
    } 
protected:

};
////////////////////////////////////////
template <typename VALUE_TYPE>
class SD_GenericRawValue : public SD_GenericValue<VALUE_TYPE> {
public:
    SD_DECLARE_CLASS_H()

    SD_GenericRawValue() {}
    SD_GenericRawValue(const VALUE_TYPE& value) : value(value) {
        this->initialized = true;
    }
    virtual ~SD_GenericRawValue() {}

    const VALUE_TYPE& GetValue() const {
        return this->value;
    }
    VALUE_TYPE& GetValue() {
        return this->value;
    }
    void SetValue(const VALUE_TYPE& value) {
        this->value = value;
    }
protected:
    VALUE_TYPE value;
};
////////////////////////////////////////
template <typename VALUE_TYPE>
class SD_GenericSharedPtrValue : public SD_GenericValue<VALUE_TYPE> {
public:
    SD_DECLARE_CLASS_H()

    SD_GenericSharedPtrValue() {}
    SD_GenericSharedPtrValue(
        const std::shared_ptr<VALUE_TYPE>& value
    ) : value(value) {
        this->initialized = true;
    }
    SD_GenericSharedPtrValue(
        VALUE_TYPE* value_ptr
    ) : value(value_ptr) {
        this->initialized = true;
    }

    const VALUE_TYPE& GetValue() const {
        return *value.get();
    }
    VALUE_TYPE& GetValue() {
        return *value.get();
    }
    void SetValue(const VALUE_TYPE& value) {
        this->value = std::make_shared<VALUE_TYPE>(value);
    }
protected:
    std::shared_ptr<VALUE_TYPE> value;
};
////////////////////////////////////////
template <typename VALUE_TYPE>
class SD_GenericUniquePtrValue : public SD_GenericValue<VALUE_TYPE> {
public:
    SD_DECLARE_CLASS_H()

    SD_GenericUniquePtrValue() {}
    SD_GenericUniquePtrValue(
        std::unique_ptr<VALUE_TYPE>&& move
    ) : value(move) {
        this->initialized = true;
    }
    SD_GenericUniquePtrValue(
        VALUE_TYPE* value_ptr
    ) : value(value_ptr) {
        this->initialized = true;
    }

    const VALUE_TYPE& GetValue() const {
        return *value.get();
    }
    VALUE_TYPE& GetValue() {
        return *value.get();
    }
    void SetValue(const VALUE_TYPE& value) {
        this->value = std::make_shared<VALUE_TYPE>(value);
    }
protected:
    std::unique_ptr<VALUE_TYPE> value;
};
////////////////////////////////////////

////////////////////////////////////////
class SD_GenericVariable : public SD_Class {
public:
    SD_DECLARE_CLASS_H()


    SD_GenericVariable() = delete;
    SD_GenericVariable(
        const std::string& variable_id
    );
    //TODO: Impl
    SD_GenericVariable(SD_GenericVariable&& move);

    template <typename VALUE_TYPE>
    bool AddVariable_RawValue(
        const SD_StringPath& path,
        const VALUE_TYPE& value
    );
    template <typename VALUE_TYPE>
    bool AddVariable_SharedPtrValue (
        const SD_StringPath& path,
        VALUE_TYPE* value
    );
    template <typename VALUE_TYPE>
    bool AddVariable_UniquePtrValue(
        const SD_StringPath& path,
        VALUE_TYPE* value
    );

    virtual SD_OptionalRef<SD_ObjectValue> GetObjectValue(const SD_StringPath& path) const;
    

    virtual void SetAs_ObjectValue();
    virtual SD_OptionalRef<SD_ObjectValue> AddVariable_ObjectValue(
        const SD_StringPath& path
    );
    template <typename VALUE_TYPE>
    inline void SetAs_RawValue(const VALUE_TYPE& value) {
        this->value = std::make_unique<SD_GenericRawValue<VALUE_TYPE>>(value);
        this->initialized = true;
    }
    template <typename VALUE_TYPE>
    inline void SetAs_SharedPtrValue(VALUE_TYPE* value) {
        this->value = std::make_unique<SD_GenericSharedPtrValue<VALUE_TYPE>>(value);
        this->initialized = true;
    }
    template <typename VALUE_TYPE>
    inline void SetAs_UniquePtrValue(VALUE_TYPE* value) {
        this->value = std::make_unique<SD_GenericUniquePtrValue<VALUE_TYPE>>(value);
        this->initialized = true;
    }
    inline std::unique_ptr<SD_IGenericValue>& GetValueMemory() {
        return value;
    }
    inline const std::unique_ptr<SD_IGenericValue>& GetValueMemory() const {
        return value;
    }
    template <typename VALUE_TYPE>
    inline SD_OptionalRef<VALUE_TYPE> GetValue() {
        if (Initialized()) {
            SD_IGenericValue* v = value.get();
            SD_GenericValue<VALUE_TYPE>* c = dynamic_cast<SD_GenericValue<VALUE_TYPE>*>(v);
            if (c) {
                SD_GenericRawValue<VALUE_TYPE>* c_rawvalue = dynamic_cast<SD_GenericRawValue<VALUE_TYPE>*>(c);
                if (c_rawvalue) {
                    return c_rawvalue->GetValue();
                }
                SD_GenericSharedPtrValue<VALUE_TYPE>* c_sharedptr = dynamic_cast<SD_GenericSharedPtrValue<VALUE_TYPE>*>(c);
                if (c_sharedptr) {
                    return c_sharedptr->GetValue();
                }
                SD_GenericUniquePtrValue<VALUE_TYPE>* c_uniqueptr = dynamic_cast<SD_GenericUniquePtrValue<VALUE_TYPE>*>(c);
                if (c_uniqueptr) {
                    return c_uniqueptr->GetValue();
                }
            }
        }
        //Empty
        return SD_OptionalRef<VALUE_TYPE>();
    }
    template <typename VALUE_TYPE>
    inline SD_OptionalConstRef<VALUE_TYPE> GetValue() const {
        if (Initialized()) {
            const SD_IGenericValue* v = value.get();
            const SD_GenericValue<VALUE_TYPE>* c = dynamic_cast<const SD_GenericValue<VALUE_TYPE>*>(v);
            if (c) {
                const SD_GenericRawValue<VALUE_TYPE>* c_rawvalue = dynamic_cast<const SD_GenericRawValue<VALUE_TYPE>*>(c);
                if (c_rawvalue) {
                    return c_rawvalue->GetValue();
                }
                const SD_GenericSharedPtrValue<VALUE_TYPE>* c_sharedptr = dynamic_cast<const SD_GenericSharedPtrValue<VALUE_TYPE>*>(c);
                if (c_sharedptr) {
                    return c_sharedptr->GetValue();
                }
                const SD_GenericUniquePtrValue<VALUE_TYPE>* c_uniqueptr = dynamic_cast<const SD_GenericUniquePtrValue<VALUE_TYPE>*>(c);
                if (c_uniqueptr) {
                    return c_uniqueptr->GetValue();
                }
            }
        }
        //Empty
        return SD_OptionalConstRef<VALUE_TYPE>();
    }
    SD_OptionalRef<SD_ObjectValue> GetAsObjectValue() const;
    template <typename VALUE_TYPE>
    inline bool OfType() const {
        if (Initialized()) {
            try {
                const SD_IGenericValue* v = value.get();
                const SD_GenericValue<VALUE_TYPE>* c = dynamic_cast<const SD_GenericValue<VALUE_TYPE>*>(v);
                return c->ValueTypeClass() == typeid(VALUE_TYPE);
            } catch (const std::bad_cast& exc) {
                return false;
            }
        }
        return false;
    }
    template <typename VALUE_TYPE>
    inline bool Is_RawValue() const {
        if (Initialized()) {
            const SD_IGenericValue* v = value.get();
            const SD_GenericRawValue<VALUE_TYPE>* c = dynamic_cast<const SD_GenericRawValue<VALUE_TYPE>*>(v);
            if (c)
                return c->ValueTypeClass() == typeid(VALUE_TYPE);

        }
        return false;
    }
    template <typename VALUE_TYPE>
    inline bool Is_SharedPtrValue() const {
        if (Initialized()) {
            const SD_IGenericValue* v = value.get();
            const SD_GenericSharedPtrValue<VALUE_TYPE>* c = dynamic_cast<const SD_GenericSharedPtrValue<VALUE_TYPE>*>(v);
            if (c)
                return c->ValueTypeClass() == typeid(VALUE_TYPE);
        }
        return false;
    }
    template <typename VALUE_TYPE>
    inline bool Is_UniquePtrValue() const {
        if (Initialized()) {
            const SD_IGenericValue* v = value.get();
            const SD_GenericUniquePtrValue<VALUE_TYPE>* c = dynamic_cast<const SD_GenericUniquePtrValue<VALUE_TYPE>*>(v);
            if (c)
                return c->ValueTypeClass() == typeid(VALUE_TYPE);
        }
        return false;
    }

    inline bool Initialized() const {
        return initialized && value;
    }
protected:
    std::string variable_id;
    
    bool initialized = false;
    std::unique_ptr<SD_IGenericValue> value;
};
////////////////////////////////////////
class SD_ObjectValue : public SD_IGenericValue {
public:
    SD_DECLARE_CLASS_H()

    typedef std::map<std::string, std::unique_ptr<SD_GenericVariable>> _Variables;

    inline SD_OptionalRef<SD_GenericVariable> CreateVariable(const std::string& variable_id) {
        auto insert_pair = variables.insert(
            std::make_pair(
                variable_id,
                std::move(std::make_unique<SD_GenericVariable>(variable_id))
            )
        );
        if (insert_pair.second) {
            std::unique_ptr<SD_GenericVariable>& var = 
            insert_pair.first->second;

            return SD_OptionalRef<SD_GenericVariable>(*var.get());
        }
        return SD_OptionalRef<SD_GenericVariable>();
    }
    inline SD_OptionalRef<SD_GenericVariable> CreateVariable_ObjectValue(const std::string& variable_id) {
        SD_OptionalRef<SD_GenericVariable> v = CreateVariable(variable_id);
        if(v.Initialized()) {
            v.Get().SetAs_ObjectValue();
        } 
        return v;
    }
    template <typename VALUE_TYPE>
    bool CreateVariable_AsRawValue(const std::string& variable_id, const VALUE_TYPE& value) {
        SD_OptionalRef<SD_GenericVariable> opt_var =
            CreateVariable(variable_id);

        if (opt_var.Initialized()) {
            opt_var.Get().SetAs_RawValue<VALUE_TYPE>(value);
            return true;
        }
        return false;
    }
    template <typename VALUE_TYPE>
    bool CreateVariable_AsSharedPtrValue(const std::string& variable_id, VALUE_TYPE* value) {
        SD_OptionalRef<SD_GenericVariable> opt_var =
            CreateVariable(variable_id);

        if (opt_var.Initialized()) {
            opt_var.Get().SetAs_SharedPtrValue<VALUE_TYPE>(value);
            return true;
        }
        return false;
    }
    template <typename VALUE_TYPE>
    bool CreateVariable_AsUniquePtrValue(const std::string& variable_id, VALUE_TYPE* value) {
        SD_OptionalRef<SD_GenericVariable> opt_var =
            CreateVariable(variable_id);

        if (opt_var.Initialized()) {
            opt_var.Get().SetAs_UniquePtrValue<VALUE_TYPE>(value);
            return true;
        }
        return false;
    }

    inline bool EraseVariable(const std::string& variable_id) {
        auto it = variables.find(variable_id);
        if (it != variables.end()) {
            variables.erase(it);
            return true;
        } else {
            return false;
        }
    }
    inline SD_OptionalConstRef<std::unique_ptr<SD_GenericVariable>> GetVariable(const std::string& variable_id) const {
        auto it = variables.find(variable_id);
        if (it != variables.end()) {
            return SD_OptionalConstRef<std::unique_ptr<SD_GenericVariable>>(
                it->second
            );
        } else {
            return SD_OptionalConstRef<std::unique_ptr<SD_GenericVariable>>();
        }
    }
    inline SD_OptionalRef<SD_ObjectValue> GetVariableObjectRef(const std::string& variable_id) {
        SD_OptionalConstRef<std::unique_ptr<SD_GenericVariable>> opt_variable = GetVariable(variable_id);
        if (opt_variable.Initialized()) {
            return opt_variable.Get()->GetAsObjectValue();
        }
        return SD_OptionalRef<SD_ObjectValue>();
    }
    template <typename VALUE_TYPE>
    SD_OptionalRef<VALUE_TYPE> GetVariableRef(const std::string& variable_id) {
        SD_OptionalConstRef<std::unique_ptr<SD_GenericVariable>> opt_variable = GetVariable(variable_id);
        if (opt_variable.Initialized()) {
            return opt_variable.Get()->GetValue<VALUE_TYPE>();
        }
        return SD_OptionalRef<VALUE_TYPE>();
    }
    template <typename VALUE_TYPE>
    SD_OptionalConstRef<VALUE_TYPE> GetVariableRef(const std::string& variable_id) const {
        SD_OptionalConstRef<std::unique_ptr<SD_GenericVariable>> opt_variable = GetVariable(variable_id);
        if (opt_variable.Initialized()) {
            const std::unique_ptr<SD_GenericVariable>& v = opt_variable.Get();
            return v->GetValue<VALUE_TYPE>();
        }
        return SD_OptionalRef<VALUE_TYPE>();
    }
    inline const _Variables& GetVariables() const {
        return variables;
    }
    inline _Variables& GetVariables() {
        return variables;
    }
protected:
    _Variables variables;
};


#endif