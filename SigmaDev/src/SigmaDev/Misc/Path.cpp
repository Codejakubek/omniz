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