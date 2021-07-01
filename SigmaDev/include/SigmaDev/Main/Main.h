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
// File: /impl/include/SigmaDev/Main/Main.cpp
// Description:
// Additional Notes:
//////////////////////////////////////////
//
// Tutorials & Documentation can be found in 
//
//     /doc/pages/SD_Main.hpp
//
////////////////////////////////////////

#ifndef SD_MAIN_MAIN_H
#define SD_MAIN_MAIN_H

#include <string>
#include <vector>
#include <boost/program_options.hpp>
#include <list>
#include <initializer_list>

#include <SigmaDev/Misc/Class.h>

////////////////////////////////////////

class SD_TestSpecify;

/**
 * @brief Enum with the default test types  
 */
enum SD_TestTypes {
    SD_TEST_TYPE_UNKNOWN = 0,
    SD_TEST_TYPE_REALTIME,
    SD_TEST_TYPE_UNIT,
    SD_TEST_TYPE_ALL
};
////////////////////////////////////////
/*class SD_MainOptionSearchInfo {
public:
    SD_MainOptionSearchInfo(
        boost::program_options::variables_map& variables_map,
        std::initializer_list<std::string> find_list
    );
    SD_MainOptionSearchInfo();

    virtual SD_MainOptionSearchInfo& Parse(
        boost::program_options::variables_map& variables_map,
        std::initializer_list<std::string> find_list
    );
    virtual bool IsThereOnlySingleOf(const std::string& el);
    virtual bool IsThere(const std::string& el);
    inline bool AddNew(const std::string& n) {
        auto insert_pair = found_options.insert(n);
        return insert_pair.second;
    }
    inline int Amount() {
        return found_options.size();
    }
protected:
    std::set<std::string> found_options;
    
};*/

class SD_HelperParserOfCmdArguments : public SD_Class {
public:
    SD_DECLARE_CLASS_H()
    SD_HelperParserOfCmdArguments() = delete;
    SD_HelperParserOfCmdArguments(boost::program_options::variables_map& map);

    virtual bool IsThereOneOf(const std::string& one, std::initializer_list<std::string> of) const;
    virtual bool IsThereListOf(std::initializer_list<std::string> list, std::initializer_list<std::string> of) const;
    virtual bool IsThere(const std::string& one) const;
    virtual int HowManyOf(std::initializer_list<std::string> of) const;

    inline const boost::program_options::variables_map& GetVariablesMap() const {
        return map;
    }
    inline boost::program_options::variables_map& GetVariablesMap() {
        return map;
    }
protected:
    boost::program_options::variables_map& map;
};


////////////////////////////////////////
class SD_Main : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    typedef SD_HelperParserOfCmdArguments _helper;

    SD_Main() = delete;
    SD_Main(int argc, char* argv[]);
    virtual ~SD_Main() = default;

    inline const boost::program_options::options_description& GetAllOptionsDescriptions() const {
        return all_options_descriptions;
    }
    inline const boost::program_options::options_description GetHelpOptionsDescriptions() const {
        return help_options_descriptions;
    }
    inline const boost::program_options::options_description& GetTestingOptionsDescriptions() const {
        return testing_options_descriptions;
    }
    inline const boost::program_options::options_description& GetDemosOptionsDescriptions() const {
        return demos_options_descriptions;
    }
    inline const boost::program_options::variables_map& GetVariablesMap() const {
        return variables_map;
    }
    inline const _helper& GetHelper() const {
        return helper;
    }
protected:
    virtual void InitializeOptionsDescriptions();
    virtual void ParseCommandLine(int argc, char* argv[]);
    virtual void Action();
    virtual void Action_ExecuteTests();
    virtual void RunTests(SD_TestSpecify& specify);

    /**
     * @brief (Not Implemented Yet)
     */
    virtual void Action_RunDemo();
    virtual void Action_Help();
    virtual void Action_HelpOptions();
    virtual void Action_TestingOptions();
    virtual void Action_DemosOptions();

    virtual void ParseExecuteList();
    virtual void ParseRealtimeExecuteList();
    virtual void ParseUnitExecuteList();
    virtual void ShowRealtimeList();
    virtual void ShowUnitList();
    virtual void ShowRealtimeDetailedList();
    virtual void ShowUnitDetailedList();
    virtual void ParseRunDemo();

    inline void SetError(const std::string& error_message) {
        this->error_message = error_message;
    }
    inline bool NoErrors() const {
        return (this->error_message.compare("no errors") == 0);
    }
    
    

    std::string help_begin_information;
    boost::program_options::options_description all_options_descriptions;
    boost::program_options::options_description help_options_descriptions;
    boost::program_options::options_description testing_options_descriptions;
    boost::program_options::options_description demos_options_descriptions;
    boost::program_options::variables_map variables_map;

    std::string error_message = "no errors";
    SD_TestTypes test_types_to_execute;
    _helper helper;
};  


////////////////////////////////////////

#endif