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
// File: /impl/src/SigmaDev/Main/Main.cp
// Description:
// Additional Notes:

#include <SigmaDev/Main/Main.h>
#include <iostream>
#include <SigmaDev/Testing/Testing.h>

//     TODO: BIG: SD_GUIObject
//     TODO: BIG: Music Playing
//     TODO: BIG: Sound Playing
//     TODO: BIG: Scripting Module
//     TODO: BIG: Networking Module
//     TODO: BIG: SD_Application Refactoring

namespace std
{
  std::ostream& operator<<(std::ostream & o, const std::vector<std::string> & v) 
  {    
    for (auto el : v) 
    { 
      o << el << " "; 
    } 
    return o; 
  }
} 

SD_DECLARE_CLASS_CPP(SD_HelperParserOfCmdArguments)
SD_HelperParserOfCmdArguments::SD_HelperParserOfCmdArguments(boost::program_options::variables_map& map) : map(map) {

}
bool SD_HelperParserOfCmdArguments::IsThereOneOf(const std::string& one, std::initializer_list<std::string> of) const {
    std::set<std::string> found_set;

    for (const std::string & el : of) {
        bool found = map.count(el);
        if (found) {
            found_set.insert(el);
        }        
    }

    if (found_set.size() == 1) {
        auto it = found_set.find(one);
        if (it != found_set.end()) {
            return true;
        } else return false;
    } else {
        return false;
    }
}
bool SD_HelperParserOfCmdArguments::IsThereListOf(std::initializer_list<std::string> list, std::initializer_list<std::string> of) const {
    std::set<std::string> found_set;

    for (const std::string& el : of) {
        bool found = map.count(el);
        if (found) {
            found_set.insert(el);
        }
    }

    if (found_set.size() == list.size()) {
        for (const std::string & el : list) {
            auto it = found_set.find(el);
            if (it != found_set.end()) {
                //ok
            } else return false;
            
        }
    } else {
        return false;
    }

    return true;
}
bool SD_HelperParserOfCmdArguments::IsThere(const std::string& one) const {
    if (map.count(one)) {
        return true;
    } else return false;
}
int SD_HelperParserOfCmdArguments::HowManyOf(std::initializer_list<std::string> of) const {
    int amount = 0;
    for (const std::string& el : of) {
        if(map.count(el)) ++amount;
    } 
    return amount;
}

