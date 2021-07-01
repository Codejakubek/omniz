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
// File: /impl/src/SigmaDev/Exception/TestingExceptions.cpp
// Description:
//      TestingExceptions.cpp contain definitions of exceptions declared in
//      /impl/include/SigmaDev/Exception/TestingException.cpp file
// Additional Notes:
////////////////////////////////////////

#include <SigmaDev/Exception/TestingExceptions.h>

////////////////////////////////////////
namespace exc {
////////////////////////////////////////

SD_TestSpecifyNotFoundType::SD_TestSpecifyNotFoundType()
 : SD_Exception("SD_TestSpecifyNotFoundType", DefaultExceptionDescription()),
 type("") {

 }

SD_TestSpecifyNotFoundType::SD_TestSpecifyNotFoundType(const std::string& type) : 
    SD_Exception("SD_TestSpecifyNotFoundType", DefaultExceptionDescription()),
    type(type) {

}
std::string SD_TestSpecifyNotFoundType::DefaultExceptionDescription() const {
    return std::string ("Unable to find in SD_TsetSpecify that specific type.");
}


////////////////////////////////////////

SD_TestCheckInsertionFailed::SD_TestCheckInsertionFailed()
 : SD_Exception(
     "SD_TestCheckInsertionFailed",
     DefaultExceptionDescription()
 ) , check_id("")
{

}
SD_TestCheckInsertionFailed::SD_TestCheckInsertionFailed(const std::string& check_id)
: SD_Exception(
    "SD_TestCheckInsertionFailed",
    DefaultExceptionDescription()
) , check_id(check_id)
{
    this->variables_map.insert(std::make_pair("check_id", check_id));
}
std::string SD_TestCheckInsertionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to insert test check in SD_TestChecks (in SD_Test)");
}

////////////////////////////////////////

SD_TestCheckSetFailed::SD_TestCheckSetFailed()
 : SD_Exception(
     "SD_TestCheckSetFailed",
     DefaultExceptionDescription()
 ) , check_id("")
{

}
SD_TestCheckSetFailed::SD_TestCheckSetFailed(const std::string& check_id)
: SD_Exception(
    "SD_TestCheckSetFailed",
    DefaultExceptionDescription()
) , check_id(check_id)
{
    this->variables_map.insert(std::make_pair("check_id", check_id));
}
std::string SD_TestCheckSetFailed::DefaultExceptionDescription() const {
    return std::string("Unable to set test check in SD_TestChecks (in SD_Test)");
}

////////////////////////////////////////

SD_TestCheckNotFound::SD_TestCheckNotFound()
 : SD_Exception(
     "SD_TestCheckNotFound",
     DefaultExceptionDescription()
 ), check_id("")
{

}
SD_TestCheckNotFound::SD_TestCheckNotFound(const std::string& check_id) :
    SD_Exception(
        "SD_TestCheckNotFound",
        DefaultExceptionDescription()
    ),
    check_id(check_id)
{
    this->variables_map.insert(std::make_pair("check_id", check_id));
}

std::string SD_TestCheckNotFound::DefaultExceptionDescription() const {
    return std::string("Unable to find test check in SD_TestChecks (in SD_Test)");
}

////////////////////////////////////////

SD_TestCheckErasionFailed::SD_TestCheckErasionFailed()
 : SD_Exception("SD_TestCheckErasionFailed", DefaultExceptionDescription()),
 check_id("")
 {

 }

SD_TestCheckErasionFailed::SD_TestCheckErasionFailed(const std::string& check_id) 
    : SD_Exception("SD_TestCheckErasionFailed", DefaultExceptionDescription()),
    check_id(check_id)
{
    this->variables_map.insert(std::make_pair("check_id", check_id));
}

std::string SD_TestCheckErasionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to erase test check in SD_TestChecks (in SD_Test)");
}

////////////////////////////////////////

SD_TestInsertionFailed::SD_TestInsertionFailed()
 : SD_Exception("SD_TestInsertionFailed", DefaultExceptionDescription()),
  test_id("")
{
    
}
SD_TestInsertionFailed::SD_TestInsertionFailed(const std::string& test_id) 
: SD_Exception(
    "SD_TestInsertionFailed",
    DefaultExceptionDescription()
), test_id(test_id)
{
    this->variables_map.insert(std::make_pair("test_id", test_id));
}

std::string SD_TestInsertionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to insert SD_Test in SD_TestContainer");
}

////////////////////////////////////////

SD_TestNotFound::SD_TestNotFound()
 : SD_Exception(
     "SD_TestNotFound",
     DefaultExceptionDescription()
 ) , test_id("")
{
    
}
SD_TestNotFound::SD_TestNotFound(const std::string& test_id) :
SD_Exception(
    "SD_TestNotFound", 
    DefaultExceptionDescription()
),
test_id(test_id)
{
    this->variables_map.insert(std::make_pair("test_id", test_id));

}

std::string SD_TestNotFound::DefaultExceptionDescription() const {
    return std::string("Unable to find SD_Test in SD_TestContainer");
}

////////////////////////////////////////

SD_TestErasionFailed::SD_TestErasionFailed()
 : SD_Exception("SD_TestErasionFailed", DefaultExceptionDescription()), test_id("")
 {

 }

SD_TestErasionFailed::SD_TestErasionFailed(
    const std::string& test_id
) : SD_Exception("SD_TestErasionFailed", DefaultExceptionDescription()), test_id(test_id)
{
    this->variables_map.insert(std::make_pair("test_id", test_id));

}

std::string SD_TestErasionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to erase SD_Test in SD_TestContainer");
}

////////////////////////////////////////

SD_TestExecutionFailed::SD_TestExecutionFailed()
 : SD_Exception("SD_TestExecutionFailed", DefaultExceptionDescription()),
    test_id("")
{
    
}

SD_TestExecutionFailed::SD_TestExecutionFailed(
    const std::string& test_id
) : SD_Exception("SD_TestExecutionFailed", DefaultExceptionDescription()),
    test_id(test_id)
{
    this->variables_map.insert(std::make_pair("test_id", test_id));

}
std::string SD_TestExecutionFailed::DefaultExceptionDescription() const {
    return std::string("Unable to execute test (problem inside the test body)");
}

////////////////////////////////////////
} //namespace exc 
////////////////////////////////////////