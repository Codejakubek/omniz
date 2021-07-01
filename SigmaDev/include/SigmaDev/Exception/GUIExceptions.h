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
// File: /impl/include/SigmaDev/Exception/GUIExceptions.h
// Description:
// Additional Notes:

#ifndef SD_GUI_EXCEPTIONS_H
#define SD_GUI_EXCEPTIONS_H

#include <SigmaDev/Exception/Exception.h>


/** 
 * @defgroup gui_object_exceptions GUIObject Exceptions
 *
 * all SD_GUIObject Exceptions
 * 
 * 
 */

namespace exc 
{
    ////////////////////////////////////////
    class SD_GUIObjectChildInsertionFailed : public SD_Exception {
    public:
        /**
         * @brief Default exception name and description constructor
         */
        SD_GUIObjectChildInsertionFailed();
        /**
         * @brief Specify the id_or_path of a SD_GUIObject children element
         * 
         * @param id_or_path Id or path of a SD_GUIObject
         */
        SD_GUIObjectChildInsertionFailed(const std::string& id_or_path);
        /**
         * @brief Specify exception name and descriptin, and 
         *        id_or_path of a SD_GUIOBject children element
         * 
         * @param id_or_path Id or path of a SD_GUIObject
         * @param exc_name Exception Name
         * @param exc_desc Exception Description
         */
        SD_GUIObjectChildInsertionFailed(
            const std::string& id_or_path,
            const std::string& exc_name,
            const std::string& exc_desc
        );
        virtual ~SD_GUIObjectChildInsertionFailed() = default;

        /**
         * @brief Overrided default exception description.
         * 
         * @return std::string Overrided default exception description
         */
        virtual std::string DefaultExceptionDescription() const override;

        inline const std::string& GetIdOrPath() const {
            return id_or_path;
        }
    protected:
        std::string id_or_path;
    };
    ////////////////////////////////////////
    class SD_GUIObjectChildErasionFailed : public SD_Exception {
    public:
        /**
         * @brief Default exception name and description constructor
         */
        SD_GUIObjectChildErasionFailed();
        /**
         * @brief Specify the id_or_path of a SD_GUIObject children element
         * 
         * @param id_or_path Id or path of a SD_GUIObject
         */
        SD_GUIObjectChildErasionFailed(const std::string& id_or_path);
        /**
         * @brief Specify exception name and descriptin, and 
         *        id_or_path of a SD_GUIOBject children element
         * 
         * @param id_or_path Id or path of a SD_GUIObject
         * @param exc_name Exception Name
         * @param exc_desc Exception Description
         */
        SD_GUIObjectChildErasionFailed(
            const std::string& id_or_path,
            const std::string& exc_name,
            const std::string& exc_desc
        );
        virtual ~SD_GUIObjectChildErasionFailed() = default;

        /**
         * @brief Overrided default exception description.
         * 
         * @return std::string Overrided default exception description
         */
        virtual std::string DefaultExceptionDescription() const override;


        inline const std::string& GetIdOrPath() const {
            return id_or_path;
        }
    protected:
        std::string id_or_path;
    };
    ////////////////////////////////////////
    class SD_GUIObjectChildNotFound : public SD_Exception {
    public:
        /**
         * @brief Default exception name and description constructor
         */
        SD_GUIObjectChildNotFound();
        /**
         * @brief Specify the id_or_path of a SD_GUIObject children element
         * 
         * @param id_or_path Id or path of a SD_GUIObject
         */
        SD_GUIObjectChildNotFound(const std::string& id_or_path);
        /**
         * @brief Specify exception name and descriptin, and 
         *        id_or_path of a SD_GUIObject children element
         * 
         * @param id_or_path Id or path of a SD_GUIObject
         * @param exc_name Exception Name
         * @param exc_desc Exception Description
         */
        SD_GUIObjectChildNotFound(
            const std::string& id_or_path,
            const std::string& exc_name,
            const std::string& exc_desc
        );
        virtual ~SD_GUIObjectChildNotFound() = default;