SD_DECLARE_CLASS_CPP(SD_Main)
SD_Main::SD_Main(int argc, char* argv[]) 
    : help_begin_information(
        "\n"
            "==================="
            "\nWelcome to the SigmaDev Testing API. Here you can execute unit and realtime tests to check"
            " if library is properly working. You can also run demos showing the functionalities"
            " of the library.\n\n"
            ""
            "Remember that you have to pick tests or demos. You can't run them both. \n\n"
            ""
            "To execute tests, you have to provide the --execute_tests flag.\n"
            "To run the demo, you have to provide the --execute_demo flag, with the name of the demo\n\n"
            ""
            "You can also customize more. Below you will find all flags you can use to test this library\n"
            "===================\n"
    ),
    all_options_descriptions{"SigmaDev Testing API Options"},
    help_options_descriptions{"  Help Related Options"},
    testing_options_descriptions{"  Testing Related Options"},
    demos_options_descriptions{" Demos Related Options"},
    helper(variables_map)
{

    InitializeOptionsDescriptions();
    
    if (NoErrors()) {
        ParseCommandLine(argc, argv);
    }
    bool no_exc_catch = variables_map.count("no_exc_catch");
    if (NoErrors()) {
        if(no_exc_catch) {
            Action();
        } else {
            try {
                Action();
            } catch (const std::exception& e) {
                SD_PrintNestedException(e);
            }
        }
    }
}
void SD_Main::InitializeOptionsDescriptions() {
    try {
        std::vector<std::string> realtime_default({"all"});
        std::vector<std::string> unit_default({"all"});

        help_options_descriptions.add_options()
            ("help,h", "Show this help panel")
            ("help_options", "Show only help options")
            ("testing_options", "Show only testing options")
            ("demos_options", "Show only demos options")
        ;
        testing_options_descriptions.add_options()
            (
                "execute_tests",
                boost::program_options::value<std::string>()->implicit_value("unit"),
                "Use this options to execute tests. By default it executes unit tests. "
                "Set to unit to execute unit tests, set to realtime to execute realtime tests, "
                "or all to execute all tests. For example.: \"--execute_tests=all\". "
                "Remember that by default you are executing all tests. Use --unit options to "
                "specify which unit tests to execute, and --realtime to specify which realtime tests "
                "to execute."
            )
            (
                "realtime",
                boost::program_options::value<std::vector<std::string>>()->
                multitoken()->zero_tokens()->composing(),
                "(Given that you are executing realtime tests) Which realtime tests to execute (\"all\" for all) "
                "You can use --realtime-list to check the available realtime tests list. "
            )
            (
                "unit",
                boost::program_options::value<std::vector<std::string>>()->
                multitoken()->zero_tokens()->composing(),
                "(Given that you are executing unit tests) Which unit tests to execute (\"all\" for all) "
                "You can use --unit-list to check the available unit tests list."
            )
            (
                "realtime_list",
                "Show all available realtime tests"
            )
            (
                "unit_list",
                "Show all available unit tests"
            )
            (
                "realtime_detailed_list",
                "Show all realtime tests with all details"
            )
            (
                "unit_detailed_list",
                "Show all unit tests with all details"
            )
            (
                "realtime_test_details",
                boost::program_options::value<std::string>()->value_name("test_name"),
                "Show specific realtime test details"
            )
            (
                "unit_test_details",
                boost::program_options::value<std::string>()->value_name("test_name"),
                "Show specific unit test details"
            )
            (
                "no_exc_catch",
                "Set this to true if you don't want to catch & print exception (if it's thrown)"
            )
        ;

        demos_options_descriptions.add_options()
            (
                "run_demo",
                boost::program_options::value<std::string>(),
                "Run the demo. You also have to specify which (for example.: "
                "\"--execute_demo=demo1\")"
                ". You can also check available demos using --demo_list option"
            )
            (
                "demo_list",
                "Show all available demos"
            )
            (
                "demo_detailed_list",
                "Show the detailed demo list"
            )
        ;

        all_options_descriptions.add(
            help_options_descriptions
        );
        all_options_descriptions.add(
            testing_options_descriptions
        );
        all_options_descriptions.add(
            demos_options_descriptions
        );
    } catch (const boost::program_options::error& exc) {
        std::cerr << exc.what() << std::endl;
    } 
}
void SD_Main::ParseCommandLine(int argc, char* argv[]) {
    try {
        boost::program_options::store(
            boost::program_options::parse_command_line(argc, argv, all_options_descriptions),
            variables_map
        );
        boost::program_options::notify(variables_map);
    } catch (const boost::program_options::error& exc) {
        std::cerr << exc.what() << std::endl;
        SetError(error_message);
    }
}



