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
// File: /impl/include/SigmaDev/Testing.h
// Description:
//
// Additional Notes:
//
////////////////////////////////////////

#ifndef SD_TESTING_H
#define SD_TESTING_H

#include <memory>
#include <string>
#include <map>
#include <functional>
#include <set>
#include <initializer_list>
#include <SigmaDev/Exception/TestingExceptions.h>
#include <vector>
#include <SigmaDev/Misc/Class.h>


////////////////////////////////////////

/**
 * @brief SD_TestSpecify is a container class, specifying the test types and names. 
 *        It could be used for specifying which tests to execute, and other. 
 * 
 */
class SD_TestSpecify : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    /**
     * @brief Raw container of specify. 
     *        First parameter (std::string) is the type (category) of tests,
     *        Second parameter (std::set<std::string>) is a set of test ids (names) 
     */
    typedef std::map<std::string, std::set<std::string>> _specify;
    /**
     * @brief Specify with no tests
     */ 
    SD_TestSpecify();
    /**
     * @brief Specify the tests. The pair inside the initializer list is as follows - {"type", "id"}
     */
    SD_TestSpecify(std::initializer_list<std::pair<std::string, std::string>> list_of_tests_and_its_types);

    /**
     * @brief Returns true if there is at least one test of type passed as a parameter
     * 
     * @param type test type (category)
     * @return true if there is at least one type.
     */
    inline bool AreThereAnyTestsOfType(const std::string& type) const {
        auto it = specify.find(type);
        if (it != specify.end()) {
            if(it->second.empty()) {
                return false;
            } else return true;
        } else return false;
    }
    /**
     * @brief Returns the amount tests of specific category
     * 
     * @param type test type (category)
     * @return unsigned int amount of tests of specific category
     */
    inline unsigned int HowManyTestsAreThereOfType(const std::string& type) const {
        auto it = specify.find(type);
        if (it != specify.end()) {
            return it->second.size();
        } else return 0;
    }
    /**
     * @brief Returns the reference of tests of a test type (category). 
     *        Throws exc::SD_TestSpecifyNotFoundType if there are none.
     * 
     * @param type test type (category)
     * @return const std::set<std::string>& reference to a set of test ids 
     */
    inline const std::set<std::string>& WhatAreSpecifiedTestsOfType(const std::string& type) const {
        auto it = specify.find(type);
        if (it != specify.end()) {
            return it->second;
        } else {
            auto e = exc::SD_TestSpecifyNotFoundType(type);
            throw e;
        }
    }
    /**
     * @brief Returns true if a container for tests of a specific test type (category) is present
     * 
     * @param type test type (category)
     * @return true if a container for test of a specific test type (category) exists
     */
    inline bool IsThereSpecifiedTypeOf(const std::string& type) const {
        auto it = specify.find(type);
        if (it != specify.end()) {
            return true; 
        } else return false;
    }
    /**
     * @brief Insert new test type id. It doesn't throw anything if fails 
     * 
     * @param type test type (category)
     * @param test_id test id (name)
     */
    virtual void AddTest(const std::string& type, const std::string& test_id);
    /**
     * @brief Erases test type id. It doesn't throw anything if fails
     * 
     * @param type test type (category)
     * @param test_id  test id (name)
     */
    virtual void EraseTest(const std::string& type, const std::string& test_id);
    /**
     * @brief Returns true if a test of a id and type exists
     * 
     * @param type test type (category)
     * @param test_id test id (name)
     * @return true if a test of a id and type exists
     */
    virtual bool TestExists(const std::string& type, const std::string& test_id) const;
    /**
     * \brief checks if there is a type, and at least one test inside it
     */
    virtual bool HasAtLeastOneTestOfType(const std::string& type) const;

    inline const _specify& GetSpecify() const {
        return specify;
    }
    inline _specify& GetSpecify() {
        return specify;
    }
    inline void SetExecuteDefaultUnitTestIfNotSpecified(bool v = true) {
        this->execute_default_unit_tests_if_not_specified = v;
    }
    inline bool ExecuteDefaultUnitTestsIfNotSpecified() const {
        return execute_default_unit_tests_if_not_specified;
    }