        /**
         * @brief Overrided default exception description.
         * 
         * @return std::string Overrided default exception description
         */
        virtual std::string DefaultExceptionDescription() const override;
    
        inline const std::string& GetIdOrPath() const {
            return id_or_path;
        }
    protected:
        std::string id_or_path;
    };
    ////////////////////////////////////////
    class SD_GUIAccessFailed : public SD_Exception {
    public:
        /**
         * @brief Default exception name and description constructor
         */
        SD_GUIAccessFailed();
        /**
         * @brief Specify the exception description. Name stays the same
         * 
         * @param exc_desc Exception Description
         */
        SD_GUIAccessFailed(const std::string& exc_desc);
        /**
         * @brief Specify the exception name and description.
         * 
         * @param exc_name Exception Name
         * @param exc_desc Exception Description
         */
        SD_GUIAccessFailed(
            const std::string& exc_name,
            const std::string& exc_desc
        );

        /**
         * @brief Overrided default exception description.
         * 
         * @return std::string Overrided default exception description
         */
        virtual std::string DefaultExceptionDescription() const override;
    protected:
        
    };
    ////////////////////////////////////////
    class SD_GUIObjectSpecializationPackageInsertionFailed : public SD_Exception {
    public:
        /**
         * @brief Default exception name and description 
         */
        SD_GUIObjectSpecializationPackageInsertionFailed();
        /**
         * @brief Default exception name and description.
         *        Specify package_id of SD_GUIObjectSpecializationPackage
         * 
         * @param package_id 
         */
        SD_GUIObjectSpecializationPackageInsertionFailed(const std::string& package_id);

        /**
         * @brief Specify exception name and description, and
         *        package_id of SD_GUIObjectSpecializationPackage
         * 
         * @param package_id SD_GUIObjectSpecializationPackage ID
         * @param exc_name Exception Name
         * @param exc_desc Exception Description
         */
        SD_GUIObjectSpecializationPackageInsertionFailed(
            const std::string& package_id,
            const std::string& exc_name,
            const std::string& exc_desc
        );
        virtual ~SD_GUIObjectSpecializationPackageInsertionFailed() = default;

        /**
         * @brief Overrided default exception description.
         * 
         * @return std::string Overrided default exception description
         */
        virtual std::string DefaultExceptionDescription() const override;

        inline const std::string& GetId() const {
            return package_id;
        }
    protected:
        std::string package_id;
    };

    ////////////////////////////////////////
    class SD_GUIObjectSpecializationPackageErasionFailed : public SD_Exception {
    public:
        /**
         * @brief Default exception name and description
         */
        SD_GUIObjectSpecializationPackageErasionFailed();
        /**
         * @brief Default exception name and description.
         *        Specify package_id of SD_GUIObjectSpecializationPackage
         * 
         * @param package_id 
         */
        SD_GUIObjectSpecializationPackageErasionFailed(const std::string& package_id);
        /**
         * @brief Specify exception name and description, and
         *        package_id of SD_GUIObejctSpecializationPackage
         * 
         * @param package_id SD_GUIObjectSpecializationPackage ID
         * @param exc_name Exception Name
         * @param exc_desc Exception Description
         */
        SD_GUIObjectSpecializationPackageErasionFailed(
            const std::string& package_id,
            const std::string& exc_name,
            const std::string& exc_desc
        );
        /**
         * @brief Overrided default exception description
         * 
         * @return std::string Overrided default exception description
         */
        virtual std::string DefaultExceptionDescription() const override;

        inline const std::string& GetId() const {
            return package_id;
        }
    protected:
        std::string package_id;
    };
    ////////////////////////////////////////
    class SD_GUIObjectSpecializationPackageNotFound : public SD_Exception {
    public:
        /**
         * @brief Default exception name and description
         */
        SD_GUIObjectSpecializationPackageNotFound();
        /**
         * @brief Default exception name and description,
         *        Specify package_id of SD_GUIObjectSpecializationPackage 
         * 
         * @param package_id 
         */
        SD_GUIObjectSpecializationPackageNotFound(const std::string& package_id);
        /**
         * @brief Specify exception name and description,
         *        and package_id of SD_GUIObjectSpecializationPackagte
         * 
         * @param package_id SD_GUIObjectSpecializationPackage ID
         * @param exc_name Exception Name
         * @param exc_desc Exception Description
         */
        SD_GUIObjectSpecializationPackageNotFound(
            const std::string& package_id,
            const std::string& exc_name,
            const std::string& exc_desc
        );

