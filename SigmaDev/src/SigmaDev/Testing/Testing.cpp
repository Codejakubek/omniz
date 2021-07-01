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
// File: /impl/src/SigmaDev/Testing.cpp
// Description:
//
// Additional Notes:
//
////////////////////////////////////////

#include <SigmaDev/Testing/Testing.h>
#include <SigmaDev/Misc/Colors.h>
#include <set>

SD_DECLARE_CLASS_CPP(SD_VerifyTests)
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_TestSpecify)
SD_TestSpecify::SD_TestSpecify() {}

SD_TestSpecify::SD_TestSpecify(std::initializer_list<std::pair<std::string, std::string>> list_of_tests) {
    for (auto & el : list_of_tests) {
        const std::string& type = el.first;
        const std::string& id = el.second;
    
        auto it = specify.find(type);
        if (it != specify.end()) {
            auto insert_pair = it->second.insert(id);
            if (insert_pair.second == false) {
                //Ok
            }
        } else {
            auto insert_pair = specify.insert(std::make_pair(
                type,
                std::set<std::string>({id})
            ));
        }
    }
}
void SD_TestSpecify::AddTest(const std::string& type, const std::string& test_id) { 
    auto it = specify.find(type);
    if (it != specify.end()) {
        auto insert_pair = it->second.insert(test_id);
        if (insert_pair.second == false) {
            //Ok
        }
    } else {
        specify.insert(std::make_pair(
            type,
            std::set<std::string>({test_id})
        ));
    }
}
void SD_TestSpecify::EraseTest(const std::string& type, const std::string& test_id) {
    auto it = specify.find(type);
    if (it != specify.end()) {
        auto it2 = it->second.find(test_id);
        if (it2 != it->second.end()) {
            it->second.erase(it2);
        } else {

        }
    } else {
        
    }
}
bool SD_TestSpecify::TestExists(const std::string& type, const std::string& test_id) const {
    auto it = specify.find(type);
    if (it != specify.end()) {
        auto it2 = it->second.find(test_id);
        if (it2 != it->second.end()) {
            return true;
        } else return false;
    } else {
        return false;
    }
}
bool SD_TestSpecify::HasAtLeastOneTestOfType(const std::string& type) const {
    auto it = specify.find(type);
    if (it != specify.end()) {
        return (it->second.empty() == false);
    } else {
        return false;
    }
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_TestChecks)
void SD_TestChecks::AddCheck(const std::string& check_id, bool check_value) {
    auto insert_pair = checks.insert(std::make_pair(check_id, check_value));
    if (insert_pair.second == false) {
        auto e = exc::SD_TestCheckInsertionFailed(check_id);
        e.GetVariablesMap().insert(std::make_pair("check_id", check_id));
        throw e;
    } else {
        if (check_value) {
            passed_checks.insert(check_id);
        } else {
            failed_checks.insert(check_id);
        }
    }
}
void SD_TestChecks::SetCheck(const std::string& check_id, bool check_value) {
    auto it = checks.find(check_id);
    if (it != checks.end()) {
        it->second = check_value;
    } else {
        auto e = exc::SD_TestCheckSetFailed(check_id);
        e.GetVariablesMap().insert(std::make_pair("check_id", check_id));
        throw e;  
    } 
}
bool SD_TestChecks::GetCheck(const std::string& check_id) const {
    auto it = checks.find(check_id);
    if (it != checks.end()) {
        return it->second;
    } else {
        auto e = exc::SD_TestCheckNotFound(check_id);
        e.GetVariablesMap().insert(std::make_pair("check_id", check_id));
        throw e;
    }
}
void SD_TestChecks::EraseCheck(const std::string& check_id) {
    auto it = checks.find(check_id);
    if (it != checks.end()) {
        checks.erase(it);
    } else {
        auto e = exc::SD_TestCheckErasionFailed(check_id);
        e.GetVariablesMap().insert(std::make_pair("check_id", check_id));
        throw e;
    }
}
////////////////////////////////////////