protected:
    _specify specify; ///< Raw container, containing test specify
    bool execute_default_unit_tests_if_not_specified = false; ///< Set this to true, if you use specify for test execution, and you want to execute default unit tests if no unit tests are specified
};  
////////////////////////////////////////
/**
 * @brief Raw container for SD_Test checks
 */
class SD_TestChecks : public SD_Class{
public: 
    SD_DECLARE_CLASS_H()

    /**
     * @brief Container typedef for checks
     */
    typedef std::map<std::string, bool> _checks;


    
    /**
     * @brief Inserts a check (inside SD_TestChecks::checks), Throws exc::SD_TestCheckInsertionFailed if unable to insert check
     * Throws exc::SD_TestCheckInsertionFailed if fails
     * 
     * @param check_id Check id
     * @param check_value check value
     * @throw exc::SD_TestCheckInsertionFailed if fails
     */
    virtual void AddCheck(const std::string& check_id, bool check_value = false);
    /**
     * @brief Set the check (inside SD_TestChecks::checks). Thorws exc::SD_TestCheckSetFailed if unable to find check (and therefore set it)
     * Throws exc::SD_TestCheckSetFailed if fails
     * 
     * @param check_id Check id
     * @param check_value check value
     * @throw exc::SD_TestCheckSetFailed if unable to find check
     */
    virtual void SetCheck(const std::string& check_id, bool check_value);
    /**
     * @brief Find and return the check (inside SD_TestChecks::checks). Throws exc::SD_TestCheckNotFound if unable to find check (and therefore return it)
     * Throws exc::SD_TestCheckNotFound if fails
     * 
     * @param check_id Check id
     * @return bool If it's set
     * @throw exc::SD_TestCheckNotFound if fails
     */
    virtual bool GetCheck(const std::string& check_id) const;
    /**
     * @brief Find and erase the check (inside SD_TestChecks::checks). Throws exc::SD_TestCheckErasionFailed if unable to find check (and therefore erase it)
     * Throws exc::SD_TestCheckErasionFailed if fails
     * 
     * @param check_id Check id
     * @throw exc::SD_TestCheckErasionFailed if fails
     */
    virtual void EraseCheck(const std::string& check_id);

    
    /**
     * @brief Returns the main checks container reference (SD_TestChecks::checks)
     * 
     * @return const _checks& 
     */
    inline const _checks& GetChecks() const {
        return checks;
    }
    /**
     * @brief Returns passed checks container reference (SD_TestChecks::passed_checks)
     * 
     * @return const std::set<std::string>& 
     */
    inline const std::set<std::string>& GetPassedChecks() const {
        return passed_checks;
    }
    /**
     * @brief Returns failed checks container reference (SD_TestChecks::failed_checks)
     * 
     * @return const std::set<std::string>& 
     */
    inline const std::set<std::string>& GetFailedChecks() const {
        return failed_checks;
    }
protected:
    
    _checks checks; ///< Container for checks
    std::set<std::string> passed_checks; ///< Container for passed checks
    std::set<std::string> failed_checks; ///< Container for failed checks
};
////////////////////////////////////////

/**
 * @brief SD_Test represents a complete test object
 */
class SD_Test : public SD_Class{
public:
    SD_DECLARE_CLASS_H()

    /**
     * @brief Disallow default (without test_id) constructor
     */
    SD_Test() = delete;
    /**
     * @brief Construct empty test with test_id
     * 
     * @param test_id 
     */
    SD_Test(const std::string& test_id);
    virtual ~SD_Test();

    /**
     * @brief Creates a check (in SD_Test::checks) with a value. 
     * Throws exc::SD_TestCheckInsertionFailed if fails
     * 
     * @param check_id Check id
     * @param check_value Check value
     * @throw exc::SD_TestCheckInsertionFailed if fails
     */
    inline void AddCheck(const std::string& check_id, bool check_value = false) {
        checks->AddCheck(check_id, check_value);
    }
    /**
     * @brief Sets a check (in SD_Test::checks) with a value. 
     * Throws exc::SD_TestCheckSetFailed if fails
     * 
     * @param check_id Check id
     * @param check_value Check value
     * @throw exc::SD_TestCheckSetFailed if fails
     */
    inline void SetCheck(const std::string& check_id, bool check_value) {
        checks->SetCheck(check_id, check_value);
    }
    /**
     * @brief Finds a check (in SD_Test::checks) and returns its value. 
     * Throws exc::SD_TestCheckNotFound if fails
     * 
     * @param check_id Check id
     * @return bool Check value 
     * @throw exc::SD_TestCheckNotFound if fails
     */
    inline bool GetCheck(const std::string& check_id) const {
        return checks->GetCheck(check_id);
    }
    /**
     * @brief Finds and erases a check (in SD_Test::checks). 
     * Throws exc::SD_TestCheckNotFound if fails
     * 
     * @param check_id Check id
     * @throw exc::SD_TestCheckNotFound if fails
     */
    inline void EraseCheck(const std::string& check_id) {
        checks->EraseCheck(check_id);
    }