        /**
         * @brief Overrided default exception description
         * 
         * @return std::string Overrided default exception description
         */
        virtual std::string DefaultExceptionDescription() const override;

        inline const std::string& GetId() const {
            return package_id;
        }
    protected:
        std::string package_id;
    };
    ////////////////////////////////////////
    class SD_GUIObjectTypeIsNotSpecialized : public SD_Exception {
    public:
        /**
         * @brief Default exception name and description 
         */
        SD_GUIObjectTypeIsNotSpecialized();
        /**
         * @brief Default exception name and description.
         *        Specify main_type of SD_GUIObjectType
         * 
         * @param main_type SD_GUIObjectType main type
         */
        SD_GUIObjectTypeIsNotSpecialized(const std::string& main_type);
        /**
         * @brief Specify exception name and description.
         *        Specify main_type of SD_GUIObjectType
         * 
         * @param main_type SD_GUIObjectType main type
         * @param exc_name Exception Name
         * @param exc_desc Exception Description
         */
        SD_GUIObjectTypeIsNotSpecialized(
            const std::string& main_type,
            const std::string& exc_name,
            const std::string& exc_desc
        );
        /**
         * @brief Overrided default exception description
         * 
         * @return std::string Overrided default exception description
         */
        virtual std::string DefaultExceptionDescription() const override;

        inline const std::string& GetId() const {
            return main_type;
        }
    protected:
        std::string main_type;
    };
    ////////////////////////////////////////
    class SD_GUIObjectInitializationFailed : public SD_Exception {
    public:
        SD_GUIObjectInitializationFailed() = delete;

        SD_GUIObjectInitializationFailed(
            const std::string& gui_object_id,
            const std::string& gui_object_type,
            const std::string& exc_description
        );

        /**
         * @brief Overrided default exception description
         * 
         * @return std::string Overrided default exception description
         */
        virtual std::string DefaultExceptionDescription() const override;

        inline const std::string& GetGUIObjectID() const {
            return gui_object_id;
        }
        inline const std::string& GetGUIObjectType() const {
            return gui_object_type;
        }
    protected:
        std::string gui_object_id;
        std::string gui_object_type;
    };
    ////////////////////////////////////////
    class SD_GUIObjectReleaseFailed : public SD_Exception {
    public:
        SD_GUIObjectReleaseFailed() = delete;

        SD_GUIObjectReleaseFailed(
            const std::string& gui_object_id,
            const std::string& gui_object_type,
            const std::string& exc_description
        );

        /**
         * @brief Overrided default exception description
         * 
         * @return std::string Overrided default exception description
         */
        virtual std::string DefaultExceptionDescription() const override;

        inline const std::string& GetGUIObjectID() const {
            return gui_object_id;
        }
        inline const std::string& GetGUIObjectType() const {
            return gui_object_type;
        }
    protected:
        std::string gui_object_id;
        std::string gui_object_type;
    };
    ////////////////////////////////////////
    class SD_GUIObjectJsonLoadFailed : public SD_Exception {
    public:
        SD_GUIObjectJsonLoadFailed() = delete;
        SD_GUIObjectJsonLoadFailed(
            const std::string& gui_object_type,
            const std::string& description
        );
        virtual ~SD_GUIObjectJsonLoadFailed() = default;

        virtual std::string DefaultExceptionDescription() const override;
    
        inline const std::string& GetObjectType() const {
            return gui_object_type;
        }
    protected:
        std::string gui_object_type;
    };
    ////////////////////////////////////////
}

#endif