SD_DECLARE_CLASS_CPP(SD_UnitTest)
SD_UnitTest::SD_UnitTest(const std::string& id, bool is_default) : SD_Test(id), is_default(is_default) {

}
SD_DECLARE_CLASS_CPP(SD_RealtimeTest)
SD_RealtimeTest::SD_RealtimeTest(const std::string& id) : SD_Test(id) {

}
SD_DECLARE_CLASS_CPP(SD_TestContainer)
void SD_TestContainer::AddUnitTest(std::unique_ptr<SD_UnitTest>&& test) {
    if (test) {
        bool is_default = test->IsDefault();
        const std::string& test_id = test->GetId();
        auto insert_pair = unit_tests.insert(std::make_pair(test_id, std::move(test)));
        if (insert_pair.second == false) {
            auto e = exc::SD_TestInsertionFailed(test->GetId());
            e.GetVariablesMap().insert(std::make_pair("test_id", test->GetId()));
            throw e;
        }
        if (is_default) {
            default_unit_tests.insert(test_id);
        }
    } else {
        auto e = exc::SD_TestInsertionFailed(test->GetId());
        throw e;
    }
}
const std::unique_ptr<SD_UnitTest>& SD_TestContainer::GetUnitTest(const std::string& id) const {
    auto it = unit_tests.find(id);
    if (it != unit_tests.end()) {
        return it->second;
    } else {
        auto e = exc::SD_TestNotFound(id);
        e.GetVariablesMap().insert(std::make_pair("test_id", id));
        throw e;
    }
}
std::unique_ptr<SD_UnitTest>& SD_TestContainer::GetUnitTest(const std::string& id) {
    auto it = unit_tests.find(id);
    if (it != unit_tests.end()) {
        return it->second;
    } else {
        auto e = exc::SD_TestNotFound(id);
        e.GetVariablesMap().insert(std::make_pair("test_id", id));
        throw e;
    }
}
void SD_TestContainer::EraseUnitTest(const std::string& id) {
    auto it = unit_tests.find(id);
    if (it != unit_tests.end()) {
        unit_tests.erase(it);
    } else {
        auto e = exc::SD_TestErasionFailed(id);
        e.GetVariablesMap().insert(std::make_pair("test_id", id));
        throw e;
    }
}
bool SD_TestContainer::UnitTestExists(const std::string& id) const {
    auto it = unit_tests.find(id);
    if (it != unit_tests.end()) {
        return true;
    } else return false;
}
void SD_TestContainer::AddRealtimeTest(std::unique_ptr<SD_RealtimeTest>&& test) {
    if (test) {
        auto insert_pair = realtime_tests.insert(std::make_pair(test->GetId(), std::move(test)));
        if (insert_pair.second == false) {
            auto e = exc::SD_TestInsertionFailed(test->GetId());
            e.GetVariablesMap().insert(std::make_pair("test_id", test->GetId()));
            throw e;
        }
    } else {
        auto e = exc::SD_TestInsertionFailed(test->GetId());
        throw e;
    }
}
const std::unique_ptr<SD_RealtimeTest>& SD_TestContainer::GetRealtimeTest(const std::string& id) const {
    auto it = realtime_tests.find(id);
    if (it != realtime_tests.end()) {
        return it->second;
    } else {
        auto e = exc::SD_TestNotFound(id);
        e.GetVariablesMap().insert(std::make_pair("test_id", id));
        throw e;
    }
}
std::unique_ptr<SD_RealtimeTest>& SD_TestContainer::GetRealtimeTest(const std::string& id) {
    auto it = realtime_tests.find(id);
    if (it != realtime_tests.end()) {
        return it->second;
    } else {
        auto e = exc::SD_TestNotFound(id);
        e.GetVariablesMap().insert(std::make_pair("test_id", id));
        throw e;
    }
}
void SD_TestContainer::EraseRealtimeTest(const std::string& id) {
    auto it = realtime_tests.find(id);
    if (it != realtime_tests.end()) {
        realtime_tests.erase(it);
    } else {
        auto e = exc::SD_TestCheckErasionFailed(id);
        e.GetVariablesMap().insert(std::make_pair("test_id", id));
        throw e;
    }
}
bool SD_TestContainer::RealtimeTestExists(const std::string& id) const {
    auto it = realtime_tests.find(id);
    if (it != realtime_tests.end()) {
        return true;
    } else return false;
}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_Test) 
SD_Test::SD_Test(const std::string& id) : id(id) {
    InitChecks();
}
SD_Test::~SD_Test() {

}
void SD_Test::InitChecks() {
    checks = std::make_unique<SD_TestChecks>();
}
void SD_Test::Execute() {

}
////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_ApplicationTesting) 
SD_ApplicationTesting::SD_ApplicationTesting() {
    InitTestContainer();
}