    inline const std::string& GetId() const {
        return id;
    }
    inline std::unique_ptr<SD_TestChecks>& GetChecks() {
        return checks;        
    }
    inline const std::unique_ptr<SD_TestChecks>& GetChecks() const {
        return checks;
    }
    /**
     * @brief Executes the test. Default SD_Test version of this method is empty, 
     * but it is specialized in the concrete test classes implementations 
     */
    virtual void Execute();
    /**
     * @brief Checks if the test passed. It returns true if there are no failed checks
     */
    inline bool TestPassed() const {
        if (checks) {
            if (checks->GetFailedChecks().size() == 0) {
                return true;
            } else return false;
        } else {
            return false;
        }
    }
protected:
    /**
     * @brief Initializes the SD_Test::checks SD_TestChecks container
     */
    virtual void InitChecks();

    std::unique_ptr<SD_TestChecks> checks; ///< Container for checks
    std::string id; ///< SD_Test string id
};
////////////////////////////////////////

/**
 * @brief SD_UnitTest is specialization of SD_Test - representing unit test.
 */
class SD_UnitTest : public SD_Test {
public:
    SD_DECLARE_CLASS_H()

    /**
     * @brief Create new unit test.
     * 
     * @param id check id
     * @param is_default 
     */
    SD_UnitTest(const std::string& id, bool is_default = true);
    SD_UnitTest() = delete;

    inline bool IsDefault() const {
        return is_default;
    }
protected:
    bool is_default = true;
};
/**
 * @brief SD_RealtimeTest is specialization of SD_Test - representing realtime test
 */
class SD_RealtimeTest : public SD_Test {
public:
    SD_DECLARE_CLASS_H()

    /**
     * @brief Create new realtime test
     * 
     * @param id check id
     */
    SD_RealtimeTest(const std::string& id);
    SD_RealtimeTest() = delete;
};
////////////////////////////////////////

/**
 * @brief SD_TestContainer represents container for SD_UnitTest and SD_RealtimeTest, for the unit and realtime testing
 * 
 */
