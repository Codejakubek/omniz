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
// File: /impl/src/SigmaDev/Application/DefaultApplication.h
// Description:
// Additional Notes:
////////////////////////////////////////

#ifndef SD_APPLICATION_DEFAULT_APPLICATION_H
#define SD_APPLICATION_DEFAULT_APPLICATION_H

#include <SigmaDev/Exception/Exception.h>
#include <SigmaDev/Application/Application.h>

////////////////////////////////////////
namespace exc {
    class SD_DefaultApplicationInitializationFailed : public SD_InitializationFailed {
    public:
        SD_DefaultApplicationInitializationFailed() = delete;
    protected:
        SD_DefaultApplicationInitializationFailed(
            const std::string& name,
            const std::string& detailed_description
        );
    public:
        SD_DefaultApplicationInitializationFailed(const std::string& detailed_description);
    };
}
////////////////////////////////////////
class SD_DefaultApplicationInitialization : public SD_ApplicationInitialization {
public:
    SD_DECLARE_CLASS_H()
    virtual void Initialize(SD_Application& application) override;
protected:

};
////////////////////////////////////////
class SD_DefaultApplicationRelease : public SD_ApplicationRelease {
public:
    SD_DECLARE_CLASS_H()
    virtual void Release(SD_Application& application) override;
};
////////////////////////////////////////
class SD_DefaultApplicationTick : public SD_ApplicationTick {
public:
    SD_DECLARE_CLASS_H()
    virtual void Tick(SD_Application& application) override;
protected:
    virtual bool IsThereClosedWindowEvent(
        SD_Application& application,
        const std::string& window_id
    );
};
////////////////////////////////////////
/** TODO: SD_DefaultApplication_Tutorial_And_Imprecise_descriptions */
class SD_DefaultApplication : public SD_Application {
public:
    SD_DECLARE_CLASS_H()
    SD_DefaultApplication();
    SD_DefaultApplication(const SD_DefaultApplication& copy_constructor) = delete;
    virtual ~SD_DefaultApplication();

    virtual void ExecuteOneTick() override;
    virtual void Start() override;
    /**
     * @brief Not implemented yet
     */
    virtual void Pause() override;
    /**
     * @brief Not implemented yet
     */
    virtual void Stop() override;
protected:
    virtual void Preinitialize() override;
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void Tick() override;
};
////////////////////////////////////////

#endif