SD_ApplicationTesting& SD_ApplicationTesting::Instance() {
    static SD_ApplicationTesting i;
    return i;
}



void SD_ApplicationTesting::AddUnitTest(std::unique_ptr<SD_UnitTest>&& test) {
    if (tests_container) {
        tests_container->AddUnitTest(std::move(test));
    } else {
        try {
            throw exc::SD_NullPtrException("tests_container in SD_ApplicationTesting is uninitialized");
        } catch (...) {
            if (test) {
                auto e = exc::SD_TestInsertionFailed(test->GetId());
                e.GetVariablesMap().insert(std::make_pair("test_id", test->GetId()));
                e.GetVariablesMap().insert(std::make_pair("unit_type", "Unit"));
                std::throw_with_nested(e);
            }
        }
    }
}
const std::unique_ptr<SD_UnitTest>& SD_ApplicationTesting::GetUnitTest(const std::string& id) const {
    if (tests_container) {
        return tests_container->GetUnitTest(id);       
    } else {
        try {
            throw exc::SD_NullPtrException("tests_container in SD_ApplicationTesting is uninitialized");
        } catch (...) {
            auto e = exc::SD_TestNotFound(id);
            e.GetVariablesMap().insert(std::make_pair("test_id", id));
            e.GetVariablesMap().insert(std::make_pair("unit_type", "Unit"));
            std::throw_with_nested(e);
        }
    }
}
std::unique_ptr<SD_UnitTest>& SD_ApplicationTesting::GetUnitTest(const std::string& id) {
    if (tests_container) {
        return tests_container->GetUnitTest(id);       
    } else {
        try {
            throw exc::SD_NullPtrException("tests_container in SD_ApplicationTesting is uninitialized");
        } catch (...) {
            auto e = exc::SD_TestNotFound(id);
            e.GetVariablesMap().insert(std::make_pair("test_id", id));
            e.GetVariablesMap().insert(std::make_pair("unit_type", "Unit"));
            std::throw_with_nested(e);
        }
    }
}
void SD_ApplicationTesting::EraseUnitTest(const std::string& id) {
    if (tests_container) {
        tests_container->EraseUnitTest(id);
    } else {
        try {
            throw exc::SD_NullPtrException("tests_container in SD_ApplicationTesting is uninitialized");
        } catch (...) {
            auto e = exc::SD_TestErasionFailed(id);
            e.GetVariablesMap().insert(std::make_pair("test_id", id));
            e.GetVariablesMap().insert(std::make_pair("unit_type", "Unit"));
            std::throw_with_nested(e);
        }
    }   
}
void SD_ApplicationTesting::AddRealtimeTest(std::unique_ptr<SD_RealtimeTest>&& test) {
    if (tests_container) {
        tests_container->AddRealtimeTest(std::move(test));
    } else {
        try {
            throw exc::SD_NullPtrException("tests_container in SD_ApplicationTesting is uninitialized");
        } catch (...) {
            if (test) {
                auto e = exc::SD_TestInsertionFailed(test->GetId());
                e.GetVariablesMap().insert(std::make_pair("test_id", test->GetId()));
                e.GetVariablesMap().insert(std::make_pair("unit_type", "Realtime"));
                std::throw_with_nested(e);
            }
        }
    }
}
const std::unique_ptr<SD_RealtimeTest>& SD_ApplicationTesting::GetRealtimeTest(const std::string& id) const {
    if (tests_container) {
        return tests_container->GetRealtimeTest(id);
    } else {
        try {
            throw exc::SD_NullPtrException("tests_container in SD_ApplicationTesting is uninitialized");
        } catch (...) {
            auto e = exc::SD_TestNotFound(id);
            e.GetVariablesMap().insert(std::make_pair("test_id", id));
            e.GetVariablesMap().insert(std::make_pair("unit_type", "Realtime"));
            std::throw_with_nested(e);
        }
    }
}
std::unique_ptr<SD_RealtimeTest>& SD_ApplicationTesting::GetRealtimeTest(const std::string& id) {
    if (tests_container) {
        return tests_container->GetRealtimeTest(id);
    } else {
        try {
            throw exc::SD_NullPtrException("tests_container in SD_ApplicationTesting is uninitialized");
        } catch (...) {
            auto e = exc::SD_TestNotFound(id);
            e.GetVariablesMap().insert(std::make_pair("test_id", id));
            e.GetVariablesMap().insert(std::make_pair("unit_type", "Realtime"));
            std::throw_with_nested(e);
        }
    }
}
void SD_ApplicationTesting::EraseRealtimeTest(const std::string& id) {
    if (tests_container) {
        tests_container->EraseRealtimeTest(id);
    } else {
        try {
            throw exc::SD_NullPtrException("tests_container in SD_ApplicationTesting is uninitialized");
        } catch (...) {
            auto e = exc::SD_TestErasionFailed(id);
            e.GetVariablesMap().insert(std::make_pair("test_id", id));
            e.GetVariablesMap().insert(std::make_pair("unit_type", "Realtime"));
            std::throw_with_nested(e);
        }
    }
}
std::map<std::string, SD_Test*> SD_ApplicationTesting::GenerateTestList(
    const std::string& tests_type,
    const std::vector<std::string>& list
) {
    std::map<std::string, SD_Test*> r;
    if (tests_type.compare("unit") == 0) {
        for (const auto& id : list) {
            SD_Test* ptr = GetUnitTest(id).get();
            r.insert(std::make_pair(id, ptr));
        }
    } else if (tests_type.compare("realtime") == 0) {
        for (const auto& id : list) {
            SD_Test* ptr = GetRealtimeTest(id).get();
            r.insert(std::make_pair(id, ptr));
        }
    } else {
        return std::map<std::string, SD_Test*>();
    }
    return r;
}
void SD_ApplicationTesting::ExecuteTestsWithNiceOutput(const SD_TestSpecify& which_to_execute) {
    auto& c = tests_container->GetUnitTests();
    

    bool execute_realtime = which_to_execute.AreThereAnyTestsOfType("realtime");
    bool execute_unit = which_to_execute.HasAtLeastOneTestOfType("unit");

    if (execute_unit || which_to_execute.ExecuteDefaultUnitTestsIfNotSpecified()) {
        SD_VerifyTests verify_tests;
        if (which_to_execute.IsThereSpecifiedTypeOf("unit")) {
            const std::set<std::string>& specified = which_to_execute.WhatAreSpecifiedTestsOfType("unit");
            
            if (specified.empty()) {
                verify_tests = GetDefaultUnitTestsList();
            } else { 
                verify_tests = VerifyIfNamesAreInTheTestsContainer("unit", specified);
            }
        } else {
            verify_tests = GetDefaultUnitTestsList();
        }
        

        if (verify_tests.not_found.empty() == false) {
            OutputNotFoundTests(verify_tests.not_found);
        }

        OutputExecutionStartInformation(
            "Unit", verify_tests.verified.size()
        );    
        auto generated_tests_list = GenerateTestList("unit", verify_tests.verified);
        ExecuteTests(generated_tests_list);
    }
    if (execute_realtime) {

        SD_VerifyTests verify_tests;
        if (which_to_execute.IsThereSpecifiedTypeOf("realtime")) {
            const std::set<std::string>& specified = which_to_execute.WhatAreSpecifiedTestsOfType("realtime");

            verify_tests = VerifyIfNamesAreInTheTestsContainer("realtime", specified);
        
            if (verify_tests.not_found.empty() == false) {
                OutputNotFoundTests(verify_tests.not_found);
            }
            OutputExecutionStartInformation(
                "Realtime", verify_tests.verified.size()
            );
            auto generated_tests_list = GenerateTestList("realtime", verify_tests.verified);
            ExecuteTests(generated_tests_list);
        }
    }
}
SD_VerifyTests SD_ApplicationTesting::GetDefaultUnitTestsList() {
    SD_VerifyTests r;
    auto& unit_tests = tests_container->GetUnitTests();
    for (auto & test : unit_tests) {
        bool is_default = test.second->IsDefault();
        if (is_default) {
            r.verified.emplace_back(test.first);
        }
    }
    return r;
}
void SD_ApplicationTesting::ExecuteTests(const std::map<std::string, SD_Test*>& list) {
    std::set<std::string> tests_passed_list;
    std::set<std::string> tests_failed_list;
    int tests_amount = list.size();

    for (const auto & test : list) {
        std::cout << "Executing " << test.first << " test\n";

        SD_Test* t = test.second;

        if (t != nullptr) {
            t->Execute();
            if (t->TestPassed()) {
                tests_passed_list.insert(test.first);
            } else {
                tests_failed_list.insert(test.first);
            }
            OutputExecutedTestInformation(*t);
        } else {
             auto e = exc::SD_UninitializedException(
                std::string()+
                "SD_Test* uninitialized inside SD_ApplicationTesting::ExecuteTest (test_id = " 
                + test.first+")");
            throw e;
        }
    }
    int tests_passed_amount = tests_passed_list.size();
    int tests_failed_amount = tests_failed_list.size();

    //Check results
     if (tests_failed_amount == 0) {
        std::cout << SD_LINUX_TERMINAL_COLOR_CYAN << 
        "\nAll (" << SD_LINUX_TERMINAL_COLOR_BOLDCYAN << 
        tests_passed_amount << SD_LINUX_TERMINAL_COLOR_CYAN << ") tests " <<
        SD_LINUX_TERMINAL_COLOR_BOLDGREEN << " PASSED!" <<
        SD_LINUX_TERMINAL_COLOR_RESET << "\n";
    } else if (tests_passed_amount == 0) {
        std::cout << SD_LINUX_TERMINAL_COLOR_CYAN <<
        "\nAll " << SD_LINUX_TERMINAL_COLOR_BOLDCYAN << tests_failed_amount <<
        SD_LINUX_TERMINAL_COLOR_CYAN << ")" <<
        "tests" << SD_LINUX_TERMINAL_COLOR_BOLDRED <<" FAILED!" <<
        SD_LINUX_TERMINAL_COLOR_RESET << "\n"; 
    } else {
        std::cout << SD_LINUX_TERMINAL_COLOR_CYAN <<
        "\nSome of the tests (" << SD_LINUX_TERMINAL_COLOR_BOLDCYAN <<
        tests_failed_amount << " out of " << tests_amount << SD_LINUX_TERMINAL_COLOR_CYAN << 
        ")" << SD_LINUX_TERMINAL_COLOR_BOLDRED <<
        " hasn't passed" << SD_LINUX_TERMINAL_COLOR_RESET << "\n";
    }
}

