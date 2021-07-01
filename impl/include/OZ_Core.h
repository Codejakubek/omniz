/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#ifndef OZ_CORE_H
#define OZ_CORE_H

#include <memory>
#include <string>
#include <OZ_Commons.h>
#include <OZ_CoreImpls.h>
#include <OZ_CoreResult.h>
#include <OZ_CoreData.h>

class OZ_Core : public OZ_Class {
public:
    OZ_DECLARE_CLASS_H()
    OZ_Core();
    OZ_Core(const OZ_Core& cpy) = delete;
    
    template <typename CORE_IMPL>
    bool BuildImpl() {
        if (!impl_initialized) {
            impl = std::make_unique<CORE_IMPL>(*this);
            impl_initialized = true;
            return true;
        } else {
            return false;
        }
    }
    inline bool BuildData() {
        if(!data_initialized) {
            data = std::make_unique<OZ_CoreData>(*this);
            data_initialized = true;
            return true;
        } else {
            return false;
        }
    }

    virtual std::shared_ptr<OZ_CoreResult> Launch();

    virtual ~OZ_Core();

    std::string OutputNiceCoreState();

    inline const std::unique_ptr<OZ_CoreImpl>& GetImpl() const {
        return impl;
    }
    inline std::unique_ptr<OZ_CoreImpl>& GetImpl() {
        return impl;
    }
    inline const std::unique_ptr<OZ_CoreData>& GetData() const {
        return data;
    }
    inline std::unique_ptr<OZ_CoreData>& GetData() {
        return data;
    }
    inline bool ImplInitialized() const {
        return impl_initialized;
    }
    inline bool DataInitialized() const {
        return data_initialized;
    }
protected:  
    
    bool impl_initialized = false;
    bool data_initialized = false;
    std::unique_ptr<OZ_CoreImpl> impl;
    std::unique_ptr<OZ_CoreData> data;
};
////////////////////////////////////////

#endif