class SD_TestContainer : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    /**
     * @brief Raw container typedef for SD_UnitTest
     */
    typedef std::map<std::string, std::unique_ptr<SD_UnitTest>> _unit_tests;
    /**
     * @brief Raw container typedef for SD_RealtimeTest
     */
    typedef std::map<std::string, std::unique_ptr<SD_RealtimeTest>> _realtime_tests;


    SD_TestContainer() = default;
    virtual ~SD_TestContainer() = default;

    /**
     * @brief Inserts SD_UnitTest in SD_TestContainer::unit_tests. 
     * Throws exc::SD_TestInsertionFailed if fails
     * 
     * @param test std::moved SD_UnitTest
     * @throw exc::SD_TestInsertionFailed if fails 
     */
    virtual void AddUnitTest(std::unique_ptr<SD_UnitTest>&& test);
    
    /**
     * @brief Finds and returns constant std::unique_ptr reference to SD_UnitTest from SD_TestContainer::unit_tests 
     * Throws exc::SD_TestNotFound if fails
     * 
     * @param test_id string id of a unit test
     * @return const std::unique_ptr<SD_UnitTest>& reference
     * @throw exc::SD_TestNotFound if fails 
     */
    virtual const std::unique_ptr<SD_UnitTest>& GetUnitTest(const std::string& test_id) const;
    
    /**
     * @brief Finds and returns non-constant std::unique_ptr reference to SD_UnitTest from SD_TestContainer::unit_tests
     * Throws exc::SD_TestNotFound if fails
     * 
     * @param test_id string id of a unit test
     * @return std::unique_ptr<SD_UnitTest>& reference
     * @throw exc::SD_TestNotFound if fails
     */
    virtual std::unique_ptr<SD_UnitTest>& GetUnitTest(const std::string& test_id);
    
    /**
     * @brief Finds and erases SD_UnitTest from SD_TestContainer::unit_tests
     * Throws exc::SD_TestErasionFailed
     * 
     * @param test_id string id of a unit test
     * @throw exc::SD_TestErasionFailed if fails
     */
    virtual void EraseUnitTest(const std::string& test_id);    

    /**
     * @brief Returns true if SD_UnitTest from SD_TestContainer::unit_tests with the id exists
     * 
     * @param test_id id of a unit test
     */
    virtual bool UnitTestExists(const std::string& test_id) const;

    /**
     * @brief Inserts SD_RealtimeTest in SD_TestContainer::realtime_tests. 
     * Throws exc::SD_TestInsertionFailed if fails
     * 
     * @param test std::moved SD_RealtimeTest
     * @throw exc::SD_TestInsertionFailed if fails
     */
    virtual void AddRealtimeTest(std::unique_ptr<SD_RealtimeTest>&& test);
    /**
     * @brief Finds and returns constant std::unique_ptr reference to SD_RealtimeTest from SD_TestContainer::realtime_tests. 
     * Throws exc::SD_TestNotFound if fails
     * 
     * @param test_id 
     * @return const std::unique_ptr<SD_RealtimeTest>&
     * @throw exc::SD_TestNotFound if fails 
     */
    virtual const std::unique_ptr<SD_RealtimeTest>& GetRealtimeTest(const std::string& test_id) const;
    /**
     * @brief Finds and returns non-constant std::unique_ptr reference to SD_RealtimeTest from SD_TestContainer::realtime_tests. 
     * Throws exc::SD_TestNotFound if fails
     * 
     * @param test_id 
     * @return std::unique_ptr<SD_RealtimeTest>&
     * @throw exc::SD_TestNotFound if fails 
     */
    virtual std::unique_ptr<SD_RealtimeTest>& GetRealtimeTest(const std::string& test_id);
    /**
     * @brief Finds and erases SD_RealtimeTest from SD_TestContainer::realtime_tests.
     * Throws exc::SD_TestErasionFailed if fails
     * 
     * @param test_id 
     * @throw exc::SD_TestErasionFailed if fails
     */
    virtual void EraseRealtimeTest(const std::string& test_id);
    /**
     * @brief Returns true if SD_RealtimeTest from SD_TestContainer::realtime_tests with the id exists
     * 
     * @param test_id id of a realtime test
     */
    virtual bool RealtimeTestExists(const std::string& test_id) const;

    inline const _unit_tests& GetUnitTests() const {
        return unit_tests;
    }
    inline _unit_tests& GetUnitTests() {
        return unit_tests;
    }
    inline const _realtime_tests& GetRealtimeTests() const {
        return realtime_tests;
    }
    inline _realtime_tests& GetRealtimeTests() {
        return realtime_tests;
    }
    inline const std::set<std::string>& GetDefaultUnitTests() {
        return default_unit_tests;
    }
protected:
    std::set<std::string> default_unit_tests; ///<Container with the default unit test set
    _unit_tests unit_tests; ///< Container for unit tests
    _realtime_tests realtime_tests; ///< Container for realtime tests
};
////////////////////////////////////////
struct SD_VerifyTests : public SD_Class{
    SD_DECLARE_CLASS_H()

    std::vector<std::string> not_found;
    std::vector<std::string> verified;
};
////////////////////////////////////////

/**
 * @brief SD_ApplicationTesting is a class responsible for test execution & management
 */
class SD_ApplicationTesting : public SD_Class {
public:
    SD_DECLARE_CLASS_H()
protected:
    /**
     * @brief Initializes smart memory & initializes the testing engine
     */
    SD_ApplicationTesting();
public:
    /**
     * @brief Returns singleton instance
     * 
     * @return SD_ApplicationTesting& 
     */
    static SD_ApplicationTesting& Instance();