SD_VerifyTests SD_ApplicationTesting::VerifyIfNamesAreInTheTestsContainer (const std::string& test_type, const std::set<std::string>& list)
{
    SD_VerifyTests verify_tests;
    std::vector<std::string>& verified = verify_tests.verified;
    std::vector<std::string>& denied = verify_tests.not_found;
    if (test_type.compare("unit") == 0) {
        for (const auto& el : list) {
            bool exists = tests_container->UnitTestExists(el);
            if (exists) {
                verified.emplace_back(el);
            } else {
                denied.emplace_back(el);
            }
        }
    } else if (test_type.compare("realtime") == 0) {
        for (const auto& el : list) {
            bool exists = tests_container->RealtimeTestExists(el);
            if (exists) {
                verified.emplace_back(el);
            } else {
                denied.emplace_back(el);
            }
        }
    }
    return verify_tests;
}

void SD_ApplicationTesting::OutputExecutionStartInformation(const std::string& test_type, int amount) {
    std::cout << SD_LINUX_TERMINAL_COLOR_CYAN <<
    "\nWe're now going to execute " << 
    SD_LINUX_TERMINAL_COLOR_BOLDCYAN << amount <<
    SD_LINUX_TERMINAL_COLOR_CYAN <<
    " " << test_type << " tests from SigmaDev Testing Frame." << 
    SD_LINUX_TERMINAL_COLOR_RESET << " \n\n";
}
void SD_ApplicationTesting::OutputExecutedTestInformation(const SD_Test& test) const {
    const std::unique_ptr<SD_TestChecks>& sd_test_checks = test.GetChecks();
    const std::map<std::string, bool>& checks = sd_test_checks->GetChecks();
    const std::set<std::string>& checks_succeeded = sd_test_checks->GetPassedChecks();
    const std::set<std::string>& checks_failed = sd_test_checks->GetFailedChecks();

    int checks_succeeded_amount = checks_succeeded.size();
    int checks_failed_amount = checks_failed.size();
    int checks_amount = checks_succeeded_amount + checks_failed_amount;

    if (checks_failed_amount == 0) {
        std::cout << SD_LINUX_TERMINAL_COLOR_GREEN 
        << "    Test PASSED "<< SD_LINUX_TERMINAL_COLOR_RESET  
        <<"- no failed checks, total succeeded checks = (" << checks_succeeded_amount << ")\n";
    } else {
        std::string failed_checks_list_string;
        for (auto it = checks_failed.begin();
             it != checks_failed.end();
             ++it) {
            const std::string& c = *it;
            auto it2 = it;
            ++it2;
            if (it2 != checks_failed.end()) {
                failed_checks_list_string += std::string(c + ", ");
            } else {
                failed_checks_list_string += c;
            }
        }
        
        std::cout << "    " << SD_LINUX_TERMINAL_COLOR_BOLDRED
        << "Test FAILED "<< SD_LINUX_TERMINAL_COLOR_RESET 
        <<"- it has failed checks (" << checks_failed_amount << ") out of total (" << checks_amount << ")\n";
        std::cout << "    Failed checks are = {" << failed_checks_list_string << "}\n";
    }
}
void SD_ApplicationTesting::OutputNotFoundTests(const std::vector<std::string>& not_found) {
    
    
    std::string ids;
    
    for (auto it = not_found.begin(); it != not_found.end(); ++it) {
        auto it2 = it;
        ++it2;

        ids += *it;
        if (it2 != not_found.end()) {
            ids += ", ";
        }
    }
    
    std::cout << SD_LINUX_TERMINAL_COLOR_CYAN 
                "Unfortunately, we cannot find tests of id = {" << ids << "}\n" <<
                "and therefore we can't execute them.\n"
                << SD_LINUX_TERMINAL_COLOR_RESET;
}
void SD_ApplicationTesting::InitTestContainer() {
    tests_container = std::make_unique<SD_TestContainer>();
}
////////////////////////////////////////

