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
// File: /impl/include/SigmaDev/Exception/TestingExceptions.h
// Description:
//      TestingExceptions.h contain the declarations of the concrete exceptions 
//      used by code related to testing.
// Additional Notes:
////////////////////////////////////////

#ifndef SD_EXCEPTION_TESTINGEXCEPTIONS_H
#define SD_EXCEPTION_TESTINGEXCEPTIONS_H

#include <SigmaDev/Exception/Exception.h>

namespace exc 
{
////////////////////////////////////////
class SD_TestSpecifyNotFoundType : public SD_Exception {
public: 
    /**
     * @brief Uses default exception name and description.
     *        type is not set.
     */
    SD_TestSpecifyNotFoundType();
    /**
     * @brief Uses default exception name and description
     *        Sets the type.
     * 
     * @param type Test category
     */
    SD_TestSpecifyNotFoundType(const std::string& type);

    inline const std::string& GetType() const {
        return type;
    }
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
protected:
    std::string type;
};
////////////////////////////////////////
class SD_TestCheckInsertionFailed : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        check_id is not set.
     */
    SD_TestCheckInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the check_id.
     * 
     * @param check_id Test Check Id (name)
     */
    SD_TestCheckInsertionFailed(const std::string& check_id);

    inline const std::string& GetCheckId() const {
        return check_id;
    }
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
protected:
    std::string check_id;
};
////////////////////////////////////////
class SD_TestCheckSetFailed : public SD_Exception {
public:
    /**
     * @brief Uses defualt exception name and description
     *        check_id is not set.
     */
    SD_TestCheckSetFailed();
    /**
     * @brief Uses default exception name and description.
     *         Sets the check_id
     * 
     * @param check_id Test Check Id (name)
     */
    SD_TestCheckSetFailed(const std::string& check_id);

    inline const std::string& GetCheckId() const {
        return check_id;
    }
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
protected:
    std::string check_id;
};
////////////////////////////////////////
class SD_TestCheckNotFound : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        check_id is not set.
     */
    SD_TestCheckNotFound();
    /**
     * @brief Uses default exception name and description.
     *        Sets the check_id
     * 
     * @param check_id Test Check Id (name)
     */
    SD_TestCheckNotFound(const std::string& check_id);

    inline const std::string& GetCheckId() const {
        return check_id;
    }
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
protected:
    std::string check_id;
};
////////////////////////////////////////
class SD_TestCheckErasionFailed : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        check_id is not set.
     */
    SD_TestCheckErasionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the check_id.
     * 
     * @param check_id Test Check Id (name)
     */
    SD_TestCheckErasionFailed(const std::string& check_id);

    inline const std::string& GetCheckId() const {
        return check_id;
    }
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
protected:
    std::string check_id;
};
////////////////////////////////////////
class SD_TestInsertionFailed : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        test_id is not set
     */
    SD_TestInsertionFailed();
    /**
     * @brief Uses default exception name and description.
     *        Sets the test_id
     * 
     * @param test_id Test Id (name)
     */
    SD_TestInsertionFailed(const std::string& test_id);

    inline const std::string& GetTestId() const {
        return test_id;
    }
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
protected:
    std::string test_id;
};
////////////////////////////////////////
class SD_TestNotFound : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        check_id is not set.
     */
    SD_TestNotFound();
    /**
     * @brief Uses default exception name and description.
     *        test_id is not set.
     * 
     * @param test_id Test Id (Name)
     */
    SD_TestNotFound(const std::string& test_id);

    inline const std::string& GetTestId() const {
        return test_id;
    }
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
protected:
    std::string test_id;
};
////////////////////////////////////////
class SD_TestErasionFailed : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        test_id is not set.
     */
    SD_TestErasionFailed();
    /**
     * @brief Uses default excepton name and description.
     *        Sets the test_id.
     * 
     * @param test_id Test Id (name) 
     */
    SD_TestErasionFailed(const std::string& test_id);

    inline const std::string& GetTestId() const {
        return test_id;
    }
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
protected:
    std::string test_id;
}; 
////////////////////////////////////////
class SD_TestExecutionFailed : public SD_Exception {
public:
    /**
     * @brief Uses default exception name and description.
     *        test_id is not set.
     * 
     */
    SD_TestExecutionFailed();
    /**
     * @brief Uses default exception name and description
     *        Sets the test_id.
     * 
     * @param test_id Test Id (Name)
     */
    SD_TestExecutionFailed(const std::string& test_id);

    inline const std::string& GetTestId() const {
        return test_id;
    }
    /**
     * @brief Overrides default exception description 
     * 
     * @return std::string Default Exception Description 
     */
    virtual std::string DefaultExceptionDescription() const override;
protected:
    std::string test_id;
};

}   
#endif
