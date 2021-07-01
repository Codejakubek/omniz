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
// File: /impl/src/SigmaDev/Misc/GenericContainer.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Misc/GenericContainer.h>
#include <SigmaDev/Testing/Testing.h>

SD_DECLARE_CLASS_CPP(SD_GenericVariable)
SD_DECLARE_CLASS_CPP(SD_ObjectValue)


SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, int)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, int)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, int)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, int)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, short)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, short)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, short)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, short)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, long)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, long)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, long)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, long)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, long long)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, long long)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, long long)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, long long)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, char)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, char)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, char)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, char)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, float)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, float)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, float)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, float)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, double)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, double)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, double)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, double)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, std::string)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, std::string)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, std::string)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, std::string)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, sf::Vector2i)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, sf::Vector2i)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, sf::Vector2i)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, sf::Vector2i)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, sf::Vector2f)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, sf::Vector2f)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, sf::Vector2f)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, sf::Vector2f)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, sf::Vector3i)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, sf::Vector3i)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, sf::Vector3i)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, sf::Vector3i)

SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericValue, sf::Vector3f)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericRawValue, sf::Vector3f)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericSharedPtrValue, sf::Vector3f)
SD_DECLARE_CLASS_CPP_TEMPLATE_1(SD_GenericUniquePtrValue, sf::Vector3f)
////////////////////////////////////////
SD_GenericVariable::SD_GenericVariable(const std::string& variable_id) : variable_id(variable_id) {

}
template <typename VALUE_TYPE>
bool SD_GenericVariable::AddVariable_SharedPtrValue(
    const SD_StringPath& path,
    VALUE_TYPE* value
) {
    //TODO
}
template <typename VALUE_TYPE>
bool SD_GenericVariable::AddVariable_UniquePtrValue(
    const SD_StringPath& path,
    VALUE_TYPE* value
) {
    //TODO
}
template <typename VALUE_TYPE>
bool SD_GenericVariable::AddVariable_RawValue(
    const SD_StringPath& path,
    const VALUE_TYPE& value
) {
    //TODO
}
void SD_GenericVariable::SetAs_ObjectValue() {
    this->value = std::make_unique<SD_ObjectValue>();
    this->initialized = true;
}
SD_OptionalRef<SD_ObjectValue> SD_GenericVariable::AddVariable_ObjectValue(
    const SD_StringPath& path
) {
    //TODO
}
SD_OptionalRef<SD_ObjectValue> SD_GenericVariable::GetObjectValue(const SD_StringPath& path) const {

}
SD_OptionalRef<SD_ObjectValue> SD_GenericVariable::GetAsObjectValue() const {
    if(Initialized()) {
    SD_ObjectValue* v = dynamic_cast<SD_ObjectValue*>(this->value.get());
    if (v) {
        return SD_OptionalRef<SD_ObjectValue>(*v);
    }
    }
    return SD_OptionalRef<SD_ObjectValue>();
}
////////////////////////////////////////

#include <SigmaDev/Testing/Testing.h>


