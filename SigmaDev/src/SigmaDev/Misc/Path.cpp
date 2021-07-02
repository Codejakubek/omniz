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
// File: /impl/src/SigmaDev/Misc/Path.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Misc/Path.h>
#include <boost/tokenizer.hpp>
#include <iostream>

SD_DECLARE_CLASS_CPP(SD_StringPath)

SD_StringPath::SD_StringPath() {
    path.clear();
    untokenized = "";
}
SD_StringPath::SD_StringPath(std::initializer_list<std::string> path) {
    for (auto & el : path) {
        this->path.emplace_back(el);
    }
    Process(this->path);
} 
SD_StringPath::SD_StringPath(const std::list<std::string>& path) {
    this->path = path;
    Process(this->path);
}
SD_StringPath::SD_StringPath(const std::string& untokenized) {
    this->untokenized = untokenized;
    Process(untokenized);
}
SD_StringPath::SD_StringPath(const SD_StringPath& cpy) {
    this->untokenized = cpy.GetUntokenized();
    this->path = cpy.GetTokenizedPath();
}
void SD_StringPath::Process(const std::list<std::string>& tokenized) {
    untokenized.clear();
    for (auto it = tokenized.begin(); it != tokenized.end(); ++it) {
        const std::string& token = *it;
        auto it2 = it;
        ++it2;
        untokenized += token;
        if (it2 != tokenized.end()) {
            untokenized += '/';
        }
    }
}
void SD_StringPath::Process(const std::string& untokenized) {
    path.clear();
    boost::char_separator<char> sep("/");
    boost::tokenizer<boost::char_separator<char>> tokens(untokenized, sep);
    for (const auto & token : tokens) {
        path.emplace_back(token);
    }
}

SD_OptionalConstRef<nlohmann::json> 
SD_Go(const nlohmann::json& json, const SD_StringPath& variable_path) {
    if (variable_path.IsEmpty()) {
        return SD_OptionalConstRef<nlohmann::json>(json);
    } else if (variable_path.Size() == 1) {
        const std::string& key = variable_path.Back();
        auto it = json.find(key);
        if (it != json.end()) {
        return SD_OptionalConstRef<nlohmann::json>(*it);
        }
    } else if (variable_path.Size() > 1) {
        const std::list<std::string>& path_keys = variable_path.GetTokenizedPath();
        const nlohmann::json* current = &json;

        for (auto & key : path_keys) {
            auto it = current->find(key);
            if (it != current->end()) {
                const nlohmann::json& found = *it;
                current = &found;
            } else {
                return SD_OptionalConstRef<nlohmann::json>();
            }
        }

        return SD_OptionalConstRef<nlohmann::json>(*current);
    }
    return SD_OptionalConstRef<nlohmann::json>();
}

SD_OptionalRef<nlohmann::json> 
SD_Go(nlohmann::json& json, const SD_StringPath& variable_path) {
    if (variable_path.IsEmpty()) {
        return SD_OptionalRef<nlohmann::json>(json);
    } else if (variable_path.Size() == 1) {
        const std::string& key = variable_path.Back();
        auto it = json.find(key);
        if (it != json.end()) {
        return SD_OptionalRef<nlohmann::json>(*it);
        }
    } else if (variable_path.Size() > 1) {
        const std::list<std::string>& path_keys = variable_path.GetTokenizedPath();
        nlohmann::json* current = &json;

        for (auto & key : path_keys) {
            auto it = current->find(key);
            if (it != current->end()) {
                nlohmann::json& found = *it;
                current = &found;
            } else {
                return SD_OptionalRef<nlohmann::json>();
            }
        }

        return SD_OptionalRef<nlohmann::json>(*current);
    }
    return SD_OptionalRef<nlohmann::json>();
}

void SD_OutputNiceJson(const nlohmann::json& json) {
    std::string str = json.dump(4,' ');

    std::cout << str << std::endl;
}
std::string SD_NiceJson(const nlohmann::json& json) {
    return json.dump(4,' ');
}



void SD_JSONSave(const nlohmann::json& json, const std::string& filepath) {
    //TODO    
}
void SD_JSONLoad(nlohmann::json& json, const std::string& filepath) {
    //TODO
}