    /**
     * @brief Attempts to insert unit tests to SD_ApplicationTesting::tests_container. If SD_ApplicationTesting::tests_container is uninitialized, it throws exc::SD_NullPtrException, if insertion in SD_ApplicationTesting::tests_container fails, it throws exc::SD_TestInsertionFailed exception
     * 
     * @param rvalue (std::moved) memory of a test
     * @throw exc::SD_NullPtrException + (optionally) exc::SD_TestInsertionFailed (nested exception) if SD_ApplicationTesting::tests_container is unitialized
     * @throw exc::SD_TestInsertionFailed if insertion in SD_TestContainer fails
     */
    virtual void AddUnitTest(std::unique_ptr<SD_UnitTest>&& test);
    /**
     * @brief Attempts to access unit test in SD_ApplicationTesting::tests_container. If SD_ApplicationTesting::tests_container is uninitialized, it throws exc::SD_NullPtrException, if access in SD_ApplicationTesting::tests_container fails, it throws exc::SD_TestNotFound
     * 
     * @param test_id test id (name)
     * @return const std::unique_ptr<SD_UnitTest>& reference to unit test
     * @throw exc::SD_NullPtrException + exc::SD_TestNotFound (nested exception) if SD_ApplicationTesting::tests_container is uninitialized
     * @throw exc::SD_TestNotFound if access in SD_TestContainer fails 
     */
    virtual const std::unique_ptr<SD_UnitTest>& GetUnitTest(const std::string& test_id) const;
    /**
     * @brief Attempts to access unit test in SD_ApplicationTesting::tests_container. If SD_ApplicationTesting::tests_container is uninitialized, it throws exc::SD_NullPtrException, if access in SD_ApplicationTesting::tests_container fails, it throws exc::SD_TestNotFound
     * 
     * @param test_id test id (name)
     * @return std::unique_ptr<SD_UnitTest>& reference to unit test
     * @throw exc::SD_NullPtrException + exc::SD_TestNotFound (nested exception) if SD_ApplicationTesting::tests_container is uninitialized
     * @throw exc::SD_TestNotFound if access in SD_TestContainer fails 
     */
    virtual std::unique_ptr<SD_UnitTest>& GetUnitTest(const std::string& test_id);
    /**
     * @brief Attempts to erase unit test in SD_ApplicationTesting::tests_container. If SD_ApplicationTesting::tests_container is uninitialized, it throws exc::SD_NullPtrException, if erasion in SD_ApplicationTesting::tests_container fails, it throws exc::SD_TestErasionFailed
     * 
     * @param test_id test id (name)
     * @throw exc::SD_NullPtrException + exc::SD_TestNotFound (nested exception) if SD_ApplicationTesting::tests_container is uninitialized
     * @throw exc::SD_TestNotFound if erasion in SD_TestContainer fails
     */
    virtual void EraseUnitTest(const std::string& test_id);    
    
    /**
     * @brief Attempts to insert realtime tests to SD_ApplicationTesting::tests_container. If SD_ApplicationTesting::tests_container is uninitialized, it throws exc::SD_NullPtrException, if insertion in SD_ApplicationTesting::tests_container fails, it throws exc::SD_TestInsertionFailed exception
     * 
     * @param rvalue (std::moved) memory of a test
     * @throw exc::SD_NullPtrException + (optionally) exc::SD_TestInsertionFailed (nested exception) if SD_ApplicationTesting::tests_container is unitialized
     * @throw exc::SD_TestInsertionFailed if insertion in SD_TestContainer fails
     */
    virtual void AddRealtimeTest(std::unique_ptr<SD_RealtimeTest>&& test);
    /**
     * @brief Attempts to access realtime test in SD_ApplicationTesting::tests_container. If SD_ApplicationTesting::tests_container is uninitialized, it throws exc::SD_NullPtrException, if access in SD_ApplicationTesting::tests_container fails, it throws exc::SD_TestNotFound
     * 
     * @param test_id test id (name)
     * @return const std::unique_ptr<SD_RealtimeTest>& reference to realtime test
     * @throw exc::SD_NullPtrException + exc::SD_TestNotFound (nested exception) if SD_ApplicationTesting::tests_container is uninitialized
     * @throw exc::SD_TestNotFound if access in SD_TestContainer fails 
     */
    virtual const std::unique_ptr<SD_RealtimeTest>& GetRealtimeTest(const std::string& test_id) const;
    /**
     * @brief Attempts to access realtime test in SD_ApplicationTesting::tests_container. If SD_ApplicationTesting::tests_container is uninitialized, it throws exc::SD_NullPtrException, if access in SD_ApplicationTesting::tests_container fails, it throws exc::SD_TestNotFound
     * 
     * @param test_id test id (name)
     * @return std::unique_ptr<SD_RealtimeTest>& reference to realtime test
     * @throw exc::SD_NullPtrException + exc::SD_TestNotFound (nested exception) if SD_ApplicationTesting::tests_container is uninitialized
     * @throw exc::SD_TestNotFound if access in SD_TestContainer fails 
     */
    virtual std::unique_ptr<SD_RealtimeTest>& GetRealtimeTest(const std::string& test_id);
    /**
     * @brief Attempts to erase realtime test in SD_ApplicationTesting::tests_container. If SD_ApplicationTesting::tests_container is uninitialized, it throws exc::SD_NullPtrException, if erasion in SD_ApplicationTesting::tests_container fails, it throws exc::SD_TestErasionFailed
     * 
     * @param test_id test id (name)
     * @throw exc::SD_NullPtrException + exc::SD_TestNotFound (nested exception) if SD_ApplicationTesting::tests_container is uninitialized
     * @throw exc::SD_TestNotFound if erasion in SD_TestContainer fails
     */
    virtual void EraseRealtimeTest(const std::string& test_id);