////////////////////////////////////////
SD_DEFINE_UNIT_TEST(sd_generic_variable)
    nlohmann::json j = {
        {"int", 10},
        {"short", 20},
        {"long", 1000000},
        {"long long", 4444444},
        {"char", "a"},
        {"string", "STRING"},
        {"float", 2.0f},
        {"double", 5.0},
        {"object",
            {
                "a" , "ZZZZ",
                "b" , 1111,
                "c" , -5
            }
        }
    };


    SD_GenericRawValue<int> a(1);
    SD_GenericRawValue<int> b(10);
    SD_GenericSharedPtrValue<int> c(std::make_shared<int>(30));
    SD_GenericSharedPtrValue<int> d(new int(40));
    SD_GenericUniquePtrValue<int> e(new int(60));


    SD_CHECK_TRUE("a_value", a.GetValue() == 1);
    SD_CHECK_TRUE("b_value", b.GetValue() == 10);
    SD_CHECK_TRUE("c_value", c.GetValue() == 30);
    SD_CHECK_TRUE("d_value", d.GetValue() == 40);
    SD_CHECK_TRUE("e_value", e.GetValue() == 60);

    SD_GenericRawValue<std::string> str_a("ABC");
    SD_GenericRawValue<std::string> str_b("CBA");
    SD_GenericSharedPtrValue<std::string> str_c(std::make_shared<std::string>("XYZ"));
    SD_GenericSharedPtrValue<std::string> str_d(new std::string("UUU"));
    SD_GenericUniquePtrValue<std::string> str_e(new std::string("III"));

    SD_CHECK_TRUE("str_a_value", str_a.GetValue().compare("ABC") == 0);
    SD_CHECK_TRUE("str_b_value", str_b.GetValue().compare("CBA") == 0);
    SD_CHECK_TRUE("str_c_value", str_c.GetValue().compare("XYZ") == 0);
    SD_CHECK_TRUE("str_d_value", str_d.GetValue().compare("UUU") == 0);
    SD_CHECK_TRUE("str_e_value", str_e.GetValue().compare("III") == 0);

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_generic_variable)
////////////////////////////////////////
SD_DEFINE_UNIT_TEST(sd_generic_variable_concretes)

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_generic_variable_concretes)
////////////////////////////////////////
SD_DEFINE_UNIT_TEST(sd_generic_variable_access)
    SD_GenericVariable var1("1");
    SD_GenericVariable var2("2");
    SD_GenericVariable var3("3");
    SD_GenericVariable var4("4");

    var1.SetAs_RawValue<int>(10);
    var2.SetAs_SharedPtrValue<int>(new int(30));
    var3.SetAs_UniquePtrValue<int>(new int(100));

    SD_CHECK_TRUE("var1_value", var1.GetValue<int>().Get() == 10);
    SD_CHECK_TRUE("var2_value", var2.GetValue<int>().Get() == 30);
    SD_CHECK_TRUE("var3_value", var3.GetValue<int>().Get() == 100);

    SD_CHECK_TRUE("var1_valuecontainertype", var1.Is_RawValue<int>());
    SD_CHECK_TRUE("var2_valuecontainertype", var2.Is_SharedPtrValue<int>());
    SD_CHECK_TRUE("var3_valuecontainertype", var3.Is_UniquePtrValue<int>());

    SD_CHECK_TRUE("var1_initialized", var1.Initialized());
    SD_CHECK_TRUE("var2_initialized", var2.Initialized());
    SD_CHECK_TRUE("var3_initialized", var3.Initialized());
    SD_CHECK_TRUE("var4_initialized", var4.Initialized() == false);

    SD_GenericVariable var5("5");
    SD_GenericVariable var6("6");
    SD_GenericVariable var7("7");

    var5.SetAs_RawValue<std::string>("GGG");
    var6.SetAs_SharedPtrValue<std::string>(new std::string("HHH"));
    var7.SetAs_UniquePtrValue<std::string>(new std::string("LLL"));

    SD_CHECK_TRUE("var5_value", var5.GetValue<std::string>().Get().compare("GGG") == 0);
    SD_CHECK_TRUE("var6_value", var6.GetValue<std::string>().Get().compare("HHH") == 0);
    SD_CHECK_TRUE("var7_value", var7.GetValue<std::string>().Get().compare("LLL") == 0);

    SD_GenericVariable nested_var("nested");

    nested_var.SetAs_ObjectValue();
    SD_CHECK_TRUE("nested_add1", nested_var.AddVariable_ObjectValue(
        SD_StringPath({"a"})
    ).Initialized());
    SD_CHECK_TRUE("nested_add2", nested_var.AddVariable_ObjectValue(
        SD_StringPath({"b"})
    ).Initialized());
    SD_CHECK_TRUE("nested_add3", nested_var.AddVariable_ObjectValue(
        SD_StringPath({"c"})
    ).Initialized());
    SD_CHECK_TRUE("nested_add4", nested_var.AddVariable_ObjectValue(
        SD_StringPath({"a", "b"})
    ).Initialized());
    SD_CHECK_TRUE("nested_add5", nested_var.AddVariable_ObjectValue(
        SD_StringPath({"a", "b", "c"})
    ).Initialized());
    SD_CHECK_FALSE("nested_add6", nested_var.AddVariable_ObjectValue(
        SD_StringPath({"a", "b", "c", "e", "f", "g"})
    ).Initialized());

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_generic_variable_access)
////////////////////////////////////////
SD_DEFINE_UNIT_TEST(sd_generic_variable_object_value)
    SD_ObjectValue object_value;

    object_value.CreateVariable_AsRawValue<int>("a", 10);
    object_value.CreateVariable_AsUniquePtrValue<int>("b", new int(100));
    object_value.CreateVariable_AsSharedPtrValue<int>("c", new int(1000));

    SD_CHECK_TRUE("a_value", object_value.GetVariableRef<int>("a").Get() == 10);
    SD_CHECK_TRUE("b_value", object_value.GetVariableRef<int>("b").Get() == 100);
    SD_CHECK_TRUE("c_value", object_value.GetVariableRef<int>("c").Get() == 1000);

    SD_CHECK_TRUE("a_value2", object_value.GetVariable("a").Get()->GetValue<int>().Get() == 10);
    SD_CHECK_TRUE("b_value2", object_value.GetVariable("b").Get()->GetValue<int>().Get() == 100);
    SD_CHECK_TRUE("c_value2", object_value.GetVariable("c").Get()->GetValue<int>().Get() == 1000);

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_generic_variable_object_value)
////////////////////////////////////////
SD_DEFINE_UNIT_TEST(sd_generic_variable_loading_rules)

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_generic_variable_loading_rules)
////////////////////////////////////////
SD_DEFINE_UNIT_TEST(sd_generic_variable_json_loading)

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_generic_variable_json_loading)
////////////////////////////////////////
SD_DEFINE_UNIT_TEST(sd_generic_variable_json_saving)

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_generic_variable_json_saving)
////////////////////////////////////////
SD_DEFINE_UNIT_TEST(sd_generic_variable_loading_rules_api)

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_generic_variable_loading_rules_api)
////////////////////////////////////////
SD_DEFINE_UNIT_TEST(sd_generic_variable_luatesting)

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_generic_variable_luatesting)
////////////////////////////////////////