template <typename VALUE_TYPE>
SD_Optional<VALUE_TYPE> SD_JSONVar(const nlohmann::json& j, const SD_StringPath& path) {
    SD_OptionalConstRef<nlohmann::json> j2 =  SD_Go(j, path);
    if (j2.Initialized()) {
        const nlohmann::json& j3 = j2.Get();

        VALUE_TYPE v;
        try {
            j3.get_to(v);
            return SD_Optional<VALUE_TYPE>(v);
        } catch (const nlohmann::json& exc) {

        }
    }
    return SD_Optional<VALUE_TYPE>();
} 


#include <SigmaDev/Testing/Testing.h>

SD_DEFINE_UNIT_TEST(stringpath_test)
    SD_StringPath path_a({"a", "b", "c"});
    SD_StringPath path_b({"a", "b", "c"});
    SD_StringPath path_c("a/b/c");
    SD_StringPath path_d(std::list<std::string>({"a", "b", "c"}));
    SD_StringPath path_e({"a", "b", "c", "d"});
    SD_StringPath path_f("a/b/c/d");
    SD_StringPath path_g(std::list<std::string>({"a", "b", "c", "d"}));

    SD_CHECK_TRUE("check_1", path_a == path_b && path_b == path_c && path_a == path_c && path_c == path_d && path_a == path_d && path_b == path_d)
    SD_CHECK_FALSE("check_2", path_a == path_e || path_a == path_f || path_a == path_g)
    SD_CHECK_TRUE("check_3", path_e == path_f && path_f == path_g && path_e == path_g)
    SD_CHECK_TRUE("check_4", path_g != path_a && path_f != path_b && path_e != path_d)
   // std::cout << "path_a == " << path_a.GetUntokenized() << "\n";
   // std::cout << "path_b == " << path_b.GetUntokenized() << "\n";
   // std::cout << "path_c == " << path_c.GetUntokenized() << "\n";
   // std::cout << "path_d == " << path_d.GetUntokenized() << "\n";
   // std::cout << "path_e == " << path_e.GetUntokenized() << "\n";
   // std::cout << "path_f == " << path_f.GetUntokenized() << "\n";
   // std::cout << "path_g == " << path_g.GetUntokenized() << "\n"; 
SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(stringpath_test)