    inline std::unique_ptr<SD_TestContainer>& GetTestContainer() {
        return tests_container;
    }
    inline const std::unique_ptr<SD_TestContainer>& GetTestContainer() const {
        return tests_container;
    }

    /**
     * @brief Creates a list of pointers to the SD_Test s, using the list of ids and a test type 
     * 
     * @param tests_type Tests Type
     * @param list List of tests ids
     * @return std::map<std::string, SD_Test*>  
     */
    virtual std::map<std::string, SD_Test*> GenerateTestList(
        const std::string& tests_type, 
        const std::vector<std::string>& list);

    /**
     * @brief Call this method after SD_ApplicationTesting init, to execute tests with "nice" output
     * 
     * @param which_to_execute Which tests to execute
     */
    virtual void ExecuteTestsWithNiceOutput(
        const SD_TestSpecify& which_to_execute);

    /**
     * @brief Creates a list of unit tests (SD_VerifyTests) with the default flag set to true 
     * 
     * @return SD_VerifyTests 
     */
    virtual SD_VerifyTests GetDefaultUnitTestsList();
protected:

    /**
     * @brief Directly execute tests
     * 
     * @param list 
     */
    virtual void ExecuteTests(const std::map<std::string, SD_Test*>& list);

    /**
     * @brief Send an information of which tests are in the tests container
     * 
     * @param test_type Test type (unit, realtime, etc)
     * @param list list of tests string ids
     * @return SD_VerifyTests Which tests are in the tests container
     */
    virtual SD_VerifyTests VerifyIfNamesAreInTheTestsContainer(const std::string& test_type, const std::set<std::string>& list);

    /**
     * @brief Outputs in a nice way information about test execution start
     * 
     * @param test_type test type (category)
     * @param amount amount of the tests (of that type)
     */
    virtual void OutputExecutionStartInformation(const std::string& test_type, int amount);
    /**
     * @brief Outputs in a nice way the result of the test execution
     * 
     * @param test const reference to SD_Test
     */
    virtual void OutputExecutedTestInformation(const SD_Test& test) const;
    /**
     * @brief Output the nice information that we are unable to find tests (specified in vector of strings, representing the test ids)
     * 
     * @param not_found vector of test ids (names)
     */
    virtual void OutputNotFoundTests(const std::vector<std::string>& not_found);

    /**
     * @brief Initializes SD_ApplicationTesting::tests_container
     */
    virtual void InitTestContainer();

    std::unique_ptr<SD_TestContainer> tests_container; ///< Container for the tests
    

    //SD_Application& application; ///< Don't reference the SD_Application to testing frame. Reason? Manage SD_Application (if it's necessary - directly in SD_Test execution method code) 
};
////////////////////////////////////////
///Unimplemented
//class SD_DefaultTestList {
//public:
//    virtual void AddTests();
//};
////////////////////////////////////////
// More specific implementation below
/**
 * @brief This class is used only as an inserted for tests. It inserts tests directly via static singleton reference to SD_ApplicationTesting
 * 
 */
