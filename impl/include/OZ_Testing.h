/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#ifndef OZ_TESTING_H
#define OZ_TESTING_H

#include <string>
#include <SigmaDev/Testing/Testing.h>

#include <OZ_Class.h>

#define OZ_DEFINE_UNIT_TEST(test_name) SD_DEFINE_UNIT_TEST(test_name)
#define OZ_DEFINE_UNIT_TEST_END() SD_DEFINE_UNIT_TEST_END()
#define OZ_DEFINE_REALTIME_TEST(test_name) SD_DEFINE_REALTIME_TEST(test_name)
#define OZ_DEFINE_REALTIME_TEST_END() SD_DEFINE_REALTIME_TEST_END()

#define OZ_INSERT_UNIT_TEST(test_name) SD_INSERT_UNIT_TEST(test_name)
#define OZ_INSERT_REALTIME_TEST(test_name) SD_INSERT_REALTIME_TEST(test_name)

#define OZ_CHECK_TRUE(check_id, value) SD_CHECK_TRUE(check_id, value)
#define OZ_CHECK_FALSE(check_id, value) SD_CHECK_FALSE(check_id, value)

#define OZ_CHECK_THROW(check_id, exc, code) SD_CHECK_THROW(check_id, exc, code)
#define OZ_CHECK_NOTHROW(check_id, exc, code) SD_CHECK_NOTHROW(check_id, exc, code)
#define OZ_CHECK_NESTED_FINAL_THROW(check_id, exc, code) SD_CHECK_NESTED_FINAL_THROW(check_id, exc, code)
#define OZ_CHECK_NESTED_FINAL_NOTHROW(check_id, exc, code) SD_CHECK_NESTED_FINAL_NOTHROW(check_id, exc, code)

class OZ_TestingManager : public OZ_Class {
public:
    OZ_DECLARE_CLASS_H()
protected:

};

#endif