////////////////////////////////////////
SD_DECLARE_CLASS_CPP(SD_TestInserter)
SD_TestInserter::SD_TestInserter(std::unique_ptr<SD_UnitTest>&& test) {
    SD_ApplicationTesting& testing = SD_ApplicationTesting::Instance();
    testing.AddUnitTest(std::move(test));
}
SD_TestInserter::SD_TestInserter(std::unique_ptr<SD_RealtimeTest>&& test) {
    SD_ApplicationTesting& testing = SD_ApplicationTesting::Instance();
    testing.AddRealtimeTest(std::move(test));
}
////////////////////////////////////////
std::string SD_DeduceNestedExceptionType(
    const std::exception& e
) {
    try {
        std::rethrow_if_nested(e);
    } catch(const std::exception& inner_e) {
        return SD_DeduceNestedExceptionType(inner_e);
    } catch(...) {
    }

    try {
        const exc::SD_Exception& exc_casted = dynamic_cast<const exc::SD_Exception&>(e); 

        //Cast successful

        return exc_casted.GetName();
    } catch (const std::bad_cast& bad_cast_exc) {

    }
    return typeid(e).name();
}


#include <SigmaDev/Exception/Exception.h>

namespace exc 
{
class _SD_TestException : public SD_Exception {
public:
    _SD_TestException() : SD_Exception("_SD_TestException", DefaultExceptionDescription()) {}