void SD_Main::Action() {
    auto& v = variables_map;
    try {

        int how_many_of = helper.HowManyOf(
            {"execute_tests", "run_demo", "help", "help_options", "testing_options", "demos_options"}
        );

        if (how_many_of == 1) {
            if(helper.IsThere("execute_tests")) {
                Action_ExecuteTests();
            } else if (helper.IsThere("run_demo")) {
                Action_RunDemo();
            } else if (helper.IsThere("help")) {
                 Action_Help();
            } else if (helper.IsThere("help_options")) {
                Action_HelpOptions();
            } else if (helper.IsThere("testing_options")) {
                Action_TestingOptions();
            } else if (helper.IsThere("demos_options")) {
                Action_DemosOptions();
            }
        } else if (how_many_of == 0) {
            Action_Help();
        } else if (how_many_of > 1 ) {
            std::cout << "Error, You've picked more than one of the main functions\n"
            "{\"execute_tests\", \"run_demo\", \"help\", "
            "\"help_options\", \"testing_options\", \"demos_options\"}\n";
        }
    } catch (const boost::program_options::error& exc) {
        std::cerr << exc.what() << std::endl;
    }
}
void SD_Main::Action_ExecuteTests() {
    
    int how_many = helper.HowManyOf({"unit", "realtime"});
    
    bool execute_realtime = false;
    bool execute_unit = false;

    if (how_many == 1) {
        if (helper.IsThere("unit")) {
            execute_unit = true;
        } else if (helper.IsThere("realtime")) {
            execute_realtime = true;
        }
    } else if (how_many == 2) {
        if (helper.IsThere("unit")) {
            execute_unit = true;
        }
        if (helper.IsThere("realtime")) {
            execute_realtime = true;
        }
    }
    SD_TestSpecify test_specify;
    try {
        if (execute_unit) {            
            const std::vector<std::string>& list = variables_map["unit"].as<std::vector<std::string>>(); 
            for (const auto & el : list) {
                test_specify.AddTest("unit", el);
            }
            if (list.empty()) {
                test_specify.SetExecuteDefaultUnitTestIfNotSpecified(true);
            }
        }
        if (execute_realtime) {
            const std::vector<std::string>& list = variables_map["realtime"].as<std::vector<std::string>>();
            for (const auto & el : list) {
                test_specify.AddTest("realtime", el);
            }
        }
    } catch (const boost::bad_any_cast& e) {
        std::cout << "Unable to process the unit tests\n";
    }
    std::cout << "Successfuly loaded a test list\n";
    
    RunTests(test_specify);
}
void SD_Main::RunTests(SD_TestSpecify& specify) {
    static SD_ApplicationTesting& testing = SD_ApplicationTesting::Instance();
    testing.ExecuteTestsWithNiceOutput(specify);
}
void SD_Main::Action_RunDemo() {

}
void SD_Main::Action_Help() {
    std::cout << help_begin_information << std::endl;
    std::cout << all_options_descriptions << std::endl;
}
void SD_Main::Action_HelpOptions() {
    std::cout << help_options_descriptions << std::endl;
}
void SD_Main::Action_TestingOptions() {
    std::cout << testing_options_descriptions << std::endl;
}
void SD_Main::Action_DemosOptions() {
    std::cout << demos_options_descriptions << std::endl;
}
void SD_Main::ParseExecuteList() {
    std::string s = variables_map["execute_tests"].as<std::string>();
    if (s.compare("unit") == 0) {
        test_types_to_execute = SD_TestTypes::SD_TEST_TYPE_UNIT;
    } else if (s.compare("realtime") == 0) {
        test_types_to_execute = SD_TestTypes::SD_TEST_TYPE_REALTIME;
    } else if (s.compare("all") == 0) {
        test_types_to_execute = SD_TestTypes::SD_TEST_TYPE_ALL;
    } else {
        //Error
    }
}
void SD_Main::ParseRealtimeExecuteList() {
    std::vector<std::string> s = variables_map["realtime_execute_list"].as<std::vector<std::string>>();
    for (auto & el : s) {
        std::cout << "Realtime Test = " << el << std::endl;
    }
}
void SD_Main::ParseUnitExecuteList() {
    std::vector<std::string> s = variables_map["unit_execute_list"].as<std::vector<std::string>>();
    for (auto & el : s) {
        std::cout << "Unit Test = " << el << std::endl;
    }
}
void SD_Main::ShowRealtimeList() {
    std::cout << "Realtime Test List" << std::endl;
}
void SD_Main::ShowUnitList() {
    std::cout << "Unit Test List" << std::endl;
}
void SD_Main::ShowRealtimeDetailedList() {
    std::cout << "Realtime Detailed Test List " << std::endl;
}
void SD_Main::ShowUnitDetailedList() {
    std::cout << "Unit Detailed Test List " << std::endl;
}
void SD_Main::ParseRunDemo() {
    std::string s = variables_map["run_demo"].as<std::string>();
    //If - not found demo, error
}