SD_DEFINE_UNIT_TEST(sd_json_go)
    nlohmann::json j = {
        {"a", 1},
        {"b", 
            {{"b2", 
                {{"b3", 
                    {{"var1", 1}, {"var2", 10}, {"var3", "AAA"}}
                }}
            }}
        }
    };
    SD_StringPath path1("a");
    SD_StringPath path2({"a"});
    SD_StringPath path3({"b", "b2", "b3", "var1"});
    SD_StringPath path4("b/b2/b3/var1");
    SD_StringPath path5({"b", "b2", "b3", "var3"});
    SD_StringPath path6("b/b2/b3/var2");
    SD_StringPath path7;
    SD_StringPath path8("a/omg/rofl/wtf/doesnt_exist");
    SD_StringPath path9({"a", "omg", "wtf", "this", "doesnt", "exist"});

    const nlohmann::json& const_j = j;

    //SD_OutputNiceJson(j);

    SD_CHECK_TRUE("exists1", SD_Go(const_j, path1).Initialized());
    SD_CHECK_TRUE("exists2", SD_Go(const_j, path2).Initialized());
    SD_CHECK_TRUE("exists3", SD_Go(const_j, path3).Initialized());
    SD_CHECK_TRUE("exists4", SD_Go(const_j, path4).Initialized());
    SD_CHECK_TRUE("exists5", SD_Go(const_j, path5).Initialized());
    SD_CHECK_TRUE("exists6", SD_Go(const_j, path6).Initialized());
    SD_CHECK_TRUE("exists7", SD_Go(const_j, path7).Initialized());
    SD_CHECK_FALSE("exists8", SD_Go(const_j, path8).Initialized());
    SD_CHECK_FALSE("exists9", SD_Go(const_j, path9).Initialized());

    SD_CHECK_TRUE("exists10", SD_Go(j, path1).Initialized());
    SD_CHECK_TRUE("exists11", SD_Go(j, path2).Initialized());
    SD_CHECK_TRUE("exists12", SD_Go(j, path3).Initialized());
    SD_CHECK_TRUE("exists13", SD_Go(j, path4).Initialized());
    SD_CHECK_TRUE("exists14", SD_Go(j, path5).Initialized());
    SD_CHECK_TRUE("exists15", SD_Go(j, path6).Initialized());
    SD_CHECK_TRUE("exists16", SD_Go(j, path7).Initialized());
    SD_CHECK_FALSE("exists17", SD_Go(j, path8).Initialized());
    SD_CHECK_FALSE("exists18", SD_Go(j, path9).Initialized());

    SD_CHECK_TRUE("value1", SD_JSONVar<int>(j, path3).Initialized());
    SD_CHECK_TRUE("value2", SD_JSONVar<short>(j, path3).Initialized());
    SD_CHECK_TRUE("value3", SD_JSONVar<long>(j, path3).Initialized());
    SD_CHECK_TRUE("value4", SD_JSONVar<long long>(j, path3).Initialized());
    if (SD_CHECK_VALUE("value1") && SD_CHECK_VALUE("value2")
        && SD_CHECK_VALUE("value3") && SD_CHECK_VALUE("value4")) {
    
        SD_CHECK_TRUE("value5", SD_JSONVar<int>(j, path3).Get() == 1);
        SD_CHECK_TRUE("value6", SD_JSONVar<short>(j, path3).Get() == 1);
        SD_CHECK_TRUE("value7", SD_JSONVar<long>(j, path3).Get() == 1);
        SD_CHECK_TRUE("value8", SD_JSONVar<long long>(j, path3).Get() == 1);
    
    } else {
        SD_CHECK_SET_FALSE("value5");
        SD_CHECK_SET_FALSE("value6");
        SD_CHECK_SET_FALSE("value7");
        SD_CHECK_SET_FALSE("value8");
    }

    SD_CHECK_TRUE("value9", SD_JSONVar<int>(j, path4).Initialized());
    SD_CHECK_TRUE("value10", SD_JSONVar<int>(j, path4).Initialized());
    SD_CHECK_TRUE("value11", SD_JSONVar<long>(j, path4).Initialized());
    SD_CHECK_TRUE("value12", SD_JSONVar<long long>(j, path4).Initialized());
    
    
    if (SD_CHECK_VALUE("value9") && SD_CHECK_VALUE("value10")
        && SD_CHECK_VALUE("value11") && SD_CHECK_VALUE("value12")) {
    
        SD_CHECK_TRUE("value13", SD_JSONVar<int>(j, path4).Get() == 1);
        SD_CHECK_TRUE("value14", SD_JSONVar<short>(j, path4).Get() == 1);
        SD_CHECK_TRUE("value15", SD_JSONVar<long>(j, path4).Get() == 1);
        SD_CHECK_TRUE("value16", SD_JSONVar<long long>(j, path4).Get() == 1);
    
    } else {
        SD_CHECK_SET_FALSE("value9");
        SD_CHECK_SET_FALSE("value10");
        SD_CHECK_SET_FALSE("value11");
        SD_CHECK_SET_FALSE("value12");
    }

    SD_CHECK_TRUE("value17", SD_JSONVar<std::string>(j, path5).Initialized());

    if (SD_CHECK_VALUE("value17")) {
        SD_CHECK_TRUE("value18", SD_JSONVar<std::string>(j, path5).Get().compare("AAA") == 0);
    } else {
        SD_CHECK_SET_FALSE("value18");
    }

    SD_CHECK_TRUE("value19", SD_JSONVar<int>(j, path6).Initialized());

    if (SD_CHECK_VALUE("value19")) {
        SD_CHECK_TRUE("value20", SD_JSONVar<int>(j, path6).Get() == 10);
    } else {
        SD_CHECK_SET_FALSE("value20");
    }

    nlohmann::json j2 = {
        {"float", 2.0f},
        {"double", 2.0},
        {"int", 1000},
        {"signed_int", -1000},
        {"string", "STRING"},
        {"object", {
            {"a", 1},
            {"b", 3}
        }},
        {"array_of_ints", {1,2,3,4,5}},
        {"array_of_floats", {1.0f, 2.0f, 3.0f}},
        {"array_of_strings", {"a", "b", "c"}},
        {"array_of_objects", {
                {{"x", 1}, {"y", 3}}, 
                {{"x", 5}, {"y", 5}},
                {{"x", 8}, {"y", 8}},
            }
        },
        {"array_of_randoms", {
                {{"x", 1}, {"y", 3}}, 
                {{"x", 5}, {"y", 5}},
                {{"x", 8}, {"y", 8}},
                "a",
                "b",
                "c",
                1.0f,
                5,
                25,
                125,
                -55,
                -66
            }
        }
    };
    SD_OutputNiceJson(j2);

    SD_CHECK_TRUE("value_initialized_b_1", SD_JSONVar<float>(j2, SD_StringPath({"float"})).Initialized());
    SD_CHECK_TRUE("value_initialized_b_2", SD_JSONVar<double>(j2, SD_StringPath({"double"})).Initialized());
    SD_CHECK_TRUE("value_initialized_b_3", SD_JSONVar<int>(j2, SD_StringPath({"int"})).Initialized());
    SD_CHECK_TRUE("value_equals_b_3", SD_JSONVar<int>(j2, SD_StringPath({"int"})).Get() == 1000);
    SD_CHECK_TRUE("value_initialized_b_4", SD_JSONVar<int>(j2, SD_StringPath({"signed_int"})).Initialized());
    SD_CHECK_TRUE("value_equals_b_4", SD_JSONVar<int>(j2, SD_StringPath({"signed_int"})).Get() == -1000);
    SD_CHECK_TRUE("value_initialized_b_5", SD_JSONVar<std::string>(j2, SD_StringPath({"string"})).Initialized());
    SD_CHECK_TRUE("value_equals_b_5", SD_JSONVar<std::string>(j2, SD_StringPath({"string"})).Get().compare("STRING") == 0);

    auto opt_object_j = SD_Go(j2, SD_StringPath({"object"}));
    SD_CHECK_TRUE("value_initialized_b_6", opt_object_j.Initialized());
    auto object_j = opt_object_j.Get();
    SD_CHECK_TRUE("value_initialized_b_6_1", SD_JSONVar<int>(object_j, SD_StringPath("a")).Initialized());
    SD_CHECK_TRUE("value_initialized_b_6_2", SD_JSONVar<int>(object_j, SD_StringPath("b")).Initialized());
    SD_CHECK_TRUE("value_equals_b_6_1", SD_JSONVar<int>(object_j, SD_StringPath("a")).Get() == 1);
    SD_CHECK_TRUE("value_equals_b_6_2", SD_JSONVar<int>(object_j, SD_StringPath("b")).Get() == 3);

    auto opt_list_of_ints = SD_JSONVar<std::vector<int>>(j2, SD_StringPath({"array_of_ints"}));
    SD_CHECK_TRUE("value_initialized_b_7", opt_list_of_ints.Initialized());
    auto list_of_ints = opt_list_of_ints.Get();
    SD_CHECK_TRUE("value_equals_b_7_1", list_of_ints.at(0) == 1);
    SD_CHECK_TRUE("value_equals_b_7_2", list_of_ints.at(1) == 2);
    SD_CHECK_TRUE("value_equals_b_7_3", list_of_ints.at(2) == 3);
    SD_CHECK_TRUE("value_equals_b_7_4", list_of_ints.at(3) == 4);
    SD_CHECK_TRUE("value_equals_b_7_5", list_of_ints.at(4) == 5);

    auto opt_list_of_floats = SD_JSONVar<std::vector<float>>(j2, SD_StringPath({"array_of_floats"}));
    SD_CHECK_TRUE("value_initialized_b_8", opt_list_of_floats.Initialized());
    auto list_of_floats = opt_list_of_floats.Get();

    auto opt_list_of_strings = SD_JSONVar<std::vector<std::string>>(j2, SD_StringPath({"array_of_strings"}));
    SD_CHECK_TRUE("value_initialized_b_9", opt_list_of_strings.Initialized());
    auto list_of_strings = opt_list_of_strings.Get();
    SD_CHECK_TRUE("value_equals_b_9_1", list_of_strings.at(0).compare("a") == 0);
    SD_CHECK_TRUE("value_equals_b_9_2", list_of_strings.at(1).compare("b") == 0);
    SD_CHECK_TRUE("value_equals_b_9_3", list_of_strings.at(2).compare("c") == 0);

    SD_Optional<std::vector<nlohmann::json>> opt_array_of_objects = SD_JSONVar<std::vector<nlohmann::json>>(j2, SD_StringPath({"array_of_objects"})); 
    SD_CHECK_TRUE("value_initialized_b_10", opt_array_of_objects.Initialized());

    SD_Optional<std::vector<nlohmann::json>> opt_array_of_randoms = SD_JSONVar<std::vector<nlohmann::json>>(j2, SD_StringPath({"array_of_randoms"})); 
    SD_CHECK_TRUE("value_initialized_b_11", opt_array_of_randoms.Initialized());

    

SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_json_go)