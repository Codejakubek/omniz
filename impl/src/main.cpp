/**
 * OmniZShooters private source code, under no license.
 * Copyright © 2021 Dawid Jakubowski (Codedemens)
 * 
 * 
 * Authors:
 * Lead Programmer, Graphic Designer, Audio Engineer, Voice Actor:
 *     - Dawid (Codedemens) Jakubowski
 */
 
#include <string>
#include <iostream>

#include <OZ_Core.h>

#include <SigmaDev/Misc/GenericContainer.h>
#include <SigmaDev/Testing/Testing.h>
#include <SigmaDev/Main/Main.h>



//#define OZ_STANDARD_CORE_INITIALIZATION
#define OZ_SIGMADEV_TESTING
//#define OTHER_LUA_TESTING

#ifdef OTHER_LUA_TESTING
#include <Other_LuaTesting.h>
#endif

int main(int argc, char* argv[]) {

#ifdef OTHER_LUA_TESTING
    Other_LuaTesting1();
#endif

#ifdef OZ_SIGMADEV_TESTING
    SD_Main main(argc, argv);
#endif

#ifdef OZ_STANDARD_CORE_INITIALIZATION
    OZ_Core core;
    core.BuildImpl<OZ_CurrentCoreImpl>();

    
#endif

    return 0;
}