class SD_TestInserter : public SD_Class{
public:
    SD_DECLARE_CLASS_H()

    SD_TestInserter() = delete;
    /**
     * @brief Get singleton reference to SD_ApplicationTesting and emplace the unit test
     * 
     * @param unit_test rvalue (std::moved()) test
     * @throw exc::SD_NullPtrException + (optionally) exc::SD_TestInsertionFailed (nested exception) if SD_ApplicationTesting::tests_container is unitialized
     * @throw exc::SD_TestInsertionFailed if insertion in SD_TestContainer fails
     */
    SD_TestInserter(std::unique_ptr<SD_UnitTest>&& unit_test);
    /**
     * @brief Get singleton reference to SD_ApplicationTesting and emplace the realtime test
     * 
     * @param realtime_test rvalue (std::moved()) test
     * @throw exc::SD_NullPtrException + (optionally) exc::SD_TestInsertionFailed (nested exception) if SD_ApplicationTesting::tests_container is unitialized
     * @throw exc::SD_TestInsertionFailed if insertion in SD_TestContainer fails
     */
    SD_TestInserter(std::unique_ptr<SD_RealtimeTest>&& realtime_test);
};
////////////////////////////////////////

/**
 * @brief Deduces the exception type (the most inner level) of a std nested (or standard) exception
 * 
 * @param e nested (or standard std::exception const) exception const reference
 * @return std::string name of the exception (if it's exc::SD_Exception, if not, returns typeid(e).name())
 */
std::string SD_DeduceNestedExceptionType (
    const std::exception& e
);

/**
 * Macros related to implementation 
 */
#define SD_DEFINE_TEST_H1(test_name, SD_Test_, SD_Test) \
class SD_Test_##test_name : public SD_Test {\
public:\
SD_Test_##test_name(const std::string& test_id) : SD_Test(test_id) {} \
virtual void Execute() override { \
    try {


#define SD_DEFINE_TEST_END_H1(test_name) \
        } catch (...) {     \
            auto e = exc::SD_TestExecutionFailed(this->GetId());     \
            std::throw_with_nested(e);  \
        }   \
    }\
};

#define SD_INSERT_TEST_H1(test_name, test_inserter, SD_Test_) \
static SD_TestInserter test_inserter##test_name = SD_TestInserter( \
    std::make_unique<SD_Test_##test_name>(#test_name) \
);

#define SD_CHECK_TRUE_H1(check_id, value) \
    AddCheck(check_id, value);

#define SD_CHECK_FALSE_H1(check_id, value) \
    AddCheck(check_id, !(value));

#define SD_CHECK_SET_TRUE_H1(check_id, value) \
    SetCheck(check_id, value);

#define SD_CHECK_SET_FALSE_H1(check_id, value) \
    SetCheck(check_id, !(value));

#define SD_CHECK_THROW_H(check_id, exception, code) \
    { \
        bool caught_that_specific_exception = false;\
        try { \
            code \
        } catch (const exception& e) { \
            caught_that_specific_exception = true;\
        } catch (...) { \
            caught_that_specific_exception = false; \
        }\
    if (caught_that_specific_exception) { \
        SD_CHECK_TRUE(check_id, true); \
    } \
    else { \
        SD_CHECK_TRUE(check_id, false); \
    } \
    \
    }

#define SD_CHECK_NOTHROW_H(check_id, exception, code) \
    { \
        bool caught_that_specific_exception = false;\
        try { \
            code \
        } catch (const exception& e) { \
            caught_that_specific_exception = true;\
        } catch (...) { \
            caught_that_specific_exception = false; \
        }\
    if (caught_that_specific_exception) {\
        SD_CHECK_TRUE(check_id, false); \
    } \
    else {\
        SD_CHECK_TRUE(check_id, true); \
    }\
    \
    }

