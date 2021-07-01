/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#include <sol/sol.hpp>
#include <string>

////////////////////////////////////////
class LuaSubClass {
public:
    LuaSubClass(int x, int y) : x(x), y(y) {}

    inline std::string Result() const {
        return std::string() + std::to_string(x)+ "_" + std::to_string(y);
    }
protected:
    int x,y;
};
////////////////////////////////////////
class LuaClass {
public:
    LuaClass() {
        sub_class = std::make_shared<LuaSubClass>(200,500);
        sub_class2 = std::make_shared<LuaSubClass>(4,524);
    }
    inline std::string Result() const {
        return sub_class->Result() + "___" + sub_class2->Result();
    }
protected:
    std::shared_ptr<LuaSubClass> sub_class;
    std::shared_ptr<LuaSubClass> sub_class2;

};
////////////////////////////////////////
void Other_LuaTesting1() {
	sol::state lua;
    lua.open_libraries(sol::lib::base);

    sol::usertype<LuaClass> userdata_luaclass = lua.new_usertype<LuaClass>("luaclass");
    sol::usertype<LuaSubClass> userdata_luasubclass = lua.new_usertype<LuaSubClass>("luasubclass");

    userdata_luaclass["result"] = &LuaClass::Result;

    lua.script_file("lua_script.lua");
}
////////////////////////////////////////