    virtual std::string DefaultExceptionDescription() const override { 
        return std::string();
    }
};
class _SD_TestException2 : public SD_Exception {
public:
    _SD_TestException2() : SD_Exception("_SD_TestException2", DefaultExceptionDescription()) {}
    
    virtual std::string DefaultExceptionDescription() const override {
        return std::string();
    }
};
}
void _SD_NullFunction() {

}



// Simple check if the testing framework is working (below)

/*
SD_DEFINE_REALTIME_TEST(realtime1)
    SD_CHECK_TRUE("true", true)
SD_DEFINE_REALTIME_TEST_END()
SD_INSERT_REALTIME_TEST(realtime1)


SD_DEFINE_REALTIME_TEST(realtime2)
    SD_CHECK_TRUE("true", true)
SD_DEFINE_REALTIME_TEST_END()
SD_INSERT_REALTIME_TEST(realtime2)


SD_DEFINE_REALTIME_TEST(realtime3)
    SD_CHECK_TRUE("true", true)
SD_DEFINE_REALTIME_TEST_END()
SD_INSERT_REALTIME_TEST(realtime3)


SD_DEFINE_UNIT_TEST(exctest)
    SD_CHECK_THROW("true_throw_1", exc::_SD_TestException, throw exc::_SD_TestException();)
    SD_CHECK_NOTHROW("true_throw_2", exc::_SD_TestException, _SD_NullFunction();)
    SD_CHECK_THROW("false_throw_1", exc::_SD_TestException, _SD_NullFunction();)
    SD_CHECK_NOTHROW("false_throw_2", exc::_SD_TestException, throw exc::_SD_TestException();)
    SD_CHECK_THROW("false_throw_3", exc::_SD_TestException, throw exc::_SD_TestException2();)
    SD_CHECK_THROW("false_throw_4", exc::_SD_TestException2, throw exc::_SD_TestException();)
    SD_CHECK_NOTHROW("false_throw_5", exc::_SD_TestException, throw exc::_SD_TestException();)
    SD_CHECK_NOTHROW("false_throw_6", exc::_SD_TestException2, throw exc::_SD_TestException2();)
    SD_CHECK_NOTHROW("true_throw_3", exc::_SD_TestException2, throw exc::_SD_TestException();)

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(exctest)

SD_DEFINE_UNIT_TEST(abc)
    SD_CHECK_TRUE("true_assert_1", true)
    SD_CHECK_FALSE("false_assert_1", false)
    SD_CHECK_TRUE("true_assert_2", true)
    SD_CHECK_FALSE("false_assert_2", false)
SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(abc)

SD_DEFINE_UNIT_TEST(abc2)
    SD_CHECK_TRUE("true_assert_1", true)
    SD_CHECK_FALSE("false_assert_1", false)
    SD_CHECK_TRUE("true_assert_2", true)
    SD_CHECK_FALSE("false_assert_2", false)
    SD_CHECK_FALSE("failed1", true)
    SD_CHECK_FALSE("failed2", true)
    SD_CHECK_FALSE("failed3", true)
    SD_CHECK_FALSE("failed4", true)
    SD_CHECK_TRUE("failed5", false)
SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(abc2)

SD_DEFINE_UNIT_TEST(abc3)
    SD_CHECK_TRUE("true_assert_1", true)
    SD_CHECK_FALSE("false_assert_1", false)
    SD_CHECK_TRUE("true_assert_2", true)
    SD_CHECK_FALSE("false_assert_2", false)
    SD_CHECK_FALSE("failed1", true)
    SD_CHECK_FALSE("failed2", true)
    SD_CHECK_FALSE("failed3", true)
    SD_CHECK_FALSE("failed4", true)
    SD_CHECK_TRUE("failed5", false)
SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(abc3)


SD_DEFINE_UNIT_TEST(abc4)
    SD_CHECK_TRUE("true_assert_1", true)
    SD_CHECK_FALSE("false_assert_1", false)
    SD_CHECK_TRUE("true_assert_2", true)
    SD_CHECK_FALSE("false_assert_2", false)
    SD_CHECK_FALSE("failed1", true)
    SD_CHECK_FALSE("failed2", true)
    SD_CHECK_FALSE("failed3", true)
    SD_CHECK_FALSE("failed4", true)
    SD_CHECK_TRUE("failed5", false)
SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(abc4)

SD_DEFINE_UNIT_TEST(empty)
SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(empty)

SD_DEFINE_UNIT_TEST(one)
    SD_CHECK_TRUE("true", true)
SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(one)

SD_DEFINE_UNIT_TEST(two)

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(two)
*/