#define SD_CHECK_NESTED_FINAL_THROW_H(check_id, exception2, code) \
    { \
        bool caught_that_specific_exception = false;\
        try { \
            code \
        } catch (const std::exception& e) { \
            std::string name = SD_DeduceNestedExceptionType(e); \
            exception2 tmp; \
            if (name.compare(tmp.GetName()) == 0) { \
                caught_that_specific_exception = true; \
            } else caught_that_specific_exception = false; \
        } catch (...) { \
            caught_that_specific_exception = false; \
        }   \
        if (caught_that_specific_exception) { \
            SD_CHECK_TRUE(check_id, true); \
        } \
        else {\
            SD_CHECK_TRUE(check_id, false); \
        }\
    }

#define SD_CHECK_NESTED_FINAL_NOTHROW_H(check_id, exception2, code) \
    { \
        bool caught_that_specific_exception = false;\
        try { \
            code \
        } catch (const std::exception& e) { \
            std::string name = SD_DeduceNestedExceptionType(e); \
            exception2 tmp; \
            if (name.compare(tmp.GetName()) == 0) { \
                caught_that_specific_exception = true; \
            } else caught_that_specific_exception = false; \
        } catch (...) { \
            caught_that_specific_exception = false; \
        }   \
        if (caught_that_specific_exception) { \
            SD_CHECK_TRUE(check_id, false); \
        } \
        else {\
            SD_CHECK_TRUE(check_id, true); \
        }\
    }

/**
 * Macros related to implementation END 
 */

// Use these macros only in .cpp files




/**
 * @brief Define the unit test, and its name (test_name) BEGIN
 * @param test_name Test name
 */
#define SD_DEFINE_UNIT_TEST(test_name) SD_DEFINE_TEST_H1(test_name, SD_UnitTest_, SD_UnitTest)
/**
 * @brief Define the unit test END
 */
#define SD_DEFINE_UNIT_TEST_END() SD_DEFINE_TEST_END_H1()
/**
 * @brief Define the realtime test, and its name (test_name) BEGIN
 * @param test_name Test name
 */
#define SD_DEFINE_REALTIME_TEST(test_name) SD_DEFINE_TEST_H1(test_name, SD_RealtimeTest_, SD_RealtimeTest)
/**
 * @brief Define the realtime test END
 */
#define SD_DEFINE_REALTIME_TEST_END() SD_DEFINE_TEST_END_H1()

/**
 * @brief Inserts the unit test with the name. 
 * @param test_name
 */
#define SD_INSERT_UNIT_TEST(test_name) SD_INSERT_TEST_H1(test_name, test_inserter_, SD_UnitTest_)
/**
 * @brief Inserts the realtime test with the name. 
 * @param test_name
 */
#define SD_INSERT_REALTIME_TEST(test_name) SD_INSERT_TEST_H1(test_name, test_inserter_, SD_RealtimeTest_)

/**
 * @brief Asserts if the expression returns true
 */
#define SD_CHECK_TRUE(check_id, value) SD_CHECK_TRUE_H1(check_id, value)
/**
 * @brief Asserts if the expression returns false
 */
#define SD_CHECK_FALSE(check_id, value) SD_CHECK_FALSE_H1(check_id, value)

#define SD_CHECK_SET_TRUE(check_id, value) SD_CHECK_SET_TRUE_H1(check_id, value)
#define SD_CHECK_SET_FALSE(check_id, value) SD_CHECK_SET_FALSE_H1(check_id, value)

/**
 * @brief Expects an exception, if it's catched, asserts true
 */
#define SD_CHECK_THROW(check_id, exc, code) SD_CHECK_THROW_H(check_id, exc, code)
/**
 * @brief Expects an exception. If it's not catched, asserts true 
 */
#define SD_CHECK_NOTHROW(check_id, exc, code) SD_CHECK_NOTHROW_H(check_id, exc, code)
/**
 * @brief Expects nested std::nested_exception or exception. If the final level (the most specific) is the specified type, asserts true
 */
#define SD_CHECK_NESTED_FINAL_THROW(check_id, exc, code) SD_CHECK_NESTED_FINAL_THROW_H(check_id, exc, code)
/**
 * @brief Expects nested std::nested_exception or exception. If the final level (the most specific) isn't the specified type, asserts true
 */
#define SD_CHECK_NESTED_FINAL_NOTHROW(check_id, exc, code) SD_CHECK_NESTED_FINAL_NOTHROW_H(check_id, exc, code)

////////////////////////////////////